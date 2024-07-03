#include <gtest/gtest.h>
#include "../sources/Matrix.h"

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