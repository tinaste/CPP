
// MFCApplication4Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication4.h"
#include "MFCApplication4Dlg.h"
#include "afxdialogex.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <sstream>
#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedCe();
	afx_msg void OnBnClickeddeleted();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()


// CMFCApplication4Dlg 대화 상자



CMFCApplication4Dlg::CMFCApplication4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION4_DIALOG, pParent)
	, m_box1(_T(""))
	, m_box2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_box1);
	DDX_Text(pDX, IDC_EDIT2, m_box2);
	//  DDX_Text(pDX, IDC_EDIT3, m_box3);
	DDX_Control(pDX, IDC_EDIT3, m_box33);
	DDX_Control(pDX, IDC_EDIT4, m_box4);
}

BEGIN_MESSAGE_MAP(CMFCApplication4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(minus, &CMFCApplication4Dlg::OnBnClickedminus)
	ON_BN_CLICKED(zero, &CMFCApplication4Dlg::OnBnClickedzero)
	ON_BN_CLICKED(one, &CMFCApplication4Dlg::OnBnClickedone)
	ON_BN_CLICKED(two, &CMFCApplication4Dlg::OnBnClickedtwo)
	ON_BN_CLICKED(three, &CMFCApplication4Dlg::OnBnClickedthree)
	ON_BN_CLICKED(four, &CMFCApplication4Dlg::OnBnClickedfour)
	ON_BN_CLICKED(five, &CMFCApplication4Dlg::OnBnClickedfive)
	ON_BN_CLICKED(six, &CMFCApplication4Dlg::OnBnClickedsix)
	ON_BN_CLICKED(seven, &CMFCApplication4Dlg::OnBnClickedseven)
	ON_BN_CLICKED(eight, &CMFCApplication4Dlg::OnBnClickedeight)
	ON_BN_CLICKED(nine, &CMFCApplication4Dlg::OnBnClickednine)
	ON_BN_CLICKED(plus, &CMFCApplication4Dlg::OnBnClickedplus)
	ON_BN_CLICKED(multi, &CMFCApplication4Dlg::OnBnClickedmulti)
	ON_BN_CLICKED(devide, &CMFCApplication4Dlg::OnBnClickeddevide)
	ON_BN_CLICKED(calc, &CMFCApplication4Dlg::OnBnClickedcalc)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCApplication4Dlg::OnEnChangeEdit3)
	ON_BN_CLICKED(CE, &CMFCApplication4Dlg::OnBnClickedCE)
	ON_BN_CLICKED(deleted, &CMFCApplication4Dlg::OnBnClickeddeleted)
END_MESSAGE_MAP()


// CMFCApplication4Dlg 메시지 처리기

BOOL CMFCApplication4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication4Dlg::OnBnClickedButton2() //버튼을 눌러 이벤트 호출
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(1); //1로 데이터를 가져옴
	//int boxchk = m_box1.GetLength(); //멤버변수
	/*
	if (boxchk == 0) //길이가 0인 경우
		MessageBox(L"에디트 박스가 비어있음");

	else
	{
		m_box2 = m_box1;
		UpdateData(0); //0으로 밀어넣음
		MessageBox(m_box2 + "\n 메세지 추가함");


	}*/
}
//public variable
int ln1 = 10, ln2 =0;
char oper;
int boxchk;
CString str;
CString str_c;
CString ln1_s;
CString ln2_s;

int col_len = 0;
int size = 0;
int j = 0;
//
int sum;
int index_a = 0;
int index_b = 0;
int index = 0;
CString test;
int flag = 0;

void CMFCApplication4Dlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication4Dlg::OnBnClickedButton17()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}




void CMFCApplication4Dlg::OnBnClickedzero()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_box33.GetWindowTextW(str);
	//ln1 = _ttoi(str);
	m_box33.SetWindowTextW((str + "0"));

}


void CMFCApplication4Dlg::OnBnClickedone()
 {
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_box33.GetWindowTextW(str);
	m_box33.SetWindowTextW((str + "1"));
}

void CMFCApplication4Dlg::OnBnClickedtwo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_box33.GetWindowTextW(str);
	m_box33.SetWindowTextW((str + "2"));
}


void CMFCApplication4Dlg::OnBnClickedthree()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_box33.GetWindowTextW(str);
	m_box33.SetWindowTextW((str + "3"));
}


void CMFCApplication4Dlg::OnBnClickedfour()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_box33.GetWindowTextW(str);
	m_box33.SetWindowTextW((str + "4"));
}


void CMFCApplication4Dlg::OnBnClickedfive()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_box33.GetWindowTextW(str);
	m_box33.SetWindowTextW((str + "5"));
}


void CMFCApplication4Dlg::OnBnClickedsix()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_box33.GetWindowTextW(str);
	m_box33.SetWindowTextW((str + "6"));
}


void CMFCApplication4Dlg::OnBnClickedseven()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_box33.GetWindowTextW(str);
	m_box33.SetWindowTextW((str + "7"));
}


void CMFCApplication4Dlg::OnBnClickedeight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_box33.GetWindowTextW(str);
	m_box33.SetWindowTextW((str + "8"));
}


void CMFCApplication4Dlg::OnBnClickednine()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_box33.GetWindowTextW(str);
	m_box33.SetWindowTextW((str + "9"));
}


void CMFCApplication4Dlg::OnBnClickedplus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_box33.GetWindowTextW(str);
	m_box33.SetWindowTextW(str + '+');
}

void CMFCApplication4Dlg::OnBnClickedminus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_box33.GetWindowTextW(str);
	m_box33.SetWindowTextW(str + '-');
}

void CMFCApplication4Dlg::OnBnClickedmulti()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_box33.GetWindowTextW(str);
	m_box33.SetWindowTextW(str + '*');
}


void CMFCApplication4Dlg::OnBnClickeddevide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_box33.GetWindowTextW(str);
	m_box33.SetWindowTextW(str + '/');
}



void CMFCApplication4Dlg::OnBnClickedCE()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	str = " ";
	oper = ' ';
	sum = 0;
	ln1 = 0;
	ln2 = 0;
	ln1_s = " ";
	ln2_s = " ";
	m_box33.SetWindowTextW(str);
	m_box4.SetWindowTextW(str);
}




void CMFCApplication4Dlg::OnBnClickeddeleted()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	str_c = "";

	m_box33.GetWindowTextW(str);

	for (int i = 0; i < str.GetLength()-1; i++)
	{
		str_c = str_c + str[i];
	}

	m_box33.SetWindowTextW(str_c);
}




void CMFCApplication4Dlg::OnBnClickedcalc()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_box33.GetWindowTextW(str);

	for (int i = 0; i < str.GetLength(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			oper = str[i];

			for (int j = 0; j < i; j++)
			{
				ln1_s = ln1_s + str[j];
			}

			for (int k = i+1; k <= str.GetLength(); k++)
			{
				ln2_s = ln2_s + str[k];
			}
		}
	}
	ln1 = _tstoi(ln1_s);
	ln2 = _tstoi(ln2_s);

	if(oper == '+')
		sum = ln1 + ln2;
	if (oper == '-')
		sum = ln1 - ln2;
	if (oper == '*')
		sum = ln1 * ln2;
	if (oper == '/')
		sum = ln1 / ln2;

	str.Format(_T("%d"), sum);

	m_box4.SetWindowTextW(str);
	
}


void CMFCApplication4Dlg::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}



