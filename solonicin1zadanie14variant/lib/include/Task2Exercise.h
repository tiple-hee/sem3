#pragma once

#include "Exercise.h"

/**
 * @brief класс Task2Exercise абстрактного класса Exercise
 */
class Task2Exercise : public Exercise
{
public:
    /**
     * @brief Конструктор
     * @param src Ссылка на матрицу
     * @param gen Ссылка на генератор
     */
    Task2Exercise(Matrix &src, Generator &gen);

    /**
     * @brief Перегруженный деструктор
     */
    ~Task2Exercise() override = default;

    /**
     * @brief Выполнить задание 2 (вставить первый столбец после столбцов с нулем)
     * @return Выполненное задание (новая матрица)
     */
    Matrix solve() override;
};
