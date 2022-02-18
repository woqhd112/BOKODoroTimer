#pragma once
#include "../../commonInclude.h"

class SelectTimerVO
{
public:

	SelectTimerVO()
		: sl(0)
	{
	
	}

	SelectTimerVO(int sl)
	{
		this->sl = sl;
	}

	SelectTimerVO(const SelectTimerVO& vo)
	{
		this->sl = vo.sl;
	}

	~SelectTimerVO()
	{
	
	}

	void Clear()
	{
		sl = 0;
	}

	void SetSl(int sl)
	{
		this->sl = sl;
	}

	int GetSl() const
	{
		return sl;
	}

private:

	int sl;

};