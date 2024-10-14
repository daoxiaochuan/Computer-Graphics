#pragma once
#include"P3.h"
class CProjection
{
public:
	CProjection(void);
	virtual ~CProjection(void);
	CP2 OrthogonalProjection(CP3 WorldPoint);//正交投影
	CP2 CavalierProjection(CP3 WorldPoint);//斜等测投影
	CP2 CabinetProjection(CP3 WorldPoint);//斜二测投影
	void SetEye(CP3 Eye);//设置视点
	CP3 GetEye(void);//获得视点
	CP2 PerspectiveProjection2(CP3 WorldPoint);//二维透视投影
	CP3 PerspectiveProjection3(CP3 WorldPoint);//三维透视投影
private:
	CP3 Eye;//视点
	double R, d;//视径和视距
};

