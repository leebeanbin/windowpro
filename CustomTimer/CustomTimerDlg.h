// CustomTimerDlg.h: 헤더 파일
//

#pragma once
#include "CClockHelpDlg.h"
#include "CClockModalDlg.h"


// CCustomTimerDlg 대화 상자
class CCustomTimerDlg : public CDialogEx
{
	// 생성입니다.
public:
	CCustomTimerDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CUSTOMTIMER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


	// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio12();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnStnClickedStaticDay();
	CString m_strYear;
	CString m_strMonth;
	CString m_strHour;
	CString m_strDay;
	CString m_strAMPM;
	CString m_strSecond;
	CString m_strMinute;
	bool m_bRadioClockType; // true : 12 unit , false : 24 unit
	bool m_bCheckYear;
	bool m_bCheckHour;
	afx_msg void OnRadio12();
	afx_msg void OnRadio24();
	afx_msg void OnClickedCheckHour();
	afx_msg void OnClickedCheckYear();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedRadio24();
	bool m_bViewHelp;
	CClockHelpDlg m_dlgClockHelp;
	afx_msg void OnClickedButtonHelp();
	CClockModalDlg m_dlgClockModal;
};