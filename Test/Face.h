#pragma once
#include "RGB.h"
class CFace
{
public:
	CFace();
	~CFace();
	void SetPtNumber(int ptNumber);
public:
	int ptNumber; //��Ķ�����
	int ptIndex[4];//��Ķ�������
	CRGB c;
};

