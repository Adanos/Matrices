#include "matrix.hpp"

Matrix::Matrix(int p_rowDimension, int p_columnDimension) :rowDimension(p_rowDimension), columnDimension(p_columnDimension)
{
   elements.resize(rowDimension, std::vector<double>(columnDimension));
}

Matrix::Matrix(const Matrix& p_other): rowDimension(p_other.rowDimension), columnDimension(p_other.columnDimension), elements(p_other.elements)
{
}

Matrix& Matrix::operator=(const Matrix& p_other)
{
    if (this != &p_other)
    {
        rowDimension = p_other.rowDimension;
        columnDimension = p_other.columnDimension;
        elements = p_other.elements;
    }

    return *this;
}

void Matrix::addElements(std::vector<std::vector<double> >&  p_elements)
{
   elements = p_elements;
}

const Matrix Matrix::operator+(const Matrix& p_matrix) const
{
   Matrix result = *this;

   for (int i = 0; i < rowDimension; i++)
      for (int j = 0; j < columnDimension; j++)
         result.elements[i][j] += p_matrix.elements[i][j];

   return result;
}

const Matrix Matrix::operator-(const Matrix& p_matrix) const
{
   Matrix result = *this;

   for (int i = 0; i < rowDimension; i++)
      for (int j = 0; j < columnDimension; j++)
         result.elements[i][j] -= p_matrix.elements[i][j];

   return result;
}

const Matrix Matrix::operator*(const Matrix& p_matrix) const
{
   Matrix result = *this;

   return result;
}
