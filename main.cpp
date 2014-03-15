//##############################################################################
//                                                                             #
// Copyright 2011 Meir yanovich,	                                           #
//	   Questions just email me to meiry242@gmail.com / meiryanovich@gmail.com  #
//                                                                             #
//##############################################################################

#include <cstdlib>
#include <cstdio>


#include <QtWidgets/qapplication.h>

#include "MainWindowContainer.h"
#include "EditableWindowContainer.h"
#include "WindowsCollector.h"

int main(int argc, char *argv[])
{
     QApplication app(argc, argv);
	 app.setStyle("WindowsXP");    
	 // QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8")); 
     // QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
     //MainWindowContainer mainWindowContainer;
     //mainWindowContainer.show();
     WindowsCollector::login = new MainWindowContainer;
     WindowsCollector::login->show();

     WindowsCollector::editable = new EditableWindowContainer;
     return app.exec();
}
