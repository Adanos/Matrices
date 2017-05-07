#include "matrixDimensionException.hpp"

MatrixDimensionException::MatrixDimensionException(std::string &p_message)
    : message(p_message)
{

}

const char* MatrixDimensionException::what() const throw()
{
    return message.c_str();
}
