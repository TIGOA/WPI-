
#ifndef MyQuaternion_h
#define MyQuaternion_h
#include <iostream>
#include <vector>
#include <cmath> // for norm of Quaternion


using namespace std;



class MyQuaternion
{
public:
    
   // double e1, e2, e3, e4;
    double Quaternion[4];
    
    //default setting
    MyQuaternion();
    //Konstruktur
    MyQuaternion(const double e1,const double e2,const double e3,const double e4);
    //Kopierkonstruktor
    MyQuaternion(const MyQuaternion &Q);
    
    
    //setter/getter operator []
    double & operator[] (const int index);
    //get operator [] const ,read only
    const double operator[](const int index)const;
   
    
    
    //addition operator +
    MyQuaternion operator+(const MyQuaternion &Q)const;
    //subtraktion operator -
    MyQuaternion operator-(const MyQuaternion &Q)const;
    //Skalierung einer Quaternion mit f  operator*(skalar)
    MyQuaternion operator* (const double & fliesszahl) const;
    
    //kopier operator=(Q_rhs)
    MyQuaternion & operator= (const MyQuaternion & Q);

    //produkt operator *
    const MyQuaternion operator* (const MyQuaternion & Qb) const;
    
    // argument with scalar initial
    MyQuaternion & operator= (const double value);
    // conjugate Quaternion
    const MyQuaternion conj(const int w = 4) const;
    // divide by scalar
    const MyQuaternion operator/ (double n) const;
    // norm of Quaternion
    double norm() const;
    
};

#endif /* MyQuaternion_h */
 
