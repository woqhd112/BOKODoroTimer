#include "pch.h"
#include "TimerModelImp.h"

void ResultSetSelectAllTimer()
{
	DATA_INSTANCE->SetTimer(DB_INSTANCE->GetInt(0), DB_INSTANCE->GetString(1), DB_INSTANCE->GetInt(2), DB_INSTANCE->GetInt(3), DB_INSTANCE->GetInt(4), DB_INSTANCE->GetInt(5), DB_INSTANCE->GetInt(6), DB_INSTANCE->GetInt(7), DB_INSTANCE->GetInt(8), DB_INSTANCE->GetInt(9), DB_INSTANCE->GetInt(10), DB_INSTANCE->GetInt(11), DB_INSTANCE->GetInt(12), DB_INSTANCE->GetInt(13), DB_INSTANCE->GetInt(14));
}

void PrepareStatementSelectOneTimer()
{
	int timerSEQ;
	DATA_INSTANCE->GetTimer(&timerSEQ, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	DB_INSTANCE->SetInt(1, timerSEQ);
	DATA_INSTANCE->ResetTimer();
}

void ResultSetSelectOneTimer()
{
	DATA_INSTANCE->SetTimer(DB_INSTANCE->GetInt(0), DB_INSTANCE->GetString(1), DB_INSTANCE->GetInt(2), DB_INSTANCE->GetInt(3), DB_INSTANCE->GetInt(4), DB_INSTANCE->GetInt(5), DB_INSTANCE->GetInt(6), DB_INSTANCE->GetInt(7), DB_INSTANCE->GetInt(8), DB_INSTANCE->GetInt(9), DB_INSTANCE->GetInt(10), DB_INSTANCE->GetInt(11), DB_INSTANCE->GetInt(12), DB_INSTANCE->GetInt(13), DB_INSTANCE->GetInt(14));
}

void PrepareStatementInsertTimer()
{
	ComplexString timerNAME;
	int wkHOUR, wkMINUTE, wkSECOND, rsHOUR, rsMINUTE, rsSECOND, rfHOUR, rfMINUTE, rfSECOND, wrREPEAT, allREPEAT, infREPEAT, muteSET;
	DATA_INSTANCE->GetTimer(NULL, &timerNAME, &wkHOUR, &wkMINUTE, &wkSECOND, &rsHOUR, &rsMINUTE, &rsSECOND, &rfHOUR, &rfMINUTE, &rfSECOND, &wrREPEAT, &allREPEAT, &infREPEAT, &muteSET);
	DB_INSTANCE->SetString(1, timerNAME);
	DB_INSTANCE->SetInt(2, wkHOUR);
	DB_INSTANCE->SetInt(3, wkMINUTE);
	DB_INSTANCE->SetInt(4, wkSECOND);
	DB_INSTANCE->SetInt(5, rsHOUR);
	DB_INSTANCE->SetInt(6, rsMINUTE);
	DB_INSTANCE->SetInt(7, rsSECOND);
	DB_INSTANCE->SetInt(8, rfHOUR);
	DB_INSTANCE->SetInt(9, rfMINUTE);
	DB_INSTANCE->SetInt(10, rfSECOND);
	DB_INSTANCE->SetInt(11, wrREPEAT);
	DB_INSTANCE->SetInt(12, allREPEAT);
	DB_INSTANCE->SetInt(13, infREPEAT);
	DB_INSTANCE->SetInt(14, muteSET);
	DATA_INSTANCE->ResetTimer();
}

void PrepareStatementUpdateTimer()
{
	ComplexString timerNAME;
	int wkHOUR, wkMINUTE, wkSECOND, rsHOUR, rsMINUTE, rsSECOND, rfHOUR, rfMINUTE, rfSECOND, timerSEQ, wrREPEAT, allREPEAT, infREPEAT, muteSET;
	DATA_INSTANCE->GetTimer(&timerSEQ, &timerNAME, &wkHOUR, &wkMINUTE, &wkSECOND, &rsHOUR, &rsMINUTE, &rsSECOND, &rfHOUR, &rfMINUTE, &rfSECOND, &wrREPEAT, &allREPEAT, &infREPEAT, &muteSET);
	DB_INSTANCE->SetString(1, timerNAME);
	DB_INSTANCE->SetInt(2, wkHOUR);
	DB_INSTANCE->SetInt(3, wkMINUTE);
	DB_INSTANCE->SetInt(4, wkSECOND);
	DB_INSTANCE->SetInt(5, rsHOUR);
	DB_INSTANCE->SetInt(6, rsMINUTE);
	DB_INSTANCE->SetInt(7, rsSECOND);
	DB_INSTANCE->SetInt(8, rfHOUR);
	DB_INSTANCE->SetInt(9, rfMINUTE);
	DB_INSTANCE->SetInt(10, rfSECOND);
	DB_INSTANCE->SetInt(11, wrREPEAT);
	DB_INSTANCE->SetInt(12, allREPEAT);
	DB_INSTANCE->SetInt(13, infREPEAT);
	DB_INSTANCE->SetInt(14, muteSET);
	DB_INSTANCE->SetInt(15, timerSEQ);
	DATA_INSTANCE->ResetTimer();
}

void PrepareStatementDeleteTimer()
{
	int timerSEQ;
	DATA_INSTANCE->GetTimer(&timerSEQ, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
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
	DATA_INSTANCE->SetTimer(in_timerSEQ, "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
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

bool TimerModelImp::InsertTimer(ComplexString in_timerNAME, int in_wkHOUR, int in_wkMINUTE, int in_wkSECOND, int in_rsHOUR, int in_rsMINUTE, int in_rsSECOND, int in_rfHOUR, int in_rfMINUTE, int in_rfSECOND, int in_wrREPEAT, int in_allREPEAT, int in_infREPEAT, int in_muteSET)
{
	bool bSuccess = false;
	DATA_INSTANCE->SetTimer(0, in_timerNAME, in_wkHOUR, in_wkMINUTE, in_wkSECOND, in_rsHOUR, in_rsMINUTE, in_rsSECOND, in_rfHOUR, in_rfMINUTE, in_rfSECOND, in_wrREPEAT, in_allREPEAT, in_infREPEAT, in_muteSET);
	bSuccess = DB_INSTANCE->PrepareStatement_Execute(DefinedDMLQuerys[INSERT_TIMER_TABLE], PrepareStatementInsertTimer);

	DATA_INSTANCE->ResetTimer();

	return bSuccess;
}

bool TimerModelImp::UpdateTimer(ComplexString in_timerNAME, int in_wkHOUR, int in_wkMINUTE, int in_wkSECOND, int in_rsHOUR, int in_rsMINUTE, int in_rsSECOND, int in_rfHOUR, int in_rfMINUTE, int in_rfSECOND, int in_timerSEQ, int in_wrREPEAT, int in_allREPEAT, int in_infREPEAT, int in_muteSET)
{
	bool bSuccess = false;
	DATA_INSTANCE->SetTimer(in_timerSEQ, in_timerNAME, in_wkHOUR, in_wkMINUTE, in_wkSECOND, in_rsHOUR, in_rsMINUTE, in_rsSECOND, in_rfHOUR, in_rfMINUTE, in_rfSECOND, in_wrREPEAT, in_allREPEAT, in_infREPEAT, in_muteSET);
	bSuccess = DB_INSTANCE->PrepareStatement_Execute(DefinedDMLQuerys[UPDATE_TIMER_TABLE], PrepareStatementUpdateTimer);

	DATA_INSTANCE->ResetTimer();

	return bSuccess;
}

bool TimerModelImp::DeleteTimer(int in_timerSEQ)
{
	bool bSuccess = false;
	DATA_INSTANCE->SetTimer(in_timerSEQ, "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
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
