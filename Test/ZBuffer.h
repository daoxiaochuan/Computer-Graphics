#pragma once
#include "P3.h"
#include "Point3.h"//����ɫ����ά��������
#include "Vector3.h"

class CZBuffer
{
public:
	CZBuffer(void);
	virtual ~CZBuffer(void);
	void SetPoint(CP3 P0, CP3 P1, CP3 P2);
	void IntialDepthBuffer(int nWidth, int nHeight, double nDepth);//��ʼ����Ȼ�����
	void FillTriangle(CDC* pDC);
private:
	void EdgeFlag(CPoint2 PStart,CPoint2 PEnd,BOOL bFeature);
	void SortPoint(void);
	CRGB Interp(double m, double m0, double m1, CRGB c0, CRGB c1);
private:
	CP3 P0, P1, P2;//�����εĸ�������
	CPoint3 point0, point1, point2;//�����ε�������������
	CPoint2* SpanLeft;//��ȵ����������־
	CPoint2* SpanRight;
	int nIndex;//��¼ɨ��������
	double** zBuffer;//��Ȼ�����
	int nWidth, nHeight;//��������Ⱥ͸߶�
};

