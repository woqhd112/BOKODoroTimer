#include "pch.h"
#include "SelectTimerDBManager.h"

SelectTimerDBManager::SelectTimerDBManager()
{

}

SelectTimerDBManager::~SelectTimerDBManager()
{

}

bool SelectTimerDBManager::SelectAllSelectTimer(SelectTimerVO* out_selectTimer)
{
	if (MVC_Controller->SelectAllSelectTimer())
	{
		RequestScope->GetRequestAttributes(out_selectTimer);
		return true;
	}

	return false;
}

bool SelectTimerDBManager::UpdateSelectTimer(SelectTimerVO& in_selectTimer)
{
	m_inputSelectTimerVO.SetSl(in_selectTimer.GetSl());

	RequestScope->SetRequestAttributes(m_inputSelectTimerVO);
	m_inputSelectTimerVO.Clear();

	if (MVC_Controller->UpdateSelectTimer())
		return true;

	return false;
}
