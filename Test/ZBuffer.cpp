#include "pch.h"
#include "ZBuffer.h"
#define ROUND(d) int(d+0.5)
#define LEFT 1
#define RIGHT 0

CZBuffer::CZBuffer(void)
{
}

CZBuffer::~CZBuffer(void)
{
	for (int i = 0; i < nWidth; i++)
	{
		delete[] zBuffer[i];
		zBuffer[i] = NULL;
	}
	if (zBuffer != NULL)
	{
		delete zBuffer;
		zBuffer = NULL;
	}
}

void CZBuffer::SetPoint(CP3 P0, CP3 P1, CP3 P2)
{
	this->P0 = P0;
	this->P1 = P1;
	this->P2 = P2;
	point0.x = ROUND(P0.x);
	point0.y = ROUND(P0.y);
	point0.z = P0.z;
	point0.c = P0.c;
	point1.x = ROUND(P1.x);
	point1.y = ROUND(P1.y);
	point1.z = P1.z;
	point1.c = P1.c;
	point2.x = ROUND(P2.x);
	point2.y = ROUND(P2.y);
	point2.z = P2.z;
	point2.c = P2.c;
}

void CZBuffer::IntialDepthBuffer(int nWidth, int nHeight, double nDepth)//��ʼ����Ȼ���
{
	this->nWidth = nWidth, this->nHeight = nHeight;
	zBuffer = new double* [nWidth];
	for (int i = 0; i < nWidth; i++)
	{
		zBuffer[i] = new double[nHeight];
	}
	for (int i = 0; i < nWidth; i++)//��ʼ����Ȼ�����
	{
		for (int j = 0; j < nHeight; j++)
			zBuffer[i][j] = nDepth;
	}
}

void CZBuffer::FillTriangle(CDC* pDC)
{
	SortPoint();//���㰴��y������С��������
	int nTotalScanLine = point2.y - point0.y + 1;
	SpanLeft = new CPoint2[nTotalScanLine];
	SpanRight = new CPoint2[nTotalScanLine];
	//�ж�P1��λ��P0P2�ߵ���໹���Ҳ�
	int nDeltz = (point2.x - point0.x) * (point1.y - point0.y) - (point2.y - point0.y) * (point1.x - point0.x);//��ʸ�������z����
	if (nDeltz > 0)//��������
	{
		nIndex = 0;
		EdgeFlag(point0, point1, LEFT);
		EdgeFlag(point1, point2, LEFT);
		nIndex = 0;
		EdgeFlag(point0, point2, RIGHT);
	}
	else//��������
	{
		nIndex = 0;
		EdgeFlag(point0, point2, LEFT);
		nIndex = 0;
		EdgeFlag(point0, point1, RIGHT);
		EdgeFlag(point1, point2, RIGHT);
	}
	CVector3 Vector01(P0, P1), Vector02(P0, P2);
	CVector3 fNormal = CrossProduct(Vector01, Vector02);
	double A = fNormal.x, B = fNormal.y, C = fNormal.z;//ƽ�淽��Ax+By+Cz��D=0��ϵ��
	double D = -A * P0.x - B * P0.y - C * P0.z;//ϵ��D
	if (fabs(C) < 1e-4)
		C = 1.0;
	double DepthStep = -A / C;//ɨ������Ȳ���
	for (int y = point0.y; y < point2.y; y++)//�±��Ͽ�
	{
		int n = y - point0.y;
		for (int x = SpanLeft[n].x; x < SpanRight[n].x; x++)//����ҿ�
		{
			double CurrentDepth = -(A * x + B * y + D) / C;//z=-(Ax+By+D)/C
			CRGB clr = Interp(x, SpanLeft[n].x, SpanRight[n].x, SpanLeft[n].c, SpanRight[n].c);
			if (CurrentDepth <= zBuffer[x + nWidth / 2][y + nHeight / 2])//�����ǰ����������С��֡��������ԭ����������
			{
				zBuffer[x + nWidth / 2][y + nHeight / 2] = CurrentDepth;//ʹ�õ�ǰ���������ȸ�����Ȼ�����
				pDC->SetPixelV(x, y, RGB(clr.red * 255, clr.green * 255, clr.blue * 255));
			}
			CurrentDepth += DepthStep;
		}
	}
	if (SpanLeft)
	{
		delete[]SpanLeft;
		SpanLeft = NULL;
	}
	if (SpanRight)
	{
		delete[]SpanRight;
		SpanRight = NULL;
	}

}
void CZBuffer::EdgeFlag(CPoint2 PStart, CPoint2 PEnd, BOOL bFeature)//DDA�㷨��ɢ��
{
	int dx = PEnd.x - PStart.x;
	int dy = PEnd.y - PStart.y;
	double m = double(dx) / dy;
	double x = PStart.x;
	for (int y = PStart.y; y < PEnd.y; y++)
	{
		CRGB crColor = Interp(y, PStart.y, PEnd.y, PStart.c, PEnd.c);
		if (bFeature)
			SpanLeft[nIndex++] = CPoint2(ROUND(x), y, crColor);
		else
			SpanRight[nIndex++] = CPoint2(ROUND(x), y, crColor);
		x += m;
	}
}

void CZBuffer::SortPoint(void)//����
{
	CPoint3 pt;//Ҫ�������P[0].y<P[1].y<P[2].y
	if (point0.y > point1.y)
	{
		pt = point0;
		point0 = point1;
		point1 = pt;
	}
	if (point0.y > point2.y)
	{
		pt = point0;
		point0 = point2;
		point2 = pt;
	}
	if (point1.y > point2.y)
	{
		pt = point1;
		point1 = point2;
		point2 = pt;
	}
}

CRGB CZBuffer::Interp(double m, double m0, double m1, CRGB c0, CRGB c1)//��ɫ���Բ�ֵ
{
	CRGB color;
	color = (m1 - m) / (m1 - m0) * c0 + (m - m0) / (m1 - m0) * c1;
	return color;
}
