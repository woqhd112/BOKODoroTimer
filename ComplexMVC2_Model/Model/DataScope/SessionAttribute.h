#pragma once
#include "DBDataKernel.h"


class COMPLEXMVC2_MODEL_DLL SessionAttribute
{
public:

	SessionAttribute()
	{
		m_kernel = new DBDataKernel;
	}

	~SessionAttribute()
	{
		if (m_kernel)
		{
			delete m_kernel;
			m_kernel = nullptr;
		}
	}

	void SetSessionInt(int in)
	{
		m_kernel->SetInt(in);
	}

	void SetSessionString(ComplexString in)
	{
		m_kernel->SetString(in);
	}

	void SetSession(TimerVO& in)
	{
		m_kernel->SetTimer(in);
	}

	void SetSession(ComplexVector<TimerVO>& in)
	{
		ComplexVector<TimerVO>::iterator iter = in.begin();
		while (iter != in.end())
		{
			m_kernel->SetTimer(iter->value);
			iter++;
		}
	}

	void SetSession(SelectTimerVO& in)
	{
		m_kernel->SetSelectTimer(in);
	}

	void GetSessionInt(int* out)
	{
		m_kernel->GetInt(out);
	}

	void GetSessionString(ComplexString* out)
	{
		m_kernel->GetString(out);
	}

	void GetSession(TimerVO* out, int get_row_index = 0)
	{
		m_kernel->GetTimer(out, get_row_index);
	}

	void GetSession(ComplexVector<TimerVO>* out)
	{
		m_kernel->GetTimerContainer(out);
	}

	void GetSession(SelectTimerVO* out)
	{
		m_kernel->GetSelectTimer(out);
	}

	void ResetSession()
	{
		m_kernel->ResetInt();
		m_kernel->ResetString();
		m_kernel->ResetTimer();
		m_kernel->ResetSelectTimer();
	}

private:

	DBDataKernel* m_kernel;

};

