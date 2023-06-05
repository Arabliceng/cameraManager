// cameraDlg.cpp : implementation file
//

#include "stdafx.h"
#include "camera.h"
#include "cameraDlg.h"

#include <SetupAPI.h>
#include <devguid.h>
#ifdef _DEBUG
#define WM_TASKBAR  WM_APP+450
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCameraDlg dialog

CCameraDlg::CCameraDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCameraDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCameraDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCameraDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCameraDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCameraDlg, CDialog)
	//{{AFX_MSG_MAP(CCameraDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
		ON_COMMAND(cam_enable,enablecamera)
			ON_COMMAND(cam_disable,disablecamera)
				ON_COMMAND(id_show,show)
				ON_COMMAND(id_hide,hide)
				ON_COMMAND(id_exit,exitw)
				ON_COMMAND(id_about,showinfo)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
		ON_MESSAGE(WM_TASKBAR,OnTaskbar)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCameraDlg message handlers

BOOL CCameraDlg::OnInitDialog()
{ 
	CDialog::OnInitDialog();
c=0;
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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

	settrayicon();
		

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCameraDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCameraDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
	if(c==0)
	{ShowWindow(0);}

		
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCameraDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCameraDlg::OnOK() 
{ //hide program window

	ShowWindow(0);


}





LRESULT	 CCameraDlg::OnTaskbar(WPARAM wParam, LPARAM lParam)

{//handle mouse buttons clicks

	UINT uMouseMsg = (UINT) lParam;
int wmId, wmEvent;
		
	switch (uMouseMsg)

	{
		case WM_LBUTTONDOWN: 
			{
				::ShowWindow(hw,SW_SHOW);
			if(hw==NULL)
			{	AfxMessageBox("Mouse ");
			break;
			}
			else
			{	
			::ShowWindow(hw,SW_SHOW);
			
							 break;
			}
			}
				case WM_RBUTTONDOWN: 
					{
				
		
			showmen();
			break;
					}

	
	}
		
	return 0;

}


void CCameraDlg::showmen()
{ //show menu when click mouse right button
CPoint pt;
	GetCursorPos(&pt);

 
   
      CMenu menu;
      if (menu.LoadMenu(IDR_MENU1))
      {
         CMenu* pPopup = menu.GetSubMenu(0);
         ASSERT(pPopup != NULL);

         pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
            pt.x, pt.y,
            AfxGetMainWnd()); // use main window for cmds
		  
		 int uu=pPopup->GetMenuItemID(0);
		 CString sd,fg;
		 sd.Format("%d",uu);
			
int dd= pPopup->GetMenuState(uu,1);
pPopup->GetMenuString(uu,(char *)sd.operator LPCTSTR(),59,2);
 
			 
  pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
            pt.x, pt.y,
            AfxGetMainWnd());
 

      }



}
void  CCameraDlg::show() 
{
	c=1;
	ShowWindow(1);
	//show program window
}
void  CCameraDlg::hide() 
{
	ShowWindow(0);
}
void  CCameraDlg::exitw() 
{
	exit(1);
}
void  CCameraDlg::disablecamera() 
{
//	disable camera by disconnect camera driver



	/////////////////////////////////


static GUID id= {0xca3e7ab9,0xb4c3,0x4ae6,0x82,0x51,0x57,0x9e,0xf9,0x33,0x89,0x0f}; //camera GUID

    HDEVINFO hDevInfo = SetupDiGetClassDevs(&id, NULL, NULL, DIGCF_PRESENT   );
   
    if (hDevInfo == INVALID_HANDLE_VALUE)
    {
         MessageBox("error","device");
       
    }
   
    SP_DEVINFO_DATA devInfoData;
    devInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
   
    for (DWORD i = 0; SetupDiEnumDeviceInfo(hDevInfo, i, &devInfoData); ++i)

    {

/////////////////////////////////////////////////////////////////////////////////////

 DWORD DataT;
        char friendly_name[2046] = { 0 };
        DWORD buffersize = 2046;
        DWORD req_bufsize = 0;
 char friendly_name1[2046] = { 0 };

CString ct = _T("Camera");
        // get device description information
        if (!SetupDiGetDeviceRegistryPropertyA(hDevInfo, &devInfoData,SPDRP_CLASS, &DataT, (PBYTE)friendly_name, buffersize, &req_bufsize))
        {
           
            continue;
        }

      if(ct==_T(friendly_name))
	  {
		  //MessageBox(friendly_name,"device");
	


	  }
          
    




////////////////////////////////////////////////////////////////////////////////////
        DWORD propertyType;
        DWORD requiredSize;
       
 
      
        {
            // Disable the webcam by disabling the device
			SP_PROPCHANGE_PARAMS param;
param.ClassInstallHeader.cbSize = sizeof(SP_CLASSINSTALL_HEADER);
param.ClassInstallHeader.InstallFunction = DIF_PROPERTYCHANGE;
param.Scope = DICS_FLAG_GLOBAL;
param.StateChange = DICS_DISABLE; //diable value

//
            if (!SetupDiSetClassInstallParams(hDevInfo, &devInfoData, (SP_CLASSINSTALL_HEADER
*)(&param),sizeof(param)))
            { MessageBox("1","device");
                // Error handling
                continue;
            }
           SetupDiChangeState(hDevInfo, &devInfoData);
		   CString cc;
cc.Format(_T("%d"), DIF_PROPERTYCHANGE);
            if (!SetupDiCallClassInstaller(DIF_PROPERTYCHANGE, hDevInfo, &devInfoData))
            {
				//MessageBox(cc,"device");
                // Error handling
                continue;
            }
           //MessageBox("444","device");
           
            break;
        }
    }
   
    SetupDiDestroyDeviceInfoList(hDevInfo);












MessageBox("camera is disabled","Camera Status");



	////////////////////////////////////////////
}
void  CCameraDlg::enablecamera() 
{
//	ShowWindow(1);



	//////////////////////////////////////////////////////////////////////////////////////



static GUID id= {0xca3e7ab9,0xb4c3,0x4ae6,0x82,0x51,0x57,0x9e,0xf9,0x33,0x89,0x0f}; //camera GUID

    HDEVINFO hDevInfo = SetupDiGetClassDevs(&id, NULL, NULL, DIGCF_PRESENT   );
   
    if (hDevInfo == INVALID_HANDLE_VALUE)
    {
         MessageBox("error","device");
       
    }
   
    SP_DEVINFO_DATA devInfoData;
    devInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
   
    for (DWORD i = 0; SetupDiEnumDeviceInfo(hDevInfo, i, &devInfoData); ++i)

    {

/////////////////////////////////////////////////////////////////////////////////////

 DWORD DataT;
        char friendly_name[2046] = { 0 };
        DWORD buffersize = 2046;
        DWORD req_bufsize = 0;
 char friendly_name1[2046] = { 0 };

CString ct = _T("Camera");
        // get device description information
        if (!SetupDiGetDeviceRegistryPropertyA(hDevInfo, &devInfoData,SPDRP_CLASS, &DataT, (PBYTE)friendly_name, buffersize, &req_bufsize))
        {
           
            continue;
        }

      if(ct==_T(friendly_name))
	  {
		  //MessageBox(friendly_name,"device");
	

	  }
          
    




////////////////////////////////////////////////////////////////////////////////////
        DWORD propertyType;
        DWORD requiredSize;
     
        {
            
			SP_PROPCHANGE_PARAMS param;
param.ClassInstallHeader.cbSize = sizeof(SP_CLASSINSTALL_HEADER);
param.ClassInstallHeader.InstallFunction = DIF_PROPERTYCHANGE;
param.Scope = DICS_FLAG_GLOBAL;
param.StateChange = DICS_ENABLE; //Enable value

//
            if (!SetupDiSetClassInstallParams(hDevInfo, &devInfoData, (SP_CLASSINSTALL_HEADER
*)(&param),sizeof(param)))
            { MessageBox("1","device");
                // Error handling
                continue;
            }
           SetupDiChangeState(hDevInfo, &devInfoData);
		   CString cc;
cc.Format(_T("%d"), DIF_PROPERTYCHANGE);
            if (!SetupDiCallClassInstaller(DIF_PROPERTYCHANGE, hDevInfo, &devInfoData))
            {
				
                // Error handling
                continue;
            }
           MessageBox("444","device");
          
            break;
        }
    }
   
    SetupDiDestroyDeviceInfoList(hDevInfo);














MessageBox("camera is enabled","Camera Status");











	//////////////////////////////////////////////////////////////////////////
}
void  CCameraDlg::settrayicon()

{




HICON hIcon;
	
	// text for tool tip
	
	char lpszTip[] = "This Program by AHMAD KASSEM ";
	
	HINSTANCE hInst = AfxFindResourceHandle(MAKEINTRESOURCE(IDR_MAINFRAME),RT_GROUP_ICON);
				
	hIcon = (HICON)LoadImage(hInst,MAKEINTRESOURCE(IDR_MAINFRAME),IMAGE_ICON,100,100,LR_DEFAULTCOLOR);
    	
	// set NOTIFYCONDATA structure	
	
	NOTIFYICONDATA tnid; 
 
    tnid.cbSize = sizeof(NOTIFYICONDATA); 
    tnid.hWnd = m_hWnd; 
    tnid.uID = IDR_MAINFRAME; 
    tnid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP; 
    tnid.uCallbackMessage = WM_TASKBAR; // reaction for click over program's icon
    tnid.hIcon = hIcon; 
    			
	if (lpszTip) 
        lstrcpyn(tnid.szTip, lpszTip, sizeof(tnid.szTip)); 
    else 
        tnid.szTip[0] = '\0'; 
 
    ////////////////////////////////////////////////////////////////	  

	// call to Shell_NotifyIcon with NIM_ADD parameter
	
	Shell_NotifyIcon(NIM_ADD, &tnid); 
 
    // free icon 
	
	if (hIcon) 
        DestroyIcon(hIcon); 







}

void CAboutDlg::OnButton1() 
{
	ShellAbout(NULL," Camera Manager Program","Ahmad Kassem \n Email : neteng.ahmadkassem@gmail",AfxGetApp()->LoadIcon(IDI_ICON2));	
		
}

void CCameraDlg::OnCancel() 
{
exit(0);
}

void CCameraDlg::OnButton1() 
{
enablecamera();
	
}

void CCameraDlg::OnButton2() 
{//getac();
	disablecamera();
	
}
void CCameraDlg::showinfo() 
{
ShellAbout(NULL," Camera Manager Program","Ahmad Kassem \n Email : neteng.ahmadkassem@gmail",AfxGetApp()->LoadIcon(IDI_ICON2));	
		

}
/*
void CCameraDlg::OnButton3() 
{
	disablemic();

	
}




void  CCameraDlg::disablemic() 
{



static GUID id= {0xc166523c,0xfe0c,0x4a94,0xa5,0x86,0xf1,0xa8,0x0c,0xfb,0xbf,0x3e};//microphone GUID

    HDEVINFO hDevInfo = SetupDiGetClassDevs(&id, NULL, NULL, DIGCF_PRESENT   );
   
    if (hDevInfo == INVALID_HANDLE_VALUE)
    {
         MessageBox("error","device");
       
    }
   
    SP_DEVINFO_DATA devInfoData;
    devInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
   
    for (DWORD i = 0; SetupDiEnumDeviceInfo(hDevInfo, i, &devInfoData); ++i)

    {

/////////////////////////////////////////////////////////////////////////////////////

 DWORD DataT;
        char friendly_name[2046] = { 0 };
        DWORD buffersize = 2046;
        DWORD req_bufsize = 0;
 char friendly_name1[2046] = { 0 };

CString ct = _T("Camera");
        // get device description information
        if (!SetupDiGetDeviceRegistryPropertyA(hDevInfo, &devInfoData,SPDRP_CLASS, &DataT, (PBYTE)friendly_name, buffersize, &req_bufsize))
        {
           
            continue;
        }

      if(ct==_T(friendly_name))
	  {
	
	  }
          
    




////////////////////////////////////////////////////////////////////////////////////
        DWORD propertyType;
        DWORD requiredSize;
      
      
        {
           
			SP_PROPCHANGE_PARAMS param;
param.ClassInstallHeader.cbSize = sizeof(SP_CLASSINSTALL_HEADER);
param.ClassInstallHeader.InstallFunction = DIF_PROPERTYCHANGE;
param.Scope = DICS_FLAG_GLOBAL;
param.StateChange = DICS_DISABLE; 

//
            if (!SetupDiSetClassInstallParams(hDevInfo, &devInfoData, (SP_CLASSINSTALL_HEADER*)(&param),sizeof(param)))
            { MessageBox("1","device");
                // Error handling
                continue;
            }
           SetupDiChangeState(hDevInfo, &devInfoData);
		   CString cc;
cc.Format(_T("%d"), DIF_PROPERTYCHANGE);
            if (!SetupDiCallClassInstaller(DIF_PROPERTYCHANGE, hDevInfo, &devInfoData))
            {
			
                continue;
            }
           MessageBox("444","device");
            
            break;
        }
    }
   
    SetupDiDestroyDeviceInfoList(hDevInfo);












MessageBox("Microphone  is disabled","Microphone Status");



	////////////////////////////////////////////
}


void  CCameraDlg::getac()


{

HANDLE hToken;
LUID seprivnameValue;
TOKEN_PRIVILEGES tp;

OpenProcessToken( GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES |TOKEN_QUERY, &hToken ) ;
//
// OpenProcessToken() failed
//

//
// Given a privilege's name SeDebugPrivilege, we should locate its local LUID mapping.
//
CString ss="SE_TCB_NAME";

LookupPrivilegeValue( NULL,SE_DEBUG_NAME, &tp.Privileges[0].Luid) ;

tp.PrivilegeCount = 1;
//tp.Privileges[0].Luid = seprivnameValue;
tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

AdjustTokenPrivileges( hToken, FALSE, &tp, 0, (PTOKEN_PRIVILEGES) NULL, 0 ) ;



}

*/


