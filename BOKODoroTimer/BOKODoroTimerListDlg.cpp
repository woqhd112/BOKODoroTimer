// BOKODoroTimerListDlg.cpp: 구현 파일
//

#include "pch.h"
#include "BOKODoroTimer.h"
#include "BOKODoroTimerListDlg.h"
#include "afxdialogex.h"


// BOKODoroTimerListDlg 대화 상자

IMPLEMENT_DYNAMIC(BOKODoroTimerListDlg, CDialogEx)

BOKODoroTimerListDlg::BOKODoroTimerListDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_TIMER_LIST, pParent)
	, DlgInterface(this, true)
{
	CreateFrame(FDT_SUB_DLG);
}

BOKODoroTimerListDlg::~BOKODoroTimerListDlg()
{
}

void BOKODoroTimerListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BOKODoroTimerListDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// BOKODoroTimerListDlg 메시지 처리기

BOOL BOKODoroTimerListDlg::OnInitDialog()
{
	__super::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	Initialize();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void BOKODoroTimerListDlg::Initialize()
{
	InitFrame("타이머 목록");
}



void BOKODoroTimerListDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 __super::OnPaint()을(를) 호출하지 마십시오.

	DrawFrame(&dc, 0);
}


void BOKODoroTimerListDlg::OnSize(UINT nType, int cx, int cy)
{
	__super::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	Sizing(nType);
}


HBRUSH BOKODoroTimerListDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = __super::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	HBRUSH returnHBR = CtlColors(pDC, pWnd, nCtlColor);
	if (returnHBR != NULL)
		return returnHBR;

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


BOOL BOKODoroTimerListDlg::PreTranslateMessage(MSG* pMsg)
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


void BOKODoroTimerListDlg::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	this->ShowWindow(SW_HIDE);

	//__super::OnClose();
}
