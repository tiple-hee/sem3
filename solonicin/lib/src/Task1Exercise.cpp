#include "Task1Exercise.h"

Task1Exercise::Task1Exercise(Matrix &src, Generator &gen) : Exercise(src, gen) {}

Matrix Task1Exercise::solve()
{
    Matrix result(source);

    const size_t rows = result.getRows();
    const size_t columns = result.getColumns();
    if (rows == 0 || columns == 0)
    {
        return result;
    }
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if (result[i][j] % 2 != 0)
            {
                result[i][j] = 0;
            }
        }
    }

    return result;
}
