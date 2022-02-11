#pragma once
#include "..\VO\TimerVO.h"

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
	void SetTimer(int timerSEQ, int wkHOUR, int wkMINUTE, int wkSECOND, int rsHOUR, int rsMINUTE, int rsSECOND, int rfHOUR, int rfMINUTE, int rfSECOND, int wrREPEAT, int allREPEAT);

	void GetInt(int* out_int);
	void GetString(ComplexString* out_string);

	void GetTimer(TimerVO* out, int get_row_index = 0);
	void GetTimer(int* out_timerSEQ, int* out_wkHOUR, int* out_wkMINUTE, int* out_wkSECOND, int* out_rsHOUR, int* out_rsMINUTE, int* out_rsSECOND, int* out_rfHOUR, int* out_rfMINUTE, int* out_rfSECOND, int* out_wrREPEAT, int* out_allREPEAT, int get_row_index = 0);
	void GetTimerContainer(ComplexVector<TimerVO>* out_timerVOContainer);

	void ResetInt();
	void ResetString();

	void ResetTimer();

private:

	ComplexString m_string;
	int m_int;
	ComplexVector<TimerVO> m_timerVOContainer;

};

