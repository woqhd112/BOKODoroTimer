
// BOKODoroTimerDlg.h: 헤더 파일
//

#pragma once
#include "BOKODoroTimerListDlg.h"

enum TimerState
{
	TMS_NONE = 0,
	TMS_WORKING,
	TMS_RESTING,
	TMS_REFRESHING
};

enum TimerStartState
{
	TSS_STOP = 0,
	TSS_START = 1,
	TSS_PAUSE = 2,
};

// CBOKODoroTimerDlg 대화 상자
class CBOKODoroTimerDlg : public CDialogEx, public DlgInterface
{
// 생성입니다.
public:
	CBOKODoroTimerDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	~CBOKODoroTimerDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_BOKODOROTIMER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


	virtual void Initialize();

	void SetTimeText(TimerVO& time);
	void SignalUpdateTimerUI();

private:

	void ResetTimer();

	void ClickTimeEditEvent(MSG* msg);
	void StartWithEnableUI(BOOL enable);

	void SaveProcessTimer();
	void LoadProcessTimer();

	void SaveDBTimer();
	void LoadDBTimer();

	void ResetWorkTimeUI();
	void ResetRestTimeUI();
	void ResetRefreshTimeUI();

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedRadioInfinite();
	afx_msg void OnBnClickedRadioCustom();
	afx_msg void OnEnChangeEditWorkMinute1();
	afx_msg void OnEnChangeEditWorkSecond1();
	afx_msg void OnEnChangeEditRestMinute1();
	afx_msg void OnEnChangeEditRestSecond1();
	afx_msg void OnEnChangeEditRefreshMinute1();
	afx_msg void OnEnChangeEditRefreshSecond1();
	afx_msg void OnBnClickedMfcbuttonStart();
	afx_msg void OnBnClickedMfcbuttonStop();
	afx_msg void OnBnClickedMfcbuttonReset();
	afx_msg void OnBnClickedMfcbuttonWorkHourUp();
	afx_msg void OnBnClickedMfcbuttonWorkHourDown();
	afx_msg void OnBnClickedMfcbuttonWorkMinuteUp();
	afx_msg void OnBnClickedMfcbuttonWorkMinuteDown();
	afx_msg void OnBnClickedMfcbuttonWorkSecondUp();
	afx_msg void OnBnClickedMfcbuttonWorkSecondDown();
	afx_msg void OnBnClickedMfcbuttonRestHourUp();
	afx_msg void OnBnClickedMfcbuttonRestHourDown();
	afx_msg void OnBnClickedMfcbuttonRestMinuteUp();
	afx_msg void OnBnClickedMfcbuttonRestMinuteDown();
	afx_msg void OnBnClickedMfcbuttonRestSecondUp();
	afx_msg void OnBnClickedMfcbuttonRestSecondDown();
	afx_msg void OnBnClickedMfcbuttonRefreshHourUp();
	afx_msg void OnBnClickedMfcbuttonRefreshHourDown();
	afx_msg void OnBnClickedMfcbuttonRefreshMinuteUp();
	afx_msg void OnBnClickedMfcbuttonRefreshMinuteDown();
	afx_msg void OnBnClickedMfcbuttonRefreshSecondUp();
	afx_msg void OnBnClickedMfcbuttonRefreshSecondDown();
	afx_msg void OnEnChangeEditWorkHour1();
	afx_msg void OnEnChangeEditWorkHour2();
	afx_msg void OnEnChangeEditRestHour1();
	afx_msg void OnEnChangeEditRestHour2();
	afx_msg void OnEnChangeEditRefreshHour1();
	afx_msg void OnEnChangeEditRefreshHour2();
	afx_msg void OnEnChangeEditWorkMinute2();
	afx_msg void OnEnChangeEditWorkSecond2();
	afx_msg void OnEnChangeEditRestMinute2();
	afx_msg void OnEnChangeEditRestSecond2();
	afx_msg void OnEnChangeEditRefreshMinute2();
	afx_msg void OnEnChangeEditRefreshSecond2();
	afx_msg void OnEnChangeEditWorkRestRepeatSet();
	afx_msg void OnEnChangeEditAllRepeatSet();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedMfcbuttonExpandTimerList();
	virtual void OnOK();

private:

	BOKODoroTimerListDlg* m_pBOKODoroTimerListDlg;

	TimerVO m_loadTimer;
	TimerVO m_processTimer;

	TimerVO m_startTimer;

	TimerState m_state;
	TimerStartState m_startState;

	CFont m_radioFont;

	CustomStatic m_stt_repeat_setting;
	CustomStatic m_stt_state;
	CustomStatic m_stt_work_rest_repeat_set;
	CustomStatic m_stt_all_repeat_set;
	CustomStatic m_stt_work_time;
	CustomStatic m_stt_rest_time;
	CustomStatic m_stt_refresh_time;
	CustomStatic m_stt_work_hour;
	CustomStatic m_stt_work_minute;
	CustomStatic m_stt_work_second;
	CustomStatic m_stt_rest_hour;
	CustomStatic m_stt_rest_minute;
	CustomStatic m_stt_rest_second;
	CustomStatic m_stt_refresh_hour;
	CustomStatic m_stt_refresh_minute;
	CustomStatic m_stt_refresh_second;

	CustomEdit m_edit_state;
	CustomEdit m_edit_work_rest_repeat_set;
	CustomEdit m_edit_all_repeat_set;
	CustomEdit m_edit_work_hour1;
	CustomEdit m_edit_work_hour2;
	CustomEdit m_edit_work_minute1;
	CustomEdit m_edit_work_minute2;
	CustomEdit m_edit_work_second1;
	CustomEdit m_edit_work_second2;
	CustomEdit m_edit_rest_hour1;
	CustomEdit m_edit_rest_hour2;
	CustomEdit m_edit_rest_minute1;
	CustomEdit m_edit_rest_minute2;
	CustomEdit m_edit_rest_second1;
	CustomEdit m_edit_rest_second2;
	CustomEdit m_edit_refresh_hour1;
	CustomEdit m_edit_refresh_hour2;
	CustomEdit m_edit_refresh_minute1;
	CustomEdit m_edit_refresh_minute2;
	CustomEdit m_edit_refresh_second1;
	CustomEdit m_edit_refresh_second2;

	CButton m_radio_infinite_repeat;
	CButton m_radio_custom_setting;
	CustomButton m_btn_work_hour_up;
	CustomButton m_btn_work_hour_down;
	CustomButton m_btn_work_minute_up;
	CustomButton m_btn_work_minute_down;
	CustomButton m_btn_work_second_up;
	CustomButton m_btn_work_second_down;
	CustomButton m_btn_rest_hour_up;
	CustomButton m_btn_rest_hour_down;
	CustomButton m_btn_rest_minute_up;
	CustomButton m_btn_rest_minute_down;
	CustomButton m_btn_rest_second_up;
	CustomButton m_btn_rest_second_down;
	CustomButton m_btn_refresh_hour_up;
	CustomButton m_btn_refresh_hour_down;
	CustomButton m_btn_refresh_minute_up;
	CustomButton m_btn_refresh_minute_down;
	CustomButton m_btn_refresh_second_up;
	CustomButton m_btn_refresh_second_down;
	CustomButton m_btn_start;
	CustomButton m_btn_stop;
	CustomButton m_btn_reset;
	CustomButton m_btn_expand_timer_list;
};
