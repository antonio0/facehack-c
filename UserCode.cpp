#include "UserCode.h"

void UserCode::run()
{
	WindowsCollector::editable->print("This is a test");
	UT::getInstance()->LogToFile(WindowsCollector::editable->getEntry());
	WindowsCollector::editable->print("This is a second test");
}