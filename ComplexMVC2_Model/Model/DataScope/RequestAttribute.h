#pragma once
#include "DBDataKernel.h"


class COMPLEXMVC2_MODEL_DLL RequestAttribute
{
public:

	RequestAttribute()
	{
		m_kernel = new DBDataKernel;
	}

	~RequestAttribute()
	{
		if (m_kernel)
		{
			delete m_kernel;
			m_kernel = nullptr;
		}
	}

	void SetRequestInt(int in)
	{
		m_kernel->SetInt(in);
	}

	void SetRequestString(ComplexString in)
	{
		m_kernel->SetString(in);
	}

	void SetRequestAttributes(TimerVO& in)
	{
		m_kernel->SetTimer(in);
	}

	void SetRequestAttributes(ComplexVector<TimerVO>& in)
	{
		ComplexVector<TimerVO>::iterator iter = in.begin();
		while (iter != in.end())
		{
			m_kernel->SetTimer(iter->value);
			iter++;
		}
	}

	void SetRequestAttributes(SelectTimerVO& in)
	{
		m_kernel->SetSelectTimer(in);
	}

	void GetRequestInt(int* out)
	{
		m_kernel->GetInt(out);
		m_kernel->ResetInt();
	}

	void GetRequestString(ComplexString* out)
	{
		m_kernel->GetString(out);
		m_kernel->ResetString();
	}

	void GetRequestAttributes(TimerVO* out, int get_row_index = 0)
	{
		m_kernel->GetTimer(out, get_row_index);
		m_kernel->ResetTimer();
	}

	void GetRequestAttributes(ComplexVector<TimerVO>* out)
	{
		m_kernel->GetTimerContainer(out);
		m_kernel->ResetTimer();
	}

	void GetRequestAttributes(SelectTimerVO* out)
	{
		m_kernel->GetSelectTimer(out);
		m_kernel->ResetSelectTimer();
	}


private:

	DBDataKernel* m_kernel;

};

