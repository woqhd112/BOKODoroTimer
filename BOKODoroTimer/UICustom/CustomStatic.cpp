// CustomStatic.cpp: 구현 파일
//

#include "pch.h"
#include "../BOKODoroTimer.h"
#include "CustomStatic.h"


// CustomStatic

IMPLEMENT_DYNAMIC(CustomStatic, CStatic)

CustomStatic::CustomStatic()
{

}

CustomStatic::~CustomStatic()
{
	m_Font.DeleteObject();
}


BEGIN_MESSAGE_MAP(CustomStatic, CStatic)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()



// CustomStatic 메시지 처리기

void CustomStatic::Initialize(int fontSize, CString fontName)
{
	this->m_strFontName = fontName;
	this->m_nFontSize = fontSize;
	m_Font.CreateFontA(fontSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
		fontName);
	this->SetFont(&m_Font);
}