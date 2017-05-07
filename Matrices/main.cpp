#include <iostream>
#include <vector>
#include "matrix.hpp"
#include <StrassenAlgorithm.hpp>

using namespace std;

int main()
{
   StrassenAlgorithm s;
   std::vector<std::vector<double> > a, b;
   Matrix A = Matrix(2, 3), B(4,3), C;

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
   }
   catch(MatrixDimensionException& e)
   {
       std::cerr << "exception caught: " << e.what() << '\n';
   }
   //A.addElements(a);
   //B.addElements(b);
   cout << "Hello World!" << endl;

   return 0;
}

