#pragma once

enum TRANSACTION_NAME_DEFINE
{
	TND_TIMER_CREATE = 0,
	TND_TIMER_DELETE,
	TND_TIMER_UPDATE,
	TND_TIMER_INSERT,
	TND_SELECT_TIMER_UPDATE,
};

// ���̺� ����Ʈ���� �������� �ȵ�
static const char* TransactionNames[] = {
										"Timer_Create",
										"Timer_Delete",
										"Timer_Update",
										"Timer_Insert",
										"SelectTimer_Update",
										};