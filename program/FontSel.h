/*
noMeiryoUI (C) 2005,2012-2021 Tatsuhiko Shoji
The sources for noMeiryoUI are distributed under the MIT open source license
*/
#pragma once

#include <vector>
#include <windows.h>
#include "Resource.h"
#include "basedialog.h"
#include "TwrCombobox.h"
#include "TwrCheckbox.h"

/** スタイルの情報 */
struct TypeInfo {
	TCHAR typeName[128];
	LOGFONT logFont;
};

/** 文字セットと対応するスタイルの情報 */
struct CharsetInfo {
	int charset;
	std::vector<struct TypeInfo> fonts;
};

/** フォントの情報 */
struct FontInfo {
	LOGFONT logFont;
	// std::vector<struct CharsetInfo> charsetList;
	TCHAR dispName[32];
	TCHAR fullName[LF_FULLFACESIZE];
};

class FontSel :
	public BaseDialog
{
private:
	TwrCombobox *m_fontNameList;
	TwrCombobox *m_fontSizeList;
	TwrCombobox *m_ChersetList;
	TwrCombobox *m_styleList;
	TwrCheckbox* m_bold;
	TwrCheckbox* m_italic;
	TwrCheckbox *m_underline;
	TwrCheckbox *m_strike;

	HFONT displayFont;

	LOGFONT selectedFont;
	LOGFONT *previousFont;

	void adjustPosition(void);
	void applyResource();
	void setCharset(void);
	void setStyle();
	INT_PTR onOK(void);

protected:
	INT_PTR OnInitDialog();
	INT_PTR OnCommand(WPARAM wParam);

public:
	FontSel(HWND parent, int resource);
	virtual ~FontSel(void);

	LOGFONT getSelectedFont() {
		return selectedFont;
	}
	void setPreviousFont(LOGFONT *item) {
		previousFont = item;
	}
	void setNoMeiryoUI();
	void setNoTahoma();

};

void copyTypeInfo(TypeInfo& typeInfo, ENUMLOGFONTEX* lpelfe);
