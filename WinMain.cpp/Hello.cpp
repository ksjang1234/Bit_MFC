// MFC에서는 main을 WinMain으로 사용.
#if 0
#include<Windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
//현재 실행중인 프로세스 핸들, 이미 존재하는 이전 프로세서 인스턴스 핸들, 명령행 인자, 윈도우의 초기 상태 나타내는 값(showwindow의 2번째 파라미터와 같은 역할.)
{
	return 0;
}
#endif

// 윈도우 클래스 등록
// 동작과 모양 정의
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
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // 기본적인 아이콘 모양
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); // 기본적인 커서 모양
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass); // 윈도우 클래스 등록.

	return 0;
}


#endif

