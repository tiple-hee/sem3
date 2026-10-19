#include "Task2Exercise.h"

Task2Exercise::Task2Exercise(Matrix &src, Generator &gen) : Exercise(src, gen) {}

Matrix Task2Exercise::solve()
{
    const size_t rows = source.getRows();
    const size_t columns = source.getColumns();

    if (rows == 0 || columns == 0)
    {
        return Matrix();
    }
    int *firstColumn = new int[rows];
    for (size_t i = 0; i < rows; i++)
    {
        firstColumn[i] = source[i][0];
    }
    Matrix result(source);
    for (size_t j = result.getColumns(); j > 0; --j)
    {
        size_t actual_index = j - 1;
        bool hasZero = false;

        for (size_t i = 0; i < rows; i++)
        {
            if (result[i][actual_index] == 0)
            {
                hasZero = true;
                break;
            }
        }

        if (hasZero)
        {
            result.insertColumnAfter(actual_index, firstColumn);
        }
    }
    delete[] firstColumn;

    return result;
}
