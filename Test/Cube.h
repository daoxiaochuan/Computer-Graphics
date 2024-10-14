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
	void ReadVertex(void);//������
	void ReadFace(void);//�������
	void Draw(CDC* pDC,CZBuffer* pZBuffer,int nSign);//����������
public:
	CP3 V[8];//��������
	CFace F[6];//��������
	CProjection projection;
};

