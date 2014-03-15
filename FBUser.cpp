
#include "UT.h"
#include "HttpClient.h"
#include "FBWrapper.h"
#include "FBApi.h"
#include <vector>
#include "json/json.h"

FBUser::FBUser(QString uid, QString name, QString picture_url) 
{
	this->id = uid;
	this->name = name;
	this->profile_pic = picture_url;
}

FBUser::FBUser(QString uid)
{

	QMap<QString, QString> args1;
    QString ApiURLToInvoke = FBApi::getInstance()->GetGENERAL_API_URL()+"/"+uid+"?";
	args1.insert("access_token",FBApi::getInstance()->GetUserAccessToken());
	args1.insert("fields", "id,name,first_name,last_name,link,birthday,picture");

	QString response1;
	FBApi::getInstance()->InvokeAPI(FBApi::GET,
	                                args1,
	                                response1,
									ApiURLToInvoke);

	UT::getInstance()->LogToFile("Rerutend from API:"+response1);
	std::string jsonResponse(response1.toLatin1());
	Json::Value root;   // will contains the root value after parsing.
	Json::Reader reader;
	
	reader.parse( jsonResponse, root );
	
	this->id = QString::fromStdString(root["id"].asString()); 
	this->name = QString::fromStdString(root["name"].asString()); 
    this->first_name = QString::fromStdString(root["first_name"].asString()); 
	this->last_name = QString::fromStdString(root["last_name"].asString()); 
	this->link = QString::fromStdString(root["link"].asString()); 
	this->birthday = QString::fromStdString(root["birthday"].asString()); 
	this->gender = QString::fromStdString(root["gender"].asString()); 
	this->email = QString::fromStdString(root["email"].asString()); 
	this->username = QString::fromStdString(root["username"].asString());
	this->profile_pic = QString::fromStdString(root["picture"]["data"]["url"].asString());
}

std::vector<FBUser> FBUser::getFriends() 
{
	QMap<QString, QString> args1;
    QString ApiURLToInvoke = FBApi::getInstance()->GetGENERAL_API_URL()+"/"+this->id+"?";
	args1.insert("access_token",FBApi::getInstance()->GetUserAccessToken());
	args1.insert("fields", "friends.fields(id,name,picture)");

	QString response1;
	FBApi::getInstance()->InvokeAPI(FBApi::GET,
	                                args1,
	                                response1,
									ApiURLToInvoke);

	QString QpreviousLink = "";
	UT::getInstance()->LogToFile("Rerutend from API:"+response1);
	std::string jsonResponse(response1.toLatin1());
	Json::Value root;   // will contains the root value after parsing.
	Json::Reader reader;
	reader.parse( jsonResponse, root );
	Json::Value friends_data = root["friends"]["data"];

	std::vector<FBUser> friends;
	QString friend_id, friend_name, friend_picture;

	for (int i = 0; i < friends_data.size(); i++) 
	{
		friend_id = QString::fromStdString( friends_data[i]["id"].asString() );
		friend_name = QString::fromStdString( friends_data[i]["name"].asString() );
		friend_picture = QString::fromStdString( friends_data[i]["picture"]["data"]["url"].asString() );
		friends.push_back( FBUser(friend_id, friend_name, friend_picture) );
	}

	return friends;
}

std::vector<FBStatusElement> FBUser::getStatuses() 
{
	QMap<QString, QString> args1;
    QString ApiURLToInvoke = FBApi::getInstance()->GetGENERAL_API_URL()+"/"+this->id+"?";
	args1.insert("access_token",FBApi::getInstance()->GetUserAccessToken());
	args1.insert("fields", "statuses");

	QString response1;
	FBApi::getInstance()->InvokeAPI(FBApi::GET,
	                                args1,
	                                response1,
									ApiURLToInvoke);

	QString QpreviousLink = "";
	UT::getInstance()->LogToFile("Returned from API:"+response1);
	std::string jsonResponse(response1.toLatin1());
	Json::Value root;   // will contains the root value after parsing.
	Json::Reader reader;
	reader.parse( jsonResponse, root );
	Json::Value statuses_data = root["statuses"]["data"];

	std::vector<FBStatusElement> statuses;
	QString status_id, status_message, status_time;

	for (int i = 0; i < statuses_data.size(); i++) 
	{
		status_id = QString::fromStdString( statuses_data[i]["id"].asString() );
		status_message = QString::fromStdString( statuses_data[i]["message"].asString() );
		status_time = QString::fromStdString( statuses_data[i]["updated_time"].asString() );
		statuses.push_back( FBStatusElement(status_id, status_message, status_time) );
	}

	return statuses;
}

