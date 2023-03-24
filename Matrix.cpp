//
//  Matrix.cpp
//  linear algebra
//
//  Created by Bruce Ning on 3/23/23.
//

#include "Matrix.hpp"
#include <iostream>
#include "Fraction.hpp"
#include <iomanip>
using namespace std;

Matrix:: Matrix(int r,int c): rowCount(r),columnCount(c)
{
    cout<< "Matrix created\n";
}
//setters
void Matrix:: setRow(int a) {rowCount=a;}
void Matrix:: setColumn(int a)  {columnCount=a;}
void Matrix:: setElement(int i, int j, double n)   {location[i-1][j-1]=n;}
void Matrix:: setArray (double** p)    {location=p;}
//getters
double Matrix:: getElement(int i, int j) { return location[i-1][j-1] ;}
void Matrix:: printMatrix()
{
    cout<<"Matrix:\n";
    for (int i=0; i<rowCount; i++)
    {
        for (int j=0;j<columnCount;j++)
        {
            cout<<setw(4)<< location[i][j];
        }
        cout<<endl;
    }
}
