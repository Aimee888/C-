
// TestDllDlg.h : header file
//

#pragma once


// CTestDllDlg dialog
class CTestDllDlg : public CDialogEx
{
// Construction
public:
	CTestDllDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTDLL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangepath();
	afx_msg void OnEnChangeMfceditbrowse1();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox m_combo;
	afx_msg void OnCbnSetfocusCombo1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnStnClickedresult();
	afx_msg void OnBnClickedclear();
	afx_msg void OnBnClickedbutton();
	CComboBox m_combo_sec;
	afx_msg void OnCbnSetfocusCombo2();
	afx_msg void OnBnClickedButtonClose();
	CButton m_btnClose;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
protected:
	CBrush m_brush;
public:
	CFont newFont;
	CStatic static_title;
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
