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


