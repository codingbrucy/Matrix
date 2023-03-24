//
//  Matrix.hpp
//  linear algebra
//
//  Created by Bruce Ning on 3/23/23.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <iostream>
#include "Fraction.hpp"

class Matrix
{

private:
    int rowCount;
    int columnCount;
    double det;
    double** location;
    bool isSquare=false;
    
public:
    Matrix(int r=1,int c=1);
    void setRow(int);
    void setColumn(int);
    void setElement(int, int, double);
    void setArray(double**);
    double getElement(int, int);
    void printMatrix();
    double getDet();
    void rref();
    Matrix subMatrix(int, int);
};
#endif /* Matrix_hpp */
