#include "pch.h"
#include "LogManager.h"

LogManager::LogManager()
{
	ComplexUtilProcess::INITIALIZE_LOG();
}

LogManager::~LogManager()
{
	ComplexUtilProcess::TERMINATE_LOG();
}

bool LogManager::OnPutLog(ComplexString logMsg, LogType type)
{
	bool bLogSuccess = false; 

	if (type == LT_EVENT)
	{
		bLogSuccess = ComplexUtilProcess::LOG_E(logMsg);
	}
	else if (type == LT_PROCESS)
	{
		bLogSuccess = ComplexUtilProcess::LOG_P(logMsg);
	}
	else if (type == LT_OPERATE)
	{
		bLogSuccess = ComplexUtilProcess::LOG_O(logMsg);
	}

	return bLogSuccess;
}
