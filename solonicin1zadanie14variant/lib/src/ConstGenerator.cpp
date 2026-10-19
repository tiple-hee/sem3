#include "ConstGenerator.h"

ConstGenerator::ConstGenerator(int value) : constant_value(value) {}

int ConstGenerator::generate()
{
    return this->constant_value;
}
