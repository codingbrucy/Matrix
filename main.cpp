//
//  main.cpp
//  linear algebra
//
//  Created by Bruce Ning on 3/23/23.
//

#include <iostream>
#include <cmath>
#include "Matrix.hpp"

using namespace std;

int main()
{
    cout<< "How many rows?\n";
    int rows,columns;
    cin>>rows;
    cout<< "How many columns?\n";
    cin>>columns;
    Matrix M1(rows,columns);
   
    int ** p =new int* [rows];
    for (int i=0; i<rows;i++)
    {
        p[i]=new int[columns];
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
    
    
}
