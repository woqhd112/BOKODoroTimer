#pragma once
#include "..\VO\TimerVO.h"
#include "..\VO\SelectTimerVO.h"

#ifdef COMPLEXMVC2_MODEL_EXPORTS
#define COMPLEXMVC2_MODEL_DLL __declspec(dllexport)
#else
#define COMPLEXMVC2_MODEL_DLL __declspec(dllimport)
#endif

class DBDataKernel
{
public:

	DBDataKernel();
	~DBDataKernel();

	void SetInt(int in_int);
	void SetString(ComplexString in_string);

	void SetTimer(TimerVO& in);
	void SetTimer(int timerSEQ, ComplexString timerNAME, int wkHOUR, int wkMINUTE, int wkSECOND, int rsHOUR, int rsMINUTE, int rsSECOND, int rfHOUR, int rfMINUTE, int rfSECOND, int wrREPEAT, int allREPEAT, int infREPEAT, int muteSET);
	void SetSelectTimer(SelectTimerVO& in);
	void SetSelectTimer(int sl);

	void GetInt(int* out_int);
	void GetString(ComplexString* out_string);

	void GetTimer(TimerVO* out, int get_row_index = 0);
	void GetTimer(int* out_timerSEQ, ComplexString* out_timerNAME, int* out_wkHOUR, int* out_wkMINUTE, int* out_wkSECOND, int* out_rsHOUR, int* out_rsMINUTE, int* out_rsSECOND, int* out_rfHOUR, int* out_rfMINUTE, int* out_rfSECOND, int* out_wrREPEAT, int* out_allREPEAT, int* out_infREPEAT, int* out_muteSET, int get_row_index = 0);
	void GetTimerContainer(ComplexVector<TimerVO>* out_timerVOContainer);
	void GetSelectTimer(SelectTimerVO* out);
	void GetSelectTimer(int* out_sl);

	void ResetInt();
	void ResetString();

	void ResetTimer();
	void ResetSelectTimer();

private:

	ComplexString m_string;
	int m_int;
	SelectTimerVO m_selectTimer;
	ComplexVector<TimerVO> m_timerVOContainer;

};

