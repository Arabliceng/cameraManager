// cameraDlg.h : header file
//

#if !defined(AFX_CAMERADLG_H__C38452FC_5EB1_464B_B31C_66C5562722BE__INCLUDED_)
#define AFX_CAMERADLG_H__C38452FC_5EB1_464B_B31C_66C5562722BE__INCLUDED_
#define WM_TASKBAR  WM_APP+450
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCameraDlg dialog

class CCameraDlg : public CDialog
{
// Construction
public:
	CCameraDlg(CWnd* pParent = NULL);	// standard constructor
LRESULT	CCameraDlg::OnTaskbar(WPARAM wParam, LPARAM lParam);
void showmen();
HWND hw;
int c;
// Dialog Data
	//{{AFX_DATA(CCameraDlg)
	enum { IDD = IDD_CAMERA_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCameraDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCameraDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
		afx_msg void enablecamera();
			afx_msg void disablecamera();
			afx_msg void disablemic();
			afx_msg void show();
			afx_msg void hide();
			afx_msg void exitw();
			afx_msg void showinfo();
			afx_msg void settrayicon();
			//	afx_msg void getac();
	virtual void OnCancel();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMERADLG_H__C38452FC_5EB1_464B_B31C_66C5562722BE__INCLUDED_)
