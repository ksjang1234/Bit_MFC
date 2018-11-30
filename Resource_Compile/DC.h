#include"CView.h"
#if !defined(_CDC_DEFINED_)
#define _CDC_DEFINED_

class CDC {
	CView *pView;
	PAINTSTRUCT ps;


public:
	HDC hdc;
	CDC(CView *pView);
	virtual ~CDC();
	BOOL MoveToEx(int, int, LPPOINT);
	BOOL LineTo(int, int);
	BOOL Polyline(CONST POINT *, int);
};

#endif