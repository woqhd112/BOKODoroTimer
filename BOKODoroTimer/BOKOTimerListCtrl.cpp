// BOKOTimerListCtrl.cpp: 구현 파일
//

#include "pch.h"
#include "BOKODoroTimer.h"
#include "BOKOTimerListCtrl.h"
#include "afxdialogex.h"


static int g_nListItemCtrlID = 10000;

// BOKOTimerListCtrl 대화 상자

IMPLEMENT_DYNAMIC(BOKOTimerListCtrl, CDialogEx)

BOKOTimerListCtrl::BOKOTimerListCtrl(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_TIMER_LIST_CTRL, pParent)
	, DlgInterface(this, false)
{
	CreateFrame(FDT_ETC_DLG);
	m_size = 0;
}

BOKOTimerListCtrl::~BOKOTimerListCtrl()
{
	Clear();
	m_scroll.DestroyWindow();
}

void BOKOTimerListCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BOKOTimerListCtrl, CDialogEx)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_MOUSEWHEEL()
	ON_WM_VSCROLL()
END_MESSAGE_MAP()


// BOKOTimerListCtrl 메시지 처리기

void BOKOTimerListCtrl::Initialize()
{
	InitFrame();

	ScrollProcess::ScrollInfo info;
	info.scrollExecuteCtrl = this;
	info.wheelSize = CHECKBOX_HEIGHT + ITEM_BY_ITEM_MARGIN;

	m_scroll.Create(CustomScroll::IDD, this);
	m_scroll.SetScrollInfo(info);
	m_scroll.ShowWindow(SW_HIDE);
}

BOOL BOKOTimerListCtrl::OnInitDialog()
{
	__super::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	Initialize();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void BOKOTimerListCtrl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 __super::OnPaint()을(를) 호출하지 마십시오.

	DrawFrame(&dc);
}

void BOKOTimerListCtrl::Clear()
{
	m_size = 0;

	ComplexMap<int, TimerListItem*>::iterator iter = m_listItemContainer.begin();

	while (iter != m_listItemContainer.end())
	{
		TimerListItem* deleteItem = iter->value.value;
		if (deleteItem)
		{
			CustomButton* deleteBKButton = iter->value.value->pButtonBackGround;
			CustomButton* deleteTitleButton = iter->value.value->pButtonItemName;
			CButton* deleteCheckBox = iter->value.value->pCheckBoxSelect;

			if (deleteBKButton)
			{
				delete deleteBKButton;
				deleteBKButton = nullptr;
			}

			if (deleteTitleButton)
			{
				delete deleteTitleButton;
				deleteTitleButton = nullptr;
			}

			if (deleteCheckBox)
			{
				delete deleteCheckBox;
				deleteCheckBox = nullptr;
			}

			delete deleteItem;
			deleteItem = nullptr;
		}

		iter++;
	}
	m_listItemContainer.clear();

	// 스크롤 초기화
	m_scroll.ResetScroll();
}

int BOKOTimerListCtrl::Size() const
{
	return m_size;
}

CRect BOKOTimerListCtrl::GetItemPos(int index, TimerPosFlag flag)
{
	CRect returnRect;

	int nCurrentScrollIndex = m_scroll.GetScrollCount();

	if (flag == TPF_CHECKBOX)
	{
		returnRect.left = m_nStartItemPos_X;
		returnRect.right = returnRect.left + CHECKBOX_WIDTH;
		returnRect.top = m_nStartItemPos_Y + ((index - nCurrentScrollIndex) * (CHECKBOX_HEIGHT + ITEM_BY_ITEM_MARGIN));
		returnRect.bottom = returnRect.top + CHECKBOX_HEIGHT;
	}
	else if (flag == TPF_BUTTON)
	{
		returnRect.left = m_nStartItemPos_X + CHECKBOX_WIDTH + CHECKBOX_STATIC_MARGIN;
		returnRect.right = returnRect.left + BUTTON_WIDTH;
		returnRect.top = m_nStartItemPos_Y + ((index - nCurrentScrollIndex) * (CHECKBOX_HEIGHT + ITEM_BY_ITEM_MARGIN));
		returnRect.bottom = returnRect.top + BUTTON_HEIGHT;
	}
	else if (flag == TPF_BACKGROUND)
	{
		returnRect.left = 2;
		returnRect.right = returnRect.left + BACKGROUND_WIDTH;
		returnRect.top = m_nStartItemPos_Y - 1 + ((index - nCurrentScrollIndex) * (CHECKBOX_HEIGHT + ITEM_BY_ITEM_MARGIN));
		returnRect.bottom = returnRect.top + BUTTON_HEIGHT + 2;
	}

	return returnRect;
}

void BOKOTimerListCtrl::Insert(ComplexString strText, int key, bool bCheck)
{
	// bCheck 이 true이면 해당 아이템 체크

	TimerListItem* pListItem = new TimerListItem;
	pListItem->pButtonBackGround = new CustomButton;
	pListItem->pButtonItemName = new CustomButton;
	pListItem->pCheckBoxSelect = new CButton;

	if (pListItem->pButtonBackGround->Create("", WS_VISIBLE | BS_LEFT | BS_OWNERDRAW, CRect(0, 0, 0, 0), this, g_nListItemCtrlID++) == FALSE)
	{
		delete pListItem->pButtonBackGround;
		pListItem->pButtonBackGround = nullptr;

		delete pListItem->pButtonItemName;
		pListItem->pButtonItemName = nullptr;

		delete pListItem->pCheckBoxSelect;
		pListItem->pCheckBoxSelect = nullptr;

		delete pListItem;
		pListItem = nullptr;

		return;
	}

	if (pListItem->pButtonItemName->Create(strText.GetBuffer(), WS_VISIBLE | BS_LEFT | BS_OWNERDRAW, CRect(0, 0, 0, 0), this, g_nListItemCtrlID++) == FALSE)
	{
		pListItem->pButtonBackGround->DestroyWindow();

		delete pListItem->pButtonBackGround;
		pListItem->pButtonBackGround = nullptr;

		delete pListItem->pButtonItemName;
		pListItem->pButtonItemName = nullptr;

		delete pListItem->pCheckBoxSelect;
		pListItem->pCheckBoxSelect = nullptr;

		delete pListItem;
		pListItem = nullptr;

		return;
	}

	if (pListItem->pCheckBoxSelect->Create("", WS_VISIBLE | BS_AUTOCHECKBOX, CRect(0, 0, 0, 0), this, g_nListItemCtrlID++) == FALSE)
	{
		pListItem->pButtonBackGround->DestroyWindow();
		pListItem->pButtonItemName->DestroyWindow();

		delete pListItem->pButtonBackGround;
		pListItem->pButtonBackGround = nullptr;

		delete pListItem->pButtonItemName;
		pListItem->pButtonItemName = nullptr;

		delete pListItem->pCheckBoxSelect;
		pListItem->pCheckBoxSelect = nullptr;

		delete pListItem;
		pListItem = nullptr;

		return;
	}

	pListItem->pButtonBackGround->Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_NORMAL);
	pListItem->pButtonItemName->Initialize(DI_BUTTON_COLOR, CMFCButton::FlatStyle::BUTTONSTYLE_NOBORDERS, FONT_NAME_TEXT, FONT_SIZE_BUTTON, FW_NORMAL, CBT_DEFAULT, CBE_TOGGLE);
	pListItem->pButtonBackGround->m_bUseMouseBkGroundColorEvent = false;
	pListItem->pButtonItemName->SetAlignText(CMFCButton::AlignStyle::ALIGN_LEFT);

	// 아직 size 증가하지않아서 마지막 인덱스번호가 size임 
	CRect stCheckBoxRect = GetItemPos(m_size, TPF_CHECKBOX);
	CRect stButtonRect = GetItemPos(m_size, TPF_BUTTON);
	CRect stBackGroundRect = GetItemPos(m_size, TPF_BACKGROUND);

	pListItem->pCheckBoxSelect->MoveWindow(stCheckBoxRect);
	pListItem->pButtonItemName->MoveWindow(stButtonRect);
	pListItem->pButtonBackGround->MoveWindow(stBackGroundRect);

	pListItem->pCheckBoxSelect->ModifyStyle(0, WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0);
	pListItem->pButtonItemName->ModifyStyle(0, WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0);
	pListItem->pButtonBackGround->ModifyStyle(0, WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0);
	m_scroll.ModifyStyle(0, WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0);
	pListItem->pCheckBoxSelect->BringWindowToTop();
	pListItem->pButtonItemName->BringWindowToTop();
	m_scroll.BringWindowToTop();

	if (bCheck)
	{
		pListItem->pCheckBoxSelect->SetCheck(TRUE);
	}
	else
	{
		pListItem->pCheckBoxSelect->SetCheck(FALSE);
	}

	m_listItemContainer.insert(key, pListItem);

	m_size++;

	// 아이템이 14개 이상이면 스크롤 이벤트
	if (m_size >= 14)
	{
		m_scroll.ExecuteScroll(SCROLL_LINE_ADD);
	}
}

void BOKOTimerListCtrl::Delete(int nIndex)
{
	ComplexMap<int, TimerListItem*>::iterator iter = m_listItemContainer.begin();

	// 삭제
	int deleteIndex = 0;
	while (iter != m_listItemContainer.end())
	{
		if (deleteIndex == nIndex)
		{
			TimerListItem* deleteItem = iter->value.value;
			m_listItemContainer.erase(iter->value.key);

			delete deleteItem->pButtonBackGround;
			deleteItem->pButtonBackGround = nullptr;

			delete deleteItem->pButtonItemName;
			deleteItem->pButtonItemName = nullptr;

			delete deleteItem->pCheckBoxSelect;
			deleteItem->pCheckBoxSelect = nullptr;

			delete deleteItem;
			deleteItem = nullptr;

			break;
		}
		deleteIndex++;
		iter++;
	}

	// 삭제 후 인덱스가 1 감소했으니 해당 인덱스부터 이후까지의 아이템들 위치조정
	iter = m_listItemContainer.begin();

	int adjustIndex = 0;
	while (iter != m_listItemContainer.end())
	{
		if (adjustIndex >= nIndex)
		{
			TimerListItem* adjustItem = iter->value.value;

			CRect stCheckBoxRect = GetItemPos(adjustIndex, TPF_CHECKBOX);
			CRect stButtonRect = GetItemPos(adjustIndex, TPF_BUTTON);
			CRect stBackGroundRect = GetItemPos(adjustIndex, TPF_BACKGROUND);

			adjustItem->pCheckBoxSelect->MoveWindow(stCheckBoxRect);
			adjustItem->pButtonItemName->MoveWindow(stButtonRect);
			adjustItem->pButtonBackGround->MoveWindow(stBackGroundRect);
		}
		adjustIndex++;
		iter++;
	}

	m_size--;

	// 아이템이 14개 이상이면 스크롤 이벤트
	if (m_size >= 14)
	{
		OnVScroll(SB_LINEUP, 0, GetScrollBarCtrl(SB_VERT));
		m_scroll.ExecuteScroll(SCROLL_LINE_DELETE);
	}
}

void BOKOTimerListCtrl::CheckUpdate(int nIndex)
{
	// 인덱스번호를 제외한 나머지는 전부 체크해제 

	ComplexMap<int, TimerListItem*>::iterator iter = m_listItemContainer.begin();

	int exceptionIndex = 0;
	while (iter != m_listItemContainer.end())
	{
		if (exceptionIndex != nIndex)
		{
			iter->value.value->pCheckBoxSelect->SetCheck(FALSE);
		}

		exceptionIndex++;
		iter++;
	}
}

ComplexVector<int> BOKOTimerListCtrl::GetSelectedItemsIndex()
{
	ComplexVector<int> returnSelectedItemsVector;

	ComplexMap<int, TimerListItem*>::iterator iter = m_listItemContainer.begin();

	int selectedIndex = 0;
	while (iter != m_listItemContainer.end())
	{
		if (iter->value.value->pButtonItemName->IsToggle())
		{
			returnSelectedItemsVector.push_back(selectedIndex);
		}
		selectedIndex++;
		iter++;
	}

	return returnSelectedItemsVector;
}

int BOKOTimerListCtrl::GetKeyByIndex(int index)
{
	ComplexMap<int, TimerListItem*>::iterator iter = m_listItemContainer.begin();

	int findIndex = 0;
	while (iter != m_listItemContainer.end())
	{
		if (findIndex == index)
		{
			return iter->value.key;
		}
		findIndex++;
		iter++;
	}

	return -1;
}

int BOKOTimerListCtrl::GetIndexByCtrlID(int id)
{
	ComplexMap<int, TimerListItem*>::iterator iter = m_listItemContainer.begin();

	bool bFind = false;
	int nReturnIndex = 0;
	while (iter != m_listItemContainer.end())
	{
		if (iter->value.value->pButtonBackGround->GetDlgCtrlID() == id)
		{
			bFind = true;
			break;
		}

		if (iter->value.value->pButtonItemName->GetDlgCtrlID() == id)
		{
			bFind = true;
			break;
		}

		if (iter->value.value->pCheckBoxSelect->GetDlgCtrlID() == id)
		{
			bFind = true;
			break;
		}

		nReturnIndex++;
		iter++;
	}

	if (bFind == false)
		return -1;

	return nReturnIndex;
}

void BOKOTimerListCtrl::AllEnableItems(bool enable)
{
	ComplexMap<int, TimerListItem*>::iterator iter = m_listItemContainer.begin();

	while (iter != m_listItemContainer.end())
	{
		iter->value.value->pButtonBackGround->EnableWindow(enable);
		iter->value.value->pButtonItemName->EnableWindow(enable);
		iter->value.value->pCheckBoxSelect->EnableWindow(enable);

		iter++;
	}
}

HBRUSH BOKOTimerListCtrl::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = __super::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(DI_BUTTON_COLOR);
		return m_buttonBrush;
	}

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


BOOL BOKOTimerListCtrl::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	// 이벤트는 모두 부모쪽으로 이동시킨다.
	GetParent()->SendMessageA(WM_COMMAND, wParam, lParam);

	return __super::OnCommand(wParam, lParam);
}


BOOL BOKOTimerListCtrl::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	OnVScroll(m_scroll.OperateWheel(zDelta), 0, GetScrollBarCtrl(SB_VERT));

	return __super::OnMouseWheel(nFlags, zDelta, pt);
}


void BOKOTimerListCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (m_scroll.GetLineCount() > 1)	// 라인카운트는 스크롤바가 생성되면 최소값이 1임.	1이상일 떄만 이벤트작동
	{
		m_scroll.OperateScroll(nSBCode, nPos);
	}

	//__super::OnVScroll(nSBCode, nPos, pScrollBar);
}
