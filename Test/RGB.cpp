#include "pch.h"
#include "RGB.h"

CRGB::CRGB(void)
{
	red = 1.0;
	green = 1.0;
	blue = 1.0;
}
CRGB::CRGB(double red, double green, double blue)//重载构造函数
{
	this->red = red;
	this->green = green;
	this->blue = blue;
}

CRGB::~CRGB(void)
{

}

CRGB operator + (const CRGB& c1, const CRGB& c2)//"+"运算符重载
{
	CRGB c;
	c.red = c1.red + c2.red;
	c.green = c1.green + c2.green;
	c.blue = c1.blue + c2.blue;
	return c;
}

CRGB operator - (const CRGB& c1, const CRGB& c2)//"-"运算符重载
{
	CRGB c;
	c.red = c1.red - c2.red;
	c.green = c1.green - c2.green;
	c.blue = c1.blue - c2.blue;
	return c;
}

CRGB operator * (const CRGB& c1, const CRGB& c2)//"*"运算符重载
{
	CRGB c;
	c.red = c1.red * c2.red;
	c.green = c1.green * c2.green;
	c.blue = c1.blue * c2.blue;
	return c;
}

CRGB operator * (const CRGB& c1, double scalalr)//"*"运算符重载
{
	CRGB c;
	c.red = scalalr * c1.red;
	c.green = scalalr * c1.green;
	c.blue = scalalr * c1.blue;
	return c;
}

CRGB operator * (double scalalr, const CRGB& c1)//"*"运算符重载
{
	CRGB c;
	c.red = scalalr * c1.red;
	c.green = scalalr * c1.green;
	c.blue = scalalr * c1.blue;
	return c;
}

CRGB operator / (const CRGB& c1, double scalalr)//"/"运算符重载
{
	CRGB c;
	c.red = c1.red / scalalr;
	c.green = c1.green / scalalr;
	c.blue = c1.blue / scalalr;
	return c;
}

CRGB operator += (CRGB& c1, CRGB& c2)//"+="运算符重载
{
	c1.red = c1.red + c2.red;
	c1.green = c1.green + c2.green;
	c1.blue = c1.blue + c2.blue;
	return c1;
}

CRGB operator -= (CRGB& c1, CRGB& c2)//"-="运算符重载
{
	c1.red = c1.red - c2.red;
	c1.green = c1.green - c2.green;
	c1.blue = c1.blue - c2.blue;
	return c1;
}

CRGB operator *= (CRGB& c1, CRGB& c2)//"*="运算符重载
{
	c1.red = c1.red * c2.red;
	c1.green = c1.green * c2.green;
	c1.blue = c1.blue * c2.blue;
	return c1;
}

CRGB operator /= (CRGB& c1, double scalalr)//"/="运算符重载
{
	c1.red = c1.red / scalalr;
	c1.green = c1.green / scalalr;
	c1.blue = c1.blue / scalalr;
	return c1;
}

void CRGB::Normalize(void)//归一化
{
	red = (red < 0.0) ? 0.0 : ((red > 1.0) ? 1.0 : red);
	green = (green < 0.0) ? 0.0 : ((green > 1.0) ? 1.0 : green);
	blue = (blue < 0.0) ? 0.0 : ((blue > 1.0) ? 1.0 : blue);
}