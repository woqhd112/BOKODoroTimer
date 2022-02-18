#include "pch.h"
#include "SelectTimerService.h"

SelectTimerService::SelectTimerService()
	: m_selectTimerModel(new SelectTimerModelImp)
{

}

SelectTimerService::~SelectTimerService()
{
	if (m_selectTimerModel)
	{
		delete m_selectTimerModel;
		m_selectTimerModel = nullptr;
	}
}

bool SelectTimerService::SelectAllSelectTimer()
{
	bool bSuccess = false;

	SelectTimerVO selectTimer;
	bSuccess = m_selectTimerModel->SelectAllSelectTimer(&selectTimer);

	if (bSuccess)
		RequestScope->SetRequestAttributes(selectTimer);

	return bSuccess;
}

bool SelectTimerService::UpdateSelectTimer(int in_sl)
{
	bool bSuccess = false;

	bSuccess = m_selectTimerModel->UpdateSelectTimer(in_sl);

	return bSuccess;
}