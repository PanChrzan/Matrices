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
    //GIVEN
    Matrix<float> cut(3,3);
    float expected = 1.1;
    //WHEN
    cut(1, 1) = 1.1;
    //THEN
    ASSERT_EQ(expected, cut(1,1));
}

TEST(Matrix__Test, ExpectWrongDimensionsThrow)
{
    // GIVEN
    Matrix<int> cut_1(3, 7), cut_2(7, 3);
    // WHEN

    // THEN
    EXPECT_THROW
    ({
        try
        {
            cut_1 + cut_2;
        }
        catch(const WrongDimensionsError& err)
        {
            throw;
        }
    }, WrongDimensionsError);
}

TEST(Matrix__Test, AddingTwoMatrices)
{
    // GIVEN
    Matrix<int> mat_left(2, 2), mat_right(2, 2), expected(2, 2);
    mat_left(1, 1) = 1;
    mat_left(1, 2) = 1;
    mat_left(2, 1) = 1;
    mat_left(2, 2) = 1;
    mat_right(1, 1) = 2;
    mat_right(1, 2) = 2;
    mat_right(2, 1) = 2;
    mat_right(2, 2) = 2;
    expected(1, 1) = 3;
    expected(1, 2) = 3;
    expected(2, 1) = 3;
    expected(2, 2) = 3;
    //WHEN
    Matrix<int> ret = mat_left + mat_right;
    //THEN
    ASSERT_EQ(expected(1, 1), ret(1, 1));
    ASSERT_EQ(expected(1, 2), ret(1, 2));
    ASSERT_EQ(expected(2, 1), ret(2, 1));
    ASSERT_EQ(expected(2, 2), ret(2, 2));
}