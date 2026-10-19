#include "RandomGenerator.h"
#include <utility>

RandomGenerator::RandomGenerator(int min, int max)
    : min_val(min),
      max_val(max),
      random_engine(std::random_device{}()),
      int_distribution(0, 0)
{
    if (min_val > max_val)
    {
        std::swap(min_val, max_val);
    }
    int_distribution = std::uniform_int_distribution<int>(min_val, max_val);
}

int RandomGenerator::generate()
{
    return int_distribution(random_engine);
}
