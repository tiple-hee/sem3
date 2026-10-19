#pragma once
#include <random>
#include "Generator.h"

/**
 * @brief Генератор случайных чисел в заданном диапазоне
 */
class RandomGenerator : public Generator
{
private:
    /**
     * @brief Минимальное значение диапазона
     */
    int min_val;

    /**
     * @brief Максимальное значение диапазона
     */
    int max_val;

    /**
     * @brief Механизм генерации псевдослучайных чисел
     */
    std::mt19937 random_engine;

    /**
     * @brief Распределение случайных чисел
     */
    std::uniform_int_distribution<int> int_distribution;

public:
    /**
     * @brief Конструктор
     * @param min Минимальное значение
     * @param max Максимальное значение
     */
    RandomGenerator(int min, int max);

    /**
     * @brief Деструктор
     */
    ~RandomGenerator() override = default;

    /**
     * @brief Генерация случайного числа
     * @return Случайное число в заданном диапазоне
     */
    int generate() override;
};
