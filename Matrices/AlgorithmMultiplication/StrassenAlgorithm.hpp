#ifndef STRASSENALGORITHM_HPP
#define STRASSENALGORITHM_HPP
#include "IAlgorithmMultiplication.hpp"

class StrassenAlgorithm: public IAlgorithmMultiplication
{
private:
   std::vector<std::vector<Matrix> > subMatricesA, subMatricesB;
public:
    StrassenAlgorithm();
    Matrix multiply(Matrix &p_matrixA, Matrix &p_matrixB);
private:
    bool isPowerOfTwo(int p_number);
    size_t findNearestPowerOfTwo(size_t p_number);
    Matrix resizeMatrix(Matrix &p_matrix, size_t p_dimension);
    Matrix mergeMatrices(Matrix& p_matrix1, Matrix& p_matrix2, Matrix& p_matrix3, Matrix& p_matrix4,
                         int p_sizeMatrix);
    std::vector<std::vector<Matrix> > createSubMatrices(Matrix& p_matrix);
};

#endif // STRASSENALGORITHM_HPP
