#include"stdafx.h"

CObject *CRuntimeClass::CreateObject() {
	// �Լ� �����͸� �̿��Ͽ� ���������� �Լ��� ȣ���Ѵ�.
	// �����Լ��� ����.
	return (*pfnCreateObject)();
}