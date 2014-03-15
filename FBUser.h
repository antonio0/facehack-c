 
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

		QString id; 
		QString name; 
		QString first_name;
		QString last_name;
		QString link;
		QString birthday;
		QString gender;
		QString email;
		QString username;
		QString profile_pic;
		
	public: 
		FBUser* getInstance();

		FBUser(QString uid);
		FBUser(QString uid, QString name, QString profile_pic);

		std::vector<FBUser> getFriends();
		std::vector<FBStatusElement> getStatuses();


		QString getId() {
		   return id;
		}

		QString getName() {
		   return name;
		}

		QString getFirstName() {
		   return first_name;
		}

		QString getLastName() {
		   return last_name;
		}
		QString getLink() {
		   return link;
		}

		QString getBirthday() {
		   return birthday;
		}
		
		QString getGender() {
		   return gender;
		}

		QString getEmail() {
		   return email;
		}

		QString getUsername() {
		   return username;
		}

		QString getProfilePic() {
		   return profile_pic;
		}
};

#endif