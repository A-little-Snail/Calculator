// Count.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Calculatora.h"
#include "Count.h"
#include<CString>
#include<stack>
#include<cmath>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE

#endif

using namespace std;



// CCount

IMPLEMENT_DYNAMIC(CCount, CWnd)

CCount::CCount(CString m_test)
{ 
	m_test += " # ";                   //��ӡ�#����Ϊת��Ϊ��׺���ʽ��ֹͣ��
	m_test.Replace("��","3.1415926");  //�������"��"��3.1415926�滻
 m_result = m_test;                    //��m_test��ֵ����m_result
}

CCount::~CCount()
{
}


BEGIN_MESSAGE_MAP(CCount, CWnd)
END_MESSAGE_MAP()



// CCount ��Ϣ�������

bool CCount::IsOprand1(CString m_a)
{
     char p = m_a.GetAt(0);
	if(p=='+'||p=='-'||p=='*'||p=='/'||p=='^'||p=='c'||p=='s'||p=='t'||p=='l'||p=='L'||p=='%')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int CCount::Compare(char m_operator)
{
	if(m_operator=='('||m_operator=='#')
	{
		return 1;
	}
	if(m_operator=='+'||m_operator=='-')
	{
		return 2;
	}
	if(m_operator=='*'||m_operator=='/')
	{
		return 3;
	}
	if(m_operator=='^'||m_operator=='%'||m_operator=='c'||m_operator=='s'||m_operator=='t'||m_operator=='l'||m_operator=='L')
	{
		return 4;
	}

}
int CCount::fac(int n)
{
  int i;
  int j = 1;
  for(i=1;i<=n;i++)
  {
	  j*=i;
  }
  return j;
}

	


void CCount::transform(void)
{
	stack<CString>s2;
	s2.push("#");                                                 //��#ѹ��ջ��
    s1.push("#");                                                   //��#ѹ��ջ��
    CString m_string;
        m_string = m_result.SpanExcluding(" ");                     //�����ӿ�ʼ����һ���հ׶ϵ㴦���ַ���
        m_result.Delete(0,m_string.GetLength()+1);                  //ɾ��m_string�ַ�������֮���һ���հ״�
       char pp = m_string.GetAt(0);                                 //����m_string�ĵ�һ���ַ�
		
  while(pp != 35)                                                   //�ж��Ƿ����
   {
     
	if(!IsOprand1(m_string))
	{
		
		if(pp !='(' && pp !=')')
		{
			s1.push(m_string);                                     //��������ֻ����ǡ���������ջs1
			
		}
		else
		{
			if(pp =='(')
			{
				s2.push(m_string);                                   //�����"("����ջs2
                
			}
			else
			{
				char n = s2.top().GetAt(0);
				while(  n != '(')
				{
					s1.push(s2.top());
					s2.pop();
					n = s2.top().GetAt(0);
				}                                              //�������")"���s2�����һ��"("֮ǰ�ķ���������ջs1
				s2.pop();                                     //���Ѹ��������׳�
              
			}
		}

	}
	else
	{
        char m = s2.top().GetAt(0);
		CString m_cstr;
		m_cstr= m_string.GetAt(0);
        
			if(Compare(m)<Compare(pp))
			{
				s2.push(m_cstr);
			}
			else
			{
				s1.push(s2.top());
				s2.pop();
				s2.push(m_cstr);
			}
                                                         //�����������ʱ���ж�ջs2���˵���������ȼ����ڸ���������������
	}                                                    //���������ֱ����ջs2������ʹs2ջ�����������s1;�����������ֱ����ջs2
	  
     m_string = m_result.SpanExcluding(" ");
     m_result.Delete(0,m_string.GetLength()+1);
     pp = m_string.GetAt(0); 

}
  char q ;
  q = s2.top().GetAt(0);
  while(q!='#')
  {
	  s1.push(s2.top());
	  s2.pop();
	  q = s2.top().GetAt(0);   //��s2ջ��ʣ�µ����������s1
  }

        
		
}

double CCount::calculate(void)
{ 
  stack<CString>s3;      //�洢˳���෴�ĺ�׺���ʽ
  stack<double>s4;       //�洢�м�������Լ����ռ�����
  s3.push("#");
  
  char a;                
  a = s1.top().GetAt(0);
  while(a !='#')
  {
	 
	  s3.push(s1.top());
	  s1.pop();
      a =s1.top().GetAt(0);
    
  }                       //��ջs1�е��ַ����ζ���ջs3

   char b = s3.top().GetAt(0);
   while(b!='#')//
  {         
       
	if(!IsOprand1(s3.top()))
   {
	   CString m_pp = s3.top();
	   double m_p = atof(m_pp.GetBuffer(m_pp.GetLength()+1));
      s4.push(m_p);
	  s3.pop();
	  
   }                           //��������������֣�����ת��double�ͣ�������ջs4
   else
   {
         double number1;
		 double number2;
		 double number3;

	  
		 if(b =='+'||b=='-'||b=='*'||b=='/'||b=='^')
		  {
			s3.pop();
		    number1 = s4.top();
			s4.pop();
			number2 = s4.top();
			s4.pop();
			switch(b)
		    {
			case'+':
				{number3 = number2+number1;
			      break;
				}
			case'-':
				{
			      number3 = number2-number1;
				  break;
				}
			case'*':
				{
			       number3 = number2*number1;
				   break;
				}
			case'/':
				{
			      number3 = number2/number1;
				  break;
				}
			case'^':
				{
			      number3 = pow(number2,number1);
				  break;
				}
			}
			  s4.push(number3);
			
		}
		
         if(b =='%')
		   {   
			   s3.pop();
			   int number5;
			   number5 = int(s4.top());
			   s4.pop();
			   int number6;
               number6 = int(s4.top());
			   s4.pop();
              int number7 = number5%number6;
              
			   s4.push(number7);
			   
		   }

			

          if(b=='!')
		  {
			  s3.pop();
              int number4;
			  number4 = int(s4.top());
			  s4.pop();
			  int number8 = fac(number4);
			  s4.push(number8);
			  
			 
		  }

		 if( b =='c'||b =='s'||b =='t'||b =='l'||b =='L')
		 {
               s3.pop();
	          number1 = s4.top();
			  s4.pop();
			  switch(b)
			  {
			  case'c':
				  {
			         s4.push(cos(number1));
			         break;
				   }


			  case's':
				  {
		   
			        s4.push(sin(number1));
					break;
		           }

			  case't':
		          {
			        s4.push(tan(number1));
					break;
		          }
			  case'l':
		         {
			       s4.push(log10(number1));
				   break;
				 }
			  case'L':
				  {
			        s4.push(log(number1));
					break;
		          }
			  }
		 }                                    //����������������������ν�����Ӧ������
		 }
     b = s3.top().GetAt(0);
		 }

    return s4.top();
  }
  
  bool CCount::Expression()//������һ�������֮������ִ����ж��Ƿ�����С����
  {
	  char m_str;
	  m_str = m_result.GetAt(m_result.GetLength()-4);
	  int i=4;
	  while(m_str !=' ' && m_result.GetLength()-i>0)
	  {
		  if(m_str =='.')
		  {
			  return true;
			  break;
		  }
		  else
		  { 
			  i+=1;
			  m_str = m_result.GetAt(m_result.GetLength()-i);
			  continue;
		  }
		 
	  }
 return false;
  }

  bool CCount::Judge()//���������ַ����ж������Ÿ����Ƿ���������Ÿ���
  {
	  int m_left=0;
	  int m_right=0;
	  for(int i=0;i<m_result.GetLength();i++)
	  {
        char m_c;
	     m_c = m_result.GetAt(i);
		 if(m_c == '(')
		 {
			 m_left+=1;
		 }
		 if(m_c == ')')
		 {
			 m_right+=1;
		 }
	  }
	  if(m_left>m_right)
	  {
		  return true;
	  }
	  else
	  {
		  return false;
	  }
  }
