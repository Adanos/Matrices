#include "matrix.hpp"

Matrix::Matrix(int p_rowDimension, int p_columnDimension) :rowDimension(p_rowDimension), columnDimension(p_columnDimension)
{
   elements.resize(rowDimension, std::vector<double>(columnDimension));
}

Matrix::Matrix(double p_element) : rowDimension(1), columnDimension(1)
{
   elements.resize(rowDimension, std::vector<double>(columnDimension));
   elements[0][0] = p_element;
}

Matrix::Matrix(const Matrix& p_other) : rowDimension(p_other.rowDimension), columnDimension(p_other.columnDimension), elements(p_other.elements)
{
}

Matrix& Matrix::operator=(const Matrix& p_other)
{
   Matrix temp(p_other);
   swap(*this, temp);

   return *this;
}

Matrix::Matrix(Matrix&& p_other) :Matrix()
{
   swap(*this, p_other);
}

Matrix& Matrix::operator=(Matrix&& p_other)
{
   swap(*this, p_other);

   return *this;
}

void Matrix::addElements(std::vector<std::vector<double> >&  p_elements)
{
   rowDimension = p_elements.size();
   columnDimension = p_elements[0].size();
   elements = p_elements;
}

const Matrix Matrix::operator+(const Matrix& p_matrix) const
{
   checkDimensions(p_matrix, "Unable to add matrices. ");

   Matrix l_result = *this;

   for (int i = 0; i < rowDimension; ++i)
      for (int j = 0; j < columnDimension; ++j)
         l_result.elements[i][j] += p_matrix.elements[i][j];

   return l_result;
}

const Matrix Matrix::operator-(const Matrix& p_matrix) const
{
   checkDimensions(p_matrix, "Unable to subtraction matrices. ");

   Matrix l_result = *this;

   for (int i = 0; i < rowDimension; ++i)
      for (int j = 0; j < columnDimension; ++j)
         l_result.elements[i][j] -= p_matrix.elements[i][j];

   return l_result;
}

const Matrix Matrix::operator*(const Matrix& p_matrix) const
{
   if (this->columnDimension != p_matrix.rowDimension)
   {
      std::string l_message = "Unable to multiply matrices. ";
      l_message += getDimensionsMatrices(p_matrix);

      throw MatrixDimensionException(l_message);
   }
   IAlgorithmMultiplication *multiplication = new StrassenAlgorithm();
   Matrix l_result = *this;
   Matrix l_matrix = *&p_matrix;

   l_result = multiplication->multiply(l_result, l_matrix);

   return l_result;
}

double Matrix::getElement(const int p_firtsIndex, const int p_secondIndex)
{
   return elements[p_firtsIndex][p_secondIndex];
}

std::vector<std::vector<double> >& Matrix::getElements()
{
   return elements;
}

const std::string Matrix::getDimensionsMatrices(const Matrix& p_matrixB) const
{
   std::ostringstream l_oss;
   l_oss << "First matrix has dimension "
      << getRowDimension() << " x " << getColumnDimension()
      << ". Second matrix has dimension "
      << p_matrixB.getRowDimension() << " x " << p_matrixB.getColumnDimension();

   return l_oss.str();
}

void Matrix::checkDimensions(const Matrix& p_matrix, const std::string& p_messagePrefix) const
{
   if (columnDimension != p_matrix.columnDimension
      || rowDimension != p_matrix.rowDimension)
   {
      std::string l_message = p_messagePrefix;
      l_message += getDimensionsMatrices(p_matrix);

      throw MatrixDimensionException(l_message);
   }
}
