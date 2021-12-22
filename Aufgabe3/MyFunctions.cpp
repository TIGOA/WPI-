/*
 * MyFunctions.cpp
 *
 *  Created on: 09.12.2021
 *      Author: DWeygand IAM-CMS
 */

#include <cmath>
#include <iostream>
#include "MyFunctions.h"
#include <iomanip>
#include <vector>

using namespace std;

MyQuaternion quaternion_rotation(double x,double y,double z,double const theta){

  // Quellcode implememtieren
    
       // Achse normiereren
        double xn = x/sqrt(x*x+y*y+z*z);
        double yn = y/sqrt(x*x+y*y+z*z);
        double zn = z/sqrt(x*x+y*y+z*z);
    
        // berechnen Einheitsquaternion
        const double e1 = xn*sin(theta*PI/360.);
        const double e2 = yn*sin(theta*PI/360.);
        const double e3 = zn*sin(theta*PI/360.);
        const double e4 = 1*cos(theta*PI/360.);
    
        MyQuaternion result(e1,e2,e3,e4);
        return result;
    
  
}

MyQuaternion rotateX(MyQuaternion const &X,MyQuaternion const &Q){
  // Quellcode implementieren: und auch in Aufgabe3 einfügen
    MyQuaternion Q_Inverse;
    MyQuaternion X_rot;
        // inverse of Q
    Q_Inverse = Q.conj()/Q.betrag();
//    Q_Inverse = Q.conj()/Q.norm();
    
        
        X_rot = Q*X*Q_Inverse;
        return X_rot;
}


/*
 *  vorgegeben:
 *
 */
void Qprint(const MyQuaternion &Q,const std::string txt=""){
	cout<<txt<<"("<<Q[0]<<","<<Q[1]<<","<<Q[2]<<","<<Q[3]<<")"<<endl;
}

