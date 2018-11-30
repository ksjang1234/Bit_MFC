#include <Windows.h>

#ifndef _stdafx_defined_
#define _stdafx_defined_

#define DECLARE_MESSAGE_MAP() static MessageMap messageMap[];
#define BEGIN_MESSAGE_MAP(class_name) MessageMap class_name::messageMap[] = {
#define END_MESSAGE_MAP() {0,NULL}};

//RTTI변수의 구조체 주소값 넘기기 (모든 클래스에 접근 가능하게 하기 위해 주소값을 반환)
#define RUNTIME_CLASS(class_name) (&class_name::class##class_name) 

// RTTI 구조체 정적 변수 선언 (모든 클래스가 공유하기 위해 static으로 선언)
#define DECLARE_DYNAMIC(class_name) static CRuntimeClass class##class_name;

// RTTI 선언한 정적 변수 초기화
#define IMPLEMENT_DYNAMIC(class_name) CRuntimeClass class_name::class##class_name={(#class_name), sizeof(class_name), class_name::CreateObject};

// RTTI 구조체 정적 변수 선언, 생성 함수 선언 (정적 구조체 변수 선언 후 함수를 접근하기 위해 포인터 함수 선언)
#define DECLARE_DYNCREATE(class_name) DECLARE_DYNAMIC(class_name) static CObject *CreateObject();

// RTTI 구조체 정적 변수 초기화, 생성 함수 정의
// 상속 받은 애들도 사용 할 수 있는 함수
#define IMPLEMENT_DYNCREATE(class_name) IMPLEMENT_DYNAMIC(class_name) CObject *class_name::CreateObject() {return new class_name;}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

class CObject; // 어딘가에 정의 되었다고 미리 선언.

struct CRuntimeClass {
	char m_lpszClassName[21];
	int m_nObjectSize;
	CObject *(*pfnCreateObject)(); // function pointer 

	CObject *CreateObject(); // 오버라이드, 실행시 *(*pfnCreateObject)()를 불러옴.
};

class CView;

typedef void (CView::*CViewFunPointer)(); // 메세지 맵 함수 포인터
typedef struct tagMessageMap { // 메세지 번호와 함수 포인터를 묶어 놓음.
	UINT iMsg;
	CViewFunPointer fp;
}MessageMap;
#endif