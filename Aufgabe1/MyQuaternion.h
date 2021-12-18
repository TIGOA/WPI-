
#ifndef MyQuaternion_h
#define MyQuaternion_h
#include <iostream>
#include <vector>
using namespace std;



class MyQuaternion
{
public:
    
    double e1, e2, e3, e4;
    //Konstruktur
    MyQuaternion(double e1,double e2,double e3,double e4);
    //Kopierkonstruktor
    MyQuaternion(const MyQuaternion &Q); 
    //addition operator +
    void operator+(const MyQuaternion &Q);
    //subtraktion operator -
    void operator-(const MyQuaternion &Q);
    //setter/getter operator []
    
    //get operator [] const
    
    //kopier operator=(Q_rhs)
    
    //zuweisung operator mit Skalar als argument operator=(skalar)
    
    //
    //conj() const
    MyQuaternion conj() const;
    //produkt zweier Quaternion, operator *
    
    //Skalierung einer Quaternion mit f  operator*(skalar)
    
    
};

#endif /* MyQuaternion_h */
 
