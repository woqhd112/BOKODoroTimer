#pragma once
#include "../../commonInclude.h"

class TimerVO
{
public:

	TimerVO()
		: timerSEQ(0)
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
	{
	
	}

	TimerVO(int timerSEQ, int wkHOUR, int wkMINUTE, int wkSECOND, int rsHOUR, int rsMINUTE, int rsSECOND, int rfHOUR, int rfMINUTE, int rfSECOND, int wrREPEAT, int allREPEAT)
	{
		this->timerSEQ = timerSEQ;
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
	}

	TimerVO(const TimerVO& vo)
	{
		this->timerSEQ = vo.timerSEQ;

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
	}

	~TimerVO()
	{
	
	}

	void Clear()
	{
		timerSEQ = 0;

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
	}

	void SetTimerSEQ(int timerSEQ)
	{
		this->timerSEQ = timerSEQ;
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

	int GetTimerSEQ() const
	{
		return timerSEQ;
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

private:

	int timerSEQ;

	int wkHOUR;
	int wkMINUTE;
	int wkSECOND;

	int rsHOUR;
	int rsMINUTE;
	int rsSECOND;

	int rfHOUR;
	int rfMINUTE;
	int rfSECOND;

	int wrREPEAT;
	int allREPEAT;

};