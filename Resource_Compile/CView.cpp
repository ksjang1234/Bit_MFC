#include <Windows.h>
#include <math.h>
#include "stdafx.h"
#include "CView.h"
#include "CObject.h"
#include "DC.h"
#include "CPaint.h"
#include "resource.h"

CView app;

BEGIN_MESSAGE_MAP(CView)
	{ WM_CREATE, &CView::OnCreate },
	{ WM_PAINT, &CView::OnDraw },
	{ WM_DESTROY, &CView::OnDestroy },
	{ WM_SIZE, &CView::OnSize },
	{ WM_LBUTTONDOWN, &CView::OnLButtonDown },
	{ WM_COMMAND, &CView::OnCommand },
END_MESSAGE_MAP()

	LRESULT CView::OnCreate(WPARAM wParam, LPARAM lParam) {
		hIcon = ::LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
		cxIcon = ::GetSystemMetrics(SM_CXICON);
		cyIcon = ::GetSystemMetrics(SM_CYICON);
		return 0L;
	}

	LRESULT CView::OnDraw(WPARAM wParam, LPARAM lparam) {
		CPaintDC pdc(this);

		pdc.GetClientRect();
		pdc.DrawTextDC();

		return 0L;
	}

	LRESULT CView::OnDestroy(WPARAM wParam, LPARAM lParam) {
		PostQuitMessage(0);
		return 0L;
	}

	LRESULT CView::OnLButtonDown(WPARAM wParam, LPARAM lParam) {
		// � ó��

		int i;

		//hdc = GetDC(hwnd);
		CDC dc(this);
		int x, y;

		//MoveToEx(hdc, 0, cyClient / 2, NULL);
		LineTo(hdc, cxClient, cyClient / 2);

		dc.MoveToEx(0, cyClient / 2, NULL);
		dc.LineTo(cxClient, cyClient / 2);

		for (i = 0; i < NUM; i++) {
			pt[i].x = i * cxClient / NUM;
			pt[i].y = (int)(cyClient / 2 * (1 - sin(TWOPI * i / NUM)));
		}
		//Polyline(hdc, pt, NUM);
		//ReleaseDC(hwnd, hdc);

		dc.Polyline(pt, NUM);
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		DrawIcon(dc.hdc, x, y, hIcon);
		return 0L;
	}

	LRESULT CView::OnSize(WPARAM wParam, LPARAM lParam) {
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		return 0L;
	}

	LRESULT CView::OnCommand(WPARAM wParam, LPARAM lParam) {
		HMENU hMenu;

		hMenu = GetMenu(hwnd);
		switch (LOWORD(wParam)) {

		case ID_AAA:
			SendMessage(hwnd, WM_CLOSE, 0, 0L);
			break;
		case ID_BBB:
			SendMessage(hwnd, WM_LBUTTONDOWN, 0, 0);
			break;
		}
		return 0L;
	}