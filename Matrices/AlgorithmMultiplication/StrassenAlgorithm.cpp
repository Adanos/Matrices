#include "StrassenAlgorithm.hpp"

StrassenAlgorithm::StrassenAlgorithm()
{

}

Matrix StrassenAlgorithm::multiply(Matrix &p_matrixA, Matrix &p_matrixB)
{
   if (p_matrixA.getColumnDimension() == 1 && p_matrixA.getRowDimension() == 1)
   {
      double p_result = p_matrixA.getElement(0, 0) * p_matrixB.getElement(0, 0);
      return Matrix(p_result);
   }
   return Matrix();
}

bool StrassenAlgorithm::isPowerOfTwo(int p_number)
{
   return (p_number != 0) && !(p_number & (p_number - 1));
}

size_t StrassenAlgorithm::findNearestPowerOfTwo(size_t p_number)
{
   --p_number;
   p_number |= p_number >> 1;
   p_number |= p_number >> 2;
   p_number |= p_number >> 4;
   p_number |= p_number >> 8;
   p_number |= p_number >> 16;
   return ++p_number;
}

Matrix StrassenAlgorithm::resizeMatrix(Matrix &p_matrix, size_t p_dimension)
{
   Matrix l_matrix(p_dimension, p_dimension);
   l_matrix.addElements(p_matrix.getElements());
}
