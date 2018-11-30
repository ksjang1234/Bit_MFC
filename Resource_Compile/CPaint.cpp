#include "CPaint.h"

CPaintDC::CPaintDC(CView *p) {
	pView = p;
	hdc = BeginPaint(pView->hwnd, &ps);
}

CPaintDC::~CPaintDC() {
	EndPaint(pView->hwnd, &ps);
}

void CPaintDC::GetClientRect() {
	::GetClientRect(pView->hwnd, &rect);
}

void CPaintDC::DrawTextDC() {
	::DrawText(hdc, "Hello, Windows!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}
