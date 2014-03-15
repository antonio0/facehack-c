 
#ifndef __FBUSER_H_
#define __FBUSER_H_


#include <QtGui>
#include "UT.h"
#include "HttpClient.h"
#include <iostream>
#include <vector>
#include "FBStatusElement.h"


class FBUser 
{

	private: 
		FBUser* _instance;
		

	public: 
		FBUser* getInstance();
		
		FBUser(QString uid);
		FBUser(QString uid, QString name);

		std::vector<FBUser> getFriends();
		std::vector<FBStatusElement> getStatuses();

		QString id; 
		QString name; 
		QString first_name;
		QString last_name;
		QString link;
		QString birthday;
		QString gender;
		QString email;
		QString username;

};

#endif