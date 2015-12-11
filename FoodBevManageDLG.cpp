//made by:计科1201，田嘉蕊，04121031（30）
//FoodBevManageDLG.cpp中登陆系统部分的实现


void CMyDlg::OnMENUlogin() 
{
	
	CLogindlg Logindlg;//登录对话框对象	
	if(Logindlg.DoModal()==IDOK)//创建对话框
	{		
		CString Sql="select * from LoginInfo where Uname='"+theApp.name+"'";
		m_pRs=theApp.m_pCon->Execute((_bstr_t)Sql,NULL,adCmdText);//执行查询
		CString Str=(char*)(_bstr_t)m_pRs->GetCollect("power");//用户权限
		int radio=atoi(Str);//转换为整型
		if(radio==0)//经理
		{
			CMenu* pMenu=GetMenu();//获取菜单指针
			pMenu->GetSubMenu(1)->EnableMenuItem(0,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->EnableMenuItem(1,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(0,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(1,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(2,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(3)->EnableMenuItem(0,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(3)->EnableMenuItem(1,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->GetSubMenu(1)->EnableMenuItem(2,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->GetSubMenu(1)->EnableMenuItem(3,MF_BYPOSITION | MF_ENABLED );
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_kaitai,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_pay,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_rishouru,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_reg,true);	
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_add,true);
		}
		if(radio==1)//主管
		{
			CMenu* pMenu=GetMenu();//获取菜单指针
			pMenu->GetSubMenu(1)->EnableMenuItem(0,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->EnableMenuItem(1,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(0,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(1,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(2,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->GetSubMenu(1)->EnableMenuItem(2,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(1)->GetSubMenu(1)->EnableMenuItem(3,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(3)->EnableMenuItem(0,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(3)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED );
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_kaitai,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_pay,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_rishouru,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_reg,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_add,true);
		}
		if(radio==2)//值班员
		{
			CMenu* pMenu=GetMenu();//获取菜单指针
			pMenu->GetSubMenu(1)->EnableMenuItem(0,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(2)->EnableMenuItem(0,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(2)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(2)->EnableMenuItem(2,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(3)->EnableMenuItem(0,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(3)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED );
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_kaitai,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_pay,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_rishouru,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_reg,false);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_add,true);
		}
		m_Statusbar.SetPaneText(1,"当前用户:"+theApp.name);//设置状态栏窗格
		SetWindowText("FoodBevManage系统    当前登录用户:"+theApp.name);//设置对话框标题
		
	}	
	if(Logindlg.i==3)
		CDialog::OnCancel();//退出对话框
}
