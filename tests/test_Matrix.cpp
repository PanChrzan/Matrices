#include <gtest/gtest.h>
#include "../sources/Matrix.hpp"
#include "../sources/Errors.hpp"

TEST(Matrix__Test, CheckVectorSize)
{
    // GIVEN
    Matrix<float> cut(3, 7);
    auto expected = 3 * 7;
    // WHEN
    auto vectorSize = cut.getSize();
    // THEN
    ASSERT_EQ(expected, vectorSize);
}

TEST(Matrix__Test, CallOperatorOverload)
{
    // GIVEN
    Matrix<float> cut(3, 3);
    float expected = 1.1;
    // WHEN
    cut(1, 1) = 1.1;
    // THEN
    ASSERT_EQ(expected, cut(1, 1));
}

TEST(Matrix__Test, ExpectWrongDimensionsThrow)
{
    // GIVEN
    Matrix<int> cut_1(3, 7), cut_2(7, 3);
    // WHEN

    // THEN
    EXPECT_THROW({
        try
        {
            cut_1 + cut_2;
        }
        catch(const WrongDimensionsError& err)
        {
            throw;
        } }, WrongDimensionsError);
}

TEST(Matrix__Test, AddingTwoMatrices)
{
    // GIVEN
    const int SIZE = 2;
    Matrix<int> mat_left(SIZE, SIZE), mat_right(SIZE, SIZE), expected(SIZE, SIZE);
    for (unsigned int i = 1; i <= SIZE; i++)
    {
        for (unsigned int j = 1; j <= SIZE; j++)
        {
            mat_left(i, j) = 1;
            mat_right(i, j) = 2;
            expected(i, j) = 3;
        }
    }
    // WHEN
    Matrix<int> ret = mat_left + mat_right;
    // THEN
    for (unsigned int i = 1; i <= SIZE; i++)
    {
        for (unsigned int j = 1; j <= SIZE; j++)
        {
            ASSERT_EQ(expected(i, j), ret(i, j));
        }
    }
}