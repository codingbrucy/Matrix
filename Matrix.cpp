//
//  Matrix.cpp
//  linear algebra
//
//  Created by Bruce Ning on 3/23/23.
//

#include "Matrix.hpp"
#include <iostream>
using namespace std;

Matrix:: Matrix(int r,int c): rowCount(r),columnCount(c)
{
    cout<< "Matrix created\n";
}

void Matrix:: setRow(int a)
{
    rowCount=a;
}
void Matrix:: setColumn(int a)
{
    columnCount=a;
}
void Matrix:: setArray (int** p)
{
    location=p;
}
