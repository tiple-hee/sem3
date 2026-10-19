#include "InputGenerator.h"
#include <iostream>

InputGenerator::InputGenerator(std::istream &input) : input_stream(input) {}

int InputGenerator::generate()
{
    int value = 0;
    this->input_stream >> value;
    return value;
}
