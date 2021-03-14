#include "FixedArray.h"

#include <iostream>

FixedArray::FixedArray(const int arraySize):BrokenArray(arraySize)
{}

FixedArray::~FixedArray()
{
   
}

FixedArray& FixedArray::operator=(const FixedArray& other)
{
    if (this != &other) {
        int* copy = new int[other.getSize()];
        for (size_t i = 0; i < other.getSize(); ++i) {
            copy[i] = other._array[i];
        }
        delete[] this->_array;
        this->_array = copy;
    }
    BrokenArray::operator=(other);
    return *this;
}

FixedArray::FixedArray(const FixedArray& other):BrokenArray(other.getSize())
{
     *this = other;
}


void FixedArray::addValueToMemory(const int value)
{
    for (int i = 0; i < this->getSize(); ++i)
    {
        _array[i] += value;
    }
}

int FixedArray::getMemorySumValue() const
{
    int sum = 0;

    for (int i = 0; i < this->getSize(); ++i)
    {
        sum += _array[i];
    }

    return sum;
}