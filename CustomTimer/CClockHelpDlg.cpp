// CClockHelpDlg.cpp: 구현 파일
//

#include "pch.h"
#include "CustomTimer.h"
#include "afxdialogex.h"
#include "CClockHelpDlg.h"


// CClockHelpDlg 대화 상자

IMPLEMENT_DYNAMIC(CClockHelpDlg, CDialogEx)

CClockHelpDlg::CClockHelpDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_HELP, pParent)
{

}

CClockHelpDlg::~CClockHelpDlg()
{
}

void CClockHelpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CClockHelpDlg, CDialogEx)
END_MESSAGE_MAP()


// CClockHelpDlg 메시지 처리기
