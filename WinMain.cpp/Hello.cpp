// MFC������ main�� WinMain���� ���.
#if 0
#include<Windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
//���� �������� ���μ��� �ڵ�, �̹� �����ϴ� ���� ���μ��� �ν��Ͻ� �ڵ�, ����� ����, �������� �ʱ� ���� ��Ÿ���� ��(showwindow�� 2��° �Ķ���Ϳ� ���� ����.)
{
	return 0;
}
#endif

// ������ Ŭ���� ���
// ���۰� ��� ����
#if 1
#include<Windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	static char szAppName[] = "Hello, Windows!!";
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = DefWindowProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // �⺻���� ������ ���
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); // �⺻���� Ŀ�� ���
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass); // ������ Ŭ���� ���.

	return 0;
}


#endif

