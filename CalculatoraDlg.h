// CalculatoraDlg.h : ͷ�ļ�
//

#pragma once



// CCalculatoraDlg �Ի���
class CCalculatoraDlg : public CDialog
{
// ����
public:
	CCalculatoraDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALCULATORA_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_show;
public:
    double ReversePolishNotion( CString);//�沨���㷨ʵ�ֺ���
	afx_msg void OnBnClickednum1();
	afx_msg void OnBnClickednum8();
	afx_msg void OnBnClickednum0();
	afx_msg void OnBnClickednum2();
	afx_msg void OnBnClickednum3();
	afx_msg void OnBnClickednum4();
	afx_msg void OnBnClickednum5();
	afx_msg void OnBnClickednum6();
	afx_msg void OnBnClickednum7();
	afx_msg void OnBnClickednum9();
	afx_msg void OnBnClickedeaqual();
	afx_msg void OnBnClickedadd();
	afx_msg void OnBnClickedabstact();
	afx_msg void OnBnClickeddevide();
	afx_msg void OnBnClickedsubstact();
	afx_msg void OnEnChangeEdit1();
public:
	afx_msg void OnBnClickedcubic();
public:
	afx_msg void OnBnClickeddelete();
public:
	afx_msg void OnBnClickedclear();
public:
	afx_msg void OnBnClickedcomma();
public:
	afx_msg void OnBnClickedopenp();
public:
	afx_msg void OnBnClickedclosedp();
    
public:
	afx_msg void OnBnClickedtan();
public:
	afx_msg void OnBnClickedcos();
public:
	afx_msg void OnBnClickedsin();
public:
	afx_msg void OnBnClickedlog();
public:
	afx_msg void OnBnClickedln();
public:
	afx_msg void OnBnClickedpow();
public:
	afx_msg void OnBnClickedmod();
public:
	afx_msg void OnBnClickedfac();

public:
	afx_msg void OnBnClickedpi();
};
