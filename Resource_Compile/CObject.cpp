#include "stdafx.h"
#include "CObject.h"
#include "resource.h"

void CObject::InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int szCmdShow) {
	hInst = hInstance;
	wndclass.cbSize = sizeof(wndclass); // ������ ����ü ������
	wndclass.style = CS_HREDRAW | CS_VREDRAW; // â�� ���� ���� ũ��
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	// wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1)); // â�� title�� �ִ� ������
	// wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1)); //â ������ ���콺
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	// wndclass.lpszMenuName = NULL; // â �޴� ��ư
	wndclass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wndclass.lpszClassName = szAppName; // â�� title name
	//wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	RegisterClassEx(&wndclass); // ����ϰڴٰ� ���

	// ������ش�.
	hwnd = CreateWindow(
		szAppName,
		"CDC step2",
		WS_OVERLAPPEDWINDOW, //â�� ���� ��ĥ �� �ְ�
		CW_USEDEFAULT, // ����Ʈ ��ǥ
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hwnd, szCmdShow); // ����� �������
	UpdateWindow(hwnd); //�׸� ���� ������Ʈ
}

void CObject::Run() { //�޼��� ó��
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

WPARAM CObject::ExitInstance() {
	return msg.wParam;
}

char CObject::szAppName[] = "Hello, Window!!";