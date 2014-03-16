//##############################################################################
//                                                                             #
// Copyright 2011 Meir yanovich,	                                           #
//	   Questions just email me to meiry242@gmail.com / meiryanovich@gmail.com  #
//                                                                             #
//##############################################################################
#include <QtGui>
#include <QThread>
#include "EditableWindowContainer.h"
#include "UT.h"
#include <QtWidgets/qapplication.h>


 
EditableWindowContainer::EditableWindowContainer(QWidget* parent) : 
	QMainWindow(parent)  
{
  ui2.setupUi(this); 
  readyToGetInput = false;
  connect(ui2.submitLine, SIGNAL(clicked()), this, SLOT(newEntry()));
  connect(this , SIGNAL(addText(QString)), this, SLOT(addTextToDisplay(QString)));

  spacer = new QSpacerItem(100, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);
  ui2.verticalLayout_5->addItem(spacer);

  m_netwManager = new QNetworkAccessManager(this);
  connect(m_netwManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(displayImage(QNetworkReply*)));
  connect(m_netwManager, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)),
          this, SLOT(sslErrorHandler(QNetworkReply*, const QList<QSslError> & )));
  connect(this, SIGNAL(download(QString)), this, SLOT(printImage2(QString)));
  timer = new QTimer();
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));
  timer->start(200);
}

void EditableWindowContainer::update()
{
    ui2.verticalLayoutWidget->adjustSize();	
}

void EditableWindowContainer::sslErrorHandler(QNetworkReply* qnr, const QList<QSslError> & errlist)
{
  UT::getInstance()->LogToFile("SSL error");  
  #if DEBUG_BUYIT
  qDebug() << "---frmBuyIt::sslErrorHandler: ";
  // show list of all ssl errors
  foreach (QSslError err, errlist)
    qDebug() << "ssl error: " << err;
  #endif
 
   qnr->ignoreSslErrors();
}

void EditableWindowContainer::printImage(QString url)
{
	emit download(url);
}

void EditableWindowContainer::printImage2(QString url)
{
	QUrl url1(url);
	QNetworkRequest request(url1);
    m_netwManager->get(request);
}

void EditableWindowContainer::displayImage(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
    	UT::getInstance()->LogToFile("NETWORK 2 ERROR");
        return;
    }
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    QLabel* label = new QLabel(this);
    label->setPixmap(pixmap);
    ui2.verticalLayout_5->addWidget(label);
    //QThread::msleep( 2000 ); 
    labels.push_back(label);
    ui2.verticalLayout_5->stretch(1);
    ui2.verticalLayoutWidget->adjustSize();
}

QString EditableWindowContainer::getEntry()
{
	mutex.lock();
	readyToGetInput = false;
	mutex.unlock();
	while( !testInput() )
		QThread::msleep( 500 ); 
	return lastEntry;
}

void EditableWindowContainer::addTextToDisplay(QString input)
{
	QLabel* label = new QLabel(this);
	label->setText(input);
	ui2.verticalLayout_5->addWidget(label);
	ui2.verticalLayoutWidget->adjustSize();
	labels.push_back(label);
}

void EditableWindowContainer::print(QString input)
{
	emit addText(input);
}

bool EditableWindowContainer::testInput()
{
	mutex.lock();
	bool result = readyToGetInput;
	mutex.unlock();
	return result;
}

void EditableWindowContainer::newEntry()
{
  lastEntry = ui2.commandLine->text();
  mutex.lock();
  readyToGetInput = true;
  mutex.unlock();
}


