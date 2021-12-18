#include"MyQuaternion.h"

/*
记得看这个
https://blog.csdn.net/silangquan/article/details/50390570

*/

//Konstruktur
MyQuaternion(double e1,double e2,double e3,double e4);
//Kopierkonstruktor
MyQuaternion(const MyQuaternion &Q){};
//addition operator +
void MyQuaternion::operator+(const MyQuaternion &Q)
{
	e1 += Q.e1;
	e2 += Q.e2;
	e3 += Q.e3;
	e4 += Q.e4;
}
//subtraktion operator -
void MyQuaternion::operator-(const MyQuaternion &Q)
{
	e1 -= Q.e1;
	e2 -= Q.e2;
	e3 -= Q.e3;
	e4 -= Q.e4;
}

//setter/getter operator []

//get operator [] const

//kopier operator=(Q_rhs)

//zuweisung operator mit Skalar als argument operator=(skalar)

//
//conj() const
MyQuaternion MyQuaternion::conj() const
{
	return MyQuaternion(-e1, -e2, -e3, e4);
}

//produkt zweier Quaternion, operator *

//Skalierung einer Quaternion mit f  operator*(skalar)
