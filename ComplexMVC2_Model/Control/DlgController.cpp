#include "pch.h"
#include "DlgController.h"


DlgController::DlgController()
	: m_timerService(new TimerService)
	, m_selectTimerService(new SelectTimerService)
{

}

DlgController::~DlgController()
{
	if (m_timerService)
	{
		delete m_timerService;
		m_timerService = nullptr;
	}

	if (m_selectTimerService)
	{
		delete m_selectTimerService;
		m_selectTimerService = nullptr;
	}
}

bool DlgController::SelectAllTimer()
{
	return m_timerService->SelectAllTimer();
}

bool DlgController::SelectOneTimer()
{
	TimerVO timer;
	RequestScope->GetRequestAttributes(&timer);
	return m_timerService->SelectOneTimer(timer.GetTimerSEQ());
}

bool DlgController::UpdateTimerAutoIncrementSeq()
{
	TimerVO timer;
	RequestScope->GetRequestAttributes(&timer);
	return m_timerService->UpdateTimerAutoIncrementSeq();
}

bool DlgController::InsertTimer()
{
	TimerVO timer;
	RequestScope->GetRequestAttributes(&timer);
	return m_timerService->InsertTimer(timer.GetTimerNAME(), timer.GetWkHOUR(), timer.GetWkMINUTE(), timer.GetWkSECOND(),
										 timer.GetRsHOUR(), timer.GetRsMINUTE(), timer.GetRsSECOND(),
										 timer.GetRfHOUR(), timer.GetRfMINUTE(), timer.GetRfSECOND(),
										 timer.GetWrREPEAT(), timer.GetAllREPEAT(), timer.GetInfREPEAT(), timer.GetMuteSET());
}

bool DlgController::UpdateTimer()
{
	TimerVO timer;
	RequestScope->GetRequestAttributes(&timer);
	return m_timerService->UpdateTimer(timer.GetTimerNAME(), timer.GetWkHOUR(), timer.GetWkMINUTE(), timer.GetWkSECOND(),
										 timer.GetRsHOUR(), timer.GetRsMINUTE(), timer.GetRsSECOND(),
										 timer.GetRfHOUR(), timer.GetRfMINUTE(), timer.GetRfSECOND(), 
										 timer.GetTimerSEQ(), timer.GetWrREPEAT(), timer.GetAllREPEAT(), timer.GetInfREPEAT(), timer.GetMuteSET());
}

bool DlgController::DeleteTimer()
{
	TimerVO timer;
	RequestScope->GetRequestAttributes(&timer);
	return m_timerService->DeleteTimer(timer.GetTimerSEQ());
}

bool DlgController::DeleteAllTimer()
{
	return m_timerService->DeleteAllTimer();
}

bool DlgController::SelectAllSelectTimer()
{
	return m_selectTimerService->SelectAllSelectTimer();
}

bool DlgController::UpdateSelectTimer()
{
	SelectTimerVO selectTimer;
	RequestScope->GetRequestAttributes(&selectTimer);
	return m_selectTimerService->UpdateSelectTimer(selectTimer.GetSl());
}