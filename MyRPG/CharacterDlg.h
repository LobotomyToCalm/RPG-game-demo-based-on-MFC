#pragma once
#include "Header.h"
#include <vector>
using std::vector;

// CharacterDlg 对话框

class CharacterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CharacterDlg)

public:
	CharacterDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CharacterDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHARACTERDLG };
#endif
public:
	CImage m_Hero;
	CImage m_WoodBow;
	CImage m_WoodWand;
	CImage m_Hat1;
	CImage m_Cloth1;
	CImage m_Shoes1;
	CImage m_CharacterBackGround;

	CBitmap m_CHcacheCBitmap;							//缓冲位图
	CDC m_CHcacheDC;									//创建缓冲DC
	CRect m_CHclient;									//保存客户区大小
	CImage m_CharacterBackGroundImage;					//人物属性背景图片
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void ShowCharacter();
	void ShowEquipment();
	void ShowCharacterstate();
	afx_msg void OnPaint();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnOK();
};
