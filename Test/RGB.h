#pragma once
class CRGB
{
public:
	CRGB(void);
	CRGB(double rred, double green, double blue);
	virtual ~CRGB(void);
	friend CRGB operator + (const CRGB& c1, const CRGB& c2);//���������
	friend CRGB operator - (const CRGB& c1, const CRGB& c2);
	friend CRGB operator * (const CRGB& c1, const CRGB& c2);
	friend CRGB operator * (const CRGB& c1, double scalalr);
	friend CRGB operator * (double k, const CRGB& c1);
	friend CRGB operator / (const CRGB& c1, double k);
	friend CRGB operator += (CRGB& c1, CRGB& c2);
	friend CRGB operator -= (CRGB& c1, CRGB& c2);
	friend CRGB operator *= (CRGB& c1, CRGB& c2);
	friend CRGB operator /= (CRGB& c1, double scalalr);
	void  Normalize(void);//��һ����[0,1]����
public:
	double red;//��ɫ����
	double green;//��ɫ����
	double blue;//��ɫ����
};

