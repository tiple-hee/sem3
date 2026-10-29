#include <gtest/gtest.h>

#include <sstream>
#include <string>

#include "Matrix.h"
#include "ConstGenerator.h"
#include "RandomGenerator.h"
#include "InputGenerator.h"
#include "Task1Exercise.h"
#include "Task2Exercise.h"

TEST(MatrixConstructors, DefaultIsEmpty)
{
    Matrix m;
    EXPECT_EQ(m.getRows(), 0u);
    EXPECT_EQ(m.getColumns(), 0u);
    EXPECT_EQ(m.toString(), "");
}

TEST(MatrixConstructors, SizedMatrixIsZeroFilled)
{
    Matrix m(3, 4);
    EXPECT_EQ(m.getRows(), 3u);
    EXPECT_EQ(m.getColumns(), 4u);
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            EXPECT_EQ(m[i][j], 0);
        }
    }
}

TEST(MatrixCopy, CopyIsDeep)
{
    Matrix a(2, 2);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;

    Matrix b = a;
    b[0][0] = 999;

    EXPECT_EQ(a[0][0], 1);
    EXPECT_EQ(b[0][0], 999);
}

TEST(MatrixCopy, CopyAssignmentIsDeep)
{
    Matrix a(2, 2);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;

    Matrix b;
    b = a;
    b[1][1] = 777;

    EXPECT_EQ(a[1][1], 4);
    EXPECT_EQ(b[1][1], 777);
}

TEST(MatrixMove, MoveLeavesSourceEmpty)
{
    Matrix a(2, 2);
    a[0][0] = 42;

    Matrix b = std::move(a);
    EXPECT_EQ(b[0][0], 42);
    EXPECT_EQ(a.getRows(), 0u);
    EXPECT_EQ(a.getColumns(), 0u);
}

TEST(MatrixCopy, SelfAssignmentIsSafe)
{
    Matrix a(2, 2);
    a[0][0] = 5;
    a = a;
    EXPECT_EQ(a[0][0], 5);
}

TEST(MatrixEquality, EqualMatrices)
{
    Matrix a(2, 2);
    Matrix b(2, 2);
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
}

TEST(MatrixEquality, DifferentValues)
{
    Matrix a(2, 2);
    Matrix b(2, 2);
    b[0][0] = 1;
    EXPECT_FALSE(a == b);
    EXPECT_TRUE(a != b);
}

TEST(MatrixEquality, DifferentSizes)
{
    Matrix a(2, 2);
    Matrix b(3, 3);
    EXPECT_FALSE(a == b);
}

TEST(MatrixIO, OutputFormat)
{
    Matrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    std::ostringstream os;
    os << m;
    EXPECT_EQ(os.str(), "2 2\n1 2\n3 4");
}

TEST(MatrixIO, InputRoundtrip)
{
    std::istringstream is("2 3\n1 2 3\n4 5 6");
    Matrix m;
    is >> m;

    EXPECT_EQ(m.getRows(), 2u);
    EXPECT_EQ(m.getColumns(), 3u);
    EXPECT_EQ(m[0][0], 1);
    EXPECT_EQ(m[1][2], 6);
}

TEST(MatrixIO, InputFailsOnBadData)
{
    std::istringstream is("2 3\n1 2 3\n4 5 x");
    Matrix m;
    is >> m;
    EXPECT_FALSE(is);
}

TEST(ConstGeneratorTest, ReturnsConstant)
{
    ConstGenerator gen(42);
    EXPECT_EQ(gen.generate(), 42);
    EXPECT_EQ(gen.generate(), 42);
    EXPECT_EQ(gen.generate(), 42);
}

TEST(RandomGeneratorTest, ValuesInRange)
{
    RandomGenerator gen(-10, 10);
    for (int i = 0; i < 1000; i++)
    {
        int v = gen.generate();
        EXPECT_GE(v, -10);
        EXPECT_LE(v, 10);
    }
}

TEST(RandomGeneratorTest, SwapsMinMaxIfReversed)
{
    RandomGenerator gen(10, -10);
    for (int i = 0; i < 100; i++)
    {
        int v = gen.generate();
        EXPECT_GE(v, -10);
        EXPECT_LE(v, 10);
    }
}

TEST(InputGeneratorTest, ReadsFromStream)
{
    std::istringstream is("10 20 30");
    InputGenerator gen(is);
    EXPECT_EQ(gen.generate(), 10);
    EXPECT_EQ(gen.generate(), 20);
    EXPECT_EQ(gen.generate(), 30);
}

TEST(Task1Test, ReplaceOddElements)
{
    Matrix m(2, 3);
    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = -3;
    m[1][0] = -4;
    m[1][1] = 5;
    m[1][2] = 0;

    RandomGenerator dummyGen(0, 0);
    Task1Exercise task(m, dummyGen);
    Matrix result = task.solve();

    EXPECT_EQ(result.getRows(), 2u);
    EXPECT_EQ(result.getColumns(), 3u);

    EXPECT_EQ(result[0][0], 0);
    EXPECT_EQ(result[0][1], 2);
    EXPECT_EQ(result[0][2], 0);
    EXPECT_EQ(result[1][0], -4);
    EXPECT_EQ(result[1][1], 0);
    EXPECT_EQ(result[1][2], 0);
}

TEST(Task1Test, OriginalIsNotModified)
{
    Matrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    RandomGenerator dummyGen(0, 0);
    Task1Exercise task(m, dummyGen);
    task.solve();

    EXPECT_EQ(m[0][0], 1);
    EXPECT_EQ(m[1][0], 3);
}

TEST(Task1Test, EmptyMatrixReturnsEmpty)
{
    Matrix m;
    RandomGenerator dummyGen(0, 0);
    Task1Exercise task(m, dummyGen);
    Matrix result = task.solve();

    EXPECT_EQ(result.getRows(), 0u);
    EXPECT_EQ(result.getColumns(), 0u);
}

TEST(Task2Test, InsertFirstColumnAfterZero)
{
    Matrix m(3, 3);
    m[0][0] = 1;
    m[0][1] = 0;
    m[0][2] = 9;
    m[1][0] = 2;
    m[1][1] = 9;
    m[1][2] = 0;
    m[2][0] = 3;
    m[2][1] = 9;
    m[2][2] = 9;

    RandomGenerator dummyGen(0, 0);
    Task2Exercise task(m, dummyGen);
    Matrix result = task.solve();

    EXPECT_EQ(result.getRows(), 3u);
    EXPECT_EQ(result.getColumns(), 5u);
    EXPECT_EQ(result[0][2], 1);
    EXPECT_EQ(result[1][2], 2);
    EXPECT_EQ(result[2][2], 3);
    EXPECT_EQ(result[0][3], 9);
    EXPECT_EQ(result[1][3], 0);
    EXPECT_EQ(result[2][3], 9);
    EXPECT_EQ(result[0][4], 1);
    EXPECT_EQ(result[1][4], 2);
    EXPECT_EQ(result[2][4], 3);
}

TEST(Task2Test, AllColumnsContainZero)
{
    Matrix m(2, 2);
    m[0][0] = 0;
    m[0][1] = 5;
    m[1][0] = 7;
    m[1][1] = 0;

    RandomGenerator dummyGen(0, 0);
    Task2Exercise task(m, dummyGen);
    Matrix result = task.solve();
    EXPECT_EQ(result.getRows(), 2u);
    EXPECT_EQ(result.getColumns(), 4u);
    EXPECT_EQ(result[0][1], 0);
    EXPECT_EQ(result[1][1], 7);
    EXPECT_EQ(result[0][3], 0);
    EXPECT_EQ(result[1][3], 7);
}

TEST(Task2Test, OriginalIsNotModified)
{
    Matrix m(2, 2);
    m[0][0] = 0;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    RandomGenerator dummyGen(0, 0);
    Task2Exercise task(m, dummyGen);
    task.solve();

    EXPECT_EQ(m.getColumns(), 2u);
    EXPECT_EQ(m[1][1], 4);
}
