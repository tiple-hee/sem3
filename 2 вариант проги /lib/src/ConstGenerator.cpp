#include "ConstGenerator.h"

ConstGenerator::ConstGenerator(const int value) : constant_value(value) {}

int ConstGenerator::generate() const
{
    return this->constant_value;
}
