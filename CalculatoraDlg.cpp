// CalculatoraDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Calculatora.h"
#include "CalculatoraDlg.h"
#include<stack>
#include <stdio.h>
#include <stdlib.h>
#include "Count.h"
#include<string>

#include<CString>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE

#endif

using namespace std;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog 
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCalculatoraDlg 对话框




CCalculatoraDlg::CCalculatoraDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalculatoraDlg::IDD, pParent)
	, m_show(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatoraDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_show);
}



BEGIN_MESSAGE_MAP(CCalculatoraDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_num1, &CCalculatoraDlg::OnBnClickednum1)
	ON_BN_CLICKED(IDC_num8, &CCalculatoraDlg::OnBnClickednum8)
	ON_BN_CLICKED(IDC_num0, &CCalculatoraDlg::OnBnClickednum0)
	ON_BN_CLICKED(IDC_num2, &CCalculatoraDlg::OnBnClickednum2)
	ON_BN_CLICKED(IDC_num3, &CCalculatoraDlg::OnBnClickednum3)
	ON_BN_CLICKED(IDC_num4, &CCalculatoraDlg::OnBnClickednum4)
	ON_BN_CLICKED(IDC_num5, &CCalculatoraDlg::OnBnClickednum5)
	ON_BN_CLICKED(IDC_num6, &CCalculatoraDlg::OnBnClickednum6)
	ON_BN_CLICKED(IDC_num7, &CCalculatoraDlg::OnBnClickednum7)
	ON_BN_CLICKED(IDC_num9, &CCalculatoraDlg::OnBnClickednum9)
	ON_BN_CLICKED(IDC_eaqual, &CCalculatoraDlg::OnBnClickedeaqual)
	ON_BN_CLICKED(IDC_add, &CCalculatoraDlg::OnBnClickedadd)
	ON_BN_CLICKED(IDC_abstact, &CCalculatoraDlg::OnBnClickedabstact)
	ON_BN_CLICKED(IDC_devide, &CCalculatoraDlg::OnBnClickeddevide)
	ON_BN_CLICKED(IDC_substact, &CCalculatoraDlg::OnBnClickedsubstact)
	ON_EN_CHANGE(IDC_EDIT1, &CCalculatoraDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_cubic, &CCalculatoraDlg::OnBnClickedcubic)
	ON_BN_CLICKED(IDC_delete, &CCalculatoraDlg::OnBnClickeddelete)
	ON_BN_CLICKED(IDC_clear, &CCalculatoraDlg::OnBnClickedclear)
	ON_BN_CLICKED(IDC_comma, &CCalculatoraDlg::OnBnClickedcomma)
	ON_BN_CLICKED(IDC_openP, &CCalculatoraDlg::OnBnClickedopenp)
	ON_BN_CLICKED(IDC_closedP, &CCalculatoraDlg::OnBnClickedclosedp)
	ON_BN_CLICKED(IDC_tan, &CCalculatoraDlg::OnBnClickedtan)
	ON_BN_CLICKED(IDC_cos, &CCalculatoraDlg::OnBnClickedcos)
	ON_BN_CLICKED(IDC_sin, &CCalculatoraDlg::OnBnClickedsin)
	ON_BN_CLICKED(IDC_log, &CCalculatoraDlg::OnBnClickedlog)
	ON_BN_CLICKED(IDC_ln, &CCalculatoraDlg::OnBnClickedln)
	ON_BN_CLICKED(IDC_pow, &CCalculatoraDlg::OnBnClickedpow)
	ON_BN_CLICKED(IDC_mod, &CCalculatoraDlg::OnBnClickedmod)
	ON_BN_CLICKED(IDC_fac, &CCalculatoraDlg::OnBnClickedfac)

	ON_BN_CLICKED(IDC_pi, &CCalculatoraDlg::OnBnClickedpi)
END_MESSAGE_MAP()


// CCalculatoraDlg 消息处理程序

BOOL CCalculatoraDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatoraDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatoraDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CCalculatoraDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
  


void CCalculatoraDlg::OnBnClickednum1()
{
	
	UpdateData(TRUE);
	if(m_show.GetLength()>=1)
	{
	char m_p;
	m_p = m_show.GetAt(m_show.GetLength()-1);
	  if(m_p == ')'||m_p =='!')
	  {
		m_show+="";
	  }
	  else
	  {
	    m_show+="1";
	  }
	}
	else
	{
		m_show+="1";
	}
	UpdateData(FALSE);//当上一次输入的是")"或者是"!"时，因此操作是错误的，所以不会读入m_show中，以下数字类似
}

void CCalculatoraDlg::OnBnClickednum8()
{
	// TODO: 在此添加控件通知处理程序代码
UpdateData(TRUE);
	if(m_show.GetLength()>=1)
	{
	char m_p;
	m_p = m_show.GetAt(m_show.GetLength()-1);
	  if(m_p == ')'||m_p =='!')
	  {
		m_show+="";
	  }
	  else
	  {
	    m_show+="8";
	  }
	}
	else
	{
		m_show+="8";
	}
	UpdateData(FALSE);
}

void CCalculatoraDlg::OnBnClickednum0()
{
	UpdateData(TRUE);
   if(m_show.GetLength()>=1)
	{
	char m_p;
	m_p = m_show.GetAt(m_show.GetLength()-1);
	  if(m_p == ')'||m_p =='!')
	  {
		m_show+="";
	  }
	  else
	  {
	    m_show+="0";
	  }
	}
	else
	{
		m_show+="0";
	}
	UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
}

void CCalculatoraDlg::OnBnClickednum2()
{
	// TODO: 在此添加控件通知处理程序代码
UpdateData(TRUE);
   if(m_show.GetLength()>=1)
	{
	char m_p;
	m_p = m_show.GetAt(m_show.GetLength()-1);
	  if(m_p == ')'||m_p =='!')
	  {
		m_show+="";
	  }
	  else
	  {
	    m_show+="2";
	  }
	}
	else
	{
		m_show+="2";
	}
	UpdateData(FALSE);
}

void CCalculatoraDlg::OnBnClickednum3()
{
	// TODO: 在此添加控件通知处理程序代码

   UpdateData(TRUE);
    if(m_show.GetLength()>=1)
	{
	char m_p;
	m_p = m_show.GetAt(m_show.GetLength()-1);
	  if(m_p == ')'||m_p =='!')
	  {
		m_show+="";
	  }
	  else
	  {
	    m_show+="3";
	  }
	}
	else
	{
		m_show+="3";
	}
	UpdateData(FALSE);
}

void CCalculatoraDlg::OnBnClickednum4()
{
	// TODO: 在此添加控件通知处理程序代码
    UpdateData(TRUE);
    if(m_show.GetLength()>=1)
	{
	char m_p;
	m_p = m_show.GetAt(m_show.GetLength()-1);
	  if(m_p == ')'||m_p =='!')
	  {
		m_show+="";
	  }
	  else
	  {
	    m_show+="4";
	  }
	}
	else
	{
		m_show+="4";
	}
	UpdateData(FALSE);
}

void CCalculatoraDlg::OnBnClickednum5()
{
	UpdateData(TRUE);
    if(m_show.GetLength()>=1)
	{
	char m_p;
	m_p = m_show.GetAt(m_show.GetLength()-1);
	  if(m_p == ')'||m_p =='!')
	  {
		m_show+="";
	  }
	  else
	  {
	    m_show+="5";
	  }
	}
	else
	{
		m_show+="5";
	}
	UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
}

void CCalculatoraDlg::OnBnClickednum6()
{
	UpdateData(TRUE);
    if(m_show.GetLength()>=1)
	{
	char m_p;
	m_p = m_show.GetAt(m_show.GetLength()-1);
	  if(m_p == ')'||m_p =='!')
	  {
		m_show+="";
	  }
	  else
	  {
	    m_show+="6";
	  }
	}
	else
	{
		m_show+="6";
	}
	UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
}

void CCalculatoraDlg::OnBnClickednum7()
{
	UpdateData(TRUE);
	  if(m_show.GetLength()>=1)
	{
	char m_p;
	m_p = m_show.GetAt(m_show.GetLength()-1);
	  if(m_p == ')'||m_p =='!')
	  {
		m_show+="";
	  }
	  else
	  {
	    m_show+="7";
	  }
	}
	else
	{
		m_show+="7";
	}
	UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
}

void CCalculatoraDlg::OnBnClickednum9()
{
	UpdateData(TRUE);
	 if(m_show.GetLength()>=1)
	{
	char m_p;
	m_p = m_show.GetAt(m_show.GetLength()-1);
	  if(m_p == ')'||m_p =='!')
	  {
		m_show+="";
	  }
	  else
	  {
	    m_show+="9";
	  }
	}
	else
	{
		m_show+="9";
	}
	UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
}

void CCalculatoraDlg::OnBnClickedeaqual()
{
	UpdateData(TRUE);
	CString m_reshow = m_show;
	if(m_reshow.GetAt(m_reshow.GetLength()-1)==' ')
	{
		m_show+="";
	}                                                  //如果最后输入的是运算符（但不是！）则是错误的操作，故不支持运算
	else
	{
	
	CCount mycalculator(m_show);                  //CCount 类的对象
	mycalculator.transform();
	double m_result = mycalculator.calculate();
	m_show.Format("%lf",m_result);   
	}
    UpdateData(FALSE);

	
	
	// TODO: 在此添加控件通知处理程序代码
}



void CCalculatoraDlg::OnBnClickedadd()
{
	UpdateData(TRUE);
		if(m_show.GetLength()>=1)   //不支持两个二元运算符连着输入，以下类似
		{	char m_pp;
		    m_pp = m_show.GetAt(m_show.GetLength()-1);
           if (m_pp == ' ')
	       {
		    m_show+="";
	       }
		   else
		   {
	         m_show+=" + ";
		   }
		}
		else
		{
			m_show+="";
		}
	UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
}

void CCalculatoraDlg::OnBnClickedabstact()
{
	UpdateData(TRUE);
	if(m_show.GetLength()>=1)
		{	char m_pp;
		    m_pp = m_show.GetAt(m_show.GetLength()-1);
           if (m_pp == ' ')
	       {
		    m_show+="";
	       }
		   else
		   {
	         m_show+=" - ";
		   }
		}
		else
		{
			m_show+="";
		}
	UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
}

	void CCalculatoraDlg::OnBnClickeddevide()
	{
		UpdateData(TRUE);
	    if(m_show.GetLength()>=1)
		{	char m_pp;
		    m_pp = m_show.GetAt(m_show.GetLength()-1);
           if (m_pp == ' ')
	       {
		    m_show+="";
	       }
		   else
		   {
	         m_show+=" / ";
		   }
		}
		else
		{
			m_show+="";
		}
	UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
	}

	void CCalculatoraDlg::OnBnClickedsubstact()
	{
		UpdateData(TRUE);

	  if(m_show.GetLength()>=1)
		{	char m_pp;
		    m_pp = m_show.GetAt(m_show.GetLength()-1);
           if (m_pp == ' ')
	       {
		    m_show+="";
	       }
		   else
		   {
	         m_show+=" * ";
		   }
		}
		else
		{
			m_show+="";
		}
		
		UpdateData(FALSE);
		
		// TODO: 在此添加控件通知处理程序代码
	}

	void CCalculatoraDlg::OnEnChangeEdit1()
	{
		// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
		// 发送该通知，除非重写 CDialog::OnInitDialog()
		// 函数并调用 CRichEditCtrl().SetEventMask()，
		// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

		// TODO:  在此添加控件通知处理程序代码
	}

	void CCalculatoraDlg::OnBnClickedcubic()
	{
		// TODO: 在此添加控件通知处理程序代码
	}
	

	void CCalculatoraDlg::OnBnClickeddelete()//对不同的字符串删除时，执行不同的动作
	{
		if(m_show.GetLength()>=2)
		{
		  char m_pp;
		  m_pp = m_show.GetAt(m_show.GetLength()-1);
		  if(m_pp ==')'||m_pp =='!')
		  {
            m_show.Delete(m_show.GetLength()-2,2);
		  }
		  else
		  {  
			  char m_p;
			  m_p = m_show.GetAt(m_show.GetLength()-2);
			  if(m_pp ==' ')
			  {
				  if(m_p=='('||m_p=='n'||m_p=='s'||m_p=='g')
				  {
					  if(m_p =='(')
				      {
					     m_show.Delete(m_show.GetLength()-2,2);
				       }
					  else
					  {
						  m_show.Delete(m_show.GetLength()-4,4);
					  }
				  }
				  else
				  {
					  m_show.Delete(m_show.GetLength()-3,3);
				  }
			  }
			  else
			  {
		          m_show.Delete(m_show.GetLength()-1,1);
			  }
		  }
		}
		else
		{
			m_show.Delete(m_show.GetLength()-1,1);
		}
		UpdateData(FALSE);                                 
		// TODO: 在此添加控件通知处理程序代码
	}

	void CCalculatoraDlg::OnBnClickedclear()//清除功能
	{
		UpdateData(TRUE);
		m_show="";
		UpdateData(FALSE);
		// TODO: 在此添加控件通知处理程序代码
	}

	void CCalculatoraDlg::OnBnClickedcomma()//当输入小数点时，判断上一次输入的字符串，不支持错误的操作
	{
		UpdateData(TRUE);
		CCount mycal(m_show);
		if(m_show.GetLength()>1)
		{	char m_pp;
		    m_pp = m_show.GetAt(m_show.GetLength()-2);
           if (m_pp == '+'||m_pp == '-'||m_pp == '*'||m_pp == '/'||m_pp=='^'||m_pp=='c'||m_pp=='s'||m_pp=='t'||m_pp=='l'||m_pp=='L'||m_pp=='%'||m_pp=='!'||m_pp=='('||m_pp==')')
	       {
		    m_show+="";
	       }
	      else
	      {
             char m_p;
              m_p = m_show.GetAt(m_show.GetLength()-1);
		      if (m_p == '.')
		      {
			    m_show+="";
		      }
		      else
		      {
				  if(mycal.Expression())
				  {
					  m_show+="";
				  }
				  else
				  {
	                m_show+=".";
				  }
		      }
	      }
		}
	else
	{
		if(m_show.GetLength()==0)
		{
			m_show+="";
		}
		else
		{
		   m_show+=".";
		}
	}

	    UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
	  
	}

	void CCalculatoraDlg::OnBnClickedopenp()//输入左括号时，判断上一次输入的字符串，是否输入是合理的，若是，则支持
	{
		UpdateData(TRUE);
       if(m_show.GetLength()>=1)
		{	char m_pp;
		    m_pp = m_show.GetAt(m_show.GetLength()-1);
           if (m_pp == ' ')
	       {
		    m_show+="( ";
	       }
		   else
		   {
	         m_show+="";
		   }
		}
		else
		{
			m_show+="( ";
		}
	    UpdateData(FALSE);
		// TODO: 在此添加控件通知处理程序代码
	}

	void CCalculatoraDlg::OnBnClickedclosedp()//输入右括号时，判断上一次输入的字符串，以及m_show中的左括号与右括号的数目，判断是否支持该操作，并执行相应的动作
	{
		UpdateData(TRUE);
         if(m_show.GetLength()>=1)
		{	char m_pp;
		    m_pp = m_show.GetAt(m_show.GetLength()-1);
           if (m_pp == ' ')
	       {
		    m_show+="";
	       }
		   else
		   {
			   CCount myc(m_show);
			   if(myc.Judge())
			   {
	              m_show+=" )";
			   }
			   else
			   {
				   m_show+="";
			   }
		   }
		}
		else
		{
			m_show+="";
		}
	    UpdateData(FALSE);
		// TODO: 在此添加控件通知处理程序代码
	}

	void CCalculatoraDlg::OnBnClickedtan()
	{
		UpdateData(TRUE);
        if(m_show.GetLength()>=1)
		{	char m_pp;
		    m_pp = m_show.GetAt(m_show.GetLength()-1);
           if (m_pp == ' ')
	       {
		    m_show+="tan ";
	       }
		   else
		   {
	         m_show+="";
		   }
		}
		else
		{
			m_show+="tan ";
		}
	   
	    UpdateData(FALSE);

		// TODO: 在此添加控件通知处理程序代码
	}

	void CCalculatoraDlg::OnBnClickedcos()
	{
		UpdateData(TRUE);
		  if(m_show.GetLength()>=1)
		{	char m_pp;
		    m_pp = m_show.GetAt(m_show.GetLength()-1);
           if (m_pp == ' ')
	       {
		    m_show+="cos ";
	       }
		   else
		   {
	         m_show+="";
		   }
		}
		else
		{
			m_show+="cos ";
		}
	    
	    UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
	}

	void CCalculatoraDlg::OnBnClickedsin()
	{
		UpdateData(TRUE);  
         if(m_show.GetLength()>=1)
		{	char m_pp;
		    m_pp = m_show.GetAt(m_show.GetLength()-1);
           if (m_pp == ' ')
	       {
		    m_show+="sin ";
	       }
		   else
		   {
	         m_show+="";
		   }
		}
		else
		{
			m_show+="sin ";
		}
	    UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
	}

	void CCalculatoraDlg::OnBnClickedlog()
	{
		UpdateData(TRUE);  
          if(m_show.GetLength()>=1)
		{	char m_pp;
		    m_pp = m_show.GetAt(m_show.GetLength()-1);
           if (m_pp == ' ')
	       {
		    m_show+="log ";
	       }
		   else
		   {
	         m_show+="";
		   }
		}
		else
		{
			m_show+="log ";
		}
	    
	    UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
	}

	void CCalculatoraDlg::OnBnClickedln()
	{
		UpdateData(TRUE);
         if(m_show.GetLength()>=1)
		{	char m_pp;
		    m_pp = m_show.GetAt(m_show.GetLength()-1);
           if (m_pp == ' ')
	       {
		    m_show+="Ln ";
	       }
		   else
		   {
	         m_show+="";
		   }
		}
		else
		{
			m_show+="Ln ";
		}
	    
	    UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
	}

	void CCalculatoraDlg::OnBnClickedpow()
	{
		UpdateData(TRUE);
        if(m_show.GetLength()>=1)
		{	char m_pp;
		    m_pp = m_show.GetAt(m_show.GetLength()-1);
           if (m_pp == ' ')
	       {
		    m_show+="";
	       }
		   else
		   {
			   m_show+=" ^ ";
		   }
		}
		else
		{
			m_show+="";
		}
	 
	    UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
	}

	void CCalculatoraDlg::OnBnClickedmod()
	{
		UpdateData(TRUE);
        if(m_show.GetLength()>=1)
		{	char m_pp;
		    m_pp = m_show.GetAt(m_show.GetLength()-1);
           if (m_pp == ' ')
	       {
		    m_show+="";
	       }
		   else
		   {
	         m_show+=" % ";
		   }
		}
		else
		{
			m_show+="";
		}
	    
	    UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
	}

	void CCalculatoraDlg::OnBnClickedfac()
	{
		UpdateData(TRUE);
        if(m_show.GetLength()>=1)
		{	char m_pp;
		    m_pp = m_show.GetAt(m_show.GetLength()-1);
           if (m_pp == ' ')
	       {
		    m_show+="";
	       }
		   else
		   {
	         m_show+=" !";
		   }
		}
		else
		{
			m_show+="";
		}
	    
	    UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
	}

	

	void CCalculatoraDlg::OnBnClickedpi()
	{
		UpdateData(TRUE);
   if(m_show.GetLength()>=1)
	{
	   char m_p;
	   m_p = m_show.GetAt(m_show.GetLength()-1);
	    if(m_p == ')'||m_p =='!')
	     {
		   m_show+="";
	      }
	    else
	    {
	      m_show+="π";
	     }
	}
	else
	{
		m_show+="π";
	}
	UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
	}
