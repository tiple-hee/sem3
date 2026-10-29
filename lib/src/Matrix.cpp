#include "Matrix.h"
#include <iostream>
#include <sstream>
#include <utility>
#include <stdexcept>

Matrix::Matrix() : matrix_data() {}

Matrix::Matrix(const size_t rows, const size_t cols)
{
    if (rows > 0 && cols > 0)
    {
        matrix_data.resize(rows, std::vector<int>(cols, 0));
    }
}

size_t Matrix::getRows() const noexcept
{
    return matrix_data.size();
}

size_t Matrix::getColumns() const noexcept
{
    return matrix_data.empty() ? 0 : matrix_data[0].size();
}

std::vector<int> &Matrix::operator[](const size_t index)
{
    return matrix_data.at(index);
}

const std::vector<int> &Matrix::operator[](const size_t index) const
{
    return matrix_data.at(index);
}

std::string Matrix::toString() const
{
    if (matrix_data.empty() || matrix_data[0].empty())
    {
        return "";
    }

    std::ostringstream oss;
    for (size_t i = 0; i < matrix_data.size(); ++i)
    {
        for (size_t j = 0; j < matrix_data[i].size(); ++j)
        {
            oss << matrix_data[i][j];
            if (j < matrix_data[i].size() - 1)
            {
                oss << " ";
            }
        }
        if (i < matrix_data.size() - 1)
        {
            oss << "\n";
        }
    }
    return oss.str();
}

bool Matrix::operator==(const Matrix &other) const
{
    return matrix_data == other.matrix_data;
}

bool Matrix::operator!=(const Matrix &other) const
{
    return matrix_data != other.matrix_data;
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

void Matrix::insertColumnAfter(const size_t index, const std::vector<int> &new_col)
{
    if (index >= getColumns())
    {
        throw std::out_of_range("Index out of bounds");
    }
    if (new_col.size() != getRows())
    {
        throw std::invalid_argument("Column size mismatch");
    }

    for (size_t i = 0; i < getRows(); ++i)
    {
        matrix_data[i].insert(matrix_data[i].begin() + index + 1, new_col[i]);
    }
}

void Matrix::fillArray(const Generator &generator)
{
    for (auto &row : matrix_data)
    {
        for (auto &elem : row)
        {
            elem = generator.generate();
        }
    }
}
