﻿#pragma once


// CustomButton

enum CustomButtonType
{
	CBT_DEFAULT = 0,
	CBT_CLOSE,
	CBT_MINIMIZE
};

enum CustomButtonEvent
{
	CBE_CLICK = 0,
	CBE_TOGGLE
};

class CustomButton : public CMFCButton
{
	DECLARE_DYNAMIC(CustomButton)

public:
	CustomButton();
	virtual ~CustomButton();

	void Initialize(COLORREF color, FlatStyle style, CString strFontName = _T("고딕"), int nFontSize = 10, int nFontFlags = FW_NORMAL, CustomButtonType buttonType = CBT_DEFAULT, CustomButtonEvent buttonEvent = CBE_CLICK, bool buttonRgn = false);

	void SetAlignText(CMFCButton::AlignStyle align);

	void ResetClickButtonColor();
	void ExecuteClickButtonColor();
	bool IsToggle() const;

	CustomButtonEvent m_buttonEvent;

	bool m_bUseMouseBkGroundColorEvent;

private:

	bool m_bTrackMouse;
	CustomButtonType m_buttonType;

	CFont m_thisFont;
	COLORREF m_defaultColor;
	COLORREF m_hoverColor;
	COLORREF m_downColor;

	bool m_bClicked;
	bool m_bDown;
	CRgn m_rgnWnd;

	void SetRgn();

public:


protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};


