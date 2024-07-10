#pragma once
#include <vector>
#include "Errors.hpp"

template <typename T>
class Matrix
{
public:
    Matrix(unsigned int rows, unsigned int columns) : _rows(rows), _columns(columns)
    {
        _data = new std::vector<T>(_rows * _columns, 0);
    }

    unsigned int getSize()
    {
        return _data->size();
    }

    T &operator()(unsigned int row, unsigned int column)
    {
        return _data->at((row - 1) * _columns + (column - 1));
    }

    friend Matrix operator+(Matrix<T> &mat_left, Matrix<T> &mat_right)
    {
        if (mat_left._rows != mat_right._rows && mat_left._columns != mat_right._columns)
        {
            throw WrongDimensionsError("When adding two matrices, both must have the same dimensions.");
        }

        Matrix ret(mat_left._rows, mat_left._columns);
        for (unsigned int i = 1; i <= mat_left._rows; i++)
        {
            for (unsigned int j = 1; j <= mat_left._columns; j++)
                ret(i, j) = mat_left(i, j) + mat_right(i, j);
        }
        return ret;
    }

private:
    unsigned int _rows, _columns;
    std::vector<T> *_data;
};