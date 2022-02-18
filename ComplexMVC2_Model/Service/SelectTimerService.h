#pragma once
#include "../Model/DAO/SelectTimerModelImp.h"

class SelectTimerService
{
public:

	SelectTimerService();
	~SelectTimerService();

	bool SelectAllSelectTimer();
	bool UpdateSelectTimer(int in_sl);

private:

	SelectTimerModelImp* m_selectTimerModel;

};

