
#include "UT.h"
#include "HttpClient.h"
#include "FBWrapper.h"
#include "FBApi.h"
#include <vector>
#include "json/json.h"

FBStatusElement::FBStatusElement(QString uid, QString mess, QString updatedtime) 
{
	this->id = uid;
	this->message = mess;
	this->time = updatedtime;
}


