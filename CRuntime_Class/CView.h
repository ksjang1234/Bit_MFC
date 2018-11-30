#include"stdafx.h"
#include"CWnd.h"

#ifndef _CView_
#define _CView_

class CView :public CWnd {
public:
	DECLARE_DYNCREATE(CView)

public:
	void OnDraw();
	void OnDestroy();
	void OnLButtonDown();
	DECLARE_MESSAGE_MAP()
};
#endif