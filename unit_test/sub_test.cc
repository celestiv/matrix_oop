#include "unit_test.h"

TEST(MatrixTest, SubMatrix_1) {
  s21::S21Matrix matrix_1 = s21::S21Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;
  s21::S21Matrix matrix_2 = s21::S21Matrix(2, 2);
  matrix_2(0, 0) = 4.0;
  matrix_2(0, 1) = 5.6;
  matrix_2(1, 0) = 6.0;
  matrix_2(1, 1) = 10.0;

  matrix_1.SubMatrix(matrix_2);

  s21::S21Matrix result = s21::S21Matrix(2, 2);
  result(0, 0) = -3.0;
  result(0, 1) = -3.6;
  result(1, 0) = -3.0;
  result(1, 1) = -6.0;

  EXPECT_TRUE(matrix_1 == result);
}

TEST(MatrixTest, SubMatrix_2) {
  s21::S21Matrix matrix_1 = s21::S21Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;
  s21::S21Matrix matrix_2 = s21::S21Matrix(2, 2);
  matrix_2(0, 0) = 4.0;
  matrix_2(0, 1) = 5.6;
  matrix_2(1, 0) = 6.0;
  matrix_2(1, 1) = 10.0;

  s21::S21Matrix matrix_3 = matrix_1 - matrix_2;

  s21::S21Matrix result = s21::S21Matrix(2, 2);
  result(0, 0) = -3.0;
  result(0, 1) = -3.6;
  result(1, 0) = -3.0;
  result(1, 1) = -6.0;

  EXPECT_TRUE(matrix_3 == result);
}

TEST(MatrixTest, SubMatrix_3) {
  s21::S21Matrix matrix_1 = s21::S21Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;
  s21::S21Matrix matrix_2 = s21::S21Matrix(2, 2);
  matrix_2(0, 0) = 4.0;
  matrix_2(0, 1) = 5.6;
  matrix_2(1, 0) = 6.0;
  matrix_2(1, 1) = 10.0;

  matrix_1 -= matrix_2;

  s21::S21Matrix result = s21::S21Matrix(2, 2);
  result(0, 0) = -3.0;
  result(0, 1) = -3.6;
  result(1, 0) = -3.0;
  result(1, 1) = -6.0;

  EXPECT_TRUE(matrix_1 == result);
}
