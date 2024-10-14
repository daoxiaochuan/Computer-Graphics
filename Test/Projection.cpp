#include "pch.h"
#include "Projection.h"
#define PI 3.1415926

CProjection::CProjection(void)
{
	R = 1200, d = 800;
}

CProjection::~CProjection(void)
{

}

CP2 CProjection::OrthogonalProjection(CP3 WorldPoint)//正交投影
{
	CP2 ScreenPoint;//屏幕坐标系二维点
	ScreenPoint.x = WorldPoint.x;
	ScreenPoint.y = WorldPoint.y;
	return ScreenPoint;
}

CP2 CProjection::CavalierProjection(CP3 WorldPoint)//斜等测投影
{
	CP2 ScreenPoint;
	double m = 0.707;
	ScreenPoint.x = WorldPoint.x - m * WorldPoint.z;
	ScreenPoint.y = WorldPoint.y - m * WorldPoint.z;
	return ScreenPoint;
}

CP2 CProjection::CabinetProjection(CP3 WorldPoint)//斜二测投影
{
	CP2 ScreenPoint;
	double m = 0.3536;
	ScreenPoint.x = WorldPoint.x - m * WorldPoint.z;
	ScreenPoint.y = WorldPoint.y - m * WorldPoint.z;
	return ScreenPoint;
}

void CProjection::SetEye(CP3 Eye)
{
	this->Eye = Eye;
}

CP3 CProjection::GetEye(void)//读取视点
{
	Eye.x = 0, Eye.y = 0, Eye.z = R;//视点位于正前方
	return Eye;
}

CP2 CProjection::PerspectiveProjection2(CP3 WorldPoint)
{
	CP3 ViewPoint;//观察坐标系三维点
	ViewPoint.x = WorldPoint.x;
	ViewPoint.y = WorldPoint.y;
	ViewPoint.z = R - WorldPoint.z;
	ViewPoint.c = WorldPoint.c;
	CP2 ScreenPoint;//屏幕坐标系二维点
	ScreenPoint.x = d * ViewPoint.x / ViewPoint.z;
	ScreenPoint.y = d * ViewPoint.y / ViewPoint.z;
	return ScreenPoint;
}

CP3 CProjection::PerspectiveProjection3(CP3 WorldPoint)
{
	CP3 ViewPoint;//观察坐标系三维点
	ViewPoint.x = WorldPoint.x;
	ViewPoint.y = WorldPoint.y;
	ViewPoint.z = R-WorldPoint.z;
	ViewPoint.c = WorldPoint.c;
	CP3 ScreenPoint;//屏幕坐标系二维点
	ScreenPoint.x = d * ViewPoint.x / ViewPoint.z;
	ScreenPoint.y = d * ViewPoint.y / ViewPoint.z;
	ScreenPoint.z = (ViewPoint.z - d) * d / ViewPoint.z;// Bouknight公式
	ScreenPoint.c = ViewPoint.c;
	return ScreenPoint;
}
