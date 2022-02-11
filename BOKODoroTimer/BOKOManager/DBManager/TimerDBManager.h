#pragma once
#include "DBManagerManagement.h"

class TimerDBManager : public DBManagerManagement
{
public:

	TimerDBManager();
	virtual ~TimerDBManager();

	bool SelectAllTimer(ComplexVector<TimerVO>* out_timerVOContainer);
	bool SelectOneTimer(int in_timerSEQ, TimerVO* out_timerVO);
	bool UpdateTimerAutoIncrementSeq();
	bool InsertTimer(TimerVO& in_timerVO);
	bool UpdateTimer(TimerVO& in_timerVO);
	bool DeleteTimer(int in_timerSEQ);
	bool DeleteAllTimer();

private:


};

