
// REALSTOPWATCHView.cpp: CREALSTOPWATCHView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "REALSTOPWATCH.h"
#endif

#include "REALSTOPWATCHDoc.h"
#include "REALSTOPWATCHView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CREALSTOPWATCHView

IMPLEMENT_DYNCREATE(CREALSTOPWATCHView, CView)

BEGIN_MESSAGE_MAP(CREALSTOPWATCHView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CREALSTOPWATCHView 생성/소멸

CREALSTOPWATCHView::CREALSTOPWATCHView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_strStopWatch = _T("00:00. 00");
	m_bStopWatchRun = false; // 스톱워치 실행 상태 초기화
	m_nMinute = 0; // 분 초기화
	m_nSecond = 0; // 초 초기화
	m_nMSec = 0; // 밀리초 초기화
	m_nCount = 0; // record num
}

CREALSTOPWATCHView::~CREALSTOPWATCHView()
{
}

BOOL CREALSTOPWATCHView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CREALSTOPWATCHView 그리기

void CREALSTOPWATCHView::OnDraw(CDC* pDC)
{
	CREALSTOPWATCHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	// 다른 디바이스 컨텍스트(de) 생성
	CClientDC de(this);

	// 스톱워치 출력을 위한 폰트 설정 (굴림체, 크기 100)
	CFont big_font;
	big_font.CreateFont(100, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("굴림체"));

	CFont* pOldFont = pDC->SelectObject(&big_font);

	// 스톱워치를 화면 중앙에 출력
	CString strStopWatch = m_strStopWatch;
	CRect rect;
	GetClientRect(&rect);

	// 텍스트 출력 위치 계산 (가운데 정렬)
	int textWidth = pDC->GetTextExtent(strStopWatch).cx;
	int textHeight = pDC->GetTextExtent(strStopWatch).cy;
	int centerX = rect.Width() / 2;
	int centerY = rect.Height() / 2;

	// 이제 가운데 정렬만 사용합니다. VTA_CENTER를 제거합니다.
	pDC->SetTextAlign(TA_CENTER);

	pDC->TextOut(centerX, centerY - textHeight / 2, strStopWatch);

	pDC->SelectObject(pOldFont); // 이전 폰트로 복원

	// 기록 출력
	int yPos = 5; // 시작 y 좌표
	for (int i = 0; i < m_nCount; i++) {
		pDC->TextOut(32, yPos, m_strRecord[i]);
		yPos += 20; // 다음 텍스트 출력 위치
	}
}



// CREALSTOPWATCHView 인쇄

BOOL CREALSTOPWATCHView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CREALSTOPWATCHView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CREALSTOPWATCHView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CREALSTOPWATCHView 진단

#ifdef _DEBUG
void CREALSTOPWATCHView::AssertValid() const
{
	CView::AssertValid();
}

void CREALSTOPWATCHView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CREALSTOPWATCHDoc* CREALSTOPWATCHView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CREALSTOPWATCHDoc)));
	return (CREALSTOPWATCHDoc*)m_pDocument;
}
#endif //_DEBUG



void CREALSTOPWATCHView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 타이머가 호출될 때마다 m_nMSec, m_nSecond, m_nMinute을 업데이트합니다.
	m_nMSec++;
	if (m_nMSec >= 100) {
		m_nMSec = 0;
		m_nSecond++;
		if (m_nSecond >= 60) {
			m_nSecond = 0;
			m_nMinute++;
		}
	}

	// m_strStopWatch에 현재 시간을 문자열로 포맷팅하여 저장합니다.
	m_strStopWatch.Format(_T("%02d:%02d.%02d"), m_nMinute, m_nSecond, m_nMSec);

	// 화면을 갱신합니다.
	Invalidate(); // 화면을 무효화하여 자동으로 다시 그리기 요청
	CView::OnTimer(nIDEvent);
}


void CREALSTOPWATCHView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (!m_bStopWatchRun) {
		// 스톱워치가 정지 중인 경우, 시작하고 타이머 설정
		m_bStopWatchRun = true;
		SetTimer(1, 10, NULL); // 10밀리초(1/100초)마다 타이머 설정
	}
	else {
		// 스톱워치가 실행 중인 경우, 정지하고 타이머 제거
		m_bStopWatchRun = false;
		KillTimer(1); // 타이머 제거
	}
	CView::OnLButtonDown(nFlags, point);
}


void CREALSTOPWATCHView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (nChar == VK_SPACE && m_bStopWatchRun) {
		// 스페이스 바를 누르고 스톱워치가 실행 중인 경우에만 기록 추가
		if (m_nCount < 20) {
			// 현재 시간을 스톱워치 문자열에서 가져와 기록 배열에 추가
			m_strRecord[m_nCount] = m_strStopWatch;
			m_nCount++;
		}
		else {
			// 기록된 내용의 개수가 40개일 경우, 배열과 개수 초기화
			for (int i = 0; i < 20; i++) {
				m_strRecord[i].Empty();
			}
			m_nCount = 0;
		}
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CREALSTOPWATCHView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 
	// 스톱워치가 실행 중이 아닌 경우에만 초기화를 허용합니다.
	if (!m_bStopWatchRun) {
		// 사용자에게 초기화 확인 메시지를 표시
		int result = MessageBox(_T("초기화 하시겠습니까?"), _T("초기화 확인"), MB_YESNO | MB_ICONQUESTION);

		if (result == IDYES) {
			// 사용자가 확인을 눌렀을 때 모든 변수를 초기화
			m_nMinute = 0;
			m_nSecond = 0;
			m_nMSec = 0;
			m_strStopWatch.Empty();
			m_nCount = 0;
			for (int i = 0; i < 20; i++) {
				m_strRecord[i].Empty();
			}

			// 화면 갱신을 요청합니다.
			Invalidate();
		}
	}
	CView::OnRButtonDown(nFlags, point);
}
