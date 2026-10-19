#pragma once
#include "Generator.h"

/**
 * @brief Класс ConstGenerator абстрактного класса Generator
 */
class ConstGenerator : public Generator
{
private:
    /**
     * @brief Значение константы
     */
    int constant_value;

public:
    /**
     * @brief Конструктор
     * @param value Значение, которое будет всегда возвращаться
     */
    explicit ConstGenerator(const int value);

    /**
     * @brief Деструктор
     */
    ~ConstGenerator() override = default;

    /**
     * @brief Генерация значения
     * @return Константное значение
     */
    int generate() override;
};
