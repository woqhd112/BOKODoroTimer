
// BOKODoroTimerDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "BOKODoroTimer.h"
#include "BOKODoroTimerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBOKODoroTimerDlg 대화 상자



CBOKODoroTimerDlg::CBOKODoroTimerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BOKODOROTIMER_DIALOG, pParent)
	, DlgInterface(this, true)
{
	CreateFrame();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	Log_Manager->OnPutLog("BOKODoroTimerDlg 생성자 호출", LogType::LT_PROCESS);

	m_pBOKODoroTimerListDlg = new BOKODoroTimerListDlg(this);
}

CBOKODoroTimerDlg::~CBOKODoroTimerDlg()
{
	m_radioFont.DeleteObject();

	if (m_pBOKODoroTimerListDlg)
	{
		m_pBOKODoroTimerListDlg->DestroyWindow();
		delete m_pBOKODoroTimerListDlg;
		m_pBOKODoroTimerListDlg = nullptr;
	}

	Log_Manager->OnPutLog("BOKODoroTimerDlg 소멸자 호출", LogType::LT_PROCESS);
}

void CBOKODoroTimerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_REPEAT, m_stt_repeat_setting);
	DDX_Control(pDX, IDC_STATIC_STATE, m_stt_state);
	DDX_Control(pDX, IDC_STATIC_WORK_REST_REPEAT_SET, m_stt_work_rest_repeat_set);
	DDX_Control(pDX, IDC_STATIC_ALL_REPEAT_SET, m_stt_all_repeat_set);
	DDX_Control(pDX, IDC_STATIC_WORK_TIME, m_stt_work_time);
	DDX_Control(pDX, IDC_STATIC_REST_TIME, m_stt_rest_time);
	DDX_Control(pDX, IDC_STATIC_REFRESH_TIME, m_stt_refresh_time);
	DDX_Control(pDX, IDC_STATIC_WORK_HOUR, m_stt_work_hour);
	DDX_Control(pDX, IDC_STATIC_WORK_MINUTE, m_stt_work_minute);
	DDX_Control(pDX, IDC_STATIC_WORK_SECOND, m_stt_work_second);
	DDX_Control(pDX, IDC_STATIC_REST_HOUR, m_stt_rest_hour);
	DDX_Control(pDX, IDC_STATIC_REST_MINUTE, m_stt_rest_minute);
	DDX_Control(pDX, IDC_STATIC_REST_SECOND, m_stt_rest_second);
	DDX_Control(pDX, IDC_STATIC_REFRESH_HOUR, m_stt_refresh_hour);
	DDX_Control(pDX, IDC_STATIC_REFRESH_MINUTE, m_stt_refresh_minute);
	DDX_Control(pDX, IDC_STATIC_REFRESH_SECOND, m_stt_refresh_second);
	DDX_Control(pDX, IDC_EDIT_STATE, m_edit_state);
	DDX_Control(pDX, IDC_EDIT_WORK_REST_REPEAT_SET, m_edit_work_rest_repeat_set);
	DDX_Control(pDX, IDC_EDIT_ALL_REPEAT_SET, m_edit_all_repeat_set);
	DDX_Control(pDX, IDC_EDIT_WORK_HOUR1, m_edit_work_hour1);
	DDX_Control(pDX, IDC_EDIT_WORK_HOUR2, m_edit_work_hour2);
	DDX_Control(pDX, IDC_EDIT_WORK_MINUTE1, m_edit_work_minute1);
	DDX_Control(pDX, IDC_EDIT_WORK_MINUTE2, m_edit_work_minute2);
	DDX_Control(pDX, IDC_EDIT_WORK_SECOND1, m_edit_work_second1);
	DDX_Control(pDX, IDC_EDIT_WORK_SECOND2, m_edit_work_second2);
	DDX_Control(pDX, IDC_EDIT_REST_HOUR1, m_edit_rest_hour1);
	DDX_Control(pDX, IDC_EDIT_REST_HOUR2, m_edit_rest_hour2);
	DDX_Control(pDX, IDC_EDIT_REST_MINUTE1, m_edit_rest_minute1);
	DDX_Control(pDX, IDC_EDIT_REST_MINUTE2, m_edit_rest_minute2);
	DDX_Control(pDX, IDC_EDIT_REST_SECOND1, m_edit_rest_second1);
	DDX_Control(pDX, IDC_EDIT_REST_SECOND2, m_edit_rest_second2);
	DDX_Control(pDX, IDC_EDIT_REFRESH_HOUR1, m_edit_refresh_hour1);
	DDX_Control(pDX, IDC_EDIT_REFRESH_HOUR2, m_edit_refresh_hour2);
	DDX_Control(pDX, IDC_EDIT_REFRESH_MINUTE1, m_edit_refresh_minute1);
	DDX_Control(pDX, IDC_EDIT_REFRESH_MINUTE2, m_edit_refresh_minute2);
	DDX_Control(pDX, IDC_EDIT_REFRESH_SECOND1, m_edit_refresh_second1);
	DDX_Control(pDX, IDC_EDIT_REFRESH_SECOND2, m_edit_refresh_second2);
	DDX_Control(pDX, IDC_RADIO_INFINITE, m_radio_infinite_repeat);
	DDX_Control(pDX, IDC_RADIO_CUSTOM, m_radio_custom_setting);
	DDX_Control(pDX, IDC_MFCBUTTON_WORK_HOUR_UP, m_btn_work_hour_up);
	DDX_Control(pDX, IDC_MFCBUTTON_WORK_HOUR_DOWN, m_btn_work_hour_down);
	DDX_Control(pDX, IDC_MFCBUTTON_WORK_MINUTE_UP, m_btn_work_minute_up);
	DDX_Control(pDX, IDC_MFCBUTTON_WORK_MINUTE_DOWN, m_btn_work_minute_down);
	DDX_Control(pDX, IDC_MFCBUTTON_WORK_SECOND_UP, m_btn_work_second_up);
	DDX_Control(pDX, IDC_MFCBUTTON_WORK_SECOND_DOWN, m_btn_work_second_down);
	DDX_Control(pDX, IDC_MFCBUTTON_REST_HOUR_UP, m_btn_rest_hour_up);
	DDX_Control(pDX, IDC_MFCBUTTON_REST_HOUR_DOWN, m_btn_rest_hour_down);
	DDX_Control(pDX, IDC_MFCBUTTON_REST_MINUTE_UP, m_btn_rest_minute_up);
	DDX_Control(pDX, IDC_MFCBUTTON_REST_MINUTE_DOWN, m_btn_rest_minute_down);
	DDX_Control(pDX, IDC_MFCBUTTON_REST_SECOND_UP, m_btn_rest_second_up);
	DDX_Control(pDX, IDC_MFCBUTTON_REST_SECOND_DOWN, m_btn_rest_second_down);
	DDX_Control(pDX, IDC_MFCBUTTON_REFRESH_HOUR_UP, m_btn_refresh_hour_up);
	DDX_Control(pDX, IDC_MFCBUTTON_REFRESH_HOUR_DOWN, m_btn_refresh_hour_down);
	DDX_Control(pDX, IDC_MFCBUTTON_REFRESH_MINUTE_UP, m_btn_refresh_minute_up);
	DDX_Control(pDX, IDC_MFCBUTTON_REFRESH_MINUTE_DOWN, m_btn_refresh_minute_down);
	DDX_Control(pDX, IDC_MFCBUTTON_REFRESH_SECOND_UP, m_btn_refresh_second_up);
	DDX_Control(pDX, IDC_MFCBUTTON_REFRESH_SECOND_DOWN, m_btn_refresh_second_down);
	DDX_Control(pDX, IDC_MFCBUTTON_START, m_btn_start);
	DDX_Control(pDX, IDC_MFCBUTTON_STOP, m_btn_stop);
	DDX_Control(pDX, IDC_MFCBUTTON_RESET, m_btn_reset);
	DDX_Control(pDX, IDC_MFCBUTTON_EXPAND_TIMER_LIST, m_btn_expand_timer_list);
}

BEGIN_MESSAGE_MAP(CBOKODoroTimerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_RADIO_INFINITE, &CBOKODoroTimerDlg::OnBnClickedRadioInfinite)
	ON_BN_CLICKED(IDC_RADIO_CUSTOM, &CBOKODoroTimerDlg::OnBnClickedRadioCustom)
	ON_EN_CHANGE(IDC_EDIT_WORK_MINUTE1, &CBOKODoroTimerDlg::OnEnChangeEditWorkMinute1)
	ON_EN_CHANGE(IDC_EDIT_WORK_SECOND1, &CBOKODoroTimerDlg::OnEnChangeEditWorkSecond1)
	ON_EN_CHANGE(IDC_EDIT_REST_MINUTE1, &CBOKODoroTimerDlg::OnEnChangeEditRestMinute1)
	ON_EN_CHANGE(IDC_EDIT_REST_SECOND1, &CBOKODoroTimerDlg::OnEnChangeEditRestSecond1)
	ON_EN_CHANGE(IDC_EDIT_REFRESH_MINUTE1, &CBOKODoroTimerDlg::OnEnChangeEditRefreshMinute1)
	ON_EN_CHANGE(IDC_EDIT_REFRESH_SECOND1, &CBOKODoroTimerDlg::OnEnChangeEditRefreshSecond1)
	ON_BN_CLICKED(IDC_MFCBUTTON_START, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonStart)
	ON_BN_CLICKED(IDC_MFCBUTTON_STOP, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonStop)
	ON_BN_CLICKED(IDC_MFCBUTTON_RESET, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonReset)
	ON_BN_CLICKED(IDC_MFCBUTTON_WORK_HOUR_UP, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonWorkHourUp)
	ON_BN_CLICKED(IDC_MFCBUTTON_WORK_HOUR_DOWN, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonWorkHourDown)
	ON_BN_CLICKED(IDC_MFCBUTTON_WORK_MINUTE_UP, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonWorkMinuteUp)
	ON_BN_CLICKED(IDC_MFCBUTTON_WORK_MINUTE_DOWN, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonWorkMinuteDown)
	ON_BN_CLICKED(IDC_MFCBUTTON_WORK_SECOND_UP, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonWorkSecondUp)
	ON_BN_CLICKED(IDC_MFCBUTTON_WORK_SECOND_DOWN, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonWorkSecondDown)
	ON_BN_CLICKED(IDC_MFCBUTTON_REST_HOUR_UP, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonRestHourUp)
	ON_BN_CLICKED(IDC_MFCBUTTON_REST_HOUR_DOWN, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonRestHourDown)
	ON_BN_CLICKED(IDC_MFCBUTTON_REST_MINUTE_UP, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonRestMinuteUp)
	ON_BN_CLICKED(IDC_MFCBUTTON_REST_MINUTE_DOWN, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonRestMinuteDown)
	ON_BN_CLICKED(IDC_MFCBUTTON_REST_SECOND_UP, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonRestSecondUp)
	ON_BN_CLICKED(IDC_MFCBUTTON_REST_SECOND_DOWN, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonRestSecondDown)
	ON_BN_CLICKED(IDC_MFCBUTTON_REFRESH_HOUR_UP, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonRefreshHourUp)
	ON_BN_CLICKED(IDC_MFCBUTTON_REFRESH_HOUR_DOWN, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonRefreshHourDown)
	ON_BN_CLICKED(IDC_MFCBUTTON_REFRESH_MINUTE_UP, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonRefreshMinuteUp)
	ON_BN_CLICKED(IDC_MFCBUTTON_REFRESH_MINUTE_DOWN, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonRefreshMinuteDown)
	ON_BN_CLICKED(IDC_MFCBUTTON_REFRESH_SECOND_UP, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonRefreshSecondUp)
	ON_BN_CLICKED(IDC_MFCBUTTON_REFRESH_SECOND_DOWN, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonRefreshSecondDown)
	ON_EN_CHANGE(IDC_EDIT_WORK_HOUR1, &CBOKODoroTimerDlg::OnEnChangeEditWorkHour1)
	ON_EN_CHANGE(IDC_EDIT_WORK_HOUR2, &CBOKODoroTimerDlg::OnEnChangeEditWorkHour2)
	ON_EN_CHANGE(IDC_EDIT_REST_HOUR1, &CBOKODoroTimerDlg::OnEnChangeEditRestHour1)
	ON_EN_CHANGE(IDC_EDIT_REST_HOUR2, &CBOKODoroTimerDlg::OnEnChangeEditRestHour2)
	ON_EN_CHANGE(IDC_EDIT_REFRESH_HOUR1, &CBOKODoroTimerDlg::OnEnChangeEditRefreshHour1)
	ON_EN_CHANGE(IDC_EDIT_REFRESH_HOUR2, &CBOKODoroTimerDlg::OnEnChangeEditRefreshHour2)
	ON_EN_CHANGE(IDC_EDIT_WORK_MINUTE2, &CBOKODoroTimerDlg::OnEnChangeEditWorkMinute2)
	ON_EN_CHANGE(IDC_EDIT_WORK_SECOND2, &CBOKODoroTimerDlg::OnEnChangeEditWorkSecond2)
	ON_EN_CHANGE(IDC_EDIT_REST_MINUTE2, &CBOKODoroTimerDlg::OnEnChangeEditRestMinute2)
	ON_EN_CHANGE(IDC_EDIT_REST_SECOND2, &CBOKODoroTimerDlg::OnEnChangeEditRestSecond2)
	ON_EN_CHANGE(IDC_EDIT_REFRESH_MINUTE2, &CBOKODoroTimerDlg::OnEnChangeEditRefreshMinute2)
	ON_EN_CHANGE(IDC_EDIT_REFRESH_SECOND2, &CBOKODoroTimerDlg::OnEnChangeEditRefreshSecond2)
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_EDIT_WORK_REST_REPEAT_SET, &CBOKODoroTimerDlg::OnEnChangeEditWorkRestRepeatSet)
	ON_EN_CHANGE(IDC_EDIT_ALL_REPEAT_SET, &CBOKODoroTimerDlg::OnEnChangeEditAllRepeatSet)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_MFCBUTTON_EXPAND_TIMER_LIST, &CBOKODoroTimerDlg::OnBnClickedMfcbuttonExpandTimerList)
END_MESSAGE_MAP()


// CBOKODoroTimerDlg 메시지 처리기

BOOL CBOKODoroTimerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	Initialize();
	Log_Manager->OnPutLog("메인 화면 초기화", LogType::LT_PROCESS);

	GotoDlgCtrl(&m_stt_repeat_setting);

	return FALSE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CBOKODoroTimerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CBOKODoroTimerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		if (m_state == TMS_NONE)
		{
			DrawFrame(&dc, 0);
		}
		else if (m_state == TMS_WORKING)
		{
			DrawFrame(&dc, 1);
		}
		else if (m_state == TMS_RESTING)
		{
			DrawFrame(&dc, 2);
		}
		else if (m_state == TMS_REFRESHING)
		{
			DrawFrame(&dc, 3);
		}
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CBOKODoroTimerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CBOKODoroTimerDlg::SetTimeText(TimerVO& time)
{
	ComplexString strWrREPEAT = ComplexConvert::IntToString(time.GetWrREPEAT());
	ComplexString strAllREPEAT = ComplexConvert::IntToString(time.GetAllREPEAT());
	ComplexString strWkHOUR = ComplexConvert::IntToString(time.GetWkHOUR());
	ComplexString strWkMINUTE = ComplexConvert::IntToString(time.GetWkMINUTE());
	ComplexString strWkSECOND = ComplexConvert::IntToString(time.GetWkSECOND());
	ComplexString strRsHOUR = ComplexConvert::IntToString(time.GetRsHOUR());
	ComplexString strRsMINUTE = ComplexConvert::IntToString(time.GetRsMINUTE());
	ComplexString strRsSECOND = ComplexConvert::IntToString(time.GetRsSECOND());
	ComplexString strRfHOUR = ComplexConvert::IntToString(time.GetRfHOUR());
	ComplexString strRfMINUTE = ComplexConvert::IntToString(time.GetRfMINUTE());
	ComplexString strRfSECOND = ComplexConvert::IntToString(time.GetRfSECOND());

	const char* buf = strWkHOUR.GetBuffer();
	if (strWkHOUR.GetLength() == 1)
		strWkHOUR.Format("0%s", buf);

	buf = strWkMINUTE.GetBuffer();
	if (strWkMINUTE.GetLength() == 1)
		strWkMINUTE.Format("0%s", buf);

	buf = strWkSECOND.GetBuffer();
	if (strWkSECOND.GetLength() == 1)
		strWkSECOND.Format("0%s", buf);

	buf = strRsHOUR.GetBuffer();
	if (strRsHOUR.GetLength() == 1)
		strRsHOUR.Format("0%s", buf);

	buf = strRsMINUTE.GetBuffer();
	if (strRsMINUTE.GetLength() == 1)
		strRsMINUTE.Format("0%s", buf);

	buf = strRsSECOND.GetBuffer();
	if (strRsSECOND.GetLength() == 1)
		strRsSECOND.Format("0%s", buf);

	buf = strRfHOUR.GetBuffer();
	if (strRfHOUR.GetLength() == 1)
		strRfHOUR.Format("0%s", buf);

	buf = strRfMINUTE.GetBuffer();
	if (strRfMINUTE.GetLength() == 1)
		strRfMINUTE.Format("0%s", buf);

	buf = strRfSECOND.GetBuffer();
	if (strRfSECOND.GetLength() == 1)
		strRfSECOND.Format("0%s", buf);

	m_edit_work_hour1.SetWindowTextA(strWkHOUR.GetText(0, 0).GetBuffer());
	m_edit_work_hour2.SetWindowTextA(strWkHOUR.GetText(1, 1).GetBuffer());
	m_edit_work_minute1.SetWindowTextA(strWkMINUTE.GetText(0, 0).GetBuffer());
	m_edit_work_minute2.SetWindowTextA(strWkMINUTE.GetText(1, 1).GetBuffer());
	m_edit_work_second1.SetWindowTextA(strWkSECOND.GetText(0, 0).GetBuffer());
	m_edit_work_second2.SetWindowTextA(strWkSECOND.GetText(1, 1).GetBuffer());
	m_edit_rest_hour1.SetWindowTextA(strRsHOUR.GetText(0, 0).GetBuffer());
	m_edit_rest_hour2.SetWindowTextA(strRsHOUR.GetText(1, 1).GetBuffer());
	m_edit_rest_minute1.SetWindowTextA(strRsMINUTE.GetText(0, 0).GetBuffer());
	m_edit_rest_minute2.SetWindowTextA(strRsMINUTE.GetText(1, 1).GetBuffer());
	m_edit_rest_second1.SetWindowTextA(strRsSECOND.GetText(0, 0).GetBuffer());
	m_edit_rest_second2.SetWindowTextA(strRsSECOND.GetText(1, 1).GetBuffer());
	m_edit_refresh_hour1.SetWindowTextA(strRfHOUR.GetText(0, 0).GetBuffer());
	m_edit_refresh_hour2.SetWindowTextA(strRfHOUR.GetText(1, 1).GetBuffer());
	m_edit_refresh_minute1.SetWindowTextA(strRfMINUTE.GetText(0, 0).GetBuffer());
	m_edit_refresh_minute2.SetWindowTextA(strRfMINUTE.GetText(1, 1).GetBuffer());
	m_edit_refresh_second1.SetWindowTextA(strRfSECOND.GetText(0, 0).GetBuffer());
	m_edit_refresh_second2.SetWindowTextA(strRfSECOND.GetText(1, 1).GetBuffer());

	m_edit_work_rest_repeat_set.SetWindowTextA(strWrREPEAT.GetBuffer());
	m_edit_all_repeat_set.SetWindowTextA(strAllREPEAT.GetBuffer());
}

void CBOKODoroTimerDlg::SignalUpdateTimerUI()
{
	if (m_state == TMS_NONE)
	{
		m_edit_state.SetWindowTextA(STATE_TEXT_NONE);
	}
	else if (m_state == TMS_WORKING)
	{
		m_edit_state.SetWindowTextA(STATE_TEXT_WORK);
	}
	else if (m_state == TMS_RESTING)
	{
		m_edit_state.SetWindowTextA(STATE_TEXT_REST);
	}
	else if (m_state == TMS_REFRESHING)
	{
		m_edit_state.SetWindowTextA(STATE_TEXT_REFRESH);
	}

	Invalidate();
}

void CBOKODoroTimerDlg::ResetTimer()
{
	m_state = TMS_NONE;
	m_startState = TSS_STOP;
	m_edit_state.SetWindowTextA(STATE_TEXT_NONE);

	SetTimeText(m_loadTimer);
}

void CBOKODoroTimerDlg::SaveProcessTimer()
{
	int nTime;
	CString strLeftTime, strRightTime;

	m_edit_work_hour1.GetWindowTextA(strLeftTime);
	m_edit_work_hour2.GetWindowTextA(strRightTime);
	strLeftTime.AppendFormat("%s", strRightTime);
	nTime = ComplexConvert::StringToInt(strLeftTime.GetBuffer());
	m_processTimer.SetWkHOUR(nTime);

	m_edit_work_minute1.GetWindowTextA(strLeftTime);
	m_edit_work_minute2.GetWindowTextA(strRightTime);
	strLeftTime.AppendFormat("%s", strRightTime);
	nTime = ComplexConvert::StringToInt(strLeftTime.GetBuffer());
	m_processTimer.SetWkMINUTE(nTime);

	m_edit_work_second1.GetWindowTextA(strLeftTime);
	m_edit_work_second2.GetWindowTextA(strRightTime);
	strLeftTime.AppendFormat("%s", strRightTime);
	nTime = ComplexConvert::StringToInt(strLeftTime.GetBuffer());
	m_processTimer.SetWkSECOND(nTime);

	m_edit_rest_hour1.GetWindowTextA(strLeftTime);
	m_edit_rest_hour2.GetWindowTextA(strRightTime);
	strLeftTime.AppendFormat("%s", strRightTime);
	nTime = ComplexConvert::StringToInt(strLeftTime.GetBuffer());
	m_processTimer.SetRsHOUR(nTime);

	m_edit_rest_minute1.GetWindowTextA(strLeftTime);
	m_edit_rest_minute2.GetWindowTextA(strRightTime);
	strLeftTime.AppendFormat("%s", strRightTime);
	nTime = ComplexConvert::StringToInt(strLeftTime.GetBuffer());
	m_processTimer.SetRsMINUTE(nTime);

	m_edit_rest_second1.GetWindowTextA(strLeftTime);
	m_edit_rest_second2.GetWindowTextA(strRightTime);
	strLeftTime.AppendFormat("%s", strRightTime);
	nTime = ComplexConvert::StringToInt(strLeftTime.GetBuffer());
	m_processTimer.SetRsSECOND(nTime);

	m_edit_refresh_hour1.GetWindowTextA(strLeftTime);
	m_edit_refresh_hour2.GetWindowTextA(strRightTime);
	strLeftTime.AppendFormat("%s", strRightTime);
	nTime = ComplexConvert::StringToInt(strLeftTime.GetBuffer());
	m_processTimer.SetRfHOUR(nTime);

	m_edit_refresh_minute1.GetWindowTextA(strLeftTime);
	m_edit_refresh_minute2.GetWindowTextA(strRightTime);
	strLeftTime.AppendFormat("%s", strRightTime);
	nTime = ComplexConvert::StringToInt(strLeftTime.GetBuffer());
	m_processTimer.SetRfMINUTE(nTime);

	m_edit_refresh_second1.GetWindowTextA(strLeftTime);
	m_edit_refresh_second2.GetWindowTextA(strRightTime);
	strLeftTime.AppendFormat("%s", strRightTime);
	nTime = ComplexConvert::StringToInt(strLeftTime.GetBuffer());
	m_processTimer.SetRfSECOND(nTime);
}

void CBOKODoroTimerDlg::LoadProcessTimer()
{
	SetTimeText(m_processTimer);
}

void CBOKODoroTimerDlg::SaveDBTimer()
{
	// 타이머 저장 버튼 추가되면 그때 db작업하자
	m_loadTimer = m_processTimer;

	// 새로저장인지 덮어쓰기인지 구분해서 insert, update 구분하기

	Log_Manager->OnPutLog("타이머 정보 저장 완료", LogType::LT_PROCESS);
}

void CBOKODoroTimerDlg::LoadDBTimer()
{
	// 타이머 로드 버튼 추가되면 이 함수 호출

	// 자주쓰는 타이머 설정한것 불러오기..
	int timerSEQ = 0;
	if (Timer_DB_Manager->SelectOneTimer(timerSEQ, &m_loadTimer) == false)
	{
		Log_Manager->OnPutLog("타이머 정보 로드 오류", LogType::LT_PROCESS);
		AfxMessageBox("타이머 정보 로드 오류");
		exit(0);
	}

	Log_Manager->OnPutLog("타이머 정보 로드 완료", LogType::LT_PROCESS);
}

void CBOKODoroTimerDlg::StartWithEnableUI(BOOL enable)
{
	m_edit_work_rest_repeat_set.EnableWindow(enable);
	m_edit_all_repeat_set.EnableWindow(enable);
	m_edit_work_hour1.EnableWindow(enable);
	m_edit_work_hour2.EnableWindow(enable);
	m_edit_work_minute1.EnableWindow(enable);
	m_edit_work_minute2.EnableWindow(enable);
	m_edit_work_second1.EnableWindow(enable);
	m_edit_work_second2.EnableWindow(enable);
	m_edit_rest_hour1.EnableWindow(enable);
	m_edit_rest_hour2.EnableWindow(enable);
	m_edit_rest_minute1.EnableWindow(enable);
	m_edit_rest_minute2.EnableWindow(enable);
	m_edit_rest_second1.EnableWindow(enable);
	m_edit_rest_second2.EnableWindow(enable);
	m_edit_refresh_hour1.EnableWindow(enable);
	m_edit_refresh_hour2.EnableWindow(enable);
	m_edit_refresh_minute1.EnableWindow(enable);
	m_edit_refresh_minute2.EnableWindow(enable);
	m_edit_refresh_second1.EnableWindow(enable);
	m_edit_refresh_second2.EnableWindow(enable);

	m_btn_work_hour_up.EnableWindow(enable);
	m_btn_work_hour_down.EnableWindow(enable);
	m_btn_work_minute_up.EnableWindow(enable);
	m_btn_work_minute_down.EnableWindow(enable);
	m_btn_work_second_up.EnableWindow(enable);
	m_btn_work_second_down.EnableWindow(enable);
	m_btn_rest_hour_up.EnableWindow(enable);
	m_btn_rest_hour_down.EnableWindow(enable);
	m_btn_rest_minute_up.EnableWindow(enable);
	m_btn_rest_minute_down.EnableWindow(enable);
	m_btn_rest_second_up.EnableWindow(enable);
	m_btn_rest_second_down.EnableWindow(enable);
	m_btn_refresh_hour_up.EnableWindow(enable);
	m_btn_refresh_hour_down.EnableWindow(enable);
	m_btn_refresh_minute_up.EnableWindow(enable);
	m_btn_refresh_minute_down.EnableWindow(enable);
	m_btn_refresh_second_up.EnableWindow(enable);
	m_btn_refresh_second_down.EnableWindow(enable);

	m_btn_reset.EnableWindow(enable);
}

void CBOKODoroTimerDlg::ResetWorkTimeUI()
{
	int wkHOUR = m_processTimer.GetWkHOUR();
	int wkMINUTE = m_processTimer.GetWkMINUTE();
	int wkSECOND = m_processTimer.GetWkSECOND();

	ComplexString strWkHOUR = ComplexConvert::IntToString(wkHOUR);
	ComplexString strWkMINUTE = ComplexConvert::IntToString(wkMINUTE);
	ComplexString strWkSECOND = ComplexConvert::IntToString(wkSECOND);

	const char* buf = strWkHOUR.GetBuffer();
	if (strWkHOUR.GetLength() == 1)
		strWkHOUR.Format("0%s", buf);

	buf = strWkMINUTE.GetBuffer();
	if (strWkMINUTE.GetLength() == 1)
		strWkMINUTE.Format("0%s", buf);

	buf = strWkSECOND.GetBuffer();
	if (strWkSECOND.GetLength() == 1)
		strWkSECOND.Format("0%s", buf);

	m_edit_work_hour1.SetWindowTextA(strWkHOUR.GetText(0, 0).GetBuffer());
	m_edit_work_hour2.SetWindowTextA(strWkHOUR.GetText(1, 1).GetBuffer());
	m_edit_work_minute1.SetWindowTextA(strWkMINUTE.GetText(0, 0).GetBuffer());
	m_edit_work_minute2.SetWindowTextA(strWkMINUTE.GetText(1, 1).GetBuffer());
	m_edit_work_second1.SetWindowTextA(strWkSECOND.GetText(0, 0).GetBuffer());
	m_edit_work_second2.SetWindowTextA(strWkSECOND.GetText(1, 1).GetBuffer());
}

void CBOKODoroTimerDlg::ResetRestTimeUI()
{
	int rsHOUR = m_processTimer.GetRsHOUR();
	int rsMINUTE = m_processTimer.GetRsMINUTE();
	int rsSECOND = m_processTimer.GetRsSECOND();

	ComplexString strRsHOUR = ComplexConvert::IntToString(rsHOUR);
	ComplexString strRsMINUTE = ComplexConvert::IntToString(rsMINUTE);
	ComplexString strRsSECOND = ComplexConvert::IntToString(rsSECOND);

	const char* buf = strRsHOUR.GetBuffer();
	if (strRsHOUR.GetLength() == 1)
		strRsHOUR.Format("0%s", buf);

	buf = strRsMINUTE.GetBuffer();
	if (strRsMINUTE.GetLength() == 1)
		strRsMINUTE.Format("0%s", buf);

	buf = strRsSECOND.GetBuffer();
	if (strRsSECOND.GetLength() == 1)
		strRsSECOND.Format("0%s", buf);

	m_edit_rest_hour1.SetWindowTextA(strRsHOUR.GetText(0, 0).GetBuffer());
	m_edit_rest_hour2.SetWindowTextA(strRsHOUR.GetText(1, 1).GetBuffer());
	m_edit_rest_minute1.SetWindowTextA(strRsMINUTE.GetText(0, 0).GetBuffer());
	m_edit_rest_minute2.SetWindowTextA(strRsMINUTE.GetText(1, 1).GetBuffer());
	m_edit_rest_second1.SetWindowTextA(strRsSECOND.GetText(0, 0).GetBuffer());
	m_edit_rest_second2.SetWindowTextA(strRsSECOND.GetText(1, 1).GetBuffer());
}

void CBOKODoroTimerDlg::ResetRefreshTimeUI()
{
	int rfHOUR = m_processTimer.GetRfHOUR();
	int rfMINUTE = m_processTimer.GetRfMINUTE();
	int rfSECOND = m_processTimer.GetRfSECOND();

	ComplexString strRfHOUR = ComplexConvert::IntToString(rfHOUR);
	ComplexString strRfMINUTE = ComplexConvert::IntToString(rfMINUTE);
	ComplexString strRfSECOND = ComplexConvert::IntToString(rfSECOND);

	const char* buf = strRfHOUR.GetBuffer();
	if (strRfHOUR.GetLength() == 1)
		strRfHOUR.Format("0%s", buf);

	buf = strRfMINUTE.GetBuffer();
	if (strRfMINUTE.GetLength() == 1)
		strRfMINUTE.Format("0%s", buf);

	buf = strRfSECOND.GetBuffer();
	if (strRfSECOND.GetLength() == 1)
		strRfSECOND.Format("0%s", buf);

	m_edit_refresh_hour1.SetWindowTextA(strRfHOUR.GetText(0, 0).GetBuffer());
	m_edit_refresh_hour2.SetWindowTextA(strRfHOUR.GetText(1, 1).GetBuffer());
	m_edit_refresh_minute1.SetWindowTextA(strRfMINUTE.GetText(0, 0).GetBuffer());
	m_edit_refresh_minute2.SetWindowTextA(strRfMINUTE.GetText(1, 1).GetBuffer());
	m_edit_refresh_second1.SetWindowTextA(strRfSECOND.GetText(0, 0).GetBuffer());
	m_edit_refresh_second2.SetWindowTextA(strRfSECOND.GetText(1, 1).GetBuffer());
}

void CBOKODoroTimerDlg::Initialize()
{
	InitFrame(TITLE_TEXT);

	SetWindowTextA(TITLE_TEXT);

	LoadDBTimer();

	m_processTimer = m_loadTimer;

	// 폰트 로드
	LoadResourceFont(IDR_TEXT_DIGITAL_FONT);
	LoadResourceFont(IDR_TEXT_GOODDAY_FONT);
	m_radioFont.CreateFontA(FONT_SIZE_REPEAT_SETTING_STATIC, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
		FONT_NAME_TEXT);

	// 컨트롤 상단배치
	CRect itemRect;
	m_stt_repeat_setting.GetWindowRect(itemRect);
	m_stt_repeat_setting.SetWindowPos(NULL, itemRect.left, itemRect.top - 2, 0, 0, SWP_NOSIZE);
	m_stt_work_time.GetWindowRect(itemRect);
	m_stt_work_time.SetWindowPos(NULL, itemRect.left, itemRect.top - 2, 0, 0, SWP_NOSIZE);
	m_stt_rest_time.GetWindowRect(itemRect);
	m_stt_rest_time.SetWindowPos(NULL, itemRect.left, itemRect.top - 2, 0, 0, SWP_NOSIZE);
	m_stt_refresh_time.GetWindowRect(itemRect);
	m_stt_refresh_time.SetWindowPos(NULL, itemRect.left, itemRect.top - 2, 0, 0, SWP_NOSIZE);

	// 버튼 초기화
	SetWindowTheme(m_radio_infinite_repeat, LPCWSTR(""), LPCWSTR(""));
	SetWindowTheme(m_radio_custom_setting, LPCWSTR(""), LPCWSTR(""));
	m_btn_work_hour_up.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_work_hour_down.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_work_minute_up.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_work_minute_down.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_work_second_up.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_work_second_down.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_rest_hour_up.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_rest_hour_down.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_rest_minute_up.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_rest_minute_down.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_rest_second_up.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_rest_second_down.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_refresh_hour_up.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_refresh_hour_down.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_refresh_minute_up.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_refresh_minute_down.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_refresh_second_up.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_refresh_second_down.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_start.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_stop.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_reset.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_expand_timer_list.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_ETC, FW_BOLD);
	m_radio_infinite_repeat.SetFont(&m_radioFont);
	m_radio_custom_setting.SetFont(&m_radioFont);

	// 에딧 초기화
	m_edit_state.Initialize(FONT_SIZE_STATE_EDIT, FONT_NAME_TEXT);
	m_edit_work_rest_repeat_set.Initialize(FONT_SIZE_REPEAT_SETTING_EDIT, FONT_NAME_TEXT);
	m_edit_all_repeat_set.Initialize(FONT_SIZE_REPEAT_SETTING_EDIT, FONT_NAME_TEXT);
	m_edit_work_hour1.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);
	m_edit_work_hour2.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);
	m_edit_work_minute1.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);
	m_edit_work_minute2.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);
	m_edit_work_second1.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);
	m_edit_work_second2.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);
	m_edit_rest_hour1.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);
	m_edit_rest_hour2.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);
	m_edit_rest_minute1.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);
	m_edit_rest_minute2.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);
	m_edit_rest_second1.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);
	m_edit_rest_second2.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);
	m_edit_refresh_hour1.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);
	m_edit_refresh_hour2.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);
	m_edit_refresh_minute1.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);
	m_edit_refresh_minute2.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);
	m_edit_refresh_second1.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);
	m_edit_refresh_second2.Initialize(FONT_SIZE_TIME_EDIT, FONT_NAME_NUMBER);

	// 스태틱 초기화
	m_stt_repeat_setting.Initialize(FONT_SIZE_GROUPBOX_STATIC, FONT_NAME_TEXT);
	m_stt_state.Initialize(FONT_SIZE_STATE_STATIC, FONT_NAME_TEXT);
	m_stt_work_rest_repeat_set.Initialize(FONT_SIZE_REPEAT_SETTING_STATIC, FONT_NAME_TEXT);
	m_stt_all_repeat_set.Initialize(FONT_SIZE_REPEAT_SETTING_STATIC, FONT_NAME_TEXT);
	m_stt_work_time.Initialize(FONT_SIZE_GROUPBOX_STATIC, FONT_NAME_TEXT);
	m_stt_rest_time.Initialize(FONT_SIZE_GROUPBOX_STATIC, FONT_NAME_TEXT);
	m_stt_refresh_time.Initialize(FONT_SIZE_GROUPBOX_STATIC, FONT_NAME_TEXT);
	m_stt_work_hour.Initialize(FONT_SIZE_TIME_STATIC, FONT_NAME_TEXT);
	m_stt_work_minute.Initialize(FONT_SIZE_TIME_STATIC, FONT_NAME_TEXT);
	m_stt_work_second.Initialize(FONT_SIZE_TIME_STATIC, FONT_NAME_TEXT);
	m_stt_rest_hour.Initialize(FONT_SIZE_TIME_STATIC, FONT_NAME_TEXT);
	m_stt_rest_minute.Initialize(FONT_SIZE_TIME_STATIC, FONT_NAME_TEXT);
	m_stt_rest_second.Initialize(FONT_SIZE_TIME_STATIC, FONT_NAME_TEXT);
	m_stt_refresh_hour.Initialize(FONT_SIZE_TIME_STATIC, FONT_NAME_TEXT);
	m_stt_refresh_minute.Initialize(FONT_SIZE_TIME_STATIC, FONT_NAME_TEXT);
	m_stt_refresh_second.Initialize(FONT_SIZE_TIME_STATIC, FONT_NAME_TEXT);

	// 초기값 설정
	m_radio_infinite_repeat.SetCheck(FALSE);
	m_radio_custom_setting.SetCheck(TRUE);

	ResetTimer();

	m_edit_work_hour1.LimitText(1);
	m_edit_work_hour2.LimitText(1);
	m_edit_work_minute1.LimitText(1);
	m_edit_work_minute2.LimitText(1);
	m_edit_work_second1.LimitText(1);
	m_edit_work_second2.LimitText(1);
	m_edit_rest_hour1.LimitText(1);
	m_edit_rest_hour2.LimitText(1);
	m_edit_rest_minute1.LimitText(1);
	m_edit_rest_minute2.LimitText(1);
	m_edit_rest_second1.LimitText(1);
	m_edit_rest_second2.LimitText(1);
	m_edit_refresh_hour1.LimitText(1);
	m_edit_refresh_hour2.LimitText(1);
	m_edit_refresh_minute1.LimitText(1);
	m_edit_refresh_minute2.LimitText(1);
	m_edit_refresh_second1.LimitText(1);
	m_edit_refresh_second2.LimitText(1);
	m_edit_work_rest_repeat_set.LimitText(3);
	m_edit_all_repeat_set.LimitText(3);

	// 타이머 리스트 초기화
	m_pBOKODoroTimerListDlg->Create(BOKODoroTimerListDlg::IDD, this);
	m_pBOKODoroTimerListDlg->ShowWindow(SW_HIDE);
}

void CBOKODoroTimerDlg::ClickTimeEditEvent(MSG* msg)
{
	if ((msg->hwnd == m_edit_work_hour1) || (msg->hwnd == m_edit_work_hour2) ||
		(msg->hwnd == m_edit_work_minute1) || (msg->hwnd == m_edit_work_minute2) ||
		(msg->hwnd == m_edit_work_second1) || (msg->hwnd == m_edit_work_second2) ||
		(msg->hwnd == m_edit_rest_hour1) || (msg->hwnd == m_edit_rest_hour2) ||
		(msg->hwnd == m_edit_rest_minute1) || (msg->hwnd == m_edit_rest_minute2) ||
		(msg->hwnd == m_edit_rest_second1) || (msg->hwnd == m_edit_rest_second2) ||
		(msg->hwnd == m_edit_refresh_hour1) || (msg->hwnd == m_edit_refresh_hour2) ||
		(msg->hwnd == m_edit_refresh_minute1) || (msg->hwnd == m_edit_refresh_minute2) ||
		(msg->hwnd == m_edit_refresh_second1) || (msg->hwnd == m_edit_refresh_second2))
	{
		CustomEdit* handleEdit = (CustomEdit*)FromHandle(msg->hwnd);
		LoadProcessTimer();

		handleEdit->SetWindowTextA("");
	}
}

BOOL CBOKODoroTimerDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (WM_KEYDOWN == pMsg->message)
	{
		if (pMsg->wParam == VK_ESCAPE)
			return TRUE;
	}
	else if (WM_LBUTTONDOWN == pMsg->message)
	{
		TitleBarActiveMove(pMsg);

		ClickTimeEditEvent(pMsg);
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CBOKODoroTimerDlg::OnSize(UINT nType, int cx, int cy)
{
	__super::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	Sizing(nType);
}


HBRUSH CBOKODoroTimerDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = __super::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	HBRUSH returnHBR = CtlColors(pDC, pWnd, nCtlColor);
	if (returnHBR != NULL)
		return returnHBR;

	if (nCtlColor == CTLCOLOR_STATIC)
	{
		if (pWnd->GetDlgCtrlID() == m_edit_state.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetTextColor(TEXT_COLOR_GREEN);
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetTextColor(TEXT_COLOR_YELLOW);
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetTextColor(TEXT_COLOR_RED);
			}

			return hbr;
		}
		else if (pWnd->GetDlgCtrlID() == m_stt_repeat_setting.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(DI_TEXT_COLOR_WHITE);

				return m_staticBrush;
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);

				return m_staticBrush_Green;
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);

				return m_staticBrush_Yellow;
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);

				return m_staticBrush_Red;
			}
			
			return hbr;
		}
		else if (pWnd->GetDlgCtrlID() == m_stt_state.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(DI_TEXT_COLOR_WHITE);

				return m_staticBrush;
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);

				return m_staticBrush_Green;
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);

				return m_staticBrush_Yellow;
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);

				return m_staticBrush_Red;
			}

			return hbr;
		}
		else if (pWnd->GetDlgCtrlID() == m_stt_work_rest_repeat_set.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(DI_TEXT_COLOR_WHITE);

				return m_staticBrush;
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);

				return m_staticBrush_Green;
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);

				return m_staticBrush_Yellow;
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);

				return m_staticBrush_Red;
			}

			return hbr;
		}
		else if (pWnd->GetDlgCtrlID() == m_stt_all_repeat_set.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(DI_TEXT_COLOR_WHITE);

				return m_staticBrush;
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);

				return m_staticBrush_Green;
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);

				return m_staticBrush_Yellow;
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);

				return m_staticBrush_Red;
			}

			return hbr;
		}
		else if (pWnd->GetDlgCtrlID() == m_stt_work_time.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(TEXT_COLOR_GREEN);

				return m_staticBrush;
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(TEXT_COLOR_GREEN);

				return m_staticBrush_Green;
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(TEXT_COLOR_GREEN);

				return m_staticBrush_Yellow;
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(TEXT_COLOR_GREEN);

				return m_staticBrush_Red;
			}

			return hbr;
		}
		else if (pWnd->GetDlgCtrlID() == m_stt_rest_time.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(TEXT_COLOR_YELLOW);

				return m_staticBrush;
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(TEXT_COLOR_YELLOW);

				return m_staticBrush_Green;
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(TEXT_COLOR_YELLOW);

				return m_staticBrush_Yellow;
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(TEXT_COLOR_YELLOW);

				return m_staticBrush_Red;
			}

			return hbr;
		}
		else if (pWnd->GetDlgCtrlID() == m_stt_refresh_time.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(TEXT_COLOR_RED);

				return m_staticBrush;
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(TEXT_COLOR_RED);

				return m_staticBrush_Green;
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(TEXT_COLOR_RED);

				return m_staticBrush_Yellow;
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(TEXT_COLOR_RED);

				return m_staticBrush_Red;
			}

			return hbr;
		}
		else if (pWnd->GetDlgCtrlID() == m_stt_work_hour.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(TEXT_COLOR_GREEN);

				return m_staticBrush;
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(TEXT_COLOR_GREEN);

				return m_staticBrush_Green;
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(TEXT_COLOR_GREEN);

				return m_staticBrush_Yellow;
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(TEXT_COLOR_GREEN);

				return m_staticBrush_Red;
			}

			return hbr;
		}
		else if (pWnd->GetDlgCtrlID() == m_stt_work_minute.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(TEXT_COLOR_GREEN);

				return m_staticBrush;
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(TEXT_COLOR_GREEN);

				return m_staticBrush_Green;
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(TEXT_COLOR_GREEN);

				return m_staticBrush_Yellow;
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(TEXT_COLOR_GREEN);

				return m_staticBrush_Red;
			}

			return hbr;
		}
		else if (pWnd->GetDlgCtrlID() == m_stt_work_second.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(TEXT_COLOR_GREEN);

				return m_staticBrush;
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(TEXT_COLOR_GREEN);

				return m_staticBrush_Green;
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(TEXT_COLOR_GREEN);

				return m_staticBrush_Yellow;
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(TEXT_COLOR_GREEN);

				return m_staticBrush_Red;
			}

			return hbr;
		}
		else if (pWnd->GetDlgCtrlID() == m_stt_rest_hour.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(TEXT_COLOR_YELLOW);

				return m_staticBrush;
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(TEXT_COLOR_YELLOW);

				return m_staticBrush_Green;
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(TEXT_COLOR_YELLOW);

				return m_staticBrush_Yellow;
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(TEXT_COLOR_YELLOW);

				return m_staticBrush_Red;
			}

			return hbr;
		}
		else if (pWnd->GetDlgCtrlID() == m_stt_rest_minute.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(TEXT_COLOR_YELLOW);

				return m_staticBrush;
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(TEXT_COLOR_YELLOW);

				return m_staticBrush_Green;
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(TEXT_COLOR_YELLOW);

				return m_staticBrush_Yellow;
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(TEXT_COLOR_YELLOW);

				return m_staticBrush_Red;
			}

			return hbr;
		}
		else if (pWnd->GetDlgCtrlID() == m_stt_rest_second.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(TEXT_COLOR_YELLOW);

				return m_staticBrush;
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(TEXT_COLOR_YELLOW);

				return m_staticBrush_Green;
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(TEXT_COLOR_YELLOW);

				return m_staticBrush_Yellow;
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(TEXT_COLOR_YELLOW);

				return m_staticBrush_Red;
			}

			return hbr;
		}
		else if (pWnd->GetDlgCtrlID() == m_stt_refresh_hour.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(TEXT_COLOR_RED);

				return m_staticBrush;
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(TEXT_COLOR_RED);

				return m_staticBrush_Green;
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(TEXT_COLOR_RED);

				return m_staticBrush_Yellow;
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(TEXT_COLOR_RED);

				return m_staticBrush_Red;
			}

			return hbr;
		}
		else if (pWnd->GetDlgCtrlID() == m_stt_refresh_minute.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(TEXT_COLOR_RED);

				return m_staticBrush;
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(TEXT_COLOR_RED);

				return m_staticBrush_Green;
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(TEXT_COLOR_RED);

				return m_staticBrush_Yellow;
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(TEXT_COLOR_RED);

				return m_staticBrush_Red;
			}

			return hbr;
		}
		else if (pWnd->GetDlgCtrlID() == m_stt_refresh_second.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(TEXT_COLOR_RED);

				return m_staticBrush;
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(TEXT_COLOR_RED);

				return m_staticBrush_Green;
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(TEXT_COLOR_RED);

				return m_staticBrush_Yellow;
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(TEXT_COLOR_RED);

				return m_staticBrush_Red;
			}

			return hbr;
		}
		else if (pWnd->GetDlgCtrlID() == m_radio_infinite_repeat.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(DI_TEXT_COLOR_WHITE);
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);
			}

			return (HBRUSH)GetStockObject(NULL_BRUSH);
		}
		else if (pWnd->GetDlgCtrlID() == m_radio_custom_setting.GetDlgCtrlID())
		{
			if (m_state == TMS_NONE)
			{
				pDC->SetBkColor(DI_BK_COLOR);
				pDC->SetTextColor(DI_TEXT_COLOR_WHITE);
			}
			else if (m_state == TMS_WORKING)
			{
				pDC->SetBkColor(DI_BK_COLOR_GREEN);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);
			}
			else if (m_state == TMS_RESTING)
			{
				pDC->SetBkColor(DI_BK_COLOR_YELLOW);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);
			}
			else if (m_state == TMS_REFRESHING)
			{
				pDC->SetBkColor(DI_BK_COLOR_RED);
				pDC->SetTextColor(DI_TEXT_COLOR_BLACK);
			}

			return (HBRUSH)GetStockObject(NULL_BRUSH);
		}
	}

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


void CBOKODoroTimerDlg::OnBnClickedRadioInfinite()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//m_edit_work_rest_repeat_set.EnableWindow(FALSE);
	//m_edit_all_repeat_set.EnableWindow(FALSE);
}


void CBOKODoroTimerDlg::OnBnClickedRadioCustom()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//m_edit_work_rest_repeat_set.EnableWindow(TRUE);
	//m_edit_all_repeat_set.EnableWindow(TRUE);
}

void CBOKODoroTimerDlg::OnEnChangeEditWorkHour1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_work_hour1.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	SaveProcessTimer();
	Log_Manager->OnPutLog("업무 시간 Hour 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnEnChangeEditWorkHour2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_work_hour2.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	SaveProcessTimer();
	Log_Manager->OnPutLog("업무 시간 Hour 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnEnChangeEditWorkMinute1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_work_minute1.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	int leftMinute = ComplexConvert::StringToInt(strText.GetBuffer());
	if (leftMinute >= 6)
	{
		m_edit_work_minute1.SetWindowTextA("");
		return;
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("업무 시간 Minute 변경 완료", LogType::LT_EVENT);
}



void CBOKODoroTimerDlg::OnEnChangeEditWorkMinute2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_work_minute2.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	SaveProcessTimer();
	Log_Manager->OnPutLog("업무 시간 Minute 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnEnChangeEditWorkSecond1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_work_second1.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	int leftSecond = ComplexConvert::StringToInt(strText.GetBuffer());
	if (leftSecond >= 6)
	{
		m_edit_work_second1.SetWindowTextA("");
		return;
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("업무 시간 Second 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnEnChangeEditWorkSecond2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_work_second2.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	SaveProcessTimer();
	Log_Manager->OnPutLog("업무 시간 Second 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnEnChangeEditRestHour1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_rest_hour1.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	SaveProcessTimer();
	Log_Manager->OnPutLog("휴식 시간 Hour 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnEnChangeEditRestHour2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_rest_hour2.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	SaveProcessTimer();
	Log_Manager->OnPutLog("휴식 시간 Hour 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnEnChangeEditRestMinute1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_rest_minute1.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	int leftMinute = ComplexConvert::StringToInt(strText.GetBuffer());
	if (leftMinute >= 6)
	{
		m_edit_rest_minute1.SetWindowTextA("");
		return;
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("휴식 시간 Minute 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnEnChangeEditRestMinute2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_rest_minute2.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	SaveProcessTimer();
	Log_Manager->OnPutLog("휴식 시간 Minute 변경 완료", LogType::LT_EVENT);
}



void CBOKODoroTimerDlg::OnEnChangeEditRestSecond1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_rest_second1.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	int leftSecond = ComplexConvert::StringToInt(strText.GetBuffer());
	if (leftSecond >= 6)
	{
		m_edit_rest_second1.SetWindowTextA("");
		return;
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("휴식 시간 Second 변경 완료", LogType::LT_EVENT);
}

void CBOKODoroTimerDlg::OnEnChangeEditRestSecond2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_rest_second1.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	SaveProcessTimer();
	Log_Manager->OnPutLog("휴식 시간 Second 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnEnChangeEditRefreshHour1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_refresh_hour1.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	SaveProcessTimer();
	Log_Manager->OnPutLog("쉬는 시간 Hour 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnEnChangeEditRefreshHour2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_refresh_hour2.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	SaveProcessTimer();
	Log_Manager->OnPutLog("쉬는 시간 Hour 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnEnChangeEditRefreshMinute1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_refresh_minute1.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	int leftMinute = ComplexConvert::StringToInt(strText.GetBuffer());
	if (leftMinute >= 6)
	{
		m_edit_refresh_minute1.SetWindowTextA("");
		return;
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("쉬는 시간 Minute 변경 완료", LogType::LT_EVENT);
}

void CBOKODoroTimerDlg::OnEnChangeEditRefreshMinute2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_refresh_minute2.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	SaveProcessTimer();
	Log_Manager->OnPutLog("쉬는 시간 Minute 변경 완료", LogType::LT_EVENT);
}

void CBOKODoroTimerDlg::OnEnChangeEditRefreshSecond1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	CString strText;
	m_edit_refresh_second1.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	int leftSecond = ComplexConvert::StringToInt(strText.GetBuffer());
	if (leftSecond >= 6)
	{
		m_edit_refresh_second1.SetWindowTextA("");
		return;
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("쉬는 시간 Second 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnEnChangeEditRefreshSecond2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_refresh_second2.GetWindowTextA(strText);

	if (strText.IsEmpty())
		return;

	SaveProcessTimer();
	Log_Manager->OnPutLog("쉬는 시간 Second 변경 완료", LogType::LT_EVENT);
}



void CBOKODoroTimerDlg::OnBnClickedMfcbuttonWorkHourUp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_work_hour1.GetWindowTextA(strLeftText);
	m_edit_work_hour2.GetWindowTextA(strRightText);
	int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightHour < 9)
	{
		nRightHour++;

		ComplexString strRightHour = ComplexConvert::IntToString(nRightHour);
		m_edit_work_hour2.SetWindowTextA(strRightHour.GetBuffer());
	}
	else if (nRightHour >= 9 && nLeftHour < 9)
	{
		nLeftHour++;

		ComplexString strLeftHour = ComplexConvert::IntToString(nLeftHour);
		m_edit_work_hour1.SetWindowTextA(strLeftHour.GetBuffer());
		m_edit_work_hour2.SetWindowTextA("0");
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("업무 시간 Hour 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonWorkHourDown()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_work_hour1.GetWindowTextA(strLeftText);
	m_edit_work_hour2.GetWindowTextA(strRightText);
	int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightHour > 0)
	{
		nRightHour--;

		ComplexString strRightHour = ComplexConvert::IntToString(nRightHour);
		m_edit_work_hour2.SetWindowTextA(strRightHour.GetBuffer());
	}
	else if (nRightHour <= 0 && nLeftHour > 0)
	{
		nLeftHour--;

		ComplexString strLeftHour = ComplexConvert::IntToString(nLeftHour);
		m_edit_work_hour1.SetWindowTextA(strLeftHour.GetBuffer());
		m_edit_work_hour2.SetWindowTextA("9");
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("업무 시간 Hour 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonWorkMinuteUp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_work_minute1.GetWindowTextA(strLeftText);
	m_edit_work_minute2.GetWindowTextA(strRightText);
	int nLeftMinute = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightMinute = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightMinute < 9)
	{
		nRightMinute++;

		ComplexString strRightMinute = ComplexConvert::IntToString(nRightMinute);
		m_edit_work_minute2.SetWindowTextA(strRightMinute.GetBuffer());
	}
	else if (nRightMinute >= 9 && nLeftMinute < 5)
	{
		nLeftMinute++;

		ComplexString strLeftMinute = ComplexConvert::IntToString(nLeftMinute);
		m_edit_work_minute1.SetWindowTextA(strLeftMinute.GetBuffer());
		m_edit_work_minute2.SetWindowTextA("0");
	}
	else if (nRightMinute >= 9 && nLeftMinute >= 5)
	{
		m_edit_work_hour1.GetWindowTextA(strLeftText);
		m_edit_work_hour2.GetWindowTextA(strRightText);
		int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
		int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());

		if (nLeftHour == 9 && nRightHour == 9)
		{
			// nothing
		}
		else
		{
			m_edit_work_minute1.SetWindowTextA("0");
			m_edit_work_minute2.SetWindowTextA("0");
			OnBnClickedMfcbuttonWorkHourUp();
		}
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("업무 시간 Minute 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonWorkMinuteDown()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_work_minute1.GetWindowTextA(strLeftText);
	m_edit_work_minute2.GetWindowTextA(strRightText);
	int nLeftMinute = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightMinute = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightMinute > 0)
	{
		nRightMinute--;

		ComplexString strRightMinute = ComplexConvert::IntToString(nRightMinute);
		m_edit_work_minute2.SetWindowTextA(strRightMinute.GetBuffer());
	}
	else if (nRightMinute <= 0 && nLeftMinute > 0)
	{
		nLeftMinute--;

		ComplexString strLeftMinute = ComplexConvert::IntToString(nLeftMinute);
		m_edit_work_minute1.SetWindowTextA(strLeftMinute.GetBuffer());
		m_edit_work_minute2.SetWindowTextA("9");
	}
	else if (nRightMinute <= 0 && nLeftMinute <= 0)
	{
		m_edit_work_hour1.GetWindowTextA(strLeftText);
		m_edit_work_hour2.GetWindowTextA(strRightText);
		int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
		int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());

		if (nLeftHour == 0 && nRightHour == 0)
		{
			// nothing
		}
		else
		{
			m_edit_work_minute1.SetWindowTextA("5");
			m_edit_work_minute2.SetWindowTextA("9");

			OnBnClickedMfcbuttonWorkHourDown();
		}
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("업무 시간 Minute 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonWorkSecondUp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_work_second1.GetWindowTextA(strLeftText);
	m_edit_work_second2.GetWindowTextA(strRightText);
	int nLeftMinute = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightMinute = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightMinute < 9)
	{
		nRightMinute++;

		ComplexString strRightMinute = ComplexConvert::IntToString(nRightMinute);
		m_edit_work_second2.SetWindowTextA(strRightMinute.GetBuffer());
	}
	else if (nRightMinute >= 9 && nLeftMinute < 5)
	{
		nLeftMinute++;

		ComplexString strLeftMinute = ComplexConvert::IntToString(nLeftMinute);
		m_edit_work_second1.SetWindowTextA(strLeftMinute.GetBuffer());
		m_edit_work_second2.SetWindowTextA("0");
	}
	else if (nRightMinute >= 9 && nLeftMinute >= 5)
	{
		CString strLeftText1, strRightText1;
		m_edit_work_hour1.GetWindowTextA(strLeftText);
		m_edit_work_hour2.GetWindowTextA(strRightText);
		m_edit_work_minute1.GetWindowTextA(strLeftText1);
		m_edit_work_minute2.GetWindowTextA(strRightText1);
		int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
		int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());
		int nLeftMinute = ComplexConvert::StringToInt(strLeftText1.GetBuffer());
		int nRightMinute = ComplexConvert::StringToInt(strRightText1.GetBuffer());

		if (nLeftMinute == 5 && nRightMinute == 9 && nLeftHour == 9 && nRightHour == 9)
		{
			// nothing
		}
		else
		{
			m_edit_work_second1.SetWindowTextA("0");
			m_edit_work_second2.SetWindowTextA("0");

			OnBnClickedMfcbuttonWorkMinuteUp();
		}
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("업무 시간 Second 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonWorkSecondDown()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_work_second1.GetWindowTextA(strLeftText);
	m_edit_work_second2.GetWindowTextA(strRightText);
	int nLeftMinute = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightMinute = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightMinute > 0)
	{
		nRightMinute--;

		ComplexString strRightMinute = ComplexConvert::IntToString(nRightMinute);
		m_edit_work_second2.SetWindowTextA(strRightMinute.GetBuffer());
	}
	else if (nRightMinute <= 0 && nLeftMinute > 0)
	{
		nLeftMinute--;

		ComplexString strLeftMinute = ComplexConvert::IntToString(nLeftMinute);
		m_edit_work_second1.SetWindowTextA(strLeftMinute.GetBuffer());
		m_edit_work_second2.SetWindowTextA("9");
	}
	else if (nRightMinute <= 0 && nLeftMinute <= 0)
	{
		CString strLeftText1, strRightText1;
		m_edit_work_hour1.GetWindowTextA(strLeftText);
		m_edit_work_hour2.GetWindowTextA(strRightText);
		m_edit_work_minute1.GetWindowTextA(strLeftText1);
		m_edit_work_minute2.GetWindowTextA(strRightText1);
		int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
		int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());
		int nLeftMinute = ComplexConvert::StringToInt(strLeftText1.GetBuffer());
		int nRightMinute = ComplexConvert::StringToInt(strRightText1.GetBuffer());

		if (nLeftMinute == 0 && nRightMinute == 0 && nLeftHour == 0 && nRightHour == 0)
		{
			// nothing
		}
		else
		{
			m_edit_work_second1.SetWindowTextA("5");
			m_edit_work_second2.SetWindowTextA("9");

			OnBnClickedMfcbuttonWorkMinuteDown();
		}
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("업무 시간 Second 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonRestHourUp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_rest_hour1.GetWindowTextA(strLeftText);
	m_edit_rest_hour2.GetWindowTextA(strRightText);
	int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightHour < 9)
	{
		nRightHour++;

		ComplexString strRightHour = ComplexConvert::IntToString(nRightHour);
		m_edit_rest_hour2.SetWindowTextA(strRightHour.GetBuffer());
	}
	else if (nRightHour >= 9 && nLeftHour < 9)
	{
		nLeftHour++;

		ComplexString strLeftHour = ComplexConvert::IntToString(nLeftHour);
		m_edit_rest_hour1.SetWindowTextA(strLeftHour.GetBuffer());
		m_edit_rest_hour2.SetWindowTextA("0");
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("휴식 시간 Hour 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonRestHourDown()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_rest_hour1.GetWindowTextA(strLeftText);
	m_edit_rest_hour2.GetWindowTextA(strRightText);
	int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightHour > 0)
	{
		nRightHour--;

		ComplexString strRightHour = ComplexConvert::IntToString(nRightHour);
		m_edit_rest_hour2.SetWindowTextA(strRightHour.GetBuffer());
	}
	else if (nRightHour <= 0 && nLeftHour > 0)
	{
		nLeftHour--;

		ComplexString strLeftHour = ComplexConvert::IntToString(nLeftHour);
		m_edit_rest_hour1.SetWindowTextA(strLeftHour.GetBuffer());
		m_edit_rest_hour2.SetWindowTextA("9");
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("휴식 시간 Hour 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonRestMinuteUp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_rest_minute1.GetWindowTextA(strLeftText);
	m_edit_rest_minute2.GetWindowTextA(strRightText);
	int nLeftMinute = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightMinute = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightMinute < 9)
	{
		nRightMinute++;

		ComplexString strRightMinute = ComplexConvert::IntToString(nRightMinute);
		m_edit_rest_minute2.SetWindowTextA(strRightMinute.GetBuffer());
	}
	else if (nRightMinute >= 9 && nLeftMinute < 5)
	{
		nLeftMinute++;

		ComplexString strLeftMinute = ComplexConvert::IntToString(nLeftMinute);
		m_edit_rest_minute1.SetWindowTextA(strLeftMinute.GetBuffer());
		m_edit_rest_minute2.SetWindowTextA("0");
	}
	else if (nRightMinute >= 9 && nLeftMinute >= 5)
	{
		m_edit_rest_hour1.GetWindowTextA(strLeftText);
		m_edit_rest_hour2.GetWindowTextA(strRightText);
		int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
		int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());

		if (nLeftHour == 9 && nRightHour == 9)
		{
			// nothing
		}
		else
		{
			m_edit_rest_minute1.SetWindowTextA("0");
			m_edit_rest_minute2.SetWindowTextA("0");
			OnBnClickedMfcbuttonRestHourUp();
		}
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("휴식 시간 Minute 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonRestMinuteDown()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_rest_minute1.GetWindowTextA(strLeftText);
	m_edit_rest_minute2.GetWindowTextA(strRightText);
	int nLeftMinute = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightMinute = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightMinute > 0)
	{
		nRightMinute--;

		ComplexString strRightMinute = ComplexConvert::IntToString(nRightMinute);
		m_edit_rest_minute2.SetWindowTextA(strRightMinute.GetBuffer());
	}
	else if (nRightMinute <= 0 && nLeftMinute > 0)
	{
		nLeftMinute--;

		ComplexString strLeftMinute = ComplexConvert::IntToString(nLeftMinute);
		m_edit_rest_minute1.SetWindowTextA(strLeftMinute.GetBuffer());
		m_edit_rest_minute2.SetWindowTextA("9");
	}
	else if (nRightMinute <= 0 && nLeftMinute <= 0)
	{
		m_edit_rest_hour1.GetWindowTextA(strLeftText);
		m_edit_rest_hour2.GetWindowTextA(strRightText);
		int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
		int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());

		if (nLeftHour == 0 && nRightHour == 0)
		{
			// nothing
		}
		else
		{
			m_edit_rest_minute1.SetWindowTextA("5");
			m_edit_rest_minute2.SetWindowTextA("9");

			OnBnClickedMfcbuttonRestHourDown();
		}
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("휴식 시간 Minute 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonRestSecondUp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_rest_second1.GetWindowTextA(strLeftText);
	m_edit_rest_second2.GetWindowTextA(strRightText);
	int nLeftMinute = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightMinute = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightMinute < 9)
	{
		nRightMinute++;

		ComplexString strRightMinute = ComplexConvert::IntToString(nRightMinute);
		m_edit_rest_second2.SetWindowTextA(strRightMinute.GetBuffer());
	}
	else if (nRightMinute >= 9 && nLeftMinute < 5)
	{
		nLeftMinute++;

		ComplexString strLeftMinute = ComplexConvert::IntToString(nLeftMinute);
		m_edit_rest_second1.SetWindowTextA(strLeftMinute.GetBuffer());
		m_edit_rest_second2.SetWindowTextA("0");
	}
	else if (nRightMinute >= 9 && nLeftMinute >= 5)
	{
		CString strLeftText1, strRightText1;
		m_edit_rest_hour1.GetWindowTextA(strLeftText);
		m_edit_rest_hour2.GetWindowTextA(strRightText);
		m_edit_rest_minute1.GetWindowTextA(strLeftText1);
		m_edit_rest_minute2.GetWindowTextA(strRightText1);
		int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
		int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());
		int nLeftMinute = ComplexConvert::StringToInt(strLeftText1.GetBuffer());
		int nRightMinute = ComplexConvert::StringToInt(strRightText1.GetBuffer());

		if (nLeftMinute == 5 && nRightMinute == 9 && nLeftHour == 9 && nRightHour == 9)
		{
			// nothing
		}
		else
		{
			m_edit_rest_second1.SetWindowTextA("0");
			m_edit_rest_second2.SetWindowTextA("0");

			OnBnClickedMfcbuttonRestMinuteUp();
		}
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("휴식 시간 Second 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonRestSecondDown()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_rest_second1.GetWindowTextA(strLeftText);
	m_edit_rest_second2.GetWindowTextA(strRightText);
	int nLeftMinute = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightMinute = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightMinute > 0)
	{
		nRightMinute--;

		ComplexString strRightMinute = ComplexConvert::IntToString(nRightMinute);
		m_edit_rest_second2.SetWindowTextA(strRightMinute.GetBuffer());
	}
	else if (nRightMinute <= 0 && nLeftMinute > 0)
	{
		nLeftMinute--;

		ComplexString strLeftMinute = ComplexConvert::IntToString(nLeftMinute);
		m_edit_rest_second1.SetWindowTextA(strLeftMinute.GetBuffer());
		m_edit_rest_second2.SetWindowTextA("9");
	}
	else if (nRightMinute <= 0 && nLeftMinute <= 0)
	{
		CString strLeftText1, strRightText1;
		m_edit_rest_hour1.GetWindowTextA(strLeftText);
		m_edit_rest_hour2.GetWindowTextA(strRightText);
		m_edit_rest_minute1.GetWindowTextA(strLeftText1);
		m_edit_rest_minute2.GetWindowTextA(strRightText1);
		int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
		int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());
		int nLeftMinute = ComplexConvert::StringToInt(strLeftText1.GetBuffer());
		int nRightMinute = ComplexConvert::StringToInt(strRightText1.GetBuffer());

		if (nLeftMinute == 0 && nRightMinute == 0 && nLeftHour == 0 && nRightHour == 0)
		{
			// nothing
		}
		else
		{
			m_edit_rest_second1.SetWindowTextA("5");
			m_edit_rest_second2.SetWindowTextA("9");

			OnBnClickedMfcbuttonRestMinuteDown();
		}
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("휴식 시간 Second 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonRefreshHourUp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_refresh_hour1.GetWindowTextA(strLeftText);
	m_edit_refresh_hour2.GetWindowTextA(strRightText);
	int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightHour < 9)
	{
		nRightHour++;

		ComplexString strRightHour = ComplexConvert::IntToString(nRightHour);
		m_edit_refresh_hour2.SetWindowTextA(strRightHour.GetBuffer());
	}
	else if (nRightHour >= 9 && nLeftHour < 9)
	{
		nLeftHour++;

		ComplexString strLeftHour = ComplexConvert::IntToString(nLeftHour);
		m_edit_refresh_hour1.SetWindowTextA(strLeftHour.GetBuffer());
		m_edit_refresh_hour2.SetWindowTextA("0");
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("쉬는 시간 Hour 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonRefreshHourDown()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_refresh_hour1.GetWindowTextA(strLeftText);
	m_edit_refresh_hour2.GetWindowTextA(strRightText);
	int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightHour > 0)
	{
		nRightHour--;

		ComplexString strRightHour = ComplexConvert::IntToString(nRightHour);
		m_edit_refresh_hour2.SetWindowTextA(strRightHour.GetBuffer());
	}
	else if (nRightHour <= 0 && nLeftHour > 0)
	{
		nLeftHour--;

		ComplexString strLeftHour = ComplexConvert::IntToString(nLeftHour);
		m_edit_refresh_hour1.SetWindowTextA(strLeftHour.GetBuffer());
		m_edit_refresh_hour2.SetWindowTextA("9");
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("쉬는 시간 Hour 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonRefreshMinuteUp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_refresh_minute1.GetWindowTextA(strLeftText);
	m_edit_refresh_minute2.GetWindowTextA(strRightText);
	int nLeftMinute = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightMinute = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightMinute < 9)
	{
		nRightMinute++;

		ComplexString strRightMinute = ComplexConvert::IntToString(nRightMinute);
		m_edit_refresh_minute2.SetWindowTextA(strRightMinute.GetBuffer());
	}
	else if (nRightMinute >= 9 && nLeftMinute < 5)
	{
		nLeftMinute++;

		ComplexString strLeftMinute = ComplexConvert::IntToString(nLeftMinute);
		m_edit_refresh_minute1.SetWindowTextA(strLeftMinute.GetBuffer());
		m_edit_refresh_minute2.SetWindowTextA("0");
	}
	else if (nRightMinute >= 9 && nLeftMinute >= 5)
	{
		m_edit_refresh_hour1.GetWindowTextA(strLeftText);
		m_edit_refresh_hour2.GetWindowTextA(strRightText);
		int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
		int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());

		if (nLeftHour == 9 && nRightHour == 9)
		{
			// nothing
		}
		else
		{
			m_edit_refresh_minute1.SetWindowTextA("0");
			m_edit_refresh_minute2.SetWindowTextA("0");

			OnBnClickedMfcbuttonRefreshHourUp();
		}
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("쉬는 시간 Minute 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonRefreshMinuteDown()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_refresh_minute1.GetWindowTextA(strLeftText);
	m_edit_refresh_minute2.GetWindowTextA(strRightText);
	int nLeftMinute = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightMinute = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightMinute > 0)
	{
		nRightMinute--;

		ComplexString strRightMinute = ComplexConvert::IntToString(nRightMinute);
		m_edit_refresh_minute2.SetWindowTextA(strRightMinute.GetBuffer());
	}
	else if (nRightMinute <= 0 && nLeftMinute > 0)
	{
		nLeftMinute--;

		ComplexString strLeftMinute = ComplexConvert::IntToString(nLeftMinute);
		m_edit_refresh_minute1.SetWindowTextA(strLeftMinute.GetBuffer());
		m_edit_refresh_minute2.SetWindowTextA("9");
	}
	else if (nRightMinute <= 0 && nLeftMinute <= 0)
	{
		m_edit_refresh_hour1.GetWindowTextA(strLeftText);
		m_edit_refresh_hour2.GetWindowTextA(strRightText);
		int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
		int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());

		if (nLeftHour == 0 && nRightHour == 0)
		{
			// nothing
		}
		else
		{
			m_edit_refresh_minute1.SetWindowTextA("5");
			m_edit_refresh_minute2.SetWindowTextA("9");

			OnBnClickedMfcbuttonRefreshHourDown();
		}
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("쉬는 시간 Minute 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonRefreshSecondUp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_refresh_second1.GetWindowTextA(strLeftText);
	m_edit_refresh_second2.GetWindowTextA(strRightText);
	int nLeftMinute = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightMinute = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightMinute < 9)
	{
		nRightMinute++;

		ComplexString strRightMinute = ComplexConvert::IntToString(nRightMinute);
		m_edit_refresh_second2.SetWindowTextA(strRightMinute.GetBuffer());
	}
	else if (nRightMinute >= 9 && nLeftMinute < 5)
	{
		nLeftMinute++;

		ComplexString strLeftMinute = ComplexConvert::IntToString(nLeftMinute);
		m_edit_refresh_second1.SetWindowTextA(strLeftMinute.GetBuffer());
		m_edit_refresh_second2.SetWindowTextA("0");
	}
	else if (nRightMinute >= 9 && nLeftMinute >= 5)
	{
		CString strLeftText1, strRightText1;
		m_edit_refresh_hour1.GetWindowTextA(strLeftText);
		m_edit_refresh_hour2.GetWindowTextA(strRightText);
		m_edit_refresh_minute1.GetWindowTextA(strLeftText1);
		m_edit_refresh_minute2.GetWindowTextA(strRightText1);
		int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
		int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());
		int nLeftMinute = ComplexConvert::StringToInt(strLeftText1.GetBuffer());
		int nRightMinute = ComplexConvert::StringToInt(strRightText1.GetBuffer());

		if (nLeftMinute == 5 && nRightMinute == 9 && nLeftHour == 9 && nRightHour == 9)
		{
			// nothing
		}
		else
		{
			m_edit_refresh_second1.SetWindowTextA("0");
			m_edit_refresh_second2.SetWindowTextA("0");

			OnBnClickedMfcbuttonRefreshMinuteUp();
		}
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("쉬는 시간 Second 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonRefreshSecondDown()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strLeftText, strRightText;
	m_edit_refresh_second1.GetWindowTextA(strLeftText);
	m_edit_refresh_second2.GetWindowTextA(strRightText);
	int nLeftMinute = ComplexConvert::StringToInt(strLeftText.GetBuffer());
	int nRightMinute = ComplexConvert::StringToInt(strRightText.GetBuffer());

	if (nRightMinute > 0)
	{
		nRightMinute--;

		ComplexString strRightMinute = ComplexConvert::IntToString(nRightMinute);
		m_edit_refresh_second2.SetWindowTextA(strRightMinute.GetBuffer());
	}
	else if (nRightMinute <= 0 && nLeftMinute > 0)
	{
		nLeftMinute--;

		ComplexString strLeftMinute = ComplexConvert::IntToString(nLeftMinute);
		m_edit_refresh_second1.SetWindowTextA(strLeftMinute.GetBuffer());
		m_edit_refresh_second2.SetWindowTextA("9");
	}
	else if (nRightMinute <= 0 && nLeftMinute <= 0)
	{
		CString strLeftText1, strRightText1;
		m_edit_refresh_hour1.GetWindowTextA(strLeftText);
		m_edit_refresh_hour2.GetWindowTextA(strRightText);
		m_edit_refresh_minute1.GetWindowTextA(strLeftText1);
		m_edit_refresh_minute2.GetWindowTextA(strRightText1);
		int nLeftHour = ComplexConvert::StringToInt(strLeftText.GetBuffer());
		int nRightHour = ComplexConvert::StringToInt(strRightText.GetBuffer());
		int nLeftMinute = ComplexConvert::StringToInt(strLeftText1.GetBuffer());
		int nRightMinute = ComplexConvert::StringToInt(strRightText1.GetBuffer());

		if (nLeftMinute == 0 && nRightMinute == 0 && nLeftHour == 0 && nRightHour == 0)
		{
			// nothing
		}
		else
		{
			m_edit_refresh_second1.SetWindowTextA("5");
			m_edit_refresh_second2.SetWindowTextA("9");

			OnBnClickedMfcbuttonRefreshMinuteDown();
		}
	}

	SaveProcessTimer();
	Log_Manager->OnPutLog("쉬는 시간 Second 변경 완료", LogType::LT_EVENT);
}

void CBOKODoroTimerDlg::OnEnChangeEditWorkRestRepeatSet()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_work_rest_repeat_set.GetWindowTextA(strText);

	if (strText.IsEmpty())
	{
		return;
	}

	int wrREPEAT = ComplexConvert::StringToInt(strText.GetBuffer());

	if (wrREPEAT < 1)
	{
		m_edit_work_rest_repeat_set.SetWindowTextA(ComplexConvert::IntToString(m_processTimer.GetWrREPEAT()).GetBuffer());
		return;
	}

	m_processTimer.SetWrREPEAT(wrREPEAT);
	Log_Manager->OnPutLog("업무 휴식 반복 횟수 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnEnChangeEditAllRepeatSet()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// __super::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strText;
	m_edit_all_repeat_set.GetWindowTextA(strText);

	if (strText.IsEmpty())
	{
		return;
	}

	int allREPEAT = ComplexConvert::StringToInt(strText.GetBuffer());

	if (allREPEAT < 0)
	{
		m_edit_all_repeat_set.SetWindowTextA(ComplexConvert::IntToString(m_processTimer.GetAllREPEAT()).GetBuffer());
		return;
	}

	m_processTimer.SetAllREPEAT(allREPEAT);
	Log_Manager->OnPutLog("전체 반복 횟수 변경 완료", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_startState == TSS_STOP)
	{
		m_startTimer = m_processTimer;
		m_startState = TSS_START;
		m_btn_start.SetWindowTextA(START_STATE_BTN_TEXT_PAUSE);
		SetTimer(NULL, 1000, NULL);
		Log_Manager->OnPutLog("타이머 시작", LogType::LT_EVENT);
	}
	else if (m_startState == TSS_START)
	{
		m_startState = TSS_PAUSE;
		m_btn_start.SetWindowTextA(START_STATE_BTN_TEXT_START);
		KillTimer(NULL);
		Log_Manager->OnPutLog("타이머 일시 정지", LogType::LT_EVENT);
	}
	else if (m_startState == TSS_PAUSE)
	{
		m_startState = TSS_START;
		m_btn_start.SetWindowTextA(START_STATE_BTN_TEXT_PAUSE);
		SetTimer(NULL, 1000, NULL);
		Log_Manager->OnPutLog("타이머 재 시작", LogType::LT_EVENT);
	}
	StartWithEnableUI(FALSE);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonStop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	KillTimer(NULL);
	m_startState = TSS_STOP;
	m_state = TMS_NONE;
	m_btn_start.SetWindowTextA(START_STATE_BTN_TEXT_START);
	StartWithEnableUI(TRUE);

	m_processTimer = m_startTimer;
	LoadProcessTimer();

	SignalUpdateTimerUI();
	Invalidate();

	Log_Manager->OnPutLog("타이머 정지", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ResetTimer();

	Log_Manager->OnPutLog("타이머 초기화", LogType::LT_EVENT);
}


void CBOKODoroTimerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (m_state == TMS_NONE)
	{
		m_state = TMS_WORKING;
	}

	if (m_state == TMS_WORKING)
	{
		OnBnClickedMfcbuttonWorkSecondDown();

		int wkHOUR = m_processTimer.GetWkHOUR();
		int wkMINUTE = m_processTimer.GetWkMINUTE();
		int wkSECOND = m_processTimer.GetWkSECOND();

		// work의 시간이 종료되었을 경우
		if (wkHOUR == 0 && wkMINUTE == 0 && wkSECOND == 0)
		{
			// work_rest 카운트개수와 모든카운트개수가 마지막 카운트일 경우는 바로 종료.
			if (m_processTimer.GetWrREPEAT() <= 1 && m_processTimer.GetAllREPEAT() <= 0)
			{
				OnBnClickedMfcbuttonStop();
			}
			// work_rest 카운트개수가 마지막 카운트이고 모든카운트개수가 남아있을 경우는 refresh로 이동.
			else if (m_processTimer.GetWrREPEAT() <= 1 && m_processTimer.GetAllREPEAT() > 0)
			{
				m_state = TMS_REFRESHING;

				m_processTimer.SetWkHOUR(m_startTimer.GetWkHOUR());
				m_processTimer.SetWkMINUTE(m_startTimer.GetWkMINUTE());
				m_processTimer.SetWkSECOND(m_startTimer.GetWkSECOND());
				ResetWorkTimeUI();
				Log_Manager->OnPutLog("업무 시간 종료. 쉬는 시간 시작", LogType::LT_EVENT);
			}
			// work_rest 카운트개수가 많이 남아있으면 rest로 이동.
			else if (m_processTimer.GetWrREPEAT() > 1)
			{
				m_state = TMS_RESTING;

				m_processTimer.SetWkHOUR(m_startTimer.GetWkHOUR());
				m_processTimer.SetWkMINUTE(m_startTimer.GetWkMINUTE());
				m_processTimer.SetWkSECOND(m_startTimer.GetWkSECOND());
				ResetWorkTimeUI();
				Log_Manager->OnPutLog("업무 시간 종료. 휴식 시간 시작", LogType::LT_EVENT);
			}
		}
	}
	else if (m_state == TMS_RESTING)
	{
		OnBnClickedMfcbuttonRestSecondDown();

		int rsHOUR = m_processTimer.GetRsHOUR();
		int rsMINUTE = m_processTimer.GetRsMINUTE();
		int rsSECOND = m_processTimer.GetRsSECOND();

		// rest의 시간이 종료되었을 경우
		if (rsHOUR == 0 && rsMINUTE == 0 && rsSECOND == 0)
		{
			// work_rest 카운트개수와 모든카운트개수가 마지막 카운트일 경우는 바로 종료.
			if (m_processTimer.GetWrREPEAT() <= 1 && m_processTimer.GetAllREPEAT() <= 0)
			{
				OnBnClickedMfcbuttonStop();
			}
			// work_rest 카운트개수가 마지막 카운트이고 모든카운트개수가 남아있을 경우는 refresh로 이동.
			else if (m_processTimer.GetWrREPEAT() <= 1 && m_processTimer.GetAllREPEAT() > 0)
			{
				m_state = TMS_REFRESHING;
				m_processTimer.SetWrREPEAT(m_processTimer.GetWrREPEAT() - 1);

				m_processTimer.SetRsHOUR(m_startTimer.GetRsHOUR());
				m_processTimer.SetRsMINUTE(m_startTimer.GetRsMINUTE());
				m_processTimer.SetRsSECOND(m_startTimer.GetRsSECOND());
				ResetRestTimeUI();
				Log_Manager->OnPutLog("휴식 시간 종료. 쉬는 시간 시작", LogType::LT_EVENT);
			}
			// work_rest 카운트개수가 많이 남아있으면 work로 이동하고 work_rest 카운트개수 1 감소.
			else if (m_processTimer.GetWrREPEAT() > 1)
			{
				m_state = TMS_WORKING;
				m_processTimer.SetWrREPEAT(m_processTimer.GetWrREPEAT() - 1);

				m_processTimer.SetRsHOUR(m_startTimer.GetRsHOUR());
				m_processTimer.SetRsMINUTE(m_startTimer.GetRsMINUTE());
				m_processTimer.SetRsSECOND(m_startTimer.GetRsSECOND());
				ResetRestTimeUI();
				Log_Manager->OnPutLog("휴식 시간 종료. 업무 시간 시작", LogType::LT_EVENT);
			}
		}
	}
	else if (m_state == TMS_REFRESHING)
	{
		OnBnClickedMfcbuttonRefreshSecondDown();

		int rfHOUR = m_processTimer.GetRfHOUR();
		int rfMINUTE = m_processTimer.GetRfMINUTE();
		int rfSECOND = m_processTimer.GetRfSECOND();

		// rest의 시간이 종료되었을 경우
		if (rfHOUR == 0 && rfMINUTE == 0 && rfSECOND == 0)
		{
			// 모든 반복 카운트개수가 남았을 경우 work로 이동하고 work_rest 카운트개수 초기화 및 모든카운트개수 1 감소.
			if (m_processTimer.GetAllREPEAT() > 0)
			{
				m_state = TMS_WORKING;
				m_processTimer.SetWrREPEAT(m_startTimer.GetWrREPEAT());
				m_processTimer.SetAllREPEAT(m_processTimer.GetAllREPEAT() - 1);

				m_processTimer.SetRfHOUR(m_startTimer.GetRfHOUR());
				m_processTimer.SetRfMINUTE(m_startTimer.GetRfMINUTE());
				m_processTimer.SetRfSECOND(m_startTimer.GetRfSECOND());
				ResetRefreshTimeUI();
				Log_Manager->OnPutLog("쉬는 시간 종료. 업무 시간 시작", LogType::LT_EVENT);
			}
			// 모든 반복 카운트개수가 마지막일 경우 종료.
			else if (m_processTimer.GetAllREPEAT() <= 0)
			{
				OnBnClickedMfcbuttonStop();
			}
		}
	}

	SignalUpdateTimerUI();
	Invalidate(FALSE);


	__super::OnTimer(nIDEvent);
}



BOOL CBOKODoroTimerDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//return __super::OnEraseBkgnd(pDC);
	return FALSE;
}


void CBOKODoroTimerDlg::OnBnClickedMfcbuttonExpandTimerList()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_pBOKODoroTimerListDlg->IsWindowVisible())
	{
		m_pBOKODoroTimerListDlg->ShowWindow(SW_HIDE);
	}
	else
	{
		CRect rect;
		GetWindowRect(rect);
		m_pBOKODoroTimerListDlg->SetWindowPos(NULL, rect.right + 2, rect.top, 0, 0, SWP_NOSIZE);
		m_pBOKODoroTimerListDlg->ShowWindow(SW_SHOW);
	}
}


void CBOKODoroTimerDlg::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	//__super::OnOK();
}
