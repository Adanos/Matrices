#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <vector>

class Matrix
{
private:
   int rowDimension;
   int columnDimension;
   std::vector<std::vector<double> > elements;

public:
   Matrix() {}
   Matrix(int p_rowDimension, int p_columnDimension);
   Matrix(const Matrix& p_other);
   Matrix& operator=(const Matrix& p_other);
   ~Matrix() {}
   void addElements(std::vector<std::vector<double> >&  p_elements);
   const Matrix operator+(const Matrix& p_matrix) const;
   const Matrix operator-(const Matrix& p_matrix) const;
   const Matrix operator*(const Matrix& p_matrix) const;
};

#endif // MATRIX_HPP
