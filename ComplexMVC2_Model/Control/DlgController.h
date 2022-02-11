#pragma once
#include "../Service/TimerService.h"


class COMPLEXMVC2_MODEL_DLL DlgController
{
public:

	DlgController();
	~DlgController();

	// timer control
	// Ÿ�̸� �ε�
	bool SelectAllTimer();
	// Ư�� Ÿ�̸� �ε�
	bool SelectOneTimer();
	// Ÿ�̸� �ڵ����� ������ ����
	bool UpdateTimerAutoIncrementSeq();
	// Ÿ�̸� ���
	bool InsertTimer();
	// Ÿ�̸� ����
	bool UpdateTimer();
	// Ÿ�̸� ����
	bool DeleteTimer();
	// Ÿ�̸� ��ü ����
	bool DeleteAllTimer();


private:

	TimerService* m_timerService;

};

