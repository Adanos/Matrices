#include <iostream>
#include <vector>
#include "matrix.hpp"
#include <StrassenAlgorithm.hpp>

using namespace std;

int main()
{
   StrassenAlgorithm s;
   std::vector<std::vector<double> > a, b;
   Matrix A = Matrix(2, 3), B(3, 3), C;
   a.resize(2, std::vector<double>(3));
   b.resize(3, std::vector<double>(3));
   a[0][0] = 3;
   a[0][1] = 2;
   //a[1][1] = 45;
   b[0][0] = 3;
   b[0][1] = 2;
   //b[1][1] = 45;
   A.addElements(a);
   B.addElements(b);

   std::cout << A.getElement(0,1) << std::endl;
   try
   {
      C = A + B;
   }
   catch(MatrixDimensionException& e)
   {
       std::cerr << "exception caught: " << e.what() << '\n';
   }

   try
   {
      C = A * B;
      for (int i = 0; i < C.getRowDimension(); ++i)
         for (int j = 0; j < C.getRowDimension(); ++j)
            std::cout << i << " " << j << " " << C.getElement(i, j) << std::endl;
   }
   catch(MatrixDimensionException& e)
   {
       std::cerr << "exception caught: " << e.what() << '\n';
   }
   //A.addElements(a);
   //B.addElements(b);

   return 0;
}

