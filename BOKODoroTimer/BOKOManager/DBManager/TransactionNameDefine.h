#pragma once

enum TRANSACTION_NAME_DEFINE
{
	TND_TIMER_CREATE = 0,
	TND_TIMER_DELETE,
	TND_TIMER_UPDATE,
	TND_TIMER_INSERT,
};

// 세이브 포인트명은 공백포함 안됨
static const char* TransactionNames[] = {
										"Timer_Create",
										"Timer_Delete",
										"Timer_Update",
										"Timer_Insert",
										};