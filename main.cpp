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

Matrix* getMatrix();

int main()
{
    Matrix* M1=getMatrix();
    
    M1->printMatrix();
    M1->rref();
   
    
    M1->printMatrix();
}
Matrix* getMatrix()
{
    cout<< "How many rows?\n";
    int rows,columns;
    cin>>rows;
    cout<< "How many columns?\n";
    cin>>columns;
    Matrix*p = new Matrix(rows,columns);
   
    double ** p1 =new double* [rows];
    for (int i=0; i<rows;i++)
    {
        p1[i]=new double[columns];
    }
    // prompt user to input the matrix
    for (int i=0;i<rows;i++)
    {
        for( int j=0;j<columns;j++)
        {
            cout<<"row "<<i+1 << " column "<< j+1<<" :";
            cin>>p1[i][j];
        }
    }
    p->setArray(p1);
    return p;
}
