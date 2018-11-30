// 화면 나타낼 때 필요한 변수,
// 메세지 처리시 필요한 함수를 선언
#pragma once
#include<Windows.h>
class CObject {
protected:
	static char szAppName[];
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;
public:
	HINSTANCE hInst;
	void InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow);
	void Run();
	WPARAM ExitInstance();
};