#include"CWinApp.h"
#include"CView.h"

IMPLEMENT_DYNCREATE(CView)

BEGIN_MESSAGE_MAP(CView)
{WM_PAINT, &CView::OnDraw},
{WM_DESTROY, &CView::OnDestroy},
{WM_LBUTTONDOWN, &CView::OnLButtonDown},
END_MESSAGE_MAP()

CWinApp app;

void CView::OnDraw() {
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	hdc = BeginPaint(GetSafeHwnd(), &ps);
	GetClientRect(GetSafeHwnd(), &rect);
	DrawText(hdc, "Hello, Windows!!!", -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	EndPaint(GetSafeHwnd(), &ps);
}

void CView::OnDestroy() {
	PostQuitMessage(0);
}
void CView::OnLButtonDown() {
	HDC hdc;
	hdc = GetDC(GetSafeHwnd());
	Ellipse(hdc, 0, 0, 300, 300);
	Sleep(500); // CWinApp.cpp에서 return이 TRUE일 경우 클릭한 동작을 확인하기 위해 삽입.
	ReleaseDC(GetSafeHwnd(), hdc);
}