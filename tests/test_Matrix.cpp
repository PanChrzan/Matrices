#include <gtest/gtest.h>
#include "../sources/Matrix.hpp"

TEST(Matrix__Test, CheckVectorSize)
{
//GIVEN
    Matrix<float> cut(3,7);
    auto expected = 3*7;
//WHEN
    auto vectorSize = cut.getSize();
//THEN
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