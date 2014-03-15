 
#ifndef __FBSTATUSELEMENT_H_
#define __FBSTATUSELEMENT_H_


#include <QtGui>
#include "UT.h"
#include "HttpClient.h"
#include <iostream>
#include <vector>


class FBStatusElement 
{

	private: 
		FBStatusElement* _instance;
		

	public: 
		FBStatusElement* getInstance();
		
		FBStatusElement(QString uid, QString mess, QString updatedtime);
		
		QString id; 
		QString message; 
		QString time;

};

#endif