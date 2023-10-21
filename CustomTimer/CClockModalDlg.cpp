// CClockModalDlg.cpp: 구현 파일
//

#include "pch.h"
#include "CustomTimer.h"
#include "afxdialogex.h"
#include "CClockModalDlg.h"


// CClockModalDlg 대화 상자

IMPLEMENT_DYNAMIC(CClockModalDlg, CDialogEx)

CClockModalDlg::CClockModalDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MODAL, pParent)
{

}

CClockModalDlg::~CClockModalDlg()
{
}

void CClockModalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CClockModalDlg, CDialogEx)
END_MESSAGE_MAP()


// CClockModalDlg 메시지 처리기
