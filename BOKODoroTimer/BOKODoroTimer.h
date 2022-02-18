
// BOKODoroTimer.h: PROJECT_NAME 응용 프로그램에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// 주 기호입니다.

#ifdef _DEBUG
#pragma comment(lib, "ComplexLibrary_dbg.lib")
#else
#pragma comment(lib, "ComplexLibrary.lib")
#endif
#include "BOKOManager/DBManager/TimerDBManager.h"
#include "BOKOManager/DBManager/SelectTimerDBManager.h"
#include "BOKOManager/LOGManager/LogManager.h"
#include "PreProcessorDefineConst.h"

// CBOKODoroTimerApp:
// 이 클래스의 구현에 대해서는 BOKODoroTimer.cpp을(를) 참조하세요.
//

static TimerDBManager* Timer_DB_Manager = ComplexSingleton<TimerDBManager>::GetInstancePtr();
static SelectTimerDBManager* SelectTimer_DB_Manager = ComplexSingleton<SelectTimerDBManager>::GetInstancePtr();
static LogManager* Log_Manager = ComplexSingleton<LogManager>::GetInstancePtr();

class CBOKODoroTimerApp : public CWinApp
{
public:
	CBOKODoroTimerApp();
	~CBOKODoroTimerApp();

// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.

	DECLARE_MESSAGE_MAP()
};

extern CBOKODoroTimerApp theApp;
