 
#ifndef __FBWRAPPER_H_
#define __FBWRAPPER_H_


#include <QtGui>
#include "UT.h"
#include "HttpClient.h"
#include <iostream>
#include <vector>
#include "FBUser.h"


class FBWrapper 
{

	private: 
		static FBWrapper* _instance;
		FBWrapper();

	public: 
		static FBWrapper* getInstance();

		FBUser getCurrentUser();
};

#endif