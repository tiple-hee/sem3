#include "Matrix.h"
#include <iostream>
#include <sstream>
#include <utility>
#include <stdexcept>

Matrix::Matrix() : row_count(0), col_count(0), matrix_data(nullptr) {}

Matrix::Matrix(const size_t rows, const size_t cols) : row_count(rows), col_count(cols), matrix_data(nullptr)
{
    if (row_count > 0 && col_count > 0)
    {
        matrix_data = new int *[row_count];
        for (size_t i = 0; i < row_count; ++i)
        {
            matrix_data[i] = new int[col_count]();
        }
    }
    else
    {
        row_count = 0;
        col_count = 0;
    }
}

Matrix::Matrix(const Matrix &other) : row_count(other.row_count), col_count(other.col_count), matrix_data(nullptr)
{
    if (row_count > 0 && col_count > 0)
    {
        matrix_data = new int *[row_count];
        for (size_t i = 0; i < row_count; ++i)
        {
            matrix_data[i] = new int[col_count];
            for (size_t j = 0; j < col_count; ++j)
            {
                matrix_data[i][j] = other.matrix_data[i][j];
            }
        }
    }
}

Matrix::Matrix(Matrix &&other) noexcept : row_count(other.row_count), col_count(other.col_count), matrix_data(other.matrix_data)
{
    other.row_count = 0;
    other.col_count = 0;
    other.matrix_data = nullptr;
}

Matrix::~Matrix()
{
    if (matrix_data)
    {
        for (size_t i = 0; i < row_count; ++i)
        {
            delete[] matrix_data[i];
        }
        delete[] matrix_data;
    }
}

Matrix &Matrix::operator=(const Matrix &other)
{
    if (this != &other)
    {
        Matrix temp(other);
        std::swap(row_count, temp.row_count);
        std::swap(col_count, temp.col_count);
        std::swap(matrix_data, temp.matrix_data);
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&other) noexcept
{
    if (this != &other)
    {
        Matrix temp(std::move(other));
        std::swap(row_count, temp.row_count);
        std::swap(col_count, temp.col_count);
        std::swap(matrix_data, temp.matrix_data);
    }
    return *this;
}

size_t Matrix::getRows() const noexcept
{
    return row_count;
}

size_t Matrix::getColumns() const noexcept
{
    return col_count;
}

int *Matrix::operator[](const size_t index)
{
    if (index >= row_count)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return matrix_data[index];
}

const int *Matrix::operator[](const size_t index) const
{
    if (index >= row_count)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return matrix_data[index];
}

std::string Matrix::toString() const
{
    if (row_count == 0 || col_count == 0)
    {
        return "";
    }

    std::ostringstream oss;
    for (size_t i = 0; i < row_count; ++i)
    {
        for (size_t j = 0; j < col_count; ++j)
        {
            oss << matrix_data[i][j];
            if (j < col_count - 1)
            {
                oss << " ";
            }
        }
        if (i < row_count - 1)
        {
            oss << "\n";
        }
    }
    return oss.str();
}

bool Matrix::operator==(const Matrix &other) const
{
    if (row_count != other.row_count || col_count != other.col_count)
    {
        return false;
    }
    for (size_t i = 0; i < row_count; ++i)
    {
        for (size_t j = 0; j < col_count; ++j)
        {
            if (matrix_data[i][j] != other.matrix_data[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &other) const
{
    return !(*this == other);
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
{
    os << matrix.getRows() << ' ' << matrix.getColumns() << '\n';
    os << matrix.toString();
    return os;
}

std::istream &operator>>(std::istream &is, Matrix &matrix)
{
    size_t r = 0;
    size_t c = 0;
    if (!(is >> r >> c))
        return is;

    if (r == 0 && c == 0)
    {
        matrix = Matrix();
        return is;
    }

    if (r == 0 || c == 0)
    {
        is.setstate(std::ios::failbit);
        return is;
    }

    Matrix temp(r, c);
    for (size_t i = 0; i < r; ++i)
    {
        for (size_t j = 0; j < c; ++j)
        {
            if (!(is >> temp[i][j]))
                return is;
        }
    }

    matrix = std::move(temp);
    return is;
}

void Matrix::insertColumnAfter(const size_t index, const int *new_col)
{
    if (index >= col_count)
    {
        throw std::out_of_range("Index out of bounds");
    }

    for (size_t i = 0; i < row_count; ++i)
    {
        int *expanded_row = new int[col_count + 1];

        for (size_t j = 0; j <= index; ++j)
        {
            expanded_row[j] = matrix_data[i][j];
        }

        expanded_row[index + 1] = new_col[i];

        for (size_t j = index + 1; j < col_count; ++j)
        {
            expanded_row[j + 1] = matrix_data[i][j];
        }

        delete[] matrix_data[i];
        matrix_data[i] = expanded_row;
    }

    col_count++;
}

void Matrix::fillArray(Generator &generator)
{
    for (size_t i = 0; i < row_count; ++i)
    {
        for (size_t j = 0; j < col_count; ++j)
        {
            matrix_data[i][j] = generator.generate();
        }
    }
}
