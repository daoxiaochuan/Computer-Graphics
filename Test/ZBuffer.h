#pragma once
#include "P3.h"
#include "Point3.h"//带颜色的三维整数点类
#include "Vector3.h"

class CZBuffer
{
public:
	CZBuffer(void);
	virtual ~CZBuffer(void);
	void SetPoint(CP3 P0, CP3 P1, CP3 P2);
	void IntialDepthBuffer(int nWidth, int nHeight, double nDepth);//初始化深度缓冲器
	void FillTriangle(CDC* pDC);
private:
	void EdgeFlag(CPoint2 PStart,CPoint2 PEnd,BOOL bFeature);
	void SortPoint(void);
	CRGB Interp(double m, double m0, double m1, CRGB c0, CRGB c1);
private:
	CP3 P0, P1, P2;//三角形的浮点坐标
	CPoint3 point0, point1, point2;//三角形的整数顶点坐标
	CPoint2* SpanLeft;//跨度的起点数组标标志
	CPoint2* SpanRight;
	int nIndex;//记录扫描线条数
	double** zBuffer;//深度缓冲区
	int nWidth, nHeight;//缓冲区宽度和高度
};

