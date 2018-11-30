// 메세지 처리 루틴
#include "stdafx.h"
#include "CView.h"

extern CView app;

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	int i = 0;

	while (CView::messageMap[i].iMsg != 0) {
		if (iMsg == CView::messageMap[i].iMsg) {
			fpCViewGlobal = CView::messageMap[i].fp;
			(app.*fpCViewGlobal)(wParam, lParam);
			return 0;
		}
		++i;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

// CObject.h에 함수 선언 됨.
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	app.InitInstance(hInstance, szCmdLine, iCmdShow);
	app.Run();
	return app.ExitInstance();
}