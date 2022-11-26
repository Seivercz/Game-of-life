#include <cstddef>
#include <iostream>

template <typename T>
// original: https://www.bestprog.net/en/2019/08/23/c-an-example-of-creating-a-template-class-matrix-dynamic-memory-allocation/
class Matrix
{
private:
    T **M; // THE matrix
    int m; // Column length
    int n; // Row length

public:
    /**
     * @brief Construct matrix with default value (which indicates type too!) with MxN dimensions
     * @param T: default value of created points MxN
     * @param _m: M size of the matrix
     * @param _n: N size of the matrix
     */
    Matrix(T defaultValue, int _m, int _n)
    {
        m = _m;
        n = _n;

        // Allocate memory for columns
        M = (T **)new T *[m];

        // Allocate memory for row length to each column
        for (size_t i = 0; i < m; i++)
        {
            M[i] = (T *)new T[n];
        }

        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                M[i][j] = defaultValue;
            }
        }
    }

    // /**
    //  * Copy constructor
    // */
    // Matrix(const Matrix& _M);

    ~Matrix()
    {
        if (n > 0)
        {
            for (size_t i = 0; i < m; i++)
            {
                delete[] M[i];
            }
        }
        if (m > 0)
        {
            delete[] M;
        }
    }

    T getValue(int i, int j)
    {
        return M[i][j];
    }

    void setValue(int i, int j, T value)
    {
        M[i][j] = value;
    }

    /**
     * Copy operator
     */
    Matrix operator=(const Matrix &_M)
    {
        ~Matrix();
    }
    void Print()
    {
        std::cout << std::endl;
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
                std::cout << M[i][j] << "\t";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};