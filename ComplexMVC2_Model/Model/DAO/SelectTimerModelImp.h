#pragma once
#include "../DlgModel.h"

void ResultSetSelectAllSelectTimer();
void PrepareStatementUpdateSelectTimer();

class SelectTimerModelImp : public DlgModel
{
public:

	SelectTimerModelImp();
	virtual ~SelectTimerModelImp();

	bool SelectAllSelectTimer(SelectTimerVO* out_selectTimer);
	bool UpdateSelectTimer(int in_sl);

private:


};

