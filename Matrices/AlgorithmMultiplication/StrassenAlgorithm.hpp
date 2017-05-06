#ifndef STRASSENALGORITHM_HPP
#define STRASSENALGORITHM_HPP
#include "IAlgorithmMultiplication.hpp"

class StrassenAlgorithm: public IAlgorithmMultiplication
{
public:
    StrassenAlgorithm();
    Matrix multiply(Matrix p_matrixA, Matrix p_matrixB);
};

#endif // STRASSENALGORITHM_HPP
