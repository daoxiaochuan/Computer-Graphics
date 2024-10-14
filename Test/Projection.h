#pragma once
#include"P3.h"
class CProjection
{
public:
	CProjection(void);
	virtual ~CProjection(void);
	CP2 OrthogonalProjection(CP3 WorldPoint);//����ͶӰ
	CP2 CavalierProjection(CP3 WorldPoint);//б�Ȳ�ͶӰ
	CP2 CabinetProjection(CP3 WorldPoint);//б����ͶӰ
	void SetEye(CP3 Eye);//�����ӵ�
	CP3 GetEye(void);//����ӵ�
	CP2 PerspectiveProjection2(CP3 WorldPoint);//��ά͸��ͶӰ
	CP3 PerspectiveProjection3(CP3 WorldPoint);//��ά͸��ͶӰ
private:
	CP3 Eye;//�ӵ�
	double R, d;//�Ӿ����Ӿ�
};

