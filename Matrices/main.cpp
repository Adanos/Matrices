#include <iostream>
#include <vector>
#include "matrix.hpp"

void checkInputData()
{
   if (std::cin.fail())
   {
      throw std::invalid_argument("Invalid data provider. Program is terminated.");
   }
}

void printMatrix(Matrix& matrix)
{
   std::cout << "Result" << std::endl;

   for (int i = 0; i < matrix.getRowDimension(); ++i)
   {
      for (int j = 0; j < matrix.getColumnDimension(); ++j)
         std::cout << matrix.getElement(i, j) << " ";

      std::cout << "\n";
   }
}

Matrix loadData(std::string p_nameMatrix)
{
   int rowDimension, columnDimension;
   std::vector<std::vector<double> > elements;
   std::cout << "Enter dimensions of " << p_nameMatrix << " matrix " <<
      "(first row then column, dimensions must be greater than 1 and integer)." << "\n";
   std::cin >> rowDimension >> columnDimension;

   checkInputData();
   std::cout << "rowDimension " << rowDimension << "\n";
   if (rowDimension < 1 || columnDimension < 1)
      throw std::invalid_argument("Dimension must be greater than 0. Program is terminated.");

   Matrix matrix(rowDimension, columnDimension);
   elements.resize(rowDimension, std::vector<double>(columnDimension));
   std::cout << "Enter elements of " << p_nameMatrix << " matrix row by row." << "\n";
   for (int i = 0; i < rowDimension; ++i)
      for (int j = 0; j < columnDimension; ++j)
         std::cin >> elements[i][j];

   checkInputData();

   matrix.addElements(elements);

   return matrix;
}

int main()
{
   try
   {
      Matrix firstMatrix = loadData("first");
      Matrix secondMatrix = loadData("second");
      Matrix resultMatrix;

      printMatrix(firstMatrix);
      printMatrix(secondMatrix);

      try
      {
         std::cout << "Adding matrices" << "\n";
         resultMatrix = firstMatrix + secondMatrix;
         printMatrix(resultMatrix);

      }
      catch(MatrixDimensionException& e)
      {
          std::cerr << "exception caught: " << e.what() << '\n';
      }

      try
      {
         std::cout << "Subtracting matrices" << "\n";
         resultMatrix = firstMatrix - secondMatrix;
         printMatrix(resultMatrix);
      }
      catch(MatrixDimensionException& e)
      {
          std::cerr << "exception caught: " << e.what() << '\n';
      }

      try
      {
         std::cout << "Multiplying matrices" << "\n";
         resultMatrix = firstMatrix * secondMatrix;
         printMatrix(resultMatrix);
      }
      catch(MatrixDimensionException& e)
      {
          std::cerr << "exception caught: " << e.what() << '\n';
      }
   }
   catch (std::invalid_argument& e)
   {
      std::cerr << "exception caught: " << e.what() << '\n';
   }
   catch (std::length_error& e)
   {
      std::cerr << "exception caught: " << e.what() << '\n';
   }
   catch (std::bad_alloc& e)
   {
      std::cerr << "exception caught: " << e.what() << '\n';
   }

   std::cout << std::endl;

   return 0;
}

