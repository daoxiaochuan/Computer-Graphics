#pragma once
#include "P3.h"

class CVector3
{
public:
	CVector3(void);
	virtual ~CVector3(void);
	CVector3(double x, double y, double z);//绝对矢量
	CVector3(const CP3& p);
	CVector3(const CP3& p0, const CP3& p1);//相对矢量
	double Magnitude(void);//计算矢量的模
	CVector3 Normalize(void);//归一化矢量
	friend CVector3 operator + (const CVector3& v0, const CVector3& v1);//运算符重载
	friend CVector3 operator - (const CVector3& v0, const CVector3& v1);
	friend CVector3 operator * (const CVector3& v, double scalar);
	friend CVector3 operator * (double scalar, const CVector3& v);
	friend CVector3 operator / (const CVector3& v, double scalar);
	friend double DotProduct(const CVector3& v0, const CVector3& v1);//计算矢量的点积
	friend CVector3 CrossProduct(const CVector3& v0, const CVector3& v1);//计算矢量的叉积
public:
	double x, y, z;
};


