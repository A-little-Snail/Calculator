// CalculatoraDlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog 
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CCalculatoraDlg �Ի���




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


// CCalculatoraDlg ��Ϣ�������

BOOL CCalculatoraDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCalculatoraDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
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
	UpdateData(FALSE);//����һ���������")"������"!"ʱ����˲����Ǵ���ģ����Բ������m_show�У�������������
}

void CCalculatoraDlg::OnBnClickednum8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	UpdateData(FALSE);// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CCalculatoraDlg::OnBnClickednum2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������

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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	UpdateData(FALSE);// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	UpdateData(FALSE);// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	UpdateData(FALSE);// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	UpdateData(FALSE);// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CCalculatoraDlg::OnBnClickedeaqual()
{
	UpdateData(TRUE);
	CString m_reshow = m_show;
	if(m_reshow.GetAt(m_reshow.GetLength()-1)==' ')
	{
		m_show+="";
	}                                                  //�������������������������ǣ������Ǵ���Ĳ������ʲ�֧������
	else
	{
	
	CCount mycalculator(m_show);                  //CCount ��Ķ���
	mycalculator.transform();
	double m_result = mycalculator.calculate();
	m_show.Format("%lf",m_result);   
	}
    UpdateData(FALSE);

	
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}



void CCalculatoraDlg::OnBnClickedadd()
{
	UpdateData(TRUE);
		if(m_show.GetLength()>=1)   //��֧��������Ԫ������������룬��������
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
	UpdateData(FALSE);// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	UpdateData(FALSE);// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	UpdateData(FALSE);// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		
		// TODO: �ڴ���ӿؼ�֪ͨ����������
	}

	void CCalculatoraDlg::OnEnChangeEdit1()
	{
		// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
		// ���͸�֪ͨ��������д CDialog::OnInitDialog()
		// ���������� CRichEditCtrl().SetEventMask()��
		// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

		// TODO:  �ڴ���ӿؼ�֪ͨ����������
	}

	void CCalculatoraDlg::OnBnClickedcubic()
	{
		// TODO: �ڴ���ӿؼ�֪ͨ����������
	}
	

	void CCalculatoraDlg::OnBnClickeddelete()//�Բ�ͬ���ַ���ɾ��ʱ��ִ�в�ͬ�Ķ���
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
		// TODO: �ڴ���ӿؼ�֪ͨ����������
	}

	void CCalculatoraDlg::OnBnClickedclear()//�������
	{
		UpdateData(TRUE);
		m_show="";
		UpdateData(FALSE);
		// TODO: �ڴ���ӿؼ�֪ͨ����������
	}

	void CCalculatoraDlg::OnBnClickedcomma()//������С����ʱ���ж���һ��������ַ�������֧�ִ���Ĳ���
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

	    UpdateData(FALSE);// TODO: �ڴ���ӿؼ�֪ͨ����������
	  
	}

	void CCalculatoraDlg::OnBnClickedopenp()//����������ʱ���ж���һ��������ַ������Ƿ������Ǻ���ģ����ǣ���֧��
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
		// TODO: �ڴ���ӿؼ�֪ͨ����������
	}

	void CCalculatoraDlg::OnBnClickedclosedp()//����������ʱ���ж���һ��������ַ������Լ�m_show�е��������������ŵ���Ŀ���ж��Ƿ�֧�ָò�������ִ����Ӧ�Ķ���
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
		// TODO: �ڴ���ӿؼ�֪ͨ����������
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

		// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	    
	    UpdateData(FALSE);// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	    UpdateData(FALSE);// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	    
	    UpdateData(FALSE);// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	    
	    UpdateData(FALSE);// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	 
	    UpdateData(FALSE);// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	    
	    UpdateData(FALSE);// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	    
	    UpdateData(FALSE);// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	      m_show+="��";
	     }
	}
	else
	{
		m_show+="��";
	}
	UpdateData(FALSE);// TODO: �ڴ���ӿؼ�֪ͨ����������
	}
