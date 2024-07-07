#pragma once
#include<vector>

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

    T& operator()(unsigned int row, unsigned int column)
    {
        return this->_data->at((row-1)*this->_columns + (column - 1));
    }
    
private:
    unsigned int _rows, _columns;
    std::vector<T>* _data;
};