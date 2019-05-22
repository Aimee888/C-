
// TestDllDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestDll.h"
#include "TestDllDlg.h"
#include "afxdialogex.h"

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


// CTestDllDlg dialog



CTestDllDlg::CTestDllDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TESTDLL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CTestDllDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Control(pDX, IDC_COMBO2, m_combo_sec);
	DDX_Control(pDX, IDC_BUTTON_CLOSE, m_btnClose);
	DDX_Control(pDX, IDC_STATIC_TITLE, static_title);
}

BEGIN_MESSAGE_MAP(CTestDllDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_MFCEDITBROWSE1, &CTestDllDlg::OnEnChangeMfceditbrowse1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CTestDllDlg::OnCbnSelchangeCombo1)
	ON_CBN_SETFOCUS(IDC_COMBO1, &CTestDllDlg::OnCbnSetfocusCombo1)
	ON_BN_CLICKED(OK, &CTestDllDlg::OnBnClickedOk)
	ON_STN_CLICKED(result, &CTestDllDlg::OnStnClickedresult)
	ON_BN_CLICKED(clear, &CTestDllDlg::OnBnClickedclear)
	ON_CBN_SETFOCUS(IDC_COMBO2, &CTestDllDlg::OnCbnSetfocusCombo2)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CTestDllDlg::OnBnClickedButtonClose)
	ON_WM_CTLCOLOR()
	ON_WM_DRAWITEM()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CTestDllDlg message handlers

BOOL CTestDllDlg::OnInitDialog()
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

	CString strBmpPath = _T(".\\res\\backgroundone.jpg");

	CImage img;

	img.Load(strBmpPath);

	MoveWindow(0, 0, img.GetWidth(), img.GetHeight());

	CBitmap bmpTmp;

	bmpTmp.Attach(img.Detach());

	m_brush.CreatePatternBrush(&bmpTmp);


	CRect rect_close;
	GetDlgItem(IDC_BUTTON_CLOSE)->GetWindowRect(&rect_close);//获得空间的绝对坐标
	ScreenToClient(&rect_close);//获得相对于主窗体的坐标
	//rect.OffsetRect(CSize(5, 0));//这里要是要移动的相对位置
	rect_close.OffsetRect(CSize(17, 0));//这里要是要移动的相对位置
	GetDlgItem(IDC_BUTTON_CLOSE)->MoveWindow(rect_close);//移动到目标位置

	CFont* font;
	font = static_title.GetFont();//获取CFont对象
	LOGFONT lf;
	font->GetLogFont(&lf);//获取LOGFONT结构体
	lf.lfHeight = -15;    //修改字体大小
	lf.lfItalic = TRUE;        //倾斜
	lf.lfWeight = 400;   //修改字体的粗细
	newFont.CreateFontIndirectW(&lf);//创建一个新的字体
	static_title.SetFont(&newFont);

	m_combo.AddString(L"Add");
	m_combo.AddString(L"Delete");
	m_combo.AddString(L"Update");
	m_combo.AddString(L"Query");
	m_combo.SetCurSel(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestDllDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestDllDlg::OnPaint()
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
		//CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestDllDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestDllDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

char* cstringTochar(CString str_tmp) {

	char *ptr;
	CString str;
	str = str_tmp;
#ifdef _UNICODE
	LONG len;
	len = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	ptr = new char[len + 1];
	memset(ptr, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, str, -1, ptr, len + 1, NULL, NULL);
#else
	ptr = new char[str.GetAllocLength() + 1];
	sprintf(ptr, _T("%s"), str);
#endif
	return ptr;
}


void CTestDllDlg::OnEnChangeMfceditbrowse1()
{

	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	//CString strFile = _T("");
	//CFileDialog dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Describe Files (*.ini)|*.ini|All Files (*.*)|*.*||"), NULL);
	//if (dlgFile.DoModal()) {
	//	strFile = dlgFile.GetPathName();
	//}
	//SetDlgItemText(path, strFile);
	//SetDlgItemText(key, L"aaa");
	m_combo_sec.ResetContent();//清空所有ComboBox的项目
	CString path_cstr;
	GetDlgItemText(IDC_MFCEDITBROWSE1, path_cstr);
	char* path_str;
	path_str = cstringTochar(path_cstr);

	HINSTANCE hInst;
	hInst = LoadLibrary(_T("IniDll.dll"));
	typedef int(*Getsec_num)(char* path_str);
	Getsec_num getsec_num = (Getsec_num)GetProcAddress(hInst, "GetSections_num");
	int num = getsec_num(path_str);

	char* sec_set;
	typedef char*(*Getsec)(char* path_str, int num);
	Getsec getsec = (Getsec)GetProcAddress(hInst, "GetSections");
	for (int i = 1; i < num + 1; i++) {
		sec_set = getsec(path_str, i);
		CString value_cstr_tmp(sec_set);
		m_combo_sec.AddString(value_cstr_tmp);
		//m_combo.SetCurSel(0);
	}
	m_combo_sec.SetCurSel(-1);
	FreeLibrary(hInst);
	//SetDlgItemText(key, path_cstr);
}


void CTestDllDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	//CString strPre, strNew;
	////GetDlgItem(IDC_COMBO1)->GetWindowTextW(m_paramname);//改变前的文本
	////SetDlgItemText(path, m_paramname);
	//int nSel = m_combo.GetCurSel();
	//m_combo.GetLBText(nSel, strNew);
	////SetDlgItemText(path, strNew);
	////m_combo.GetWindowText(strPre);
	//if (!strNew.CompareNoCase(L"Query")) {
	//	SetDlgItemText(value, strNew);
	//	//query_page.DoModal();
	//	//query_page.ChangeProc(GetDlgItem(IDC_COMBO1)->GetSafeHwnd());
	//}
	GetDlgItem(value)->EnableWindow(TRUE);
	CString strNew_change;
	int nSel_change = m_combo.GetCurSel();
	m_combo.GetLBText(nSel_change, strNew_change);
	if (!strNew_change.CompareNoCase(L"Query")) {
		GetDlgItem(value)->EnableWindow(FALSE);
	}
}


void CTestDllDlg::OnCbnSetfocusCombo1()
{
	 //TODO: Add your control notification handler code here
	//m_combo.ResetContent();//清空所有ComboBox的项目
	//m_combo.AddString(L"Add");
	//m_combo.AddString(L"Delete");
	//m_combo.AddString(L"Update");
	//m_combo.AddString(L"Query");

	//int nSel = m_combo.GetCurSel();
	//m_combo.SetCurSel(nSel);
}


void CTestDllDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString strNew;
	int nSel = m_combo.GetCurSel();
	m_combo.GetLBText(nSel, strNew);

	CString path_cstr, sec_cstr, key_cstr, value_cstr;
	char* path_str;
	char* sec_str;
	char* key_str;
	//GetDlgItemText(path, path_cstr);//获取指定ID的编辑框内容
	GetDlgItemText(IDC_MFCEDITBROWSE1, path_cstr);
	if (!strNew.CompareNoCase(L"Query")) {
		int nSel_sec = m_combo_sec.GetCurSel();
		m_combo_sec.GetLBText(nSel_sec, sec_cstr);
	}
	else {
		m_combo_sec.GetWindowText(sec_cstr);
	}
	//GetDlgItemText(section, sec_cstr);//获取指定ID的编辑框内容
	GetDlgItemText(key, key_cstr);//获取指定ID的编辑框内容
	path_str = cstringTochar(path_cstr);
	sec_str = cstringTochar(sec_cstr);
	key_str = cstringTochar(key_cstr);

	if (!strNew.CompareNoCase(L"Query")) {
		GetDlgItem(value)->EnableWindow(TRUE);
		//SetDlgItemText(value, strNew);
		HINSTANCE hInst;
		hInst = LoadLibrary(L"IniDll.dll");
		typedef char*(*Read)(char* sec_str, char* key_str, char* path_str);
		Read read_string = (Read)GetProcAddress(hInst, "Ini_Read");
		//Read read_string = (Read)GetProcAddress(hInst, (LPCSTR)MAKEINTRESOURCE(2));
		char* a = read_string(sec_str, key_str, path_str);
		//char* a = Ini_Read(sec_str, key_str, path_str);
		CString value_cstr_tmp(a);

		SetDlgItemText(value, value_cstr_tmp);

		//SetDlgItemText(result, L"查询成功");//获取指定ID的编辑框内容
		FreeLibrary(hInst);
		AfxMessageBox(_T("查询成功！"));
		GetDlgItem(value)->EnableWindow(FALSE);
	}
	else if (!strNew.CompareNoCase(L"Add")) {
		GetDlgItemText(value, value_cstr);
		char* value_str = new char[1024];
		value_str = cstringTochar(value_cstr);

		HINSTANCE hInst;
		hInst = LoadLibrary(_T("IniDll.dll"));
		typedef void(*Write)(char* sec_str, char* key_str, char* value_str, char* path_str);
		Write write = (Write)GetProcAddress(hInst, "Ini_Write");
		write(sec_str, key_str, value_str, path_str);
		//SetDlgItemText(result, L"添加成功");//获取指定ID的编辑框内容
		FreeLibrary(hInst);
		AfxMessageBox(_T("添加成功！"));
	}
	else if (!strNew.CompareNoCase(L"Update")) {
		GetDlgItemText(value, value_cstr);
		char* value_str = new char[1024];
		value_str = cstringTochar(value_cstr);

		HINSTANCE hInst;
		hInst = LoadLibrary(_T("IniDll.dll"));
		typedef void(*Write)(char* sec_str, char* key_str, char* value_str, char* path_str);
		Write write = (Write)GetProcAddress(hInst, "Ini_Write");
		write(sec_str, key_str, value_str, path_str);
		//SetDlgItemText(result, L"修改成功");//获取指定ID的编辑框内容
		FreeLibrary(hInst);
		AfxMessageBox(_T("修改成功！"));
	}
	else if (!strNew.CompareNoCase(L"Delete")) {
		//GetDlgItemText(value, value_cstr);
		//char* value_str = new char[1024];
		//value_str = cstringTochar(value_cstr);


		if (!key_cstr.CompareNoCase(L"")) {
			HINSTANCE hInst;
			hInst = LoadLibrary(_T("IniDll.dll"));
			typedef void(*Del_Sec)(char* sec_str, char* path_str);
			Del_Sec del_sec = (Del_Sec)GetProcAddress(hInst, "Ini_Del_Sec");
			del_sec(sec_str, path_str);
			FreeLibrary(hInst);
			AfxMessageBox(_T("删除成功！"));
		}
		else {
			HINSTANCE hInst;
			hInst = LoadLibrary(_T("IniDll.dll"));
			typedef void(*Del_Key)(char* sec_str, char* key_str, char* path_str);
			Del_Key del_key = (Del_Key)GetProcAddress(hInst, "Ini_Del_Key");
			del_key(sec_str, key_str, path_str);
			FreeLibrary(hInst);
			AfxMessageBox(_T("删除成功！"));
		}
	}

}


void CTestDllDlg::OnStnClickedresult()
{
	// TODO: Add your control notification handler code here
}


void CTestDllDlg::OnBnClickedclear()
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_MFCEDITBROWSE1, L"");
	m_combo_sec.ResetContent();//清空所有ComboBox的项目
	SetDlgItemText(key, L"");
	SetDlgItemText(value, L"");
	SetDlgItemText(result, L"");
}


void CTestDllDlg::OnBnClickedbutton()
{
	// TODO: Add your control notification handler code here
}


void CTestDllDlg::OnCbnSetfocusCombo2()
{
	// TODO: Add your control notification handler code here
}


void CTestDllDlg::OnBnClickedButtonClose()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}


HBRUSH CTestDllDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here

	// TODO:  Return a different brush if the default is not desired

	if (pWnd == this)
	{
		return m_brush;
	}


	if (pWnd->GetDlgCtrlID() == (IDC_STATIC_TITLE))
	{
		//MessageBox(_T("static text"));
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 251, 240));
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}

	if (pWnd->GetDlgCtrlID() == (IDC_STATIC))
	{
		//MessageBox(_T("static text"));
		pDC->SetBkMode(TRANSPARENT);
		//pDC->SetTextColor(RGB(0, 225, 225));
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}

	return hbr;
}


void CTestDllDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: Add your message handler code here and/or call default

	////获得button标题 
	//CString btnCaption = _T("Dialog");
	//CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);

	CString btnCaption = L"";
	//设置标题
	switch (lpDrawItemStruct->CtlID)
	{
	case OK:
		btnCaption = "OK";
		break;
	case clear:
		btnCaption = "Clear";
		break;
	default:
		;
	}
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);

	CRect drawRect;
	//获得绘图DC
	//得到原Button的矩形大小
	drawRect.CopyRect(&(lpDrawItemStruct->rcItem));
	//绘制控件框架 
	pDC->DrawFrameControl(&drawRect, DFC_BUTTON, lpDrawItemStruct->CtlType);


	//创建画刷
	CBrush pBrush;
	//pBrush.CreateSolidBrush(RGB(100, 130, 10));
	pBrush.CreateSolidBrush(RGB(0, 128, 255));
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

	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);

	//CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
}


void CTestDllDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	ReleaseCapture();

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CTestDllDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	SetCapture();

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CTestDllDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	static CPoint PrePoint = CPoint(0, 0);
	if (MK_LBUTTON == nFlags)
	{
		if (point != PrePoint)
		{
			CPoint ptTemp = point - PrePoint;
			CRect rcWindow;
			GetWindowRect(&rcWindow);
			rcWindow.OffsetRect(ptTemp.x, ptTemp.y);
			MoveWindow(&rcWindow);
			return;
		}
	}
	PrePoint = point;

	CDialogEx::OnMouseMove(nFlags, point);
}


void CTestDllDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	//CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}
