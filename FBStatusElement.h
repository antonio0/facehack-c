 
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
			
		QString id; 
		QString message; 
		QString time;	

	public: 
		FBStatusElement* getInstance();
		
		FBStatusElement(QString uid, QString mess, QString updatedtime);


		QString getId() {
		   return id;
		}

		QString getMessage() {
		   return message;
		}

		QString getTime() {
		   return time;
		}
		
};

#endif