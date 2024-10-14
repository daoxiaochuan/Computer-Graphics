#pragma once
#include"P3.h"
class CTransform3//��ά�任
{
public:
	CTransform3(void);
	virtual ~CTransform3(void);
	void SetMatrix(CP3* P, int ptNumber);
	void Identity(void);
	void Translate(double tx, double ty, double tz);//ƽ�Ʊ任
	void Scale(double sx, double sy, double sz);//�����任
	void Scale(double sx, double sy, double sz, CP3 p);//����������ı����任
	void RotateX(double beta);//��X����ת�任
	void RotateX(double beta, CP3 p);//�������������X����ת�任
	void RotateY(double beta);//��Y����ת�任
	void RotateY(double beta, CP3 p);//�������������Y����ת�任
	void RotateZ(double beta);//��Z����ת�任����
	void RotateZ(double beta, CP3 p);//�������������Z����ת�任
	void ReflectX(void);//X�ᷴ��任
	void ReflectY(void);//Y�ᷴ��任
	void ReflectZ(void);//Z�ᷴ��任
	void ReflectXOY(void);//XOY�淴��任
	void ReflectYOZ(void);//YOZ�淴��任
	void ReflectZOX(void);//ZOX�淴��任
	void ShearX(double d, double g);//X������б任
	void ShearY(double b, double h);//Y������б任
	void ShearZ(double c, double f);//Z������б任
	void MultiplyMatrix(void);//�������
private:
	double M[4][4];
	CP3* P;//��ά����������
	int ptNumber;//��ά�������
};


