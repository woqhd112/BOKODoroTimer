#include "pch.h"
#include "DBDataKernel.h"

DBDataKernel::DBDataKernel()
{

}

DBDataKernel::~DBDataKernel()
{
	
}

void DBDataKernel::ResetInt()
{
	m_int = 0;
}

void DBDataKernel::ResetString()
{
	m_string = "";
}

void DBDataKernel::ResetTimer()
{
	m_timerVOContainer.clear();
}

void DBDataKernel::SetInt(int in_int)
{
	m_int = in_int;
}

void DBDataKernel::SetString(ComplexString in_string)
{
	m_string = in_string;
}

void DBDataKernel::SetTimer(TimerVO& in)
{
	TimerVO timer;
	timer.SetTimerSEQ(in.GetTimerSEQ());
	timer.SetWkHOUR(in.GetWkHOUR());
	timer.SetWkMINUTE(in.GetWkMINUTE());
	timer.SetWkSECOND(in.GetWkSECOND());
	timer.SetRsHOUR(in.GetRsHOUR());
	timer.SetRsMINUTE(in.GetRsMINUTE());
	timer.SetRsSECOND(in.GetRsSECOND());
	timer.SetRfHOUR(in.GetRfHOUR());
	timer.SetRfMINUTE(in.GetRfMINUTE());
	timer.SetRfSECOND(in.GetRfSECOND());
	timer.SetWrREPEAT(in.GetWrREPEAT());
	timer.SetAllREPEAT(in.GetAllREPEAT());
	m_timerVOContainer.push_back(timer);
}

void DBDataKernel::SetTimer(int timerSEQ, int wkHOUR, int wkMINUTE, int wkSECOND, int rsHOUR, int rsMINUTE, int rsSECOND, int rfHOUR, int rfMINUTE, int rfSECOND, int wrREPEAT, int allREPEAT)
{
	TimerVO timer;
	timer.SetTimerSEQ(timerSEQ);
	timer.SetWkHOUR(wkHOUR);
	timer.SetWkMINUTE(wkMINUTE);
	timer.SetWkSECOND(wkSECOND);
	timer.SetRsHOUR(rsHOUR);
	timer.SetRsMINUTE(rsMINUTE);
	timer.SetRsSECOND(rsSECOND);
	timer.SetRfHOUR(rfHOUR);
	timer.SetRfMINUTE(rfMINUTE);
	timer.SetRfSECOND(rfSECOND);
	timer.SetWrREPEAT(wrREPEAT);
	timer.SetAllREPEAT(allREPEAT);
	m_timerVOContainer.push_back(timer);
}

void DBDataKernel::GetInt(int* out_int)
{
	*out_int = m_int;
}

void DBDataKernel::GetString(ComplexString* out_string)
{
	*out_string = m_string;
}

void DBDataKernel::GetTimer(TimerVO* out, int get_row_index)
{
	if (m_timerVOContainer.empty())
		return;

	if (out)
	{
		out->SetTimerSEQ(m_timerVOContainer.at(get_row_index).GetTimerSEQ());
		out->SetWkHOUR(m_timerVOContainer.at(get_row_index).GetWkHOUR());
		out->SetWkMINUTE(m_timerVOContainer.at(get_row_index).GetWkMINUTE());
		out->SetWkSECOND(m_timerVOContainer.at(get_row_index).GetWkSECOND());
		out->SetRsHOUR(m_timerVOContainer.at(get_row_index).GetRsHOUR());
		out->SetRsMINUTE(m_timerVOContainer.at(get_row_index).GetRsMINUTE());
		out->SetRsSECOND(m_timerVOContainer.at(get_row_index).GetRsSECOND());
		out->SetRfHOUR(m_timerVOContainer.at(get_row_index).GetRfHOUR());
		out->SetRfMINUTE(m_timerVOContainer.at(get_row_index).GetRfMINUTE());
		out->SetRfSECOND(m_timerVOContainer.at(get_row_index).GetRfSECOND());
		out->SetWrREPEAT(m_timerVOContainer.at(get_row_index).GetWrREPEAT());
		out->SetAllREPEAT(m_timerVOContainer.at(get_row_index).GetAllREPEAT());
	}
}

void DBDataKernel::GetTimer(int* out_timerSEQ, int* out_wkHOUR, int* out_wkMINUTE, int* out_wkSECOND, int* out_rsHOUR, int* out_rsMINUTE, int* out_rsSECOND, int* out_rfHOUR, int* out_rfMINUTE, int* out_rfSECOND, int* out_wrREPEAT, int* out_allREPEAT, int get_row_index)
{
	if (m_timerVOContainer.empty())
		return;

	if (out_timerSEQ)
		*out_timerSEQ = m_timerVOContainer.at(get_row_index).GetTimerSEQ();

	if (out_wkHOUR)
		*out_wkHOUR = m_timerVOContainer.at(get_row_index).GetWkHOUR();
	if (out_wkMINUTE)
		*out_wkMINUTE = m_timerVOContainer.at(get_row_index).GetWkMINUTE();
	if (out_wkSECOND)
		*out_wkSECOND = m_timerVOContainer.at(get_row_index).GetWkSECOND();

	if (out_rsHOUR)
		*out_rsHOUR = m_timerVOContainer.at(get_row_index).GetRsHOUR();
	if (out_rsMINUTE)
		*out_rsMINUTE = m_timerVOContainer.at(get_row_index).GetRsMINUTE();
	if (out_rsSECOND)
		*out_rsSECOND = m_timerVOContainer.at(get_row_index).GetRsSECOND();

	if (out_rfHOUR)
		*out_rfHOUR = m_timerVOContainer.at(get_row_index).GetRfHOUR();
	if (out_rfMINUTE)
		*out_rfMINUTE = m_timerVOContainer.at(get_row_index).GetRfMINUTE();
	if (out_rfSECOND)
		*out_rfSECOND = m_timerVOContainer.at(get_row_index).GetRfSECOND();

	if (out_wrREPEAT)
		*out_wrREPEAT = m_timerVOContainer.at(get_row_index).GetWrREPEAT();
	if (out_allREPEAT)
		*out_allREPEAT = m_timerVOContainer.at(get_row_index).GetAllREPEAT();
}

void DBDataKernel::GetTimerContainer(ComplexVector<TimerVO>* out_timerVOContainer)
{
	if (out_timerVOContainer)
	{
		ComplexVector<TimerVO>::iterator iter = m_timerVOContainer.begin();

		while (iter != m_timerVOContainer.end())
		{
			TimerVO in_timer;
			in_timer.SetTimerSEQ(iter->value.GetTimerSEQ());

			in_timer.SetWkHOUR(iter->value.GetWkHOUR());
			in_timer.SetWkMINUTE(iter->value.GetWkMINUTE());
			in_timer.SetWkSECOND(iter->value.GetWkSECOND());

			in_timer.SetRsHOUR(iter->value.GetRsHOUR());
			in_timer.SetRsMINUTE(iter->value.GetRsMINUTE());
			in_timer.SetRsSECOND(iter->value.GetRsSECOND());

			in_timer.SetRfHOUR(iter->value.GetRfHOUR());
			in_timer.SetRfMINUTE(iter->value.GetRfMINUTE());
			in_timer.SetRfSECOND(iter->value.GetRfSECOND());

			in_timer.SetWrREPEAT(iter->value.GetWrREPEAT());
			in_timer.SetAllREPEAT(iter->value.GetAllREPEAT());

			out_timerVOContainer->push_back(in_timer);
			iter++;
		}
	}
}
