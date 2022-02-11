#pragma once
#include "ComplexMap.h"
#include "Model/VO/TimerVO.h"

using namespace ComplexLibrary;


#define CURSOR_HAND SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND))
#define CURSOR_ARROW SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW))
#define CURSOR_CROSS SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS))
#define CURSOR_HAND SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND))
#define CURSOR_WAIT SetCursor(AfxGetApp()->LoadStandardCursor(IDC_WAIT))


enum PerformanceMessage
{
	PM_CREATE = 0,
};

struct TimerManagerStruct
{
	TimerManagerStruct()
	{

	}
	TimerManagerStruct(ScenarioListVO scenarioData, int scenarioIndex = -1)
		: scenarioData(scenarioData)
		, scenarioIndex(scenarioIndex)
	{

	}
	ScenarioListVO scenarioData;	// 저장할 시나리오 데이터
	int scenarioIndex;	// 시나리오 리스트의 인덱스 번호
};

struct NoteManagerStruct
{
	NoteManagerStruct()
	{

	}
	NoteManagerStruct(NoteInformationVO* noteData, CRect* noteRect, bool noteView, int noteIndex = -1)
		: noteData(noteData)
		, noteView(noteView)
		, noteIndex(noteIndex)
		, noteRect(noteRect)
	{

	}
	bool noteView;
	int noteIndex;	// 노트 리스트의 인덱스 번호
	NoteInformationVO* noteData;	// 저장할 노트 데이터
	CRect* noteRect;
};

struct DragDataStruct
{
	DragDataStruct()
	{
	
	}
	DragDataStruct(bool pushShift, bool pushCtrl, int target_sceSEQ, int sceIndex, int noteSEQ, int sceSEQ, int noteIndex, int buttonID, ComplexString noteCONTENT, int mousePos_X, int mousePos_Y)
		: pushShiftButton(pushShift)
		, pushCtrlButton(pushCtrl)
		, target_sceSEQ(target_sceSEQ)
		, sceIndex(sceIndex)
		, noteSEQ(noteSEQ)
		, sceSEQ(sceSEQ)
		, noteIndex(noteIndex)
		, noteCONTENT(noteCONTENT)
		, buttonID(buttonID)
		, mousePos_X(mousePos_X)
		, mousePos_Y(mousePos_Y)
	{

	}

	bool pushShiftButton = false;
	bool pushCtrlButton = false;
	int target_sceSEQ = -1;
	int sceSEQ = -1;
	int sceIndex = -1;
	int noteSEQ = -1;
	int noteIndex = -1;

	int buttonID = -1;
	int mousePos_X = -1;
	int mousePos_Y = -1;

	ComplexString noteCONTENT;
};

class UIManagerManagement
{
public:

	UIManagerManagement();
	~UIManagerManagement();

	void AttachManager(CWnd* dlgAttachPointer);
	CWnd* DetachManager();

	void InputDragStruct(DragDataStruct* dragDataStruct);
	void InputScenarioStruct(ScenarioManagerStruct* scenarioDataStruct);
	void InputNoteStruct(NoteManagerStruct* noteDataStruct);

	DragUpState GetDragState() const;

protected:

	struct NotePadStruct
	{
		bool bOpenView;
		CustomEditCtrl* noteEdit;
		CustomButton* noteButton;
		CButton* noteCheckBox;
	};

	virtual bool SendMessages(PerformanceMessage message) = 0;
	virtual bool InvokeHelper(PerformanceMessage message) = 0;

	ScenarioManagerStruct* BringScenarioStruct() const;
	void ReleaseScenarioStruct();

	DragDataStruct* BringDragStruct() const;
	void ReleaseDragStruct();

	NoteManagerStruct* BringNoteStruct() const;
	void ReleaseNoteStruct();

	void SortScenarioManagerKey();
	void SortNoteManagerKey();

	void CursorCountRestore(int setCursorCnt);

	bool m_bAttach;
	CWnd* m_mainDlg;
	BOKODragDlg* m_dragDlg;

	static ComplexMap<int, BOKOScenarioDetailDlg*> m_scenarioDlgManager;
	static ComplexMap<int, int> m_scenarioSeqMap;
	static DragUpState m_dragState;
	static int m_cursorEventCnt;
	static bool m_bIsDragging;

	ComplexMap<int, NotePadStruct> m_notePadManager;
	ComplexMap<int, int> m_noteSeqMap;

	CFont m_setFont;
	const int DRAG_DLG_WIDTH = 30;
	const int DRAG_DLG_HEIGHT = 30;

private:

	ScenarioManagerStruct* m_pPutScenarioStruct;
	NoteManagerStruct* m_pPutNoteStruct;
	DragDataStruct* m_pPutDragStruct;

};

