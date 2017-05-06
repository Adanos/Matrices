#include <iostream>
#include <vector>
#include "matrix.hpp"
#include <StrassenAlgorithm.hpp>

using namespace std;

int main()
{
   StrassenAlgorithm s;
   std::vector<std::vector<double> > a, b;
   Matrix A = Matrix(2, 3), B(2,3), C;
   C = A + B;
   //A.addElements(a);
   //B.addElements(b);
   cout << "Hello World!" << endl;

   return 0;
}

