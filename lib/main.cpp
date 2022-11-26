#include <iostream>
#include "Matrix.h"

int main() {
    std::cout << "Hello" << std::endl;
    Matrix<int> intMatrix(5, 3, 3);
    intMatrix.Print();
    return 0;
}