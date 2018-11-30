#include <Windows.h>
#include "stdafx.h"
#include "CObject.h"

#ifndef _CView_
#define _CView_

class CView;

typedef LRESULT(CView::*CViewFunPointer)(WPARAM, LPARAM);

typedef struct tagMessageMap{
	UINT iMsg;
	CViewFunPointer fp;
}MessageMap;

static CViewFunPointer fpCViewGlobal;

#define NUM 1000
#define TWOPI (2 * 3.141592)

class CView :public CObject {
public:
	CObject::hwnd;
	PAINTSTRUCT ps;
	POINT pt[NUM]; 
	HDC hdc;
	int cyClient;
	int cxClient;


	int cxIcon;
	int cyIcon;
	HICON hIcon;

	//아래의 구조가 다 같은 이유는 fpCViewGlobal 변수 하나로 모두 접근하기 위해.
	LRESULT OnCreate(WPARAM, LPARAM);
	LRESULT OnDraw(WPARAM, LPARAM);
	LRESULT OnDestroy(WPARAM, LPARAM);
	LRESULT OnSize(WPARAM wParam, LPARAM lParam);
	LRESULT OnLButtonDown(WPARAM wParam, LPARAM lParam);
	LRESULT OnCommand(WPARAM wParam, LPARAM lParam);

	DCLARE_MESSAGE_MAP()
};
#endif