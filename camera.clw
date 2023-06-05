; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCameraDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "camera.h"

ClassCount=4
Class1=CCameraApp
Class2=CCameraDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CAMERA_DIALOG
Resource4=IDR_MENU1

[CLS:CCameraApp]
Type=0
HeaderFile=camera.h
ImplementationFile=camera.cpp
Filter=N

[CLS:CCameraDlg]
Type=0
HeaderFile=cameraDlg.h
ImplementationFile=cameraDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=cameraDlg.h
ImplementationFile=cameraDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_BUTTON1,button,1342242816

[DLG:IDD_CAMERA_DIALOG]
Type=1
Class=CCameraDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=cam_enable
Command2=cam_disable
Command3=id_show
Command4=id_hide
Command5=id_about
Command6=id_exit
CommandCount=6

