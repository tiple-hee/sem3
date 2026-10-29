#pragma once

#include "Exercise.h"

/**
 * @brief Класс Task1Exercise абстрактного класса Exercise
 */
class Task1Exercise : public Exercise
{
public:
    /**
     * @brief Конструктор
     * @param src Ссылка на матрицу
     * @param gen Ссылка на генератор
     */
    Task1Exercise(Matrix &src, const Generator &gen);

    /**
     * @brief Перегруженный деструктор
     */
    ~Task1Exercise() override = default;

    /**
     * @brief Выполнить задание 1 (заменить нечетные элементы каждой строки нулем)
     * @return Выполненное задание (новая матрица)
     */
    Matrix solve() override;
};
