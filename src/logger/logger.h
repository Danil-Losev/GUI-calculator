//
// Created by user on 15.10.2025.
//

#ifndef GUI_CALCULATOR_LOGGER_H
#define GUI_CALCULATOR_LOGGER_H

#include <iostream>
#include <sstream>

class logger
{
public:
    logger() = default;

    ~logger()
    {
        std::cout << stream.str();
    }

    template <typename T>
    logger& operator<<(const T& value)
    {
        stream << value;
        return *this;
    }

private:
    std::ostringstream stream;
};


#endif //GUI_CALCULATOR_LOGGER_H
