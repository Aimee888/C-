
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
	m_hIcon = AfxGetApp()->LoadIcon(IDR_ICON1);//MFC的图标,是用于创建包含有ID号为IDR_MAINFRAME窗口小图标的句柄
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
	//m_brush.CreateSolidBrush(RGB(255, 255, 102));//设置背景颜色为黄色

	CString strBmpPath = _T(".\\res\\backgroundone.jpg");

	CImage img;

	img.Load(strBmpPath);

	MoveWindow(0, 0, img.GetWidth(), img.GetHeight());

	CBitmap bmpTmp;

	bmpTmp.Attach(img.Detach());

	m_brush.CreatePatternBrush(&bmpTmp);

	CRect rect;
	GetDlgItem(IDC_BUTTON_CLOSE)->GetWindowRect(&rect);//获得空间的绝对坐标
	ScreenToClient(&rect);//获得相对于主窗体的坐标
	rect.OffsetRect(CSize(15, 0));//这里要是要移动的相对位置
	GetDlgItem(IDC_BUTTON_CLOSE)->MoveWindow(rect);//移动到目标位置

	CFont* font;
	font = static_title.GetFont();//获取CFont对象
	LOGFONT lf;
	font->GetLogFont(&lf);//获取LOGFONT结构体
	lf.lfHeight = -15;    //修改字体大小
	lf.lfItalic = TRUE;        //倾斜
	lf.lfWeight = 400;   //修改字体的粗细
	newFont.CreateFontIndirectW(&lf);//创建一个新的字体
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


	if (pWnd->GetDlgCtrlID() == (IDC_STATIC_TITLE))//IDC_STATIC_TITLE:标题ID
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 251, 240));
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}

	if (pWnd->GetDlgCtrlID() == (IDC_STATIC))//IDC_STATIC:文本ID
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

	//获得button标题 
	CString btnCaption = _T("Dialog");
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);

	//CString btnCaption = L"";
	////设置标题
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
	//获得绘图DC
	//得到原Button的矩形大小
	drawRect.CopyRect(&(lpDrawItemStruct->rcItem));
	//绘制控件框架 
	pDC->DrawFrameControl(&drawRect, DFC_BUTTON, lpDrawItemStruct->CtlType);


	//创建画刷
	CBrush pBrush;
	pBrush.CreateSolidBrush(RGB(100, 130, 10));
	//画矩形 
	pDC->FillRect(drawRect, &pBrush);


	//定义一个CRect用于绘制文本 
	CRect textRect;
	//拷贝矩形区域 
	textRect.CopyRect(&drawRect);
	//获得字符串尺寸
	CSize sz = pDC->GetTextExtent(btnCaption);
	//调整文本位置 居中 
	textRect.top += (textRect.Height() - sz.cy) / 2;
	//设置文本背景透明 
	pDC->SetBkMode(TRANSPARENT);
	//设置文本颜色
	pDC->SetTextColor(RGB(0, 0, 255));
	//绘制文本内容
	pDC->DrawText(btnCaption, &textRect, DT_RIGHT | DT_CENTER | DT_BOTTOM);

	CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
