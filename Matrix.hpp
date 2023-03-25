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
    void makeUnitVector(int i);
    bool isZeroRow(int i);

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
    void rowSwap(int,int);
    void rowMultiply(int, double);
    void rowAddition(double a, int i, int j);// eg: a*(Ri) + Rj = Rj(new)
    
};
#endif /* Matrix_hpp */
