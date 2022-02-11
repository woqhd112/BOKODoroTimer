// CustomEdit.cpp: 구현 파일
//

#include "pch.h"
#include "../BOKODoroTimer.h"
#include "CustomEdit.h"


// CustomEdit

IMPLEMENT_DYNAMIC(CustomEdit, CEdit)

CustomEdit::CustomEdit()
{

}

CustomEdit::~CustomEdit()
{
	thisFont.DeleteObject();
}


BEGIN_MESSAGE_MAP(CustomEdit, CEdit)
END_MESSAGE_MAP()



// CustomEdit 메시지 처리기
void CustomEdit::Initialize(int nFontSize, CString strFontName)
{
	thisFont.CreateFontA(nFontSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
		strFontName);
	this->SetFont(&thisFont);
}

