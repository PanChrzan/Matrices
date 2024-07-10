#pragma once

#include <exception>
#include <iostream>
#include <string>

class WrongDimensionsError : public std::exception
{
private:
    std::string message;

public:
    WrongDimensionsError(const char *msg) : message(msg) {}

    const char *what() const throw()
    {
        return message.c_str();
    }
};