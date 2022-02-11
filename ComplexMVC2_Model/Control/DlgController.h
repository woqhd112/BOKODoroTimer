#pragma once
#include "../Service/TimerService.h"


class COMPLEXMVC2_MODEL_DLL DlgController
{
public:

	DlgController();
	~DlgController();

	// timer control
	// 타이머 로드
	bool SelectAllTimer();
	// 특정 타이머 로드
	bool SelectOneTimer();
	// 타이머 자동증가 시퀀스 리셋
	bool UpdateTimerAutoIncrementSeq();
	// 타이머 등록
	bool InsertTimer();
	// 타이머 갱신
	bool UpdateTimer();
	// 타이머 삭제
	bool DeleteTimer();
	// 타이머 전체 삭제
	bool DeleteAllTimer();


private:

	TimerService* m_timerService;

};

