//
//  main.cpp
//  linear algebra
//
//  Created by Bruce Ning on 3/23/23.
//

#include <iostream>
#include <cmath>
#include "Matrix.hpp"
#include "Fraction.hpp"

using namespace std;

int main()
{
    cout<< "How many rows?\n";
    int rows,columns;
    cin>>rows;
    cout<< "How many columns?\n";
    cin>>columns;
    Matrix M1(rows,columns);
   
    double ** p =new double* [rows];
    for (int i=0; i<rows;i++)
    {
        p[i]=new double[columns];
    }
    // prompt user to input the matrix
    for (int i=0;i<rows;i++)
    {
        for( int j=0;j<columns;j++)
        {
            cout<<"row "<<i+1 << " column "<< j+1<<" :";
            cin>>p[i][j];
        }
    }
    M1.setArray(p);
    double temp=M1.getDet();
    cout<<temp<<endl;
    return 0;
}
