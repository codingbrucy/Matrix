//
//  Fraction.cpp
//  Fraction
//
//  Created by Bruce Ning on 3/2/23.
//
#include<iostream>
#include "Fraction.hpp"
#include<cmath>
#include <string>
#include <ctime>
#include <cstdlib>
#include <memory>
using namespace std;
//constructor
int Fraction:: FractionCount =1;
//****************************CONSTRUCTOR****************************//
Fraction:: Fraction(long int nu, long int de, string des): FractionID(FractionCount++), description(des)
{
    if (de==0)
    {
        exit(EXIT_FAILURE); // correct erroneous input
    }
    if (de<0)
    {
        de=-de;
        nu=-nu;
    }// check for if de is negative
    
    long int g= getGCD(nu, de);
    nu/=g; de/=g;
    n=nu; d=de;
    cout<< "Fraction created"<<endl;
}

Fraction:: Fraction(double num)// an overloaded constructor that approximates doubles with fraction objects
{
    // handle the extreme cases 
    if ( num>=100000000) num=100000000;
    if ( num<=-100000000) num=-100000000;
    if ( num<=0.00000001 && num>0)num=0.000000001;
    if ( num>=0.00000001 && num<0)num=-0.000000001;
    //done
    bool isn=false;
    if (num<0)
    {
        num=-num;
        isn=true;
    }
     long int dextra=1;  // assign the integer part of num to nextra
     long int nextra=num;
    double temp=nextra; // temp is a type double with the value of int part of num
    while(temp!=num)
    {
        num*=10;
        long int john=num; // john gets the int part of the modified num
        long int billy= john%10;  // billy gets the right most digits of modified num
        temp*=10;
        temp+=billy;
        dextra*=10;
    }
    
    n=temp/(getGCD(static_cast<long int>(temp),dextra));
    d= dextra/(getGCD(static_cast<long int>(temp),dextra));
    if (isn)n=-n;
    cout<<"A new double variable has been converted to fraction\n";
}
//****************************CONSTRUCTORS****************************//


//****************************OPERATOR OVERLOAD IMPLEMENTATIONS************************************//
Fraction Fraction:: operator -()  //unary '-'
{
    Fraction temp(-n,d);
    return temp;
}

Fraction Fraction:: operator+ (const Fraction& other) const
{
    int n1= (this->n *other.d)+(other.n * this->d) ;
    int d1= (this->d)*other.d;
    Fraction temp(n1,d1);
    return temp;
}
Fraction& Fraction:: operator+=(const Fraction& other)  // overloading '+' & '+='
{
    *this=*this+other;
    return *this;  // (f1+=f2)+=f3;
}

Fraction Fraction:: operator* ( const Fraction& otter) const
{
    int n1= this->n * otter.n;
    int d1= this->d * otter.d;
    cout <<"In operator*... calling Fraction constructor now: \n";
    Fraction temp(n1,d1);
    return temp;
}
Fraction& Fraction:: operator *= (const Fraction& oter)  // overloading '*' & '*='
{
    *this = (*this) * oter;
    return *this;
}

Fraction Fraction::operator^(int e) const
{
    bool isN = false;
    if (e<0)
    {
        isN=true;
        e=-e;
    }  // get e to positive first and flag isN to deal with it when returning.
    int nu=n,de=d;
    for (int i=1;i<e; i++)
    {
        nu=nu*n;
        de=de*d;
    }
   
    if (! isN)
    {
        Fraction temp(nu,de);
        return temp;
    }
    Fraction temp2(de,nu);
    return temp2;
}
Fraction& Fraction:: operator^=(const int e)
{
    *this=*this^e;
    return *this;
}
double Fraction::operator^(double p) const
{
    double newnu=pow((this->n),p);
    double newde=pow((this->d),p);
    return static_cast<double>(newnu/newde);
}

Fraction Fraction:: operator*(int i) const
{

    int nu=(this->n)*i;
    
    Fraction temp(nu,(this->d));
    return temp;
}
Fraction& Fraction:: operator*=(int i)
{
    *this=*this*i;
    return *this;
}
// overloaded logical operators🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦
bool Fraction:: operator< (const Fraction& other) const
{
   
    if ( (*this) == other )  {return false;} // no need to account for both fraction being 0
    if ( (this->n *other.d)> (this->d *other.n) ) {return false;}// everything accounted for
    
    return true;
}
bool Fraction:: operator== (const Fraction& other) const
{
    if ( (this->n *other.d) == (this->d *other.n) ) {return true;}
    return false;
}
//⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️⛔️ crucial ones( '<' and '==')

bool Fraction:: operator> (const Fraction& other) const{
    if ( (*this)== other || (*this)< other) {return false;}
    return true;
}
bool Fraction:: operator<= (const Fraction& other) const{
    if ( (*this)== other || (*this)< other) {return true;}
    return false;
}
bool Fraction:: operator>= (const Fraction& other) const{
    if ( (*this)== other || (*this)> other) {return true;}
    return false;
}

bool Fraction:: operator!= (const Fraction& other) const{
    if ( (*this)== other) {return false;}
    return true;
}
//🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦🦦

Fraction& Fraction:: operator++()//pre-increment, passed by reference
{
    (this->n)+=(this->d);
   
    return *this;
}
Fraction Fraction:: operator++(int)// post-increment, not by reference
{
    Fraction temp=*this;
    (this->n)+=(this->d);
    
    return temp;
}
Fraction& Fraction:: operator--(){
    (this->n)-=(this->d);

    return *this;
}
Fraction Fraction:: operator--(int){
    Fraction temp=*this;
    (this->n)-=(this->d);
    return temp;
}




//***********************************************************************************************//



//****************************non-math related helpers****************************//
double Fraction:: toDouble(const Fraction& f)
{
    return (static_cast<double>(f.n) / static_cast<double>(f.d));
}

void Fraction:: print(bool bol)
{
    if (bol)
        cout<< "Description: " <<description<<"\tFraction:"<<n<<"/"<<d<<endl;
    else cout<<"Fraction "<<FractionID<<" is "<<n<<"/"<<d<<'\n';
}
void Fraction:: printDescription()
{
    this->print();
    cout<<"Description"<<":"<<description<<endl;
    
}
void Fraction::setDescription(string de)
{
    description=de;
}
//long Fraction:: getGCD(long int b, long int c)// improvable
//{
//    if (b<0)b=-b;
//    if (c<0)c=-c;
//
//
//    while (c!= 0)
//    {
//        long temp = c;
//        c=b%c;
//        b=temp;
//    }
//    return b;
//}
long int Fraction::getGCD(long int x,long int y)     //stein算法递归算法
{
    if(x<y)     //x是大数
    {
        long temp=x;
        x=y;
        y=temp;
    }
    if(y==0) return x;
    if((x&0x1)==0&&(y&0x1)==0) return 2*getGCD(x>>1,y>>1); //俩数都是偶数
    if((x&0x1)==0&&(y&0x1)!=0) return getGCD(x>>1,y);     //一偶一奇
    if((x&0x1)!=0&&(y&0x1)==0) return getGCD(x,y>>1);     //一奇一偶
    if((x&0x1)!=0&&(y&0x1)!=0) return getGCD((x-y)>>1,y); //俩奇
    return 0;
}


 // what exactly is this function being static good for? since the parameters never mentioned n or d
 // Would it have worked too if this wasn't a static?
 // would it be the same if b and c are passed as  'const reference' ?

Fraction Fraction:: generateFraction()
{
    long int seed=time(0);
    srand(seed);
    const int MAX=99,MIN=1;
    int newn=(rand()%(MAX-MIN+1)+MIN);
    int newd=(rand()%(MAX-MIN+1)+MIN);
    Fraction temp(newn, newd);
    return temp;
}

//****************************************************************************************************************//
