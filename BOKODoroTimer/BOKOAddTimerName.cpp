// BOKOAddTimerName.cpp: 구현 파일
//

#include "pch.h"
#include "BOKODoroTimer.h"
#include "BOKOAddTimerName.h"
#include "afxdialogex.h"


// BOKOAddTimerName 대화 상자

IMPLEMENT_DYNAMIC(BOKOAddTimerName, CDialogEx)

BOKOAddTimerName::BOKOAddTimerName(ComplexString* timerNAME, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADD_TIMER_NAME, pParent)
	, DlgInterface(this, true)
{
	CreateFrame(FDT_SUB_DLG);
	this->m_timerNAME = timerNAME;
	Log_Manager->OnPutLog("BOKOAddTimerName 생성자 호출", LogType::LT_PROCESS);
}

BOKOAddTimerName::~BOKOAddTimerName()
{
	Log_Manager->OnPutLog("BOKOAddTimerName 소멸자 호출", LogType::LT_PROCESS);
}

void BOKOAddTimerName::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_TIMER_NAME, m_stt_timer_name);
	DDX_Control(pDX, IDC_EDIT_TIMER_NAME, m_edit_timer_name);
	DDX_Control(pDX, IDC_MFCBUTTON_SAVE_TIMER_NAME, m_btn_save);
	DDX_Control(pDX, IDC_MFCBUTTON_CANCEL_TIMER_NAME, m_btn_cancel);
}


BEGIN_MESSAGE_MAP(BOKOAddTimerName, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_MFCBUTTON_SAVE_TIMER_NAME, &BOKOAddTimerName::OnBnClickedMfcbuttonSaveTimerName)
	ON_BN_CLICKED(IDC_MFCBUTTON_CANCEL_TIMER_NAME, &BOKOAddTimerName::OnBnClickedMfcbuttonCancelTimerName)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// BOKOAddTimerName 메시지 처리기

void BOKOAddTimerName::Initialize()
{
	InitFrame("타이머 이름 작성");

	m_stt_timer_name.Initialize(FONT_SIZE_TIME_STATIC, FONT_NAME_TEXT);
	m_edit_timer_name.Initialize(FONT_SIZE_STATE_EDIT, FONT_NAME_TEXT);
	m_btn_save.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
	m_btn_cancel.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
}

BOOL BOKOAddTimerName::OnInitDialog()
{
	__super::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	Initialize();
	Log_Manager->OnPutLog("타이머 이름 작성 화면 초기화", LogType::LT_PROCESS);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL BOKOAddTimerName::PreTranslateMessage(MSG* pMsg)
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
	}

	return __super::PreTranslateMessage(pMsg);
}


HBRUSH BOKOAddTimerName::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = __super::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	HBRUSH returnHBR = CtlColors(pDC, pWnd, nCtlColor);
	if (returnHBR != NULL)
		return returnHBR;

	if (nCtlColor == CTLCOLOR_STATIC)
	{
		if (pWnd->GetDlgCtrlID() == m_stt_timer_name.GetDlgCtrlID())
		{
			pDC->SetBkColor(DI_LIGHT_COLOR);

			return m_staticLightBrush;
		}
	}

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


void BOKOAddTimerName::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	//__super::OnOK();
}


void BOKOAddTimerName::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 __super::OnPaint()을(를) 호출하지 마십시오.

	DrawFrame(&dc, 0);
}


void BOKOAddTimerName::OnSize(UINT nType, int cx, int cy)
{
	__super::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	Sizing(nType);
}


void BOKOAddTimerName::OnBnClickedMfcbuttonSaveTimerName()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strAddTimerName;
	m_edit_timer_name.GetWindowTextA(strAddTimerName);

	if (strAddTimerName.IsEmpty())
	{
		AfxMessageBox("공백은 입력 불가능 합니다.");
		Log_Manager->OnPutLog("타이머 이름 작성 공백 오류", LogType::LT_PROCESS);
	}
	else
	{
		*m_timerNAME = strAddTimerName.GetBuffer();
		Log_Manager->OnPutLog("타이머 이름 작성 완료", LogType::LT_PROCESS);
		__super::OnOK();
	}
}


void BOKOAddTimerName::OnBnClickedMfcbuttonCancelTimerName()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	this->SendMessageA(WM_CLOSE);
}


void BOKOAddTimerName::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	Log_Manager->OnPutLog("타이머 이름 작성 취소", LogType::LT_PROCESS);
	__super::OnClose();
}
