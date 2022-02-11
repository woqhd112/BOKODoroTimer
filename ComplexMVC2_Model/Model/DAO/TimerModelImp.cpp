#include "TimerModelImp.h"

void ResultSetSelectAllTimer()
{
	DATA_INSTANCE->SetTimer(DB_INSTANCE->GetInt(0), DB_INSTANCE->GetInt(1), DB_INSTANCE->GetInt(2), DB_INSTANCE->GetInt(3), DB_INSTANCE->GetInt(4), DB_INSTANCE->GetInt(5), DB_INSTANCE->GetInt(6), DB_INSTANCE->GetInt(7), DB_INSTANCE->GetInt(8), DB_INSTANCE->GetInt(9), DB_INSTANCE->GetInt(10), DB_INSTANCE->GetInt(11));
}

void PrepareStatementSelectOneTimer()
{
	int timerSEQ;
	DATA_INSTANCE->GetTimer(&timerSEQ, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	DB_INSTANCE->SetInt(1, timerSEQ);
	DATA_INSTANCE->ResetTimer();
}

void ResultSetSelectOneTimer()
{
	DATA_INSTANCE->SetTimer(DB_INSTANCE->GetInt(0), DB_INSTANCE->GetInt(1), DB_INSTANCE->GetInt(2), DB_INSTANCE->GetInt(3), DB_INSTANCE->GetInt(4), DB_INSTANCE->GetInt(5), DB_INSTANCE->GetInt(6), DB_INSTANCE->GetInt(7), DB_INSTANCE->GetInt(8), DB_INSTANCE->GetInt(9), DB_INSTANCE->GetInt(10), DB_INSTANCE->GetInt(11));
}

void PrepareStatementInsertTimer()
{
	int wkHOUR, wkMINUTE, wkSECOND, rsHOUR, rsMINUTE, rsSECOND, rfHOUR, rfMINUTE, rfSECOND, wrREPEAT, allREPEAT;
	DATA_INSTANCE->GetTimer(NULL, &wkHOUR, &wkMINUTE, &wkSECOND, &rsHOUR, &rsMINUTE, &rsSECOND, &rfHOUR, &rfMINUTE, &rfSECOND, &wrREPEAT, &allREPEAT);
	DB_INSTANCE->SetInt(1, wkHOUR);
	DB_INSTANCE->SetInt(2, wkMINUTE);
	DB_INSTANCE->SetInt(3, wkSECOND);
	DB_INSTANCE->SetInt(4, rsHOUR);
	DB_INSTANCE->SetInt(5, rsMINUTE);
	DB_INSTANCE->SetInt(6, rsSECOND);
	DB_INSTANCE->SetInt(7, rfHOUR);
	DB_INSTANCE->SetInt(8, rfMINUTE);
	DB_INSTANCE->SetInt(9, rfSECOND);
	DB_INSTANCE->SetInt(10, wrREPEAT);
	DB_INSTANCE->SetInt(11, allREPEAT);
	DATA_INSTANCE->ResetTimer();
}

void PrepareStatementUpdateTimer()
{
	int wkHOUR, wkMINUTE, wkSECOND, rsHOUR, rsMINUTE, rsSECOND, rfHOUR, rfMINUTE, rfSECOND, timerSEQ, wrREPEAT, allREPEAT;
	DATA_INSTANCE->GetTimer(&timerSEQ, &wkHOUR, &wkMINUTE, &wkSECOND, &rsHOUR, &rsMINUTE, &rsSECOND, &rfHOUR, &rfMINUTE, &rfSECOND, &wrREPEAT, &allREPEAT);
	DB_INSTANCE->SetInt(1, wkHOUR);
	DB_INSTANCE->SetInt(2, wkMINUTE);
	DB_INSTANCE->SetInt(3, wkSECOND);
	DB_INSTANCE->SetInt(4, rsHOUR);
	DB_INSTANCE->SetInt(5, rsMINUTE);
	DB_INSTANCE->SetInt(6, rsSECOND);
	DB_INSTANCE->SetInt(7, rfHOUR);
	DB_INSTANCE->SetInt(8, rfMINUTE);
	DB_INSTANCE->SetInt(9, rfSECOND);
	DB_INSTANCE->SetInt(10, wrREPEAT);
	DB_INSTANCE->SetInt(11, allREPEAT);
	DB_INSTANCE->SetInt(12, timerSEQ);
	DATA_INSTANCE->ResetTimer();
}

void PrepareStatementDeleteTimer()
{
	int timerSEQ;
	DATA_INSTANCE->GetTimer(&timerSEQ, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	DB_INSTANCE->SetInt(1, timerSEQ);
	DATA_INSTANCE->ResetTimer();
}


TimerModelImp::TimerModelImp()
{

}

TimerModelImp::~TimerModelImp()
{

}

bool TimerModelImp::SelectAllTimer(ComplexVector<TimerVO>* out_timerVOContainer)
{
	bool bSuccess = false;
	bSuccess = DB_INSTANCE->PrepareStatement_Execute(DefinedDMLQuerys[SELECT_ALL_TIMER_TABLE], NULL, ResultSetSelectAllTimer);

	if (bSuccess)
		DATA_INSTANCE->GetTimerContainer(out_timerVOContainer);

	DATA_INSTANCE->ResetTimer();

	return bSuccess;
}

bool TimerModelImp::SelectOneTimer(int in_timerSEQ, TimerVO* out_timerVO)
{
	bool bSuccess = false;
	DATA_INSTANCE->SetTimer(in_timerSEQ, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	bSuccess = DB_INSTANCE->PrepareStatement_Execute(DefinedDMLQuerys[SELECT_ONE_TIMER_TABLE], PrepareStatementSelectOneTimer, ResultSetSelectOneTimer);

	if (bSuccess)
		DATA_INSTANCE->GetTimer(out_timerVO);

	DATA_INSTANCE->ResetTimer();

	return bSuccess;
}

bool TimerModelImp::UpdateTimerAutoIncrementSeq()
{
	bool bSuccess = false;
	bSuccess = DB_INSTANCE->PrepareStatement_Execute(DefinedDMLQuerys[UPDATE_AUTOINCREMENT_RESET_TIMER], NULL);

	return bSuccess;
}

bool TimerModelImp::InsertTimer(int in_wkHOUR, int in_wkMINUTE, int in_wkSECOND, int in_rsHOUR, int in_rsMINUTE, int in_rsSECOND, int in_rfHOUR, int in_rfMINUTE, int in_rfSECOND, int in_wrREPEAT, int in_allREPEAT)
{
	bool bSuccess = false;
	DATA_INSTANCE->SetTimer(0, in_wkHOUR, in_wkMINUTE, in_wkSECOND, in_rsHOUR, in_rsMINUTE, in_rsSECOND, in_rfHOUR, in_rfMINUTE, in_rfSECOND, in_wrREPEAT, in_allREPEAT);
	bSuccess = DB_INSTANCE->PrepareStatement_Execute(DefinedDMLQuerys[INSERT_TIMER_TABLE], PrepareStatementInsertTimer);

	DATA_INSTANCE->ResetTimer();

	return bSuccess;
}

bool TimerModelImp::UpdateTimer(int in_wkHOUR, int in_wkMINUTE, int in_wkSECOND, int in_rsHOUR, int in_rsMINUTE, int in_rsSECOND, int in_rfHOUR, int in_rfMINUTE, int in_rfSECOND, int in_timerSEQ, int in_wrREPEAT, int in_allREPEAT)
{
	bool bSuccess = false;
	DATA_INSTANCE->SetTimer(in_timerSEQ, in_wkHOUR, in_wkMINUTE, in_wkSECOND, in_rsHOUR, in_rsMINUTE, in_rsSECOND, in_rfHOUR, in_rfMINUTE, in_rfSECOND, in_wrREPEAT, in_allREPEAT);
	bSuccess = DB_INSTANCE->PrepareStatement_Execute(DefinedDMLQuerys[UPDATE_TIMER_TABLE], PrepareStatementUpdateTimer);

	DATA_INSTANCE->ResetTimer();

	return bSuccess;
}

bool TimerModelImp::DeleteTimer(int in_timerSEQ)
{
	bool bSuccess = false;
	DATA_INSTANCE->SetTimer(in_timerSEQ, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	bSuccess = DB_INSTANCE->PrepareStatement_Execute(DefinedDMLQuerys[DELETE_TIMER_TABLE], PrepareStatementDeleteTimer);

	DATA_INSTANCE->ResetTimer();

	return bSuccess;
}

bool TimerModelImp::DeleteAllTimer()
{
	bool bSuccess = false;

	bSuccess = DB_INSTANCE->PrepareStatement_Execute(DefinedDMLQuerys[DELETE_ALL_TIMER_TABLE], NULL);

	return bSuccess;
}
