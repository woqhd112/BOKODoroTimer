#include "pch.h"
#include "TimerDBManager.h"

TimerDBManager::TimerDBManager()
{

}

TimerDBManager::~TimerDBManager()
{
	if (MVC_Controller)
	{
		delete MVC_Controller;
		MVC_Controller = nullptr;
	}
}


bool TimerDBManager::SelectAllTimer(ComplexVector<TimerVO>* out_timerVOContainer)
{
	if (MVC_Controller->SelectAllTimer())
	{
		RequestScope->GetRequestAttributes(out_timerVOContainer);
		return true;
	}

	return false;
}

bool TimerDBManager::SelectOneTimer(int in_timerSEQ, TimerVO* out_timerVO)
{
	m_inputTimerVO.SetTimerSEQ(in_timerSEQ);
	RequestScope->SetRequestAttributes(m_inputTimerVO);
	m_inputTimerVO.Clear();

	if (MVC_Controller->SelectOneTimer())
	{
		RequestScope->GetRequestAttributes(out_timerVO);
		return true;
	}

	return false;
}

bool TimerDBManager::UpdateTimerAutoIncrementSeq()
{
	if (MVC_Controller->UpdateTimerAutoIncrementSeq())
		return true;

	return false;
}

bool TimerDBManager::InsertTimer(TimerVO& in_timerVO)
{
	m_inputTimerVO.SetWkHOUR(in_timerVO.GetWkHOUR());
	m_inputTimerVO.SetWkMINUTE(in_timerVO.GetWkMINUTE());
	m_inputTimerVO.SetWkSECOND(in_timerVO.GetWkSECOND());
	m_inputTimerVO.SetRsHOUR(in_timerVO.GetRsHOUR());
	m_inputTimerVO.SetRsMINUTE(in_timerVO.GetRsMINUTE());
	m_inputTimerVO.SetRsSECOND(in_timerVO.GetRsSECOND());
	m_inputTimerVO.SetRfHOUR(in_timerVO.GetRfHOUR());
	m_inputTimerVO.SetRfMINUTE(in_timerVO.GetRfMINUTE());
	m_inputTimerVO.SetRfSECOND(in_timerVO.GetRfSECOND());
	m_inputTimerVO.SetTimerSEQ(in_timerVO.GetTimerSEQ());
	m_inputTimerVO.SetWrREPEAT(in_timerVO.GetWrREPEAT());
	m_inputTimerVO.SetAllREPEAT(in_timerVO.GetAllREPEAT());

	RequestScope->SetRequestAttributes(m_inputTimerVO);
	m_inputTimerVO.Clear();

	if (MVC_Controller->InsertTimer())
		return true;

	return false;
}

bool TimerDBManager::UpdateTimer(TimerVO& in_timerVO)
{
	m_inputTimerVO.SetWkHOUR(in_timerVO.GetWkHOUR());
	m_inputTimerVO.SetWkMINUTE(in_timerVO.GetWkMINUTE());
	m_inputTimerVO.SetWkSECOND(in_timerVO.GetWkSECOND());
	m_inputTimerVO.SetRsHOUR(in_timerVO.GetRsHOUR());
	m_inputTimerVO.SetRsMINUTE(in_timerVO.GetRsMINUTE());
	m_inputTimerVO.SetRsSECOND(in_timerVO.GetRsSECOND());
	m_inputTimerVO.SetRfHOUR(in_timerVO.GetRfHOUR());
	m_inputTimerVO.SetRfMINUTE(in_timerVO.GetRfMINUTE());
	m_inputTimerVO.SetRfSECOND(in_timerVO.GetRfSECOND());
	m_inputTimerVO.SetWrREPEAT(in_timerVO.GetWrREPEAT());
	m_inputTimerVO.SetAllREPEAT(in_timerVO.GetAllREPEAT());

	RequestScope->SetRequestAttributes(m_inputTimerVO);
	m_inputTimerVO.Clear();

	if (MVC_Controller->UpdateTimer())
		return true;

	return false;
}

bool TimerDBManager::DeleteTimer(int in_timerSEQ)
{
	m_inputTimerVO.SetTimerSEQ(in_timerSEQ);

	RequestScope->SetRequestAttributes(m_inputTimerVO);
	m_inputTimerVO.Clear();

	if (MVC_Controller->DeleteTimer())
		return true;

	return false;
}

bool TimerDBManager::DeleteAllTimer()
{
	if (MVC_Controller->DeleteAllTimer())
		return true;

	return false;
}
