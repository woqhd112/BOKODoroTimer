#pragma once
#include "../Model/DAO/TimerModelImp.h"

class TimerService
{
public:

	TimerService();
	~TimerService();

	bool SelectAllTimer();
	bool SelectOneTimer(int in_timerSEQ);
	bool UpdateTimerAutoIncrementSeq();
	bool InsertTimer(int in_wkHOUR, int in_wkMINUTE, int in_wkSECOND, int in_rsHOUR, int in_rsMINUTE, int in_rsSECOND, int in_rfHOUR, int in_rfMINUTE, int in_rfSECOND, int in_wrREPEAT, int in_allREPEAT);
	bool UpdateTimer(int in_wkHOUR, int in_wkMINUTE, int in_wkSECOND, int in_rsHOUR, int in_rsMINUTE, int in_rsSECOND, int in_rfHOUR, int in_rfMINUTE, int in_rfSECOND, int in_timerSEQ, int in_wrREPEAT, int in_allREPEAT);
	bool DeleteTimer(int in_timerSEQ);
	bool DeleteAllTimer();

private:

	TimerModelImp* m_timerModel;

};

