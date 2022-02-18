#include "pch.h"
#include "SelectTimerModelImp.h"

void ResultSetSelectAllSelectTimer()
{
	DATA_INSTANCE->SetSelectTimer(DB_INSTANCE->GetInt(0));
}

void PrepareStatementUpdateSelectTimer()
{
	int sl;
	DATA_INSTANCE->GetSelectTimer(&sl);
	DB_INSTANCE->SetInt(1, sl);
	DATA_INSTANCE->ResetSelectTimer();
}

SelectTimerModelImp::SelectTimerModelImp()
{

}

SelectTimerModelImp::~SelectTimerModelImp()
{

}

bool SelectTimerModelImp::SelectAllSelectTimer(SelectTimerVO* out_selectTimer)
{
	bool bSuccess = false;
	bSuccess = DB_INSTANCE->PrepareStatement_Execute(DefinedDMLQuerys[SELECT_ALL_SELECT_TIMER_TABLE], NULL, ResultSetSelectAllSelectTimer);

	if (bSuccess)
		DATA_INSTANCE->GetSelectTimer(out_selectTimer);

	DATA_INSTANCE->ResetSelectTimer();

	return bSuccess;
}

bool SelectTimerModelImp::UpdateSelectTimer(int in_sl)
{
	bool bSuccess = false;
	DATA_INSTANCE->SetSelectTimer(in_sl);
	bSuccess = DB_INSTANCE->PrepareStatement_Execute(DefinedDMLQuerys[UPDATE_SELECT_TIMER_TABLE], PrepareStatementUpdateSelectTimer);

	DATA_INSTANCE->ResetSelectTimer();

	return bSuccess;
}
