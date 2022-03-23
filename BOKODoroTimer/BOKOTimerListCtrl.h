#pragma once
#include "UICustom/DlgInterface.h"
#include "UICustom/CustomScroll.h"

// BOKOTimerListCtrl 대화 상자

struct TimerListItem
{
	CustomButton* pButtonBackGround;
	CustomButton* pButtonItemName;
	CButton* pCheckBoxSelect;
};

enum TimerPosFlag
{
	TPF_CHECKBOX = 0,
	TPF_BUTTON,
	TPF_BACKGROUND,
};

class BOKOTimerListCtrl : public CDialogEx, public DlgInterface
{
	DECLARE_DYNAMIC(BOKOTimerListCtrl)

public:
	BOKOTimerListCtrl(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~BOKOTimerListCtrl();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_TIMER_LIST_CTRL };

public:

	void Insert(ComplexString strText, int key, bool bCheck = false);
	void Delete(int nIndex);

	void CheckUpdate(int nIndex);

	int Size() const;

	void Clear();

	ComplexVector<int> GetSelectedItemsIndex();

	int GetKeyByIndex(int index);
	int GetIndexByCtrlID(int id);

	void AllEnableItems(bool enable);

private:

	virtual void Initialize() override;

	CRect GetItemPos(int index, TimerPosFlag flag);

public:


private:

	CustomScroll m_scroll;

	ComplexMap<int, TimerListItem*> m_listItemContainer;
	int m_size;

	const int CHECKBOX_STATIC_MARGIN = 1;
	const int ITEM_BY_ITEM_MARGIN = 4;
	const int CHECKBOX_WIDTH = 20;
	const int CHECKBOX_HEIGHT = 20;
	const int BUTTON_WIDTH = 204;
	const int BUTTON_HEIGHT = 20;
	const int BACKGROUND_WIDTH = 234;

	int m_nStartItemPos_X = 5;
	int m_nStartItemPos_Y = 2;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
