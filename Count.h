#pragma once


// CCount
#include<stack>
#include<CString>
#include<string>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class CCount : public CWnd
{
	DECLARE_DYNAMIC(CCount)

public:
	CCount(CString);
	virtual ~CCount();
    void transform();//תΪ�沨����׺���ʽ
    bool IsOprand1(CString);//�ж�������ĺ���
    double calculate(void);//���м���
    int fac(int);//��׳˵ĺ���
	bool Expression();//�ж�һ�������Ƿ��Ѿ���С������
	bool Judge();//�ж��������������ŵ���Ŀ
	int Compare(char);//�ж���������ȼ�

protected:
	DECLARE_MESSAGE_MAP() 
	CString m_result;//������������ʽ
    stack<CString>s1;//�洢��׺���ʽ��ջ
};


