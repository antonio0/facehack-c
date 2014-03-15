#ifndef __WINDOWSCOLLECTOR_H_
#define __WINDOWSCOLLECTOR_H_

#include "EditableWindowContainer.h"
#include "MainWindowContainer.h"

class WindowsCollector
{
  public:
  	static MainWindowContainer* login;
  	static EditableWindowContainer* editable; 
};

#endif