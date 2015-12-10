// FoodBevManage.cpp
//计科1201,田嘉蕊，04121031（30）数据库连接模块

#include "stdafx.h"
#include "FoodBevManage.h"
#include "FoodBevManageDlg.h"
#include ".\skins\SkinPlusPlus.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


BEGIN_MESSAGE_MAP(CMyApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


CMyApp::CMyApp()
{
}


CMyApp theApp;


BOOL CMyApp::InitInstance()
{
	AfxEnableControlContainer();
	::CoInitialize(NULL);
	InitializeSkin(_T("XPCorona.ssk"));
	HRESULT hr;
	try
	{
		hr=m_pCon.CreateInstance("ADODB.Connection");
		if(SUCCEEDED(hr))
		{
			m_pCon->ConnectionTimeout=5;
			hr=m_pCon->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=FoodBevMag.mdb","sa","ZuiAiZaiZai128",adModeUnknown);
			//hr=m_pCon->Open("driver={SQLServer};Server=FZ161-47;DATABASE=FoodBevMag;UID=sa;","","",adModeUnknown);
			//hr=m_pCon->Open("Provider=SQLOLEDB.1;Server=FZ161-47;DATABASE=FoodBevMag;UID=sa;PWD=ZuiAiZaiZai128;","","",adModeUnknown);
			//hr=m_pCon->Open("driver={SQL Server};Server=2012-20120725MJ\\SQLSERVER2005;Database=FoodBevMag;UID=sa;PWD=ZuiAiZaiZai128","","",adModeUnknown);
			hr=m_pCon->Open("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=FoodBevMag;Data Source=2012-20120725MJ","sa","ZuiAiZaiZai128",NULL);
		}
	}
	catch(_com_error e)
	{
		CString temp;
		temp.Format("连接数据库错误信息:%s",e.ErrorMessage());
		::MessageBox(NULL,temp,"提示信息",NULL);
		return false;
	}
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CMyDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	return FALSE;
}
