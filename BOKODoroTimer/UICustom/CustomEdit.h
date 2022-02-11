#pragma once


// CustomEdit

class CustomEdit : public CEdit
{
	DECLARE_DYNAMIC(CustomEdit)

public:
	CustomEdit();
	virtual ~CustomEdit();

	void Initialize(int nFontSize, CString strFontName);

private:

	CFont thisFont;

protected:
	DECLARE_MESSAGE_MAP()
};


