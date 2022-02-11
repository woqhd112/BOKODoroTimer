#include "TimerService.h"

TimerService::TimerService()
	: m_timerModel(new TimerModelImp)
{

}

TimerService::~TimerService()
{
	if (m_timerModel)
	{
		delete m_timerModel;
		m_timerModel = nullptr;
	}
}


bool TimerService::SelectAllTimer()
{
	bool bSuccess = false;

	ComplexVector<TimerVO> timer;
	bSuccess = m_timerModel->SelectAllTimer(&timer);

	if (bSuccess)
		RequestScope->SetRequestAttributes(timer);

	return bSuccess;
}

bool TimerService::SelectOneTimer(int in_timerSEQ)
{
	bool bSuccess = false;

	TimerVO timer;
	bSuccess = m_timerModel->SelectOneTimer(in_timerSEQ, &timer);

	if (bSuccess)
		RequestScope->SetRequestAttributes(timer);

	return bSuccess;
}

bool TimerService::UpdateTimerAutoIncrementSeq()
{
	bool bSuccess = false;
	bSuccess = m_timerModel->UpdateTimerAutoIncrementSeq();

	if (bSuccess)
		m_timerModel->Commit();
	else
		m_timerModel->Rollback();

	return bSuccess;
}

bool TimerService::InsertTimer(int in_wkHOUR, int in_wkMINUTE, int in_wkSECOND, int in_rsHOUR, int in_rsMINUTE, int in_rsSECOND, int in_rfHOUR, int in_rfMINUTE, int in_rfSECOND, int in_wrREPEAT, int in_allREPEAT)
{
	bool bSuccess = false;

	bSuccess = m_timerModel->InsertTimer(in_wkHOUR, in_wkMINUTE, in_wkSECOND, in_rsHOUR, in_rsMINUTE, in_rsSECOND, in_rfHOUR, in_rfMINUTE, in_rfSECOND, in_wrREPEAT, in_allREPEAT);

	return bSuccess;
}

bool TimerService::UpdateTimer(int in_wkHOUR, int in_wkMINUTE, int in_wkSECOND, int in_rsHOUR, int in_rsMINUTE, int in_rsSECOND, int in_rfHOUR, int in_rfMINUTE, int in_rfSECOND, int in_timerSEQ, int in_wrREPEAT, int in_allREPEAT)
{
	bool bSuccess = false;

	bSuccess = m_timerModel->UpdateTimer(in_wkHOUR, in_wkMINUTE, in_wkSECOND, in_rsHOUR, in_rsMINUTE, in_rsSECOND, in_rfHOUR, in_rfMINUTE, in_rfSECOND, in_timerSEQ, in_wrREPEAT, in_allREPEAT);

	return bSuccess;
}

bool TimerService::DeleteTimer(int in_timerSEQ)
{
	bool bSuccess = false;

	bSuccess = m_timerModel->DeleteTimer(in_timerSEQ);

	return bSuccess;
}

bool TimerService::DeleteAllTimer()
{
	bool bSuccess = false;

	bSuccess = m_timerModel->DeleteAllTimer();

	return bSuccess;
}
