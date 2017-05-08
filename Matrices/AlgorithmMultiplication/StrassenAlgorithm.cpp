#include "StrassenAlgorithm.hpp"

StrassenAlgorithm::StrassenAlgorithm()
{

}

Matrix StrassenAlgorithm::multiply(Matrix &p_matrixA, Matrix &p_matrixB)
{
   int l_columnDimensionA = p_matrixA.getColumnDimension();
   int l_rowDimensionA = p_matrixA.getRowDimension();
   int l_columnDimensionB = p_matrixB.getColumnDimension();
   int l_rowDimensionB = p_matrixB.getRowDimension();

   if (l_columnDimensionA == 1 && l_rowDimensionA == 1)
   {
      double p_result = p_matrixA.getElement(0, 0) * p_matrixB.getElement(0, 0);
      return Matrix(p_result);
   }
   if (l_columnDimensionA != l_rowDimensionA || l_columnDimensionB != l_rowDimensionB
      || l_columnDimensionA != l_rowDimensionB)
   {
      int l_max = l_columnDimensionA > l_rowDimensionA ? l_columnDimensionA : l_rowDimensionA;
      l_max = l_max > l_rowDimensionB ? l_max : l_rowDimensionB;

      if (!isPowerOfTwo(l_max))
      {
         l_max = findNearestPowerOfTwo(l_max);
      }
      p_matrixA = resizeMatrix(p_matrixA, l_max);
      p_matrixB = resizeMatrix(p_matrixB, l_max);
   }
   else if (!isPowerOfTwo(l_columnDimensionA))
   {
      l_columnDimensionA = findNearestPowerOfTwo(l_columnDimensionA);
      p_matrixA = resizeMatrix(p_matrixA, l_columnDimensionA);
      p_matrixB = resizeMatrix(p_matrixB, l_columnDimensionA);
   }

   subMatricesA = createSubMatrices(p_matrixA);
   subMatricesB = createSubMatrices(p_matrixB);

   int l_sizeMatrix = p_matrixA.getColumnDimension();
   Matrix ma11, ma12, ma21, ma22, mb11, mb12, mb21, mb22;

   ma11 = subMatricesA[0][0];
   ma12 = subMatricesA[0][1];
   ma21 = subMatricesA[1][0];
   ma22 = subMatricesA[1][1];
   mb11 = subMatricesB[0][0];
   mb12 = subMatricesB[0][1];
   mb21 = subMatricesB[1][0];
   mb22 = subMatricesB[1][1];

   Matrix M1 = (ma11 + ma22) * (mb11 + mb22);
   Matrix M2 = (ma21 + ma22) * mb11;
   Matrix M3 = ma11 * (mb12 - mb22);
   Matrix M4 = ma22 * (mb21 - mb11);
   Matrix M5 = (ma11 + ma12) * mb22;
   Matrix M6 = (ma21 - ma11) * (mb11 + mb12);
   Matrix M7 = (ma12 - ma22) * (mb21 + mb22);

   Matrix C11 = M1 + M4 - M5 + M7;
   Matrix C12 = M3 + M5;
   Matrix C21 = M2 + M4;
   Matrix C22 = M1 - M2 + M3 + M6;

   return mergeMatrices(C11, C12, C21, C22, l_sizeMatrix);
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
   std::vector<std::vector<double> > l_elements = p_matrix.getElements();

   l_elements.resize(p_dimension);
   for (int i = 0; i < p_dimension; ++i)
      l_elements[i].resize(p_dimension);
   l_matrix.addElements(l_elements);
   return l_matrix;
}

std::vector<std::vector<Matrix> > StrassenAlgorithm::createSubMatrices(Matrix& p_matrix)
{
   int l_columnDimension = p_matrix.getColumnDimension();
   int l_rowDimension = p_matrix.getRowDimension();
   std::vector<std::vector<Matrix> > l_subMatrices;

   if (l_columnDimension > 1 && l_columnDimension == l_rowDimension)
   {
      int l_sizeMatrix = l_columnDimension;

      l_subMatrices.resize(2, std::vector<Matrix>(2));

      for (int i = 0; i < 2; ++i)
         for (int j = 0; j < 2; ++j)
            l_subMatrices[i][j] = Matrix(l_sizeMatrix / 2, l_sizeMatrix / 2);

      for (int i = 0; i < l_sizeMatrix / 2; ++i)
         for (int j = 0; j < l_sizeMatrix / 2; ++j)
         {
            l_subMatrices[0][0].getElements()[i][j] = p_matrix.getElement(i, j);
            l_subMatrices[0][1].getElements()[i][j] = p_matrix.getElement(i, j + l_sizeMatrix / 2);
            l_subMatrices[1][0].getElements()[i][j] = p_matrix.getElement(i + l_sizeMatrix / 2, j);
            l_subMatrices[1][1].getElements()[i][j] = p_matrix.getElement(i + l_sizeMatrix / 2, j + l_sizeMatrix / 2);
         }
   }

   return l_subMatrices;
}

Matrix StrassenAlgorithm::mergeMatrices(Matrix& p_matrix1, Matrix& p_matrix2, Matrix& p_matrix3,
                                        Matrix& p_matrix4, int p_sizeMatrix)
{
   Matrix l_resultMatrixC;
   std::vector<std::vector<double> > l_elementsMatrixC(p_sizeMatrix, std::vector<double>(p_sizeMatrix));

   for (int i = 0; i < p_sizeMatrix / 2; ++i)
      for (int j = 0; j < p_sizeMatrix / 2; ++j)
      {
         l_elementsMatrixC[i][j] = p_matrix1.getElement(i, j);
         l_elementsMatrixC[i][j + p_sizeMatrix / 2] = p_matrix2.getElement(i, j);
         l_elementsMatrixC[i + p_sizeMatrix / 2][j] = p_matrix3.getElement(i, j);
         l_elementsMatrixC[i + p_sizeMatrix / 2][j + p_sizeMatrix / 2] = p_matrix4.getElement(i, j);
      }

   l_resultMatrixC.addElements(l_elementsMatrixC);
   return l_resultMatrixC;
}
