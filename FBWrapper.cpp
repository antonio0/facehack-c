 
#include "UT.h"
#include "HttpClient.h"
#include "FBWrapper.h"
#include "FBApi.h"
#include <vector>
#include "json/json.h"
#include "FBUser.h"

FBWrapper* FBWrapper::_instance = NULL ;

FBWrapper::FBWrapper()
{
}


FBWrapper* FBWrapper::getInstance()
{
    
 	if(_instance == NULL)
    {
        _instance = new FBWrapper();
    }
    return _instance;
}

FBUser FBWrapper::getCurrentUser() 
{
	QMap<QString, QString> args1;
    QString ApiURLToInvoke = FBApi::getInstance()->GetGENERAL_API_URL()+"/me?";
	args1.insert("access_token",FBApi::getInstance()->GetUserAccessToken());

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
	bool parsingSuccessful = reader.parse( jsonResponse, root );
	Json::Value id = root["id"];
	QString id_str = QString::fromStdString(id.asString());

	FBApi::getInstance()->SetUserIdKey( id_str );
	
	return FBUser(id_str);
}
