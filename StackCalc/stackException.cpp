#include "stackException.h"

StackException::StackException(const std::string &newErrow) : errow(newErrow)
{}

std::string StackException::errowString()
{
    return errow;
}
