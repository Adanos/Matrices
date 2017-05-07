#ifndef STRASSENALGORITHM_HPP
#define STRASSENALGORITHM_HPP
#include "IAlgorithmMultiplication.hpp"

class StrassenAlgorithm: public IAlgorithmMultiplication
{
public:
    StrassenAlgorithm();
    Matrix multiply(Matrix &p_matrixA, Matrix &p_matrixB);
private:
    bool isPowerOfTwo(int p_number);
    size_t findNearestPowerOfTwo(size_t p_number);
    Matrix resizeMatrix(Matrix &p_matrix, size_t p_dimension);
};

#endif // STRASSENALGORITHM_HPP
