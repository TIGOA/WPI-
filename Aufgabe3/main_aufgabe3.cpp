//
//  main.cpp
//  aufgabe 3
//
//  Created by Tianyi Gao on 21.12.21.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <random>
#include <vector>
#include <array>
#include <cassert>

#include "MyQuaternion.h"
#include "MyFunctions.h"
using namespace std;

// Abkuerzungen fuer Datentypen:
typedef std::array<double,4> Vec4d;

// for seed of random number generator in C++11

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_real_distribution<double> zufall(-1.,1.); //C++11 documentation
//http://www.cplusplus.com/reference/random/uniform_real_distribution/




//Hilfsfunktion fuer random_vec4d:
void zufall_in_einheitskreis(double &a, double &b, double &s){
    do{
        a = zufall(mt);
        b = zufall(mt);
        s = (a*a+b*b);
    }while(s>=1.);
}

// Algorithm 4 of Marsaglia paper, The Annals of Math. Stat. 1972,645-6
// random point on a surface
// hier: Methode 4: point on unit 4d-sphere
//
void random_vec4d(Vec4d &Q){
    double v1,v2,v3,v4,s1,s2;
    zufall_in_einheitskreis(v1,v2,s1);
    zufall_in_einheitskreis(v3,v4,s2);
    //
    const double tmp = sqrt(max(0.,(1.-s1))/s2);
    Q[0]= v1;
    Q[1]= v2;
    Q[2]= v3*tmp;
    Q[3]= v4*tmp;
}


// Aufgabe 3.2.A:
double get_theta(const MyQuaternion &Q){
    // einfügen..
    
    double theta_result;
//    double p[2];
    
   theta_result= acos(Q.Quaternion[3])*2;
//    p[0]=Q.Quaternion[0]/sin(theta_result/2);
//    p[1]=Q.Quaternion[1]/sin(theta_result/2);
//    p[2]=Q.Quaternion[2]/sin(theta_result/2);
    return theta_result;
    

}

//Aufgabe 3.2.B:
double get_theta_cubic(const MyQuaternion &Q){
    // einfügen..
    return 0;
}


//



int main(){
    //generate data:
    Vec4d tmp;
    
    int nmax;
    std::vector<MyQuaternion> QL(nmax);
    do{
        cout<<"Anzahl der Zufallsorientierungen eingeben:";
        cin>>nmax;
    }while(nmax<1);
    //random Initialisierung:
    /*....some code
     *
     */
    
    for(auto i=0;i<nmax;i++){
        MyQuaternion Qtmp(tmp[0],tmp[1],tmp[2],tmp[3]);
        random_vec4d(tmp);
        QL[i]=Qtmp;
      
    }
    
 
    

    //AUFGABE 3:

    //TEIL A)
    cout<<"Aufgabe A:"<<endl;
    /*some code; calls
     *
     */
    
    for(auto i=0;i<nmax;i++){

        for(auto j=0;j<nmax;j++){

         get_theta(QL[i]*(QL[j].conj()/QL[j].betrag()));
            

            
        }


    }
    
    //aufgabe_bearbeiten("random",QL,get_theta);

    //TEIL B)
    cout<<"Aufgabe B:"<<endl;
    /*some code; calls
     *
     */
   //  aufgabe_bearbeiten("cube",QL,get_theta_cubic);

    cout<<"DONE"<<endl;

    return 0;
}

