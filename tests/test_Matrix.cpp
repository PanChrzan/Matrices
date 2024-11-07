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

TEST(Matrix__Test, ExpectWrongDimensionsThrowAdding)
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

TEST(Matrix__Test, ExpectWrongDimensionsThrowMultiplicating)
{
    //GIVEN
    Matrix<int> cut_1(3, 1), cut_2(3, 1);
    //WHEN

    //THEN
    EXPECT_THROW({
        try
        {
            cut_1 * cut_2;
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

TEST(Matrix__Test, MultiplicatingTwoMatrices)
{
    //GIVEN
    Matrix<int> A(3, 3), B(3, 4), expected(3, 4);
    A(1,1) = 2;
    A(1,2) = 5;
    A(1,3) = 6;
    A(2,1) = 3;
    A(2,2) = 1;
    A(2,3) = 3;
    A(3,1) = 2;
    A(3,2) = 7;
    A(3,3) = 8;

    B(1,1) = 1;
    B(1,2) = 2;
    B(1,3) = 3;
    B(1,4) = 7;
    B(2,1) = 4;
    B(2,2) = 2;
    B(2,3) = 1;
    B(2,4) = 3;
    B(3,1) = 2;
    B(3,2) = 7;
    B(3,3) = 5;
    B(3,4) = 9;

    expected(1,1) = 34;
    expected(1,2) = 56;
    expected(1,3) = 41;
    expected(1,4) = 83;
    expected(2,1) = 13;
    expected(2,2) = 29;
    expected(2,3) = 25;
    expected(2,4) = 51;
    expected(3,1) = 46;
    expected(3,2) = 74;
    expected(3,3) = 53;
    expected(3,4) = 107;
    
    //WHEN
    Matrix<int> ret(3, 4);
    ret = A*B;

    //THEN
    for (unsigned int i = 1; i <= 3; i++)
    {
        for (unsigned int j = 1; j <= 4; j++)
        {
            ASSERT_EQ(expected(i, j), ret(i, j));
        }
    }
}