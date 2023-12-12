#include "unit_test.h"

TEST(MatrixTest, Matrix2x2) {
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

  s21::S21Matrix result = s21::S21Matrix(2, 2);
  result(0, 0) = 16.0;
  result(0, 1) = 25.6;
  result(1, 0) = 36.0;
  result(1, 1) = 56.8;
  matrix_1.MulMatrix(matrix_2);

  EXPECT_TRUE(matrix_1 == result);
}

TEST(MatrixTest, Matrix3x2) {
  s21::S21Matrix matrix_1 = s21::S21Matrix(3, 2);
  matrix_1(0, 0) = 1.123456;
  matrix_1(0, 1) = 4.543564;
  matrix_1(1, 0) = 2.546356;
  matrix_1(1, 1) = 5.454325;
  matrix_1(2, 0) = 3.254562;
  matrix_1(2, 1) = 6.252452;

  s21::S21Matrix matrix_2 = s21::S21Matrix(2, 3);
  matrix_2(0, 0) = 1.254352;
  matrix_2(0, 1) = 6.245223;
  matrix_2(0, 2) = -1.14245;
  matrix_2(1, 0) = 2.153252;
  matrix_2(1, 1) = 3.132411;
  matrix_2(1, 2) = 4.413214;

  s21::S21Matrix result = s21::S21Matrix(3, 3);
  result(0, 0) = 11.19264755064;
  result(0, 1) = 21.248543103492;
  result(0, 2) = 18.768227947496;
  result(1, 0) = 14.938562956212;
  result(1, 1) = 32.987748684963;
  result(1, 2) = 21.16201903835;
  result(2, 0) = 17.545471127728;
  result(2, 1) = 39.910714879098;
  result(2, 2) = 23.875234343828;

  matrix_1.MulMatrix(matrix_2);
  EXPECT_TRUE(matrix_1.EqMatrix(result));
}

TEST(MatrixTest, SameSize) {
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

  s21::S21Matrix matrix_3 = matrix_1 * matrix_2;

  s21::S21Matrix result = s21::S21Matrix(2, 2);
  result(0, 0) = 16.0;
  result(0, 1) = 25.6;
  result(1, 0) = 36.0;
  result(1, 1) = 56.8;

  EXPECT_EQ(matrix_3(0, 0), result(0, 0));
}

TEST(MatrixTest, SameSize_2) {
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

  matrix_1 *= matrix_2;

  s21::S21Matrix result = s21::S21Matrix(2, 2);
  result(0, 0) = 16.0;
  result(0, 1) = 25.6;
  result(1, 0) = 36.0;
  result(1, 1) = 56.8;

  EXPECT_EQ(matrix_1(0, 0), result(0, 0));
}

TEST(MatrixTest, MatrixDifferentThrow) {
  s21::S21Matrix matrix_1 = s21::S21Matrix(2, 3);
  s21::S21Matrix matrix_2 = s21::S21Matrix(4, 2);
  EXPECT_THROW(matrix_1.MulMatrix(matrix_2), std::invalid_argument);
}