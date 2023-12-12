#include "unit_test.h"

TEST(MatrixTest, TransposeMatrix3x4) {
  s21::S21Matrix m1(3, 4);
  m1(0, 0) = 0.0;
  m1(0, 1) = 1.0;
  m1(0, 2) = 2.0;
  m1(0, 3) = 3.0;
  m1(1, 0) = 4.0;
  m1(1, 1) = 5.0;
  m1(1, 2) = 6.0;
  m1(1, 3) = 7.0;
  m1(2, 0) = 8.0;
  m1(2, 1) = 9.0;
  m1(2, 2) = 10.0;
  m1(2, 3) = 11.0;
  s21::S21Matrix m2 = m1.Transpose();
  EXPECT_EQ(m2(0, 0), 0.0);
  EXPECT_EQ(m2(1, 1), 5.0);
  EXPECT_EQ(m2(2, 2), 10.0);
  EXPECT_EQ(m2(0, 2), 8.0);
  EXPECT_EQ(m2(3, 2), 11.0);
}

TEST(MatrixTest, TransposeMatrix1x1) {
  s21::S21Matrix matrix_1(1, 1);
  matrix_1(0, 0) = 123.345;

  s21::S21Matrix matrix_2 = matrix_1.Transpose();

  s21::S21Matrix result(1, 1);
  result(0, 0) = 123.345;

  EXPECT_TRUE(matrix_2 == result);
}

TEST(MatrixTest, TransposeMatrix3x2) {
  s21::S21Matrix matrix_1(3, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 4.0;
  matrix_1(1, 0) = 2.0;
  matrix_1(1, 1) = 5.0;
  matrix_1(2, 0) = 3.0;
  matrix_1(2, 1) = 6.0;

  s21::S21Matrix matrix_2 = matrix_1.Transpose();

  s21::S21Matrix result(2, 3);
  result(0, 0) = 1.0;
  result(0, 1) = 2.0;
  result(0, 2) = 3.0;
  result(1, 0) = 4.0;
  result(1, 1) = 5.0;
  result(1, 2) = 6.0;

  EXPECT_TRUE(matrix_2 == result);
}