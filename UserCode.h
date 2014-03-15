#ifndef __USERCODE_H_
#define __USERCODE_H_

#include "WindowsCollector.h"

class UserCode : public QThread
{
	protected:
    	void run();
};

#endif