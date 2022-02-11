#pragma once

// CustomStatic

class CustomStatic : public CStatic
{
	DECLARE_DYNAMIC(CustomStatic)

public:
	CustomStatic();
	virtual ~CustomStatic();

	void Initialize(int fontSize, CString fontName);

private:

	CString m_strFontName;
	int m_nFontSize;
	CFont m_Font;

public:

protected:
	DECLARE_MESSAGE_MAP()
};


