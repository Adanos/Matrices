#ifndef IALGORITHMMULTIPLICATION
#define IALGORITHMMULTIPLICATION
#include "../matrix.hpp"
class Matrix;
class IAlgorithmMultiplication
{
public:
     virtual Matrix multiply(Matrix &p_matrixA, Matrix &p_matrixB) = 0;
};
#endif // IALGORITHMMULTIPLICATION

