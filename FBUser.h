 
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

		bool isFullyLoaded = false;
		
		void loadEverything(QString uid);

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
			if (! isFullyLoaded) loadEverything(id);
			return first_name;
		}

		QString getLastName() {
			if (! isFullyLoaded) loadEverything(id);
		   return last_name;
		}

		QString getLink() {
			if (! isFullyLoaded) loadEverything(id);
		   return link;
		}

		QString getBirthday() {
			if (! isFullyLoaded) loadEverything(id);
		   return birthday;
		}
		
		QString getGender() {
			if (! isFullyLoaded) loadEverything(id);
		   return gender;
		}

		QString getEmail() {
			if (! isFullyLoaded) loadEverything(id);
		   return email;
		}

		QString getUsername() {
			if (! isFullyLoaded) loadEverything(id);
		   return username;
		}

		QString getProfilePic() {
		   return profile_pic;
		}

		void postToWall(QString message);
};

#endif