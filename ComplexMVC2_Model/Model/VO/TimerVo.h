#pragma once
#include "../../commonInclude.h"

class TimerVO
{
public:

	TimerVO()
		: timerSEQ(0)
		, timerNAME("")
		, wkHOUR(0)
		, wkMINUTE(0)
		, wkSECOND(0)
		, rsHOUR(0)
		, rsMINUTE(0)
		, rsSECOND(0)
		, rfHOUR(0)
		, rfMINUTE(0)
		, rfSECOND(0)
		, wrREPEAT(1)
		, allREPEAT(0)
		, infREPEAT(0)
		, muteSET(0)
	{
	
	}

	TimerVO(int timerSEQ, ComplexString timerNAME, int wkHOUR, int wkMINUTE, int wkSECOND, int rsHOUR, int rsMINUTE, int rsSECOND, int rfHOUR, int rfMINUTE, int rfSECOND, int wrREPEAT, int allREPEAT, int infREPEAT, int muteSET)
	{
		this->timerSEQ = timerSEQ;
		this->timerNAME = timerNAME;
		this->wkHOUR = wkHOUR;
		this->wkMINUTE = wkMINUTE;
		this->wkSECOND = wkSECOND;
		this->rsHOUR = rsHOUR;
		this->rsMINUTE = rsMINUTE;
		this->rsSECOND = rsSECOND;
		this->rfHOUR = rfHOUR;
		this->rfMINUTE = rfMINUTE;
		this->rfSECOND = rfSECOND;
		this->wrREPEAT = wrREPEAT;
		this->allREPEAT = allREPEAT;
		this->infREPEAT = infREPEAT;
		this->muteSET = muteSET;
	}

	TimerVO(const TimerVO& vo)
	{
		this->timerSEQ = vo.timerSEQ;

		this->timerNAME = vo.timerNAME;

		this->wkHOUR = vo.wkHOUR;
		this->wkMINUTE = vo.wkMINUTE;
		this->wkSECOND = vo.wkSECOND;

		this->rsHOUR = vo.rsHOUR;
		this->rsMINUTE = vo.rsMINUTE;
		this->rsSECOND = vo.rsSECOND;

		this->rfHOUR = vo.rfHOUR;
		this->rfMINUTE = vo.rfMINUTE;
		this->rfSECOND = vo.rfSECOND;

		this->wrREPEAT = vo.wrREPEAT;
		this->allREPEAT = vo.allREPEAT;
		this->infREPEAT = vo.infREPEAT;
		this->muteSET = vo.muteSET;
	}

	~TimerVO()
	{
	
	}

	void Clear()
	{
		timerSEQ = 0;

		timerNAME = "";

		wkHOUR = 0;
		wkMINUTE = 0;
		wkSECOND = 0;

		rsHOUR = 0;
		rsMINUTE = 0;
		rsSECOND = 0;

		rfHOUR = 0;
		rfMINUTE = 0;
		rfSECOND = 0;

		wrREPEAT = 1;
		allREPEAT = 0;
		infREPEAT = 0;
		muteSET = 0;
	}
	
	void SetTimerSEQ(int timerSEQ)
	{
		this->timerSEQ = timerSEQ;
	}

	void SetTimerNAME(ComplexString timerNAME)
	{
		this->timerNAME = timerNAME;
	}

	void SetWkHOUR(int wkHOUR)
	{
		this->wkHOUR = wkHOUR;
	}

	void SetWkMINUTE(int wkMINUTE)
	{
		this->wkMINUTE = wkMINUTE;
	}

	void SetWkSECOND(int wkSECOND)
	{
		this->wkSECOND = wkSECOND;
	}

	void SetRsHOUR(int rsHOUR)
	{
		this->rsHOUR = rsHOUR;
	}

	void SetRsMINUTE(int rsMINUTE)
	{
		this->rsMINUTE = rsMINUTE;
	}

	void SetRsSECOND(int rsSECOND)
	{
		this->rsSECOND = rsSECOND;
	}

	void SetRfHOUR(int rfHOUR)
	{
		this->rfHOUR = rfHOUR;
	}

	void SetRfMINUTE(int rfMINUTE)
	{
		this->rfMINUTE = rfMINUTE;
	}

	void SetRfSECOND(int rfSECOND)
	{
		this->rfSECOND = rfSECOND;
	}

	void SetWrREPEAT(int wrREPEAT)
	{
		this->wrREPEAT = wrREPEAT;
	}

	void SetAllREPEAT(int allREPEAT)
	{
		this->allREPEAT = allREPEAT;
	}

	void SetInfREPEAT(int infREPEAT)
	{
		this->infREPEAT = infREPEAT;
	}

	void SetMuteSET(int muteSET)
	{
		this->muteSET = muteSET;
	}

	int GetTimerSEQ() const
	{
		return timerSEQ;
	}

	ComplexString GetTimerNAME() const
	{
		return timerNAME;
	}

	int GetWkHOUR() const
	{
		return wkHOUR;
	}

	int GetWkMINUTE() const
	{
		return wkMINUTE;
	}

	int GetWkSECOND() const
	{
		return wkSECOND;
	}

	int GetRsHOUR() const
	{
		return rsHOUR;
	}

	int GetRsMINUTE() const
	{
		return rsMINUTE;
	}

	int GetRsSECOND() const
	{
		return rsSECOND;
	}

	int GetRfHOUR() const
	{
		return rfHOUR;
	}

	int GetRfMINUTE() const
	{
		return rfMINUTE;
	}

	int GetRfSECOND() const
	{
		return rfSECOND;
	}

	int GetWrREPEAT() const
	{
		return wrREPEAT;
	}

	int GetAllREPEAT() const
	{
		return allREPEAT;
	}

	int GetInfREPEAT() const
	{
		return infREPEAT;
	}

	int GetMuteSET() const
	{
		return muteSET;
	}

private:

	int timerSEQ; // 타이머 번호

	ComplexString timerNAME; // 타이머이름

	int wkHOUR;	// 업무 시간 0~99
	int wkMINUTE; // 업무 분 0~59
	int wkSECOND; // 업무 초 0~59

	int rsHOUR; // 휴식 시간 0~99
	int rsMINUTE; // 휴식 분 0~59
	int rsSECOND; // 휴식 초 0~59

	int rfHOUR; // 쉼 시간 0~99
	int rfMINUTE; // 쉼 분 0~59
	int rfSECOND; // 쉼 초 0~59

	int wrREPEAT; // 업무 휴식 반복횟수 1~
	int allREPEAT; // 모든반복횟수 0~

	int infREPEAT; // 무한반복 설정 1:무한, 0:커스텀
	int muteSET; // 음소거설정 1:음소거, 0:소리

};