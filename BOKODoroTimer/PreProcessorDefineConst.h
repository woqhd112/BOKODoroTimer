#pragma once
// 다이얼로그 전처리 정의

#define TITLE_TEXT	"복고도로"

#define FONT_NAME_NUMBER	"DS-Digital"
#define FONT_NAME_TEXT		"잘풀리는하루 Medium"

#define STATE_TEXT_NONE		"준비"
#define STATE_TEXT_WORK		"집중"
#define STATE_TEXT_REST		"휴식"
#define STATE_TEXT_REFRESH	"회복"
#define START_STATE_BTN_TEXT_START	"시작"
#define START_STATE_BTN_TEXT_PAUSE	"일시 정지"

#define START_TIMER_BEEP_SOUND_COUNT	3
#define END_TIMER_BEEP_SOUND_COUNT		1

#define FONT_SIZE_GROUPBOX_STATIC			18
#define FONT_SIZE_TIME_STATIC				16
#define FONT_SIZE_STATE_STATIC				20
#define FONT_SIZE_REPEAT_SETTING_STATIC		14
#define FONT_SIZE_BUTTON					16
#define FONT_SIZE_ETC						10

#define FONT_SIZE_TIME_EDIT					36
#define FONT_SIZE_STATE_EDIT				26
#define FONT_SIZE_REPEAT_SETTING_EDIT		14

#define TEXT_COLOR_RED		RGB(177, 5, 10)
#define TEXT_COLOR_GREEN	RGB(16, 167, 60)
#define TEXT_COLOR_YELLOW	RGB(253, 215, 62)

#define CURSOR_HAND SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND))
#define CURSOR_ARROW SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW))
#define CURSOR_CROSS SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS))
#define CURSOR_WAIT SetCursor(AfxGetApp()->LoadStandardCursor(IDC_WAIT))
