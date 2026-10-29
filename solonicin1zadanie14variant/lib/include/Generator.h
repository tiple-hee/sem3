#pragma once

/**
 * @brief Абстрактный класс Generator
 */
class Generator
{
public:
    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Generator() = default;

    /**
     * @brief Виртуальный "генератор" значений массива
     * @return Сгенерированное целочисленное значение
     */
    virtual int generate() = 0;
};
