
// ChildView.h: CChildView 类的接口
//


#pragma once
#include"Header.h"
#include "BagDlg.h"
#include "CharacterDlg.h"
#include "BusinessManDlg.h"
#include <vector>

using std::vector;
// CChildView 窗口

class CChildView : public CWnd
{
// 构造
public:
	CChildView();
	bool CanPass();							//判断英雄可否通过
	bool CanPass(CMonster);					//判断怪物可否通过
	void IniHeroPatrick();					//初始化英雄
	void IniMap(int[12][16]);				//初始化地图
	void IniMonster(int[][3]);				//初始化怪物
	void IniBullet();						//初始化英雄子弹
	void IniBullet(CMonster);				//初始化怪物子弹
	void IniHeroEquipment(CHero&);			//初始化英雄装备
	void IniHeroBag();						//初始化英雄背包
	void IniBusinessManItem();				//初始化商人有的东西
	void ShowMap();							//显示地图
	void ShowHero();						//显示英雄
	void ShowHeroEquipment();				//显示英雄装备
	void ShowBullet();						//显示子弹
	void ShowHP();							//显示英雄血量
	void ShowBusinessMan();					//显示商人图片
	void BulletOut();						//判断子弹是否出界函数
	void BulletMove();						//子弹移动
	void BulletHitMonster(int);				//判断子弹是否击中怪物
	void BulletHitHero(int);				//判断子弹是否击中英雄
	void BulletReload();					//重置子弹
	void ShowMonster();						//显示怪物
	void MonsterMove();						//怪物移动
	void MonsterChangeDirec();				//怪物改变移动方向
	void MonsterAttack();					//怪物攻击
	void MapChange();						//切换地图
	void KillMonster();						//杀死当前地图所有怪物
	void KillBullet();						//清空当前屏幕的子弹
	void BagButton();						//点击背包按钮执行函数
	void CharacterButton();					//人物属性按钮执行函数
	void ShowButton();						//贴出按钮图片函数
	void RestoreHP(CHero&);					//自动回血函数
	void HeroReborn();						//英雄死亡之后重生
	void MeetBusinessMan();					//遇到商人
	void BusinessManRenew();				//商人进货
// 特性
public:

// 操作
public:
	CRect m_client;							//保存客户区大小
	
	CImage m_UIImage;						//UI图片
	CImage m_BackGroundImage;				//背景图片 
	CImage m_BackGroundImage1;
	CImage m_BackGroundImage2;
	CImage m_BackGroundImage3;
	CImage m_BackGroundImage4;
	CImage m_BackGroundImage5;
	CImage m_BagButtonImage;				//背包按钮图像
	CImage m_CharacterButtonImage;			//人物按钮图像
	CImage m_HeroImage_DOWN;				//英雄图片
	CImage m_AppleImage;					//苹果图片
	CImage m_VioletPotionImage;				//紫色药水图片
	CImage m_HeroImage_UP;				
	CImage m_HeroImage_LEFT;			
	CImage m_HeroImage_RIGHT;			
	CImage m_WoodBowImage_UP;				//木弓图片
	CImage m_WoodBowImage_DOWN;
	CImage m_WoodBowImage_LEFT;
	CImage m_WoodBowImage_RIGHT;
	CImage m_WoodWandImage_UP;				//木法杖图片
	CImage m_WoodWandImage_DOWN;
	CImage m_WoodWandImage_LEFT;
	CImage m_WoodWandImage_RIGHT;
	CImage m_Hat1Image_UP;					//新手帽子图片
	CImage m_Hat1Image_DOWN;
	CImage m_Hat1Image_LEFT;
	CImage m_Hat1Image_RIGHT;
	CImage m_Cloth1Image_UP;				//新手衣服图片
	CImage m_Cloth1Image_DOWN;
	CImage m_Cloth1Image_LEFT;
	CImage m_Cloth1Image_RIGHT;
	CImage m_Shoes1Image_UP;				//新手鞋子图片
	CImage m_Shoes1Image_DOWN;
	CImage m_Shoes1Image_LEFT;
	CImage m_Shoes1Image_RIGHT;
	CImage m_ArrowImage_UP;					//箭图片
	CImage m_ArrowImage_DOWN;
	CImage m_ArrowImage_LEFT;
	CImage m_ArrowImage_RIGHT;
	CImage m_OrbImage_UP;					//法球图片
	CImage m_OrbImage_DOWN;
	CImage m_OrbImage_RIGHT;
	CImage m_OrbImage_LEFT;
	CImage m_BusinessManImage;				//商人图片
	CImage m_MudMonsterBulletImage_UP;		//泥怪子弹图片
	CImage m_MudMonsterBulletImage_DOWN;
	CImage m_MudMonsterBulletImage_LEFT;
	CImage m_MudMonsterBulletImage_RIGHT;
	CImage m_BlackGhostBulletImage_UP;		//黑鬼子弹图片
	CImage m_BlackGhostBulletImage_DOWN;
	CImage m_BlackGhostBulletImage_LEFT;
	CImage m_BlackGhostBulletImage_RIGHT;
	CImage m_BlackGhostImage_UP;			//黑鬼图片
	CImage m_BlackGhostImage_DOWN;
	CImage m_BlackGhostImage_LEFT;
	CImage m_BlackGhostImage_RIGHT;
	CImage m_MudMonsterImage_UP;			//泥怪图片
	CImage m_MudMonsterImage_DOWN;
	CImage m_MudMonsterImage_LEFT;
	CImage m_MudMonsterImage_RIGHT;
	CImage m_StoneImage;					//石头墙图片
	CImage m_WoodImage;						//木桩图片
	CImage m_BlackBackGround;				//为了碰撞判定建立的蒙版地图
	CImage m_BlackBackGround1;
	CImage m_BlackBackGround2;
	CImage m_BlackBackGround3;
	CImage m_BlackBackGround4;
	CImage m_BlackBackGround5;
	CBitmap m_cacheCBitmap;					//缓冲位图
	CDC m_cacheDC;							//创建缓冲DC
	
	//创建储存游戏元素的数组
	vector<CBullet> BulletVector;			//箭数组
	vector<CMonster> MonsterVector;			//怪物数组
	
	//地图标记
	int CurrentMap;							//当前地图
	int LateMap;							//上一个地图  
	//LateMap这个变量现在暂时没用 不过如果加一些新东西指不定有用 先放着

	BagDlg* pBagDlg;
	CharacterDlg* pCharacterDlg;
	BusinessManDlg* pBusinessManDlg;

// 重写
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildView();

	// 生成的消息映射函数
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

