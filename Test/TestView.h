
// TestView.h: CTestView 类的接口
//

#pragma once
#include"P3.h"
#include"Transform3.h"
#include"Cube.h"
class CTestView : public CView
{
protected: // 仅从序列化创建
	CTestView() noexcept;
	DECLARE_DYNCREATE(CTestView)

// 特性
public:
	CTestDoc* GetDocument() const;

// 操作
public:
	void DoubleBuffer(CDC* pDC);//双缓冲
	void DrawObject(CDC* pDC);//绘制图形
	// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	BOOL bPlay;//动画按钮
	CCube smallCube[3],largeCube;//六面体对象
	CTransform3 smallTransform[3],largeTransform;//变换
	double Alpha, Beta;//旋转角
// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAnimation();
	afx_msg void OnUpdateAnimation(CCmdUI* pCmdUI);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // TestView.cpp 中的调试版本
inline CTestDoc* CTestView::GetDocument() const
   { return reinterpret_cast<CTestDoc*>(m_pDocument); }
#endif

