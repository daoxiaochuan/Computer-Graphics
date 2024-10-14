#pragma once
#include"RGB.h"

class CPoint2
{
public:
	CPoint2(void);
	CPoint2(int x, int y);
	CPoint2(int x, int y, CRGB c);
	virtual ~CPoint2(void);
public:
	int x;
	int y;
	CRGB c;
};

