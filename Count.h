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
    void transform();//转为逆波兰后缀表达式
    bool IsOprand1(CString);//判断运算符的函数
    double calculate(void);//进行计算
    int fac(int);//求阶乘的函数
	bool Expression();//判断一个数里是否已经有小数点了
	bool Judge();//判断左括号与右括号的数目
	int Compare(char);//判断运算符优先级

protected:
	DECLARE_MESSAGE_MAP() 
	CString m_result;//输入的算术表达式
    stack<CString>s1;//存储后缀表达式的栈
};


