#include "unit_test.h"

TEST(MatrixTest, MulNumber2x2) {
  s21::S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;
  matrix.MulNumber(12.4);

  s21::S21Matrix result(2, 2);
  result(0, 0) = 12.4;
  result(0, 1) = 24.8;
  result(1, 0) = 37.2;
  result(1, 1) = 49.6;

  EXPECT_TRUE(matrix == result);
}

TEST(MatrixTest, MulNumber2x2_operator) {
  s21::S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;
  s21::S21Matrix matrix_2 = matrix_1 * 12.4;

  s21::S21Matrix result(2, 2);
  result(0, 0) = 12.4;
  result(0, 1) = 24.8;
  result(1, 0) = 37.2;
  result(1, 1) = 49.6;

  EXPECT_TRUE(matrix_2 == result);
}

TEST(MatrixTest, MulNumber2x2_inplace) {
  s21::S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;
  matrix *= 12.4;

  s21::S21Matrix result(2, 2);
  result(0, 0) = 12.4;
  result(0, 1) = 24.8;
  result(1, 0) = 37.2;
  result(1, 1) = 49.6;

  EXPECT_TRUE(matrix == result);
}

TEST(MatrixTest, MulNumber2x2_operator_friend) {
  s21::S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  s21::S21Matrix result(2, 2);
  result(0, 0) = 12.4;
  result(0, 1) = 24.8;
  result(1, 0) = 37.2;
  result(1, 1) = 49.6;

  EXPECT_TRUE((12.4 * matrix_1) == result);
}