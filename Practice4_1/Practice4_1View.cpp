
// Practice4_1View.cpp: CPractice41View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Practice4_1.h"
#endif

#include "Practice4_1Doc.h"
#include "Practice4_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice41View

IMPLEMENT_DYNCREATE(CPractice41View, CView)

BEGIN_MESSAGE_MAP(CPractice41View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CPractice41View 생성/소멸

CPractice41View::CPractice41View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPractice41View::~CPractice41View()
{
}

BOOL CPractice41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPractice41View 그리기

void CPractice41View::OnDraw(CDC* /*pDC*/)
{
	CPractice41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CPractice41View 인쇄

BOOL CPractice41View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPractice41View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPractice41View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPractice41View 진단

#ifdef _DEBUG
void CPractice41View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice41Doc* CPractice41View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice41Doc)));
	return (CPractice41Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice41View 메시지 처리기


int CPractice41View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	// it shows message bos when window creates.
	AfxMessageBox(_T("Create Window!"), MB_OKCANCEL | MB_ICONINFORMATION);
	return 0;
}


void CPractice41View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	AfxMessageBox(_T("Did you double click ? "), MB_YESNO | MB_ICONQUESTION);
	CView::OnLButtonDblClk(nFlags, point);
}


void CPractice41View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	AfxMessageBox(_T("Shut Down"), MB_YESNO | MB_ICONWARNING);
}
