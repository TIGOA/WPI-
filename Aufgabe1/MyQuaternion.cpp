#include"MyQuaternion.h"

//default konstruktur
MyQuaternion::MyQuaternion() {
    this->Quaternion[0] = 0.;
    this->Quaternion[1] = 0.;
    this->Quaternion[2] = 0.;
    this->Quaternion[3] = 0.;
}

//Konstruktur
MyQuaternion::MyQuaternion(const double e1,const double e2,const double e3,const double e4)
{
        this->Quaternion[0] = e1;
        this->Quaternion[1] = e2;
        this->Quaternion[2] = e3;
        this->Quaternion[3] = e4;
};
//Kopierkonstruktor
MyQuaternion::MyQuaternion(const MyQuaternion &Q)
{
        this->Quaternion[0]=Q.Quaternion[0];
        this->Quaternion[1]=Q.Quaternion[1];
        this->Quaternion[2]=Q.Quaternion[2];
        this->Quaternion[3]=Q.Quaternion[3];
};


//addition operator +
MyQuaternion MyQuaternion::operator+(const MyQuaternion &Q)const
{
    MyQuaternion result =*this;
    
    for (auto i=0; i<4; i++)
    {
        result.Quaternion[i]+=Q.Quaternion[i];
    }
    
    return result;
    
}
//subtraktion operator -
MyQuaternion MyQuaternion::operator-(const MyQuaternion &Q)const
{
    MyQuaternion result =*this;
    
    for (auto i=0; i<4; i++)
    {
        result.Quaternion[i]-=Q.Quaternion[i];
    }
    
    return result;
}

//setter/getter operator []
double & MyQuaternion::operator[] (const int index)
{
    return this->Quaternion[index];
}

//get operator [] const
const double MyQuaternion::operator[] (const int index) const
{
    return this->Quaternion[index];
}



// copy operator
MyQuaternion& MyQuaternion::operator=(const MyQuaternion & Q) {
   
    for (auto i=0; i<4; i++)
        {
            this->Quaternion[i]=Q.Quaternion[i];
        }
    return *this;
}

//produkt zweier Quaternion, operator *

const MyQuaternion MyQuaternion::operator* (const MyQuaternion & Q) const{
    
    MyQuaternion result =*this;
    
    
    
    const double e1 = result.Quaternion[0]*Q.Quaternion[3]
                    + result.Quaternion[3]*Q.Quaternion[0]
                    - result.Quaternion[1]*Q.Quaternion[2]
                    + result.Quaternion[2]*Q.Quaternion[1];
    const double e2 = result.Quaternion[1]*Q.Quaternion[3]
                    + result.Quaternion[3]*Q.Quaternion[1]
                    - result.Quaternion[2]*Q.Quaternion[0]
                    + result.Quaternion[0]*Q.Quaternion[2];
    const double e3 = result.Quaternion[2]*Q.Quaternion[3]
                    + result.Quaternion[3]*Q.Quaternion[2]
                    - result.Quaternion[0]*Q.Quaternion[1]
                    + result.Quaternion[1]*Q.Quaternion[0];
    const double e4 = result.Quaternion[3]*Q.Quaternion[3]
                    - result.Quaternion[0]*Q.Quaternion[0]
                    - result.Quaternion[1]*Q.Quaternion[1]
                    - result.Quaternion[2]*Q.Quaternion[2];
    
    std::vector<double> e = {e1,e2,e3,e4};
    
   
    
    for(auto i=0;i<4;i++)
    {
        result.Quaternion[i]=e[i];
    }
    
    return result;
}






//Skalierung operator* (skalar)
MyQuaternion MyQuaternion::operator* (const double & fliesszahl) const{
    
    MyQuaternion result =*this;
    
    for (auto i=0; i<4; i++)
    {
        result.Quaternion[i]=fliesszahl*this->Quaternion[i];
    }
    
    return result;
}


// operator = zuweisung
MyQuaternion & MyQuaternion::operator= (const double value){
   
    for (auto i=0; i<4; i++)
        {
            this->Quaternion[i]=value;
        }
    return *this;
    
    
}


//Konjugiert
const MyQuaternion MyQuaternion::conj(const int w) const{
    
    
    
    MyQuaternion result =*this;
    
    for (auto i=0; i<w-1; i++)
    {
        result.Quaternion[i]=-1*this->Quaternion[i];
        result.Quaternion[w-1]=this->Quaternion[w-1];
        
    }
    
    return result;
    
    
}

// divide by scalar
const MyQuaternion MyQuaternion::operator/ (double n) const{
   
    MyQuaternion result =*this;
    
    for (auto i=0; i<4; i++)
    {
        result.Quaternion[i]=this->Quaternion[i]/n;
    }
    
    return result;
    
}

// norm of Quaternion
double MyQuaternion::norm() const{
    
    return sqrt(this->Quaternion[0]*this->Quaternion[0]
               +this->Quaternion[1]*this->Quaternion[1]
               +this->Quaternion[2]*this->Quaternion[2]
               +this->Quaternion[3]*this->Quaternion[3]);
}
