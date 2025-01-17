// CharacterDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MyRPG.h"
#include "CharacterDlg.h"
#include "afxdialogex.h"

#define TIMER_PAINT 1
// CharacterDlg 对话框

IMPLEMENT_DYNAMIC(CharacterDlg, CDialogEx)

CharacterDlg::CharacterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHARACTERDLG, pParent)
{

}

CharacterDlg::~CharacterDlg()
{
}

void CharacterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CharacterDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_RBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CharacterDlg 消息处理程序


BOOL CharacterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetTimer(TIMER_PAINT, 20, NULL);

	// TODO:  在此添加额外的初始化
	m_Hero.Load(_T("res\\Hero_DOWN_PNG.png"));
	m_WoodBow.Load(_T("res\\WoodBow_DOWN_PNG.png"));
	m_WoodWand.Load(_T("res\\WoodWand_DOWN_PNG.png"));
	m_CharacterBackGround.Load(_T("res\\CharacterBackGround_PNG.png"));
	m_Hat1.Load(_T("res\\Hat1_DOWN_PNG.png"));
	m_Cloth1.Load(_T("res\\Cloth1_DOWN_PNG.png"));
	m_Shoes1.Load(_T("res\\Shoes1_DOWN_PNG.png"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CharacterDlg::OnPaint()
{
	CPaintDC dc(this); 
	CDC *cDC = this->GetDC();		//获得当前窗口的DC   
	GetClientRect(&m_CHclient);     //获得窗口的尺寸

	//创建缓冲DC
	m_CHcacheDC.CreateCompatibleDC(NULL);
	m_CHcacheCBitmap.CreateCompatibleBitmap(cDC, m_CHclient.Width(), m_CHclient.Height());
	m_CHcacheDC.SelectObject(&m_CHcacheCBitmap);

	m_CharacterBackGround.Draw(m_CHcacheDC, m_CHclient);
	ShowCharacter();
	ShowEquipment();
	ShowCharacterstate();
	//将缓冲DC上的图贴在客户窗口区
	cDC->BitBlt(0, 0, m_CHclient.Width(), m_CHclient.Height(), &m_CHcacheDC, 0, 0, SRCCOPY);

	ValidateRect(&m_CHclient);//使窗口有效
		 //释放缓冲DC										  //如果没有这两句
	m_CHcacheDC.DeleteDC();								  //将会内存溢出，触发一个断点
		 //释放缓冲位图对象								  //<--------------
	m_CHcacheCBitmap.DeleteObject();					  //<--------------
		 //释放显示DC
	ReleaseDC(cDC);
}


void CharacterDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	for (int i = 0; i < 4; i++)
	{
		CMyRPGApp *pApp = (CMyRPGApp*)AfxGetApp();
		if (point.x > 148 && point.x<188 && point.y>(i * 56 + 10) && point.y < (i * 56 + 66))
		{
			for (int j = 0; j < 9; j++)
			{
				if (pApp->HeroBagVector[j]->Name == EMPTY)
				{
					delete pApp->HeroBagVector[j];
					pApp->HeroBagVector[j] = pApp->EquipmentVector[i];
					pApp->HeroBagVector[j]->State = EQUIPOFF;
					pApp->HeroBagVector[j]->GetOff(pApp->Patrick);
					pApp->EquipmentVector[i] = new CWeapon(EMPTY, EMPTY, EMPTY);
					pApp->EquipmentVector[i]->IniEmpty();
					break;
				}
				
			}
		}
	}
	CDialogEx::OnRButtonDown(nFlags, point);
}

void CharacterDlg::ShowCharacter()
{
	m_Hero.Draw(m_CHcacheDC, 40, 60, 50, 70);
}

void CharacterDlg::ShowEquipment()
{
	CMyRPGApp *pApp = (CMyRPGApp*)AfxGetApp();
	for (int i = 0; i < 4; i++)
	{
		if (pApp->EquipmentVector[i]->State == EQUIPON)
		{
			switch (pApp->EquipmentVector[i]->Name)
			{
			case WOODBOW:
				m_WoodBow.Draw(m_CHcacheDC, 148, i * 56 + 10, 40, 56);
				m_WoodBow.Draw(m_CHcacheDC, 40, 60, 50, 70);
				break;
			case WOODWAND:
				m_WoodWand.Draw(m_CHcacheDC, 148, i * 56 + 10, 40, 56);
				m_WoodWand.Draw(m_CHcacheDC, 40, 60, 50, 70);
				break;
			case HAT1:
				m_Hat1.Draw(m_CHcacheDC, 148, i * 56 + 10, 40, 56);
				m_Hat1.Draw(m_CHcacheDC, 40, 60, 50, 70);
				break;
			case CLOTH1:
				m_Cloth1.Draw(m_CHcacheDC, 148, i * 56 + 10, 40, 56);
				m_Cloth1.Draw(m_CHcacheDC, 40, 60, 50, 70);
				break;
			case SHOES1:
				m_Shoes1.Draw(m_CHcacheDC, 148, i * 56 + 10, 40, 56);
				m_Shoes1.Draw(m_CHcacheDC, 40, 60, 50, 70);
				break;
			case EMPTY:
				break;
			}
		}
	}
}

void CharacterDlg::OnTimer(UINT_PTR nIDEvent)
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


void CharacterDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialogEx::OnOK();
}

void CharacterDlg::ShowCharacterstate()
{
	CMyRPGApp *pApp = (CMyRPGApp*)AfxGetApp();
	CDC* pcacheDC = &m_CHcacheDC;//缓冲DC的指针

	pcacheDC->SetBkMode(TRANSPARENT);
	pcacheDC->TextOutW(10, 200, _T("ATK: "));
	pcacheDC->TextOutW(10, 215, _T("DEF: "));
	pcacheDC->TextOutW(10, 230, _T("MAXHP: "));
	pcacheDC->TextOutW(10, 245, _T("SPEED: "));
	CString str1;
	str1.Format(_T("%d"), pApp->Patrick.ATK);
	CString str2;
	str2.Format(_T("%d"), pApp->Patrick.DEF);
	CString str3;
	str3.Format(_T("%d"), pApp->Patrick.MaxHP);
	CString str4;
	str4.Format(_T("%d"), pApp->Patrick.Speed);
	pcacheDC->TextOutW(60, 200, str1);
	pcacheDC->TextOutW(60, 215, str2);
	pcacheDC->TextOutW(80, 230, str3);
	pcacheDC->TextOutW(90, 245, str4);
}