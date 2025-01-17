// ChooseOcc.cpp: 实现文件
//

#include "stdafx.h"
#include "Header.h"
#include "ChooseOcc.h"
#include "afxdialogex.h"

#define TIMER_PAINT 999

// ChooseOcc 对话框

IMPLEMENT_DYNAMIC(ChooseOcc, CDialogEx)

ChooseOcc::ChooseOcc(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHOOSEOCC, pParent)
{
}

ChooseOcc::~ChooseOcc()
{
}

void ChooseOcc::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ChooseOcc, CDialogEx)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// ChooseOcc 消息处理程序
BOOL ChooseOcc::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_ChooseOccBackGround.Load(_T("res\\ChooseOccBackGround_PNG.png"));
	m_OK.Load(_T("res\\OK_PNG.png"));
	m_Hunter.Load(_T("res\\HUNTER_PNG.png"));
	m_Mage.Load(_T("res\\MAGE_PNG.png"));
	m_ButtonFrame.Load(_T("res\\ButtonFrame_PNG.png"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ChooseOcc::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CDC *cDC = this->GetDC();   //获得当前窗口的DC   
	GetClientRect(&m_Cclient);   //获得窗口的尺寸

	//创建缓冲DC
	m_CcacheDC.CreateCompatibleDC(NULL);
	m_CcacheCBitmap.CreateCompatibleBitmap(cDC, m_Cclient.Width(), m_Cclient.Height());
	m_CcacheDC.SelectObject(&m_CcacheCBitmap);

	//绘制背景图片
	m_ChooseOccBackGround.Draw(m_CcacheDC,m_Cclient);//窗口大小测试得686，452
	//绘制按钮图片
	ShowButton();
	//绘制按钮选择框架图片
	ShowButtonFrame();
	//将缓冲DC上的图贴在客户窗口区
	cDC->BitBlt(0, 0, m_Cclient.Width(), m_Cclient.Height(), &m_CcacheDC, 0, 0, SRCCOPY);

	ValidateRect(&m_Cclient);//使窗口有效
		 //释放缓冲DC										  //如果没有这两句
	m_CcacheDC.DeleteDC();								  //将会内存溢出，触发一个断点
		 //释放缓冲位图对象								  //<--------------
	m_CcacheCBitmap.DeleteObject();						  //<--------------
		 //释放显示DC
	ReleaseDC(cDC);
}


void ChooseOcc::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMyRPGApp *pApp = (CMyRPGApp*)AfxGetApp();
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (point.x > 141 && point.x < 201 && point.y>40 & point.y < 80)
	{
		ChangeButtonFrame(141);
		pApp->OccChoose = HUNTER;
	}
	if (point.x > 484 && point.x < 544 && point.y>40 & point.y < 80)
	{
		ChangeButtonFrame(484);
		pApp->OccChoose = MAGE;
	}
	if (point.x > 313 && point.x < 373 && point.y>380 & point.y < 420)
	{
		OnOK();
	}
	
	CDialogEx::OnLButtonDown(nFlags, point);
}

void ChooseOcc::ShowButton()
{
	m_Hunter.Draw(m_CcacheDC, 141, 40, 60, 40);
	m_Mage.Draw(m_CcacheDC, 484, 40, 60, 40);
	m_OK.Draw(m_CcacheDC, 313, 380, 60, 40);
}


void ChooseOcc::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialogEx::OnOK();
}

void ChooseOcc::ShowButtonFrame()
{
	if(FrameX!=EMPTY)
	m_ButtonFrame.Draw(m_CcacheDC, FrameX, 40, 60, 40);
}

void ChooseOcc::ChangeButtonFrame(int x)
{
	FrameX = x;
}

void ChooseOcc::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
	case TIMER_PAINT:
		OnPaint();
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}


int ChooseOcc::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetTimer(TIMER_PAINT, 10, NULL);
	return 0;
}
