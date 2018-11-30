#include "stdafx.h"
#include "CObject.h"
#include "resource.h"

void CObject::InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int szCmdShow) {
	hInst = hInstance;
	wndclass.cbSize = sizeof(wndclass); // 윈도우 구조체 사이즈
	wndclass.style = CS_HREDRAW | CS_VREDRAW; // 창의 가로 세로 크기
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	// wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1)); // 창의 title에 있는 아이콘
	// wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1)); //창 내에서 마우스
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	// wndclass.lpszMenuName = NULL; // 창 메뉴 버튼
	wndclass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wndclass.lpszClassName = szAppName; // 창의 title name
	//wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	RegisterClassEx(&wndclass); // 사용하겠다고 등록

	// 만들어준다.
	hwnd = CreateWindow(
		szAppName,
		"CDC step2",
		WS_OVERLAPPEDWINDOW, //창을 서로 겹칠 수 있게
		CW_USEDEFAULT, // 디폴트 좌표
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hwnd, szCmdShow); // 만들걸 보여줘라
	UpdateWindow(hwnd); //그린 것을 업데이트
}

void CObject::Run() { //메세지 처리
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

WPARAM CObject::ExitInstance() {
	return msg.wParam;
}

char CObject::szAppName[] = "Hello, Window!!";