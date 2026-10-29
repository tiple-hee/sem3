#pragma once

#include "Matrix.h"
#include "Generator.h"

/**
 * @brief Виртуальный класс Exercise
 */
class Exercise
{
protected:
    /**
     * @brief Ссылка на исходную матрицу
     */
    Matrix &source;

    /**
     * @brief Ссылка на генератор значений
     */
    const Generator &generator;

public:
    /**
     * @brief Конструктор
     * @param src Ссылка на исходную матрицу
     * @param gen Ссылка на генератор
     */
    Exercise(Matrix &src, const Generator &gen);

    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Exercise() = default;

    /**
     * @brief Виртуальный метод решения задания
     * @return Новая матрица - результат решения задания
     */
    virtual Matrix solve() = 0;
};
