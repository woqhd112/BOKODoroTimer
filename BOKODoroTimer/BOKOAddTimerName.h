#pragma once
#include "UICustom/DlgInterface.h"

// BOKOAddTimerName 대화 상자

class BOKOAddTimerName : public CDialogEx, public DlgInterface
{
	DECLARE_DYNAMIC(BOKOAddTimerName)

public:
	BOKOAddTimerName(ComplexString* timerNAME, CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~BOKOAddTimerName();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_ADD_TIMER_NAME };

public:

	CustomStatic m_stt_timer_name;
	CustomEdit m_edit_timer_name;
	CustomButton m_btn_save;
	CustomButton m_btn_cancel;

private:

	ComplexString* m_timerNAME;

private:

	virtual void Initialize() override;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual void OnOK();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedMfcbuttonSaveTimerName();
	afx_msg void OnBnClickedMfcbuttonCancelTimerName();
	afx_msg void OnClose();
};
