#pragma once
#include "afxdialogex.h"


// CClockModalDlg 대화 상자

class CClockModalDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CClockModalDlg)

public:
	CClockModalDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CClockModalDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MODAL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
