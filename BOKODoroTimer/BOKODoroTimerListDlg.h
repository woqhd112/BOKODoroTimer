#pragma once
#include "UICustom/DlgInterface.h"
#include "BOKOTimerListCtrl.h"

// BOKODoroTimerListDlg 대화 상자

class BOKODoroTimerListDlg : public CDialogEx, public DlgInterface
{
	DECLARE_DYNAMIC(BOKODoroTimerListDlg)

public:
	BOKODoroTimerListDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~BOKODoroTimerListDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_TIMER_LIST };

	void InsertTimer(TimerVO& timerVO);
	bool DeleteTimer(int itemIndex);
	void StartWithEnableUI(bool enable);

private:

	virtual void Initialize();

	void ReLoadTimerList();
	void LoadTimerDBList();
	void LoadTimerUIList();
	bool UpdateSelectTimer(SelectTimerVO& in_selectTimer);

public:


private:

	ComplexVector<TimerVO> m_timerContainer;
	BOKOTimerListCtrl m_timerListCtrl;
	CustomButton m_btn_delete;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnClose();
	afx_msg void OnBnClickedMfcbuttonTimerDelete();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
};
