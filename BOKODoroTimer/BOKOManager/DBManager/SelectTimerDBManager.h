#pragma once
#include "DBManagerManagement.h"

class SelectTimerDBManager : public DBManagerManagement
{
public:

	SelectTimerDBManager();
	virtual ~SelectTimerDBManager();

	bool SelectAllSelectTimer(SelectTimerVO* out_selectTimer);
	bool UpdateSelectTimer(SelectTimerVO& in_selectTimer);

private:


};

