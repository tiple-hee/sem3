#pragma once
#include <iosfwd>
#include "Generator.h"

/**
 * @brief Класс InputGenerator абстрактного класса Generator
 */
class InputGenerator : public Generator
{
private:
    /**
     * @brief Ссылка на поток ввода
     */
    std::istream &input_stream;

public:
    /**
     * @brief Конструктор
     * @param input Ссылка на используемый поток ввода
     */
    explicit InputGenerator(std::istream &input);

    /**
     * @brief Деструктор
     */
    ~InputGenerator() override = default;

    /**
     * @brief Считывание числа из потока
     * @return Считанное число, иначе 0 в случае ошибки ввода
     */
    int generate() override;
};
