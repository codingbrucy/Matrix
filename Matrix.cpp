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
#include <memory>
using namespace std;

Matrix:: Matrix(int r,int c): rowCount(r),columnCount(c)
{
    if(r==c){isSquare=true;}
    cout<< "Matrix created...\n";
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
    cout<<"Printing Matrix...\n";
    for (int i=0; i<rowCount; i++)
    {
        for (int j=0;j<columnCount;j++)
        {
            cout<<setw(4)<< location[i][j];
        }
        cout<<endl;
    }
}
// miscellaneous
Matrix Matrix:: subMatrix(int i, int j)
{
    if ( i>(rowCount)|| j>(columnCount) || i<1||j<1) {exit(EXIT_FAILURE);}
    Matrix temp(this->rowCount-1,this->columnCount-1);
    double **ptr = new double*[temp.rowCount];
    for (int k=0;k<temp.rowCount;k++)
    {
        ptr[k]=new double [temp.columnCount];
    }
    temp.location=ptr;
    for(int k=0,m=0;k<temp.rowCount;k++)
    {
        if(m==i-1)m++;
        for (int l=0,n=0;l<temp.columnCount;l++)
        {
            if(n==j-1)n++;
            temp.setElement(k+1, l+1, (this->location)[m][n]);
            n++;
        }
        m++;
    }
    cout<<"Matrix truncated...\n";
    return temp;
}

double Matrix:: getDet()
{
    double temp=0;
    if(!isSquare) { cout<< "CANNOT CALCULATE DET FOR NON-SQUARE MATRICES\n"; exit(EXIT_FAILURE);}
    else
    {
        if(this->rowCount==2){ return (  (this->location)[0][0]*(this->location)[1][1] -(this->location)[1][0]*(this->location)[0][1] ); } // case of a 2 by 2
        int flag=1;
        for(int i=0;i<columnCount;i++)
        {
            Matrix subM=(*this).subMatrix(1, i+1);
            temp+= ( flag*(location[0][i])*(subM.getDet()) ) ;
            flag*=-1;
        }
    }
    return temp;
}
