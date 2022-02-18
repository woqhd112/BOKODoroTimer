// BOKODoroTimerListDlg.cpp: 구현 파일
//

#include "pch.h"
#include "BOKODoroTimer.h"
#include "BOKODoroTimerListDlg.h"
#include "BOKODoroTimerDlg.h"
#include "afxdialogex.h"


// BOKODoroTimerListDlg 대화 상자

IMPLEMENT_DYNAMIC(BOKODoroTimerListDlg, CDialogEx)

BOKODoroTimerListDlg::BOKODoroTimerListDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_TIMER_LIST, pParent)
	, DlgInterface(this, true)
{
	CreateFrame(FDT_SUB_DLG);
	Log_Manager->OnPutLog("BOKODoroTimerListDlg 생성자 호출", LogType::LT_PROCESS);
}

BOKODoroTimerListDlg::~BOKODoroTimerListDlg()
{
	m_timerListCtrl.DestroyWindow();

	Log_Manager->OnPutLog("BOKODoroTimerListDlg 소멸자 호출", LogType::LT_PROCESS);
}

void BOKODoroTimerListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON_TIMER_DELETE, m_btn_delete);
}


BEGIN_MESSAGE_MAP(BOKODoroTimerListDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_MFCBUTTON_TIMER_DELETE, &BOKODoroTimerListDlg::OnBnClickedMfcbuttonTimerDelete)
END_MESSAGE_MAP()


// BOKODoroTimerListDlg 메시지 처리기

BOOL BOKODoroTimerListDlg::OnInitDialog()
{
	__super::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	Initialize();
	ReLoadTimerList();
	Log_Manager->OnPutLog("타이머 리스트 초기화", LogType::LT_PROCESS);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void BOKODoroTimerListDlg::Initialize()
{
	InitFrame("타이머 목록");

	m_timerListCtrl.Create(BOKOTimerListCtrl::IDD, this);
	m_timerListCtrl.ShowWindow(SW_SHOW);

	m_btn_delete.Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_BOLD);
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

void BOKODoroTimerListDlg::ReLoadTimerList()
{
	m_timerContainer.clear();
	m_timerListCtrl.Clear();
	
	LoadTimerDBList();
	LoadTimerUIList();
}

void BOKODoroTimerListDlg::LoadTimerUIList()
{
	if (m_timerContainer.empty())
		return;

	ComplexVector<TimerVO>::iterator iter = m_timerContainer.begin();

	while (iter != m_timerContainer.end())
	{
		m_timerListCtrl.Insert(iter->value.GetTimerNAME(), iter->value.GetTimerSEQ(), true);
		iter++;
	}

	int nLastInsertIndex = m_timerListCtrl.Size() - 1;
	m_timerListCtrl.CheckUpdate(nLastInsertIndex < 0 ? 0 : nLastInsertIndex);
}

void BOKODoroTimerListDlg::LoadTimerDBList()
{
	m_timerContainer.clear();

	if (Timer_DB_Manager->SelectAllTimer(&m_timerContainer) == false)
	{
		Log_Manager->OnPutLog("타이머 정보 로드 오류", LogType::LT_PROCESS);
		AfxMessageBox("타이머 정보 로드 오류");
		exit(0);
	}

	Log_Manager->OnPutLog("모든 타이머 정보 로드 성공", LogType::LT_PROCESS);
}

void BOKODoroTimerListDlg::InsertTimer(TimerVO& timerVO)
{
	Timer_DB_Manager->StartTransaction(TransactionNames[TND_TIMER_INSERT]);

	if (Timer_DB_Manager->InsertTimer(timerVO) == false)
	{
		Timer_DB_Manager->RollbackTransaction();
		ReLoadTimerList();
		return;
	}

	LoadTimerDBList();

	int nLastInsertTimerSEQ = m_timerContainer.at(m_timerContainer.size() - 1).GetTimerSEQ();// 새로 불러와서 마지막 시퀀스 타이머 (새로등록한 타이머)의 시퀀스번호를 넣는다.

	timerVO.SetTimerSEQ(nLastInsertTimerSEQ);

	// UI 작업
	m_timerListCtrl.Insert(timerVO.GetTimerNAME(), timerVO.GetTimerSEQ(), true);

	int nLastInsertIndex = m_timerListCtrl.Size() - 1;
	m_timerListCtrl.CheckUpdate(nLastInsertIndex < 0 ? 0 : nLastInsertIndex);

	SelectTimerVO selectTimer;
	selectTimer.SetSl(nLastInsertTimerSEQ);

	SelectTimer_DB_Manager->StartTransaction(TransactionNames[TND_SELECT_TIMER_UPDATE]);
	// 새 등록한 타이머는 선택타이머로 변경
	if (SelectTimer_DB_Manager->UpdateSelectTimer(selectTimer) == false)
	{
		Timer_DB_Manager->RollbackTransaction();
		SelectTimer_DB_Manager->RollbackTransaction();
		Log_Manager->OnPutLog("타이머 정보 등록 오류", LogType::LT_PROCESS);
		ReLoadTimerList();
		return;
	}

	Log_Manager->OnPutLog("타이머 정보 등록 성공", LogType::LT_PROCESS);

	SelectTimer_DB_Manager->CommitTransaction();
	Timer_DB_Manager->CommitTransaction();
}

bool BOKODoroTimerListDlg::DeleteTimer(int itemIndex)
{
	// UI 작업
	// 삭제 전 인덱스로 키값 뽑아오기
	int timerSEQ = m_timerListCtrl.GetKeyByIndex(itemIndex);

	if (timerSEQ == -1)
		return false;

	// 타이머시퀀스와 메인화면의 m_loadTimer의 타이머시퀀스가 같다면 메인화면 초기화
	CBOKODoroTimerDlg* pParent = (CBOKODoroTimerDlg*)GetParent();
	if (timerSEQ == pParent->m_loadTimer.GetTimerSEQ())
	{
		pParent->m_loadTimer = TimerVO();
		pParent->ResetTimerTitle();
		pParent->ResetTimer();
	}

	m_timerListCtrl.Delete(itemIndex);

	if (Timer_DB_Manager->DeleteTimer(timerSEQ) == false)
	{
		return false;
	}

	return true;
}

bool BOKODoroTimerListDlg::UpdateSelectTimer(SelectTimerVO& in_selectTimer)
{
	SelectTimer_DB_Manager->StartTransaction(TransactionNames[TND_SELECT_TIMER_UPDATE]);
	// UI 작업

	if (SelectTimer_DB_Manager->UpdateSelectTimer(in_selectTimer) == false)
	{
		SelectTimer_DB_Manager->RollbackTransaction();
		Log_Manager->OnPutLog("선택한 타이머 변경 오류", LogType::LT_PROCESS);
		return false;
	}

	Log_Manager->OnPutLog("선택한 타이머 변경 성공", LogType::LT_PROCESS);

	SelectTimer_DB_Manager->CommitTransaction();

	return true;
}

void BOKODoroTimerListDlg::OnBnClickedMfcbuttonTimerDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	Timer_DB_Manager->StartTransaction(TransactionNames[TND_TIMER_DELETE]);

	ComplexVector<int> selectedItems = m_timerListCtrl.GetSelectedItemsIndex();

	ComplexVector<int>::iterator iter = selectedItems.begin();
	while (iter != selectedItems.end())
	{
		if (DeleteTimer(iter->value) == false)
		{
			Timer_DB_Manager->RollbackTransaction();
			Log_Manager->OnPutLog("타이머 정보 삭제 오류", LogType::LT_PROCESS);
			ReLoadTimerList();
			return;
		}

		iter++;
	}

	LoadTimerDBList();

	Log_Manager->OnPutLog("타이머 정보 삭제 성공", LogType::LT_PROCESS);

	Timer_DB_Manager->CommitTransaction();
}


BOOL BOKODoroTimerListDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	UINT nButtonStyle = GetWindowLongA(m_timerListCtrl.GetDlgItem(LOWORD(wParam))->GetSafeHwnd(), GWL_STYLE) & 0x0000000F;
	if (nButtonStyle == BS_AUTOCHECKBOX)
	{
		int nClickedCheckBoxID = LOWORD(wParam);
		int nSelectedIndex = m_timerListCtrl.GetIndexByCtrlID(nClickedCheckBoxID);
		m_timerListCtrl.CheckUpdate(nSelectedIndex);
		CButton* pCheckBox = (CButton*)m_timerListCtrl.GetDlgItem(nClickedCheckBoxID);
		
		// 체크박스가 선택된 상태에서 해제하였을 경우는 존재할 수 없으므로 다시 선택시킴
		if (pCheckBox->GetCheck() == FALSE)
		{
			pCheckBox->SetCheck(TRUE);
		}

		// 모든 작업이 완료되면 DB 저장 및 메인화면 갱신
		int nSelectedTimerSEQ = m_timerListCtrl.GetKeyByIndex(nSelectedIndex);
		SelectTimerVO selectTimer;
		selectTimer.SetSl(nSelectedTimerSEQ);

		if (UpdateSelectTimer(selectTimer))
		{
			TimerVO reloadTimer;
			if (Timer_DB_Manager->SelectOneTimer(nSelectedTimerSEQ, &reloadTimer) == false)
			{
				Log_Manager->OnPutLog("타이머 정보 로드 오류", LogType::LT_PROCESS);
				AfxMessageBox("타이머 정보 로드 오류");
				exit(0);
			}

			CBOKODoroTimerDlg* pParent = (CBOKODoroTimerDlg*)GetParent();
			pParent->m_loadTimer = reloadTimer;
			pParent->ResetTimerTitle();
			pParent->ResetTimer();
			Log_Manager->OnPutLog("선택 타이머 화면 변경 성공", LogType::LT_PROCESS);
		}
	}

	return __super::OnCommand(wParam, lParam);
}

void BOKODoroTimerListDlg::StartWithEnableUI(bool enable)
{
	m_timerListCtrl.AllEnableItems(enable);
	m_btn_delete.EnableWindow(enable);
}
