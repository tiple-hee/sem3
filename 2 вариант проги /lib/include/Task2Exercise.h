#pragma once

#include "Exercise.h"

/**
 * @brief Класс Task2Exercise абстрактного класса Exercise
 */
class Task2Exercise : public Exercise
{
public:
    /**
     * @brief Конструктор
     * @param src Ссылка на матрицу
     * @param gen Ссылка на генератор
     */
    Task2Exercise(Matrix &src, const Generator &gen);

    /**
     * @brief Перегруженный деструктор
     */
    ~Task2Exercise() override = default;

    /**
     * @brief Выполнить задание 2 (вставить после столбцов с нулевым элементом первый столбец)
     * @return Выполненное задание (новая матрица)
     */
    Matrix solve() override;
};
