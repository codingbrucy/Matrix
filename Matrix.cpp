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
            if(location[i][j]==0|| (location[i][j]>0&& location[i][j]<0.0001)||(location[i][j]<0 && location[i][j]>=0.0001 ) )
            {
            cout<<setw(4)<<"0";
            }
           else
               cout<<setw(4)<<setprecision(2)<< location[i][j];
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
//🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀row operations🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀
void Matrix:: rowSwap(int i,int j)
{
    if( i>rowCount || j>rowCount) exit(EXIT_FAILURE);
    double temp;
    for (int k=0; k<columnCount; k++)
    {
        temp=location[i-1][k];
        location[i-1][k]=location[j-1][k];
        location[j-1][k]=temp;
    }
}
void Matrix:: rowMultiply(int m, double a)
{
    for (int k=0; k<columnCount; k++)
    {
        (location[m-1][k])*=a;
    }
}
void Matrix:: rowAddition(double a, int i, int j)// eg: a*(Ri) + Rj = Rj(new)
{
    for (int k=0; k<columnCount; k++)
    {
        location[j-1][k]=a*location[i-1][k]+location[j-1][k];
    }
}
//🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀🦀
void Matrix:: rref()
{
    for (int i=1;i<=rowCount;i++)
    {
        int r=i+1;
        while (location[i-1][i-1]==0 && r<=rowCount)
        {
            rowSwap(i, r);
            r++;
        }//move rows below up if zero encountered
        if(location[i-1][i-1]==0) continue;
        rowMultiply(i, (1/(location[i-1][i-1])) ); // make 1 at (i,i)
        for( int o=0;o<rowCount;o++)
        {
            if (o==i-1) continue;
            double scalar=(-1)*location[o][i-1];
            rowAddition(scalar,i,o+1);
        }
        // move down zero rows...
           for (int b=rowCount;b>1;b--)
           {
               for(int j=1;j<b;j++)
               {
                   if (isZeroRow(j)) {rowSwap(j, j+1);}
               }
           }
     }
    if (rowCount<columnCount)// check for pivot columns undetected
    {
        //make sure rows are in order
    
        int i=rowCount;
        int j=i;
        while (location[i-1][j]!=0 || j<columnCount )
        {
            if (subMatrix(i, j+1).isZeroRow(i-1) && location[i][j]!=0)
            {
                rowSwap(i, i-1);
                rowMultiply(i, (1/(location[i-1][j])) );
                for( int o=0;o<i-1;o++)
                {
                    double scalar=(-1)*location[o][j];
                    rowAddition(scalar,i,o+1);
                }
                j++;
            }
            j++;
        }
    }
}
//💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌RREF💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌💌
bool Matrix::isZeroRow(int i)
{
    bool flag=true;
    for (int j=0;j<columnCount;j++)
    {
        if(location[i-1][j]!=0) flag= false;
    }
    if (flag) return true;
    else return false;
}
