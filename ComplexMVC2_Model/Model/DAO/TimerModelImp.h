#pragma once
#include "../DlgModel.h"

void ResultSetSelectAllTimer();
void PrepareStatementSelectOneTimer();
void ResultSetSelectOneTimer();
void PrepareStatementInsertTimer();
void PrepareStatementUpdateTimer();
void PrepareStatementDeleteTimer();

class TimerModelImp : public DlgModel
{
public:

	TimerModelImp();
	virtual ~TimerModelImp();

	bool SelectAllTimer(ComplexVector<TimerVO>* out_timerVOContainer);
	bool SelectOneTimer(int in_timerSEQ, TimerVO* out_timerVO);
	bool UpdateTimerAutoIncrementSeq();
	bool InsertTimer(ComplexString in_timerNAME, int in_wkHOUR, int in_wkMINUTE, int in_wkSECOND, int in_rsHOUR, int in_rsMINUTE, int in_rsSECOND, int in_rfHOUR, int in_rfMINUTE, int in_rfSECOND, int in_wrREPEAT, int in_allREPEAT, int in_infREPEAT, int in_muteSET);
	bool UpdateTimer(ComplexString in_timerNAME, int in_wkHOUR, int in_wkMINUTE, int in_wkSECOND, int in_rsHOUR, int in_rsMINUTE, int in_rsSECOND, int in_rfHOUR, int in_rfMINUTE, int in_rfSECOND, int in_timerSEQ, int in_wrREPEAT, int in_allREPEAT, int in_infREPEAT, int in_muteSET);
	bool DeleteTimer(int in_timerSEQ);
	bool DeleteAllTimer();

private:


};