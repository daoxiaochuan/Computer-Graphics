#pragma once
#include"Face.h"
#include"Projection.h"
#include"Vector3.h"
#include "ZBuffer.h"

class CCube
{
public:
	CCube(void);
	virtual ~CCube(void);
	void ReadVertex(void);//读入点表
	void ReadFace(void);//读入面表
	void Draw(CDC* pDC,CZBuffer* pZBuffer,int nSign);//绘制立方体
public:
	CP3 V[8];//顶点数组
	CFace F[6];//表面数组
	CProjection projection;
};

