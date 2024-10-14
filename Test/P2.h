#pragma once
#include "RGB.h"

class CP2
{
public:
	CP2();
	virtual ~CP2();
	CP2(double x, double y);
	CP2(double x, double y, CRGB c);
	friend CP2 operator + (const CP2& p0, const CP2& p1);//‘ÀÀ„∑˚÷ÿ‘ÿ
	friend CP2 operator - (const CP2& p0, const CP2& p1);
	friend CP2 operator * (const CP2& p, double scalar);
	friend CP2 operator * (double scalar, const CP2& p);
	friend CP2 operator / (const CP2& p, double scalar);
	friend CP2 operator += (CP2& p0, CP2& p1);
	friend CP2 operator -= (CP2& p0, CP2& p1);
	friend CP2 operator *= (CP2& p, double scalar);
	friend CP2 operator /= (CP2& p, double scalar);
public:
	double x,y;
	double w;
	CRGB c;
};

