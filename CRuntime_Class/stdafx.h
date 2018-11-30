#include <Windows.h>

#ifndef _stdafx_defined_
#define _stdafx_defined_

#define DECLARE_MESSAGE_MAP() static MessageMap messageMap[];
#define BEGIN_MESSAGE_MAP(class_name) MessageMap class_name::messageMap[] = {
#define END_MESSAGE_MAP() {0,NULL}};

//RTTI������ ����ü �ּҰ� �ѱ�� (��� Ŭ������ ���� �����ϰ� �ϱ� ���� �ּҰ��� ��ȯ)
#define RUNTIME_CLASS(class_name) (&class_name::class##class_name) 

// RTTI ����ü ���� ���� ���� (��� Ŭ������ �����ϱ� ���� static���� ����)
#define DECLARE_DYNAMIC(class_name) static CRuntimeClass class##class_name;

// RTTI ������ ���� ���� �ʱ�ȭ
#define IMPLEMENT_DYNAMIC(class_name) CRuntimeClass class_name::class##class_name={(#class_name), sizeof(class_name), class_name::CreateObject};

// RTTI ����ü ���� ���� ����, ���� �Լ� ���� (���� ����ü ���� ���� �� �Լ��� �����ϱ� ���� ������ �Լ� ����)
#define DECLARE_DYNCREATE(class_name) DECLARE_DYNAMIC(class_name) static CObject *CreateObject();

// RTTI ����ü ���� ���� �ʱ�ȭ, ���� �Լ� ����
// ��� ���� �ֵ鵵 ��� �� �� �ִ� �Լ�
#define IMPLEMENT_DYNCREATE(class_name) IMPLEMENT_DYNAMIC(class_name) CObject *class_name::CreateObject() {return new class_name;}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

class CObject; // ��򰡿� ���� �Ǿ��ٰ� �̸� ����.

struct CRuntimeClass {
	char m_lpszClassName[21];
	int m_nObjectSize;
	CObject *(*pfnCreateObject)(); // function pointer 

	CObject *CreateObject(); // �������̵�, ����� *(*pfnCreateObject)()�� �ҷ���.
};

class CView;

typedef void (CView::*CViewFunPointer)(); // �޼��� �� �Լ� ������
typedef struct tagMessageMap { // �޼��� ��ȣ�� �Լ� �����͸� ���� ����.
	UINT iMsg;
	CViewFunPointer fp;
}MessageMap;
#endif