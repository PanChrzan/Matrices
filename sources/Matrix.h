#pragma once
#include<vector>

template <typename T>
class Matrix
{
public:
    Matrix(unsigned int rows, unsigned int columns) : _rows(rows), _columns(columns)
    {
        _data = new std::vector<float>(_rows * _columns, 0);
    }
    unsigned int getSize()
    {
        return _data->size();
    }

private:
    unsigned int _rows, _columns;
    std::vector<T>* _data;
};