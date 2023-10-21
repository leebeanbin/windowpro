﻿
// StopWatchandNormalView.h: CStopWatchandNormalView 클래스의 인터페이스
//

#pragma once


class CStopWatchandNormalView : public CView
{
protected: // serialization에서만 만들어집니다.
	CStopWatchandNormalView() noexcept;
	DECLARE_DYNCREATE(CStopWatchandNormalView)

// 특성입니다.
public:
	CStopWatchandNormalDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CStopWatchandNormalView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	bool m_bTimerRun; // timer ui on and off
	bool m_bTimerType; // the method to calculata type chages
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CString m_strTimer;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // StopWatchandNormalView.cpp의 디버그 버전
inline CStopWatchandNormalDoc* CStopWatchandNormalView::GetDocument() const
   { return reinterpret_cast<CStopWatchandNormalDoc*>(m_pDocument); }
#endif

