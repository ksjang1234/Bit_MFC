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

	//�Ʒ��� ������ �� ���� ������ fpCViewGlobal ���� �ϳ��� ��� �����ϱ� ����.
	LRESULT OnCreate(WPARAM, LPARAM);
	LRESULT OnDraw(WPARAM, LPARAM);
	LRESULT OnDestroy(WPARAM, LPARAM);
	LRESULT OnSize(WPARAM wParam, LPARAM lParam);
	LRESULT OnLButtonDown(WPARAM wParam, LPARAM lParam);
	LRESULT OnCommand(WPARAM wParam, LPARAM lParam);

	DCLARE_MESSAGE_MAP()
};
#endif