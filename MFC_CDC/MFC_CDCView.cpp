
// MFC_CDCView.cpp: CMFCCDCView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC_CDC.h"
#endif

#include "MFC_CDCDoc.h"
#include "MFC_CDCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCCDCView

IMPLEMENT_DYNCREATE(CMFCCDCView, CView)

BEGIN_MESSAGE_MAP(CMFCCDCView, CView)
END_MESSAGE_MAP()

// CMFCCDCView 생성/소멸

CMFCCDCView::CMFCCDCView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCCDCView::~CMFCCDCView()
{
}

BOOL CMFCCDCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCCDCView 그리기

void CMFCCDCView::OnDraw(CDC* /*pDC*/)
{
	CMFCCDCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMFCCDCView 진단

#ifdef _DEBUG
void CMFCCDCView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCCDCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCCDCDoc* CMFCCDCView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCCDCDoc)));
	return (CMFCCDCDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCCDCView 메시지 처리기
