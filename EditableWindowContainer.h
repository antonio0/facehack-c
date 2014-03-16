//##############################################################################
//                                                                             #
// Copyright 2011 Meir yanovich,	                                           #
//	   Questions just email me to meiry242@gmail.com / meiryanovich@gmail.com  #
//                                                                             #
//##############################################################################
#ifndef __EDITABLEWINDOWCONTAINER_H_
#define __EDITABLEWINDOWCONTAINER_H_


#include "ui_main_gui.h"
#include <QtGui> 
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/qnetworkreply.h>
#include <QUrl>
#include <QTimer>
#include <QtWidgets/QLabel>



//========================
#define IO_ReadOnly QIODevice::ReadOnly
#define IO_WriteOnly QIODevice::WriteOnly
#define IO_ReadWrite QIODevice::ReadWrite
#define IO_Append QIODevice::Append
#define IO_Truncate QIODevice::Truncate
#define IO_Translate QIODevice::Text
#define IO_ModeMask 0x00ff
//========================



class EditableWindowContainer : public QMainWindow 
{
    Q_OBJECT

public:
    EditableWindowContainer(QWidget *parent = 0);
    QString getEntry();
    void print(QString input);
    bool testInput();
    void printImage(QString url);


public slots:
  void printImage2(QString url);
	void newEntry();
	void addTextToDisplay(QString);
  void displayImage(QNetworkReply* reply);
  void sslErrorHandler(QNetworkReply* qnr, const QList<QSslError> & errlist);
  void update();

signals:
  void download(QString text);
  void addText(QString text);  

private:
   	Ui2::MainWindow ui2;
   	QString lastEntry;
   	bool readyToGetInput;
   	QMutex mutex;
   	std::vector<QLabel*> labels;
   	QSpacerItem* spacer;
    QNetworkAccessManager* m_netwManager;
    QTimer* timer;
};



#endif
