#include"stdafx.h"

CObject *CRuntimeClass::CreateObject() {
	// 함수 포인터를 이용하여 간접적으로 함수를 호출한다.
	// 생성함수를 실행.
	return (*pfnCreateObject)();
}