#include <iostream>
#include <vector>
#include "matrix.hpp"
#include <StrassenAlgorithm.hpp>

using namespace std;

int main()
{
   StrassenAlgorithm s;
   std::vector<std::vector<double> > a, b;
   Matrix A = Matrix(2, 3), B(2, 3), C;
   a.resize(2, std::vector<double>(3));
   b.resize(2, std::vector<double>(3));
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
      std::cout << "mnożenie " << C.getElement(0, 0) << std::endl;
   }
   catch(MatrixDimensionException& e)
   {
       std::cerr << "exception caught: " << e.what() << '\n';
   }
   //A.addElements(a);
   //B.addElements(b);

   return 0;
}

