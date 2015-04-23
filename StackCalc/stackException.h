#pragma once

#include <exception>
#include <string>

class StackException
{
public:
    StackException(const std::string &errow);
    std::string errowString();

private:
    std::string errow;
};


