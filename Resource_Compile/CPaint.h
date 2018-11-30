#pragma once
#include "CView.h"
#if !defined(_CPAINT_DEFINED_)
#define _CPAINT_DEFINED_

class CPaintDC {
private:
	CView *pView;
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect;

public:
	CPaintDC(CView *pView);
	virtual ~CPaintDC();
	void GetClientRect();
	void DrawTextDC();
};

#endif