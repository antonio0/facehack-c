#include "UserCode.h"

void UserCode::run()
{
	WindowsCollector::editable->print("This is a test");
	WindowsCollector::editable->printImage("https://fbcdn-profile-a.akamaihd.net/hprofile-ak-prn2/t5/1119368_1041452858_30478944_q.jpg");
	UT::getInstance()->LogToFile(WindowsCollector::editable->getEntry());
	WindowsCollector::editable->print("This is a second test");
}