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

