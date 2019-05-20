
// MFCInterfaceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCInterface.h"
#include "MFCInterfaceDlg.h"
#include "afxdialogex.h"
//#include "Windows.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
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


// CMFCInterfaceDlg dialog



CMFCInterfaceDlg::CMFCInterfaceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCINTERFACE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_ICON1);//MFC��ͼ��,�����ڴ���������ID��ΪIDR_MAINFRAME����Сͼ��ľ��
	//IDR_MAINFRAME
}

void CMFCInterfaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_CLOSE, m_btnClose);
	DDX_Control(pDX, IDC_STATIC_TITLE, static_title);
}

BEGIN_MESSAGE_MAP(CMFCInterfaceDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CMFCInterfaceDlg::OnBnClickedButtonClose)
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// CMFCInterfaceDlg message handlers

BOOL CMFCInterfaceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//m_brush.CreateSolidBrush(RGB(255, 255, 102));//���ñ�����ɫΪ��ɫ

	CString strBmpPath = _T(".\\res\\backgroundone.jpg");

	CImage img;

	img.Load(strBmpPath);

	MoveWindow(0, 0, img.GetWidth(), img.GetHeight());

	CBitmap bmpTmp;

	bmpTmp.Attach(img.Detach());

	m_brush.CreatePatternBrush(&bmpTmp);

	CRect rect;
	GetDlgItem(IDC_BUTTON_CLOSE)->GetWindowRect(&rect);//��ÿռ�ľ�������
	ScreenToClient(&rect);//�������������������
	rect.OffsetRect(CSize(15, 0));//����Ҫ��Ҫ�ƶ������λ��
	GetDlgItem(IDC_BUTTON_CLOSE)->MoveWindow(rect);//�ƶ���Ŀ��λ��

	CFont* font;
	font = static_title.GetFont();//��ȡCFont����
	LOGFONT lf;
	font->GetLogFont(&lf);//��ȡLOGFONT�ṹ��
	lf.lfHeight = -15;    //�޸������С
	lf.lfItalic = TRUE;        //��б
	lf.lfWeight = 400;   //�޸�����Ĵ�ϸ
	newFont.CreateFontIndirectW(&lf);//����һ���µ�����
	static_title.SetFont(&newFont);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCInterfaceDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCInterfaceDlg::OnPaint()
{

	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCInterfaceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



HBRUSH CMFCInterfaceDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if (pWnd == this)
	{
		return m_brush;
	}


	if (pWnd->GetDlgCtrlID() == (IDC_STATIC_TITLE))//IDC_STATIC_TITLE:����ID
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 251, 240));
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}

	if (pWnd->GetDlgCtrlID() == (IDC_STATIC))//IDC_STATIC:�ı�ID
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0, 225, 225));
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}

	return hbr;

	//return m_brush;
}


void CMFCInterfaceDlg::OnBnClickedButtonClose()
{
	CDialog::OnOK();
}


void CMFCInterfaceDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: Add your message handler code here and/or call default

	//���button���� 
	CString btnCaption = _T("Dialog");
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);

	//CString btnCaption = L"";
	////���ñ���
	//switch (lpDrawItemStruct->CtlID)
	//{
	//case ID1:
	//	btnCaption = "1";
	//	break;
	//case ID2:
	//	btnCaption = "2";
	//	break;
	//case ID3:
	//	btnCaption = "3";
	//	break;
	//default:
	//	;
	//}

	CRect drawRect;
	//��û�ͼDC
	//�õ�ԭButton�ľ��δ�С
	drawRect.CopyRect(&(lpDrawItemStruct->rcItem));
	//���ƿؼ���� 
	pDC->DrawFrameControl(&drawRect, DFC_BUTTON, lpDrawItemStruct->CtlType);


	//������ˢ
	CBrush pBrush;
	pBrush.CreateSolidBrush(RGB(100, 130, 10));
	//������ 
	pDC->FillRect(drawRect, &pBrush);


	//����һ��CRect���ڻ����ı� 
	CRect textRect;
	//������������ 
	textRect.CopyRect(&drawRect);
	//����ַ����ߴ�
	CSize sz = pDC->GetTextExtent(btnCaption);
	//�����ı�λ�� ���� 
	textRect.top += (textRect.Height() - sz.cy) / 2;
	//�����ı�����͸�� 
	pDC->SetBkMode(TRANSPARENT);
	//�����ı���ɫ
	pDC->SetTextColor(RGB(0, 0, 255));
	//�����ı�����
	pDC->DrawText(btnCaption, &textRect, DT_RIGHT | DT_CENTER | DT_BOTTOM);

	CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
