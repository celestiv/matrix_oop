#include "unit_test.h"

TEST(MatrixTest, InverseMatrix1x1) {
  s21::S21Matrix matrix_1(1, 1);
  matrix_1(0, 0) = 432.1;
  s21::S21Matrix matrix_2 = matrix_1.InverseMatrix();
  EXPECT_FLOAT_EQ(matrix_2(0, 0), 0.002314279102);
}

TEST(MatrixTest, InverseMatrix3x3) {
  s21::S21Matrix matrix_1(3, 3);
  matrix_1(0, 0) = 2.0;
  matrix_1(0, 1) = 5.0;
  matrix_1(0, 2) = 7.0;
  matrix_1(1, 0) = 6.0;
  matrix_1(1, 1) = 3.0;
  matrix_1(1, 2) = 4.0;
  matrix_1(2, 0) = 5.0;
  matrix_1(2, 1) = -2.0;
  matrix_1(2, 2) = -3.0;

  s21::S21Matrix matrix_2 = matrix_1.InverseMatrix();
  s21::S21Matrix result(3, 3);
  result(0, 0) = 1.0;
  result(0, 1) = -1.0;
  result(0, 2) = 1.0;
  result(1, 0) = -38.0;
  result(1, 1) = 41.0;
  result(1, 2) = -34.0;
  result(2, 0) = 27.0;
  result(2, 1) = -29.0;
  result(2, 2) = 24.0;

  EXPECT_TRUE(result == matrix_2);
}

TEST(MatrixTest, InverseMatrixZeroDet) {
  s21::S21Matrix matrix_1(4, 4);
  EXPECT_THROW(matrix_1.InverseMatrix(), std::invalid_argument);
}
