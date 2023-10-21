
// Practice2021View.cpp: CPractice2021View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Practice2021.h"
#endif

#include "Practice2021Doc.h"
#include "Practice2021View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice2021View

IMPLEMENT_DYNCREATE(CPractice2021View, CView)

BEGIN_MESSAGE_MAP(CPractice2021View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPractice2021View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CPractice2021View 생성/소멸

CPractice2021View::CPractice2021View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPractice2021View::~CPractice2021View()
{
}

BOOL CPractice2021View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPractice2021View 그리기

void CPractice2021View::OnDraw(CDC* pDC)
{
	CPractice2021Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDC->TextOut(10, 10, m_strWindowSize);

	CRect rect; // Basically this function has four location of x, y lines.
	GetClientRect(&rect); // it's also quite same like rect but this one has only two. 
	pDC->DrawText(m_strOutput, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	// BOOL TextOut(int x, int y, const CString& str);
	// str mean strings I wanna print.
}


// CPractice2021View 인쇄


void CPractice2021View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPractice2021View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPractice2021View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPractice2021View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CPractice2021View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice2021View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	// theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPractice2021View 진단

#ifdef _DEBUG
void CPractice2021View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice2021View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice2021Doc* CPractice2021View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice2021Doc)));
	return (CPractice2021Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice2021View 메시지 처리기


void CPractice2021View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_strWindowSize.Format(_T("This tab width and height is %d, %d."), cx, cy);

	Invalidate(); // reset view
}


void CPractice2021View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_strOutput = _T("Left Cursor pressed.");
	Invalidate(); // OnDraw function callout
	m_bDrag = TRUE;
	CView::OnLButtonDown(nFlags, point); // mouse left pressed -> WM_LBUTTONDOWN on -> OnLButtonDown on -> OnDraw 
}


void CPractice2021View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_strOutput = _T("RIght Cursor pressed.");
	Invalidate(); // OnDraw function callout
	CView::OnRButtonDown(nFlags, point);
}


void CPractice2021View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_strOutput = _T("Keyboard pressed.");
	Invalidate(); // OnDraw function callout
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CPractice2021View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	m_bDrag = FALSE;
	CView::OnLButtonUp(nFlags, point);
}


void CPractice2021View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrag == TRUE) {
		m_strOutput = _T("it's dragging on");
	}
	else {
		m_strOutput = _T("it's on move");
	}
	Invalidate();

	CView::OnMouseMove(nFlags, point);
}