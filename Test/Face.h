#pragma once
#include "RGB.h"
class CFace
{
public:
	CFace();
	~CFace();
	void SetPtNumber(int ptNumber);
public:
	int ptNumber; //面的顶点数
	int ptIndex[4];//面的顶点索引
	CRGB c;
};

