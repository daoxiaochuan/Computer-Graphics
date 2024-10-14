
// TestView.cpp: CTestView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Test.h"
#endif

#include "TestDoc.h"
#include "TestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ANIMATION, &CTestView::OnAnimation)
	ON_UPDATE_COMMAND_UI(ID_ANIMATION, &CTestView::OnUpdateAnimation)
	ON_WM_TIMER()
//	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CTestView 构造/析构

CTestView::CTestView() noexcept
{
	// TODO: 在此处添加构造代码
	bPlay = FALSE;
	largeCube.ReadVertex();
	largeCube.ReadFace();
	largeTransform.SetMatrix(largeCube.V, 8);
	largeTransform.Translate(-0.5, -0.5, -0.5);
	int nLargeScale = 200;
	largeTransform.Scale(nLargeScale, nLargeScale, nLargeScale);
	for (int i = 0; i < 3; i++)
	{
		smallCube[i].ReadVertex();
		smallCube[i].ReadFace();
		smallTransform[i].SetMatrix(smallCube[i].V, 8);
		smallTransform[i].Translate(-0.5, -0.5, -0.5);//将小立方体中心位于坐标系原点
	}
	int nSmallScale = 100;
	smallTransform[0].Scale(3 * nLargeScale, nSmallScale, nSmallScale);
	smallTransform[1].Scale(nSmallScale, 3 * nLargeScale, nSmallScale);
	smallTransform[2].Scale(nSmallScale, nSmallScale, 3 * nLargeScale);
}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTestView 绘图

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	DoubleBuffer(pDC);
	// TODO: 在此处为本机数据添加绘制代码
}


// CTestView 打印

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CTestView 诊断

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestView 消息处理程序


void CTestView::OnAnimation()
{
	// TODO: 在此添加命令处理程序代码
	bPlay = ~bPlay;
	if (bPlay)//设置定时器
		SetTimer(1, 150, NULL);
	else
		KillTimer(1);
}


void CTestView::OnUpdateAnimation(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (bPlay)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);
}


void CTestView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Alpha = 5, Beta = 5;
	for (int i = 0; i < 3; i++)
	{
		smallTransform[i].RotateX(Alpha);
		smallTransform[i].RotateY(Beta);
	}
	largeTransform.RotateX(Alpha);
	largeTransform.RotateY(Beta);
	Invalidate(FALSE);
	CView::OnTimer(nIDEvent);
}

void CTestView::DoubleBuffer(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	CDC memDC;//声明内存DC
	memDC.CreateCompatibleDC(pDC);//创建一个与显示DC兼容的内存DC
	CBitmap NewBitmap, * pOldBitmap;
	NewBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());//创建兼容内存位图 
	pOldBitmap = memDC.SelectObject(&NewBitmap);//将兼容位图选入内存DC
	memDC.FillSolidRect(rect, pDC->GetBkColor());//设置客户区背景色
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
	memDC.SetMapMode(MM_ANISOTROPIC);//内存DC自定义坐标系
	memDC.SetWindowExt(rect.Width(), rect.Height());
	memDC.SetViewportExt(rect.Width(), -rect.Height());
	memDC.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	DrawObject(&memDC);//绘制图形
	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, -rect.Width() / 2, -rect.Height() / 2, SRCCOPY); //将内存DC中的位图拷贝到显示DC
	memDC.SelectObject(pOldBitmap);
	NewBitmap.DeleteObject();
	memDC.DeleteDC();
}

void CTestView::DrawObject(CDC* pDC)
{
	CZBuffer* pZBuffer = new CZBuffer;
	pZBuffer->IntialDepthBuffer(1000, 1000, 1000);
	/*smallCube[0].Draw(pDC, pZBuffer, 0);
	smallCube[1].Draw(pDC, pZBuffer, 1);
	smallCube[2].Draw(pDC, pZBuffer, 2);*/
	largeCube.Draw(pDC, pZBuffer, 3);
	delete pZBuffer;
}

