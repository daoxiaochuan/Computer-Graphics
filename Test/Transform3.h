#pragma once
#include"P3.h"
class CTransform3//三维变换
{
public:
	CTransform3(void);
	virtual ~CTransform3(void);
	void SetMatrix(CP3* P, int ptNumber);
	void Identity(void);
	void Translate(double tx, double ty, double tz);//平移变换
	void Scale(double sx, double sy, double sz);//比例变换
	void Scale(double sx, double sy, double sz, CP3 p);//相对于任意点的比例变换
	void RotateX(double beta);//绕X轴旋转变换
	void RotateX(double beta, CP3 p);//相对于任意点的绕X轴旋转变换
	void RotateY(double beta);//绕Y轴旋转变换
	void RotateY(double beta, CP3 p);//相对于任意点的绕Y轴旋转变换
	void RotateZ(double beta);//绕Z轴旋转变换矩阵
	void RotateZ(double beta, CP3 p);//相对于任意点的绕Z轴旋转变换
	void ReflectX(void);//X轴反射变换
	void ReflectY(void);//Y轴反射变换
	void ReflectZ(void);//Z轴反射变换
	void ReflectXOY(void);//XOY面反射变换
	void ReflectYOZ(void);//YOZ面反射变换
	void ReflectZOX(void);//ZOX面反射变换
	void ShearX(double d, double g);//X方向错切变换
	void ShearY(double b, double h);//Y方向错切变换
	void ShearZ(double c, double f);//Z方向错切变换
	void MultiplyMatrix(void);//矩阵相乘
private:
	double M[4][4];
	CP3* P;//三维顶点数组名
	int ptNumber;//三维顶点个数
};


