#pragma once
#include "Log/LogProcess.h"

#ifdef _DEBUG
#pragma comment(lib, "ComplexUtilProcess_dbg.lib")
#else
#pragma comment(lib, "ComplexUtilProcess.lib")
#endif

enum LogType
{
	LT_EVENT = 0,
	LT_PROCESS,
	LT_OPERATE
};

class LogManager
{
public:

	LogManager();
	~LogManager();

	bool OnPutLog(ComplexString logMsg, LogType type);

private:

};

