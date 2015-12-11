# FoodManage_System

//made by:计科1201，田嘉蕊，04121031（30）

FoodBevManage.cpp---->实现数据库连接，将VC++6.0与sql server2000进行连接。

FoodBevManageDlg.cpp---->实现登陆功能，程序启动后，用户执行“用户登陆”命令，在弹出的窗口中输用户名和密码，单击“登陆”按钮，系统会根据登陆用户的权限激活相关的系统功能。

Logindlg.cpp---->实现登陆用户的验证，在登陆对话框类CLogindlg的“登陆”按钮响应函数OnOK中实现，根据用户输入的用户名和密码，从

LoginInfo表中进行查询，若查询结果记录集为空，则表明登陆失败。若查询结果记录集不为空，则表明登陆成功，保存用户名和密码到CMyApp类对象。
