#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <vector>
#include <matrixDimensionException.hpp>
#include <StrassenAlgorithm.hpp>

class Matrix
{
private:
   int rowDimension;
   int columnDimension;
   std::vector<std::vector<double> > elements;

   void checkDimensions(const Matrix& p_matrix, const std::string& p_messagePrefix) const;

public:
   Matrix() {}
   Matrix(double p_element);
   Matrix(int p_rowDimension, int p_columnDimension);
   Matrix(const Matrix& p_other);
   Matrix& operator=(const Matrix& p_other);
   ~Matrix() {}
   void addElements(std::vector<std::vector<double> >&  p_elements);
   const Matrix operator+(const Matrix& p_matrix) const;
   const Matrix operator-(const Matrix& p_matrix) const;
   const Matrix operator*(const Matrix& p_matrix) const;
   const int getRowDimension() const { return rowDimension; }
   const int getColumnDimension() const { return columnDimension; }
   const std::string getDimensionsMatrices(const Matrix& p_matrixB) const;
   double getElement(const int p_firtsIndex, const int p_secondIndex);
   std::vector<std::vector<double> >& getElements();
};

#endif // MATRIX_HPP
