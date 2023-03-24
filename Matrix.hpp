//
//  Matrix.hpp
//  linear algebra
//
//  Created by Bruce Ning on 3/23/23.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <iostream>

class Matrix
{

private:
    int rowCount;
    int columnCount;
    int det;
    int** location;
    
    
public:
    Matrix(int r=1,int c=1);
    void setRow(int);
    void setColumn(int);
    void setElement(int, int, int);
    void setArray(int**);
    
};
#endif /* Matrix_hpp */
