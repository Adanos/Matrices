#ifndef MATRIXDIMENSIONEXCEPTION_HPP
#define MATRIXDIMENSIONEXCEPTION_HPP
#include <iostream>
#include <sstream>

class MatrixDimensionException : public std::exception
{
private:
    std::string message;
public:
    MatrixDimensionException() {}
    MatrixDimensionException(std::string &p_message);
    virtual const char* what() const throw();
};

#endif // MATRIXDIMENSIONEXCEPTION_HPP
