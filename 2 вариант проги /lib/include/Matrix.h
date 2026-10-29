#pragma once
#include <iosfwd>
#include <string>
#include <vector>
#include "Generator.h"

/**
 * @brief Класс двумерного массива
 */
class Matrix
{
private:
    /**
     * @brief Указатель на массив
     */
    std::vector<std::vector<int>> matrix_data;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Matrix();

    /**
     * @brief Конструктор матрицы rows * columns, заполненной нулями
     * @param rows Количество строк
     * @param cols Количество столбцов
     */
    Matrix(const size_t rows, const size_t cols);

    /**
     * @brief Конструктор копирования
     * @param other Ссылка на другую матрицу
     */
    Matrix(const Matrix &other) = default;

    /**
     * @brief Конструктор перемещения
     * @param other Перемещаемый объект
     */
    Matrix(Matrix &&other) noexcept = default;

    /**
     * @brief Деструктор
     */
    ~Matrix() = default;

    /**
     * @brief Оператор присваивания копированием
     * @param other Ссылка на другую матрицу
     * @return Ссылка на скопированную матрицу
     */
    Matrix &operator=(const Matrix &other) = default;

    /**
     * @brief Оператор присваивания перемещением
     * @param other Перемещаемый объект
     * @return Ссылка на перемещенную матрицу
     */
    Matrix &operator=(Matrix &&other) noexcept = default;

    /**
     * @brief Перегрузка оператора вывода
     * @param os Поток вывода
     * @param matrix Матрица для вывода
     * @return Перегруженный поток вывода
     */
    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

    /**
     * @brief Перегрузка оператора ввода
     * @param is Поток ввода
     * @param matrix Матрица для ввода
     * @return Перегруженный поток ввода
     */
    friend std::istream &operator>>(std::istream &is, Matrix &matrix);

    /**
     * @brief Оператор проверки на равенство
     * @param other - ссылка на другую матрицу
     * @return 1 - если матрицы равны, иначе 0
     */
    bool operator==(const Matrix &other) const;

    /**
     * @brief Оператор проверки на неравенство
     * @param other - ссылка на другую матрицу
     * @return 1 - если матрицы не равны, иначе 0
     */
    bool operator!=(const Matrix &other) const;

    /**
     * @brief Преобразование матрицы в строку
     * @return Содержимое строки
     */
    std::string toString() const;

    /**
     * @brief Доступ к строке матрицы (только чтение)
     * @param index - номер элемента
     * @return Элемент по индексу
     */
    const std::vector<int> &operator[](const size_t index) const;

    /**
     * @brief Доступ к строке матрицы (чтение и запись)
     * @param index - номер элемента
     * @return Элемент по индексу
     */
    std::vector<int> &operator[](const size_t index);

    /**
     * @brief Получить количество строк
     * @return Количество строк
     */
    size_t getRows() const noexcept;

    /**
     * @brief Получить количество столбцов
     * @return Количество столбцов
     */
    size_t getColumns() const noexcept;

    /**
     * @brief Вставка нового столбца после заданного индекса
     * @param index Индекс столбца, после которого вставляется новый столбец
     * @param new_col Указатель на массив значений нового столбца
     */
    void insertColumnAfter(const size_t index, const std::vector<int> &new_col);

    /**
     * @brief Заполнение матрицы с помощью абстрактного класса Generator
     * @param generator - ссылка на объект Generator
     */
    void fillArray(const Generator &generator);
};
