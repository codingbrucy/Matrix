//
//  Fraction.hpp
//  Fraction
//
//  Created by Bruce Ning on 3/2/23.
//

#ifndef Fraction_hpp
#define Fraction_hpp

#include <iostream>
#include <string>


using namespace std;
class Fraction {
    
    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);  // cout<<(...ostream?) f1<<f2;
    friend std::istream& operator>> (std::istream& in, Fraction& frac);
    
    //
    
private:
    
    long int n;
    long int d;
    int FractionID;
    static long int getGCD ( long int b,long int c);  // returns gcd of b and c
    static int FractionCount;
    string description;
    
public:
    //constructor prototype
    Fraction (long int nu=0, long int de=1, string des= "none.");   // constructor default value being (1/0)
    Fraction(double);
    //operator overload functions
    Fraction operator-();
    
    Fraction operator+ (const Fraction& ) const;
    Fraction& operator +=(const Fraction& );   // could it be void?// no
    
    Fraction operator* (const Fraction&) const; //🦦
    Fraction& operator*=( const Fraction&) ;
   
    Fraction operator^ (const int )const ;
    Fraction& operator ^=(const int );
    double operator^(double ) const;
    
    Fraction operator*(int k) const;
    Fraction& operator*=(int k);
    
    bool operator< (const Fraction& other) const;
    bool operator> (const Fraction& other) const;
    bool operator<= (const Fraction& other) const;
    bool operator>= (const Fraction& other) const;
    bool operator== (const Fraction& other) const;
    bool operator!= (const Fraction& other) const;
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);
    
    void print(bool bol=false);
    void printDescription();
    void setDescription(string);
    Fraction generateFraction();
    static double toDouble(const Fraction&);
};


#endif /* Fraction_hpp */
