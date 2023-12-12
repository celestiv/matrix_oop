#include "unit_test.h"

TEST(MatrixTest, Equal_1) {
  s21::S21Matrix matrix_1(3, 2);
  matrix_1(0, 0) = 1.123456;
  matrix_1(0, 1) = 4.543564;
  matrix_1(1, 0) = 2.546356;
  matrix_1(1, 1) = 5.454325;

  s21::S21Matrix matrix_2(3, 2);
  matrix_2(0, 0) = 1.123456;
  matrix_2(0, 1) = 4.543564;
  matrix_2(1, 0) = 2.546356;
  matrix_2(1, 1) = 5.454325;
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(MatrixTest, NotEqual) {
  s21::S21Matrix matrix_1(3, 2);
  matrix_1(0, 0) = 1.123456;
  matrix_1(0, 1) = 4.543564;
  matrix_1(1, 0) = 2.546356;
  matrix_1(1, 1) = 5.454325;

  s21::S21Matrix matrix_2(3, 2);
  matrix_2(0, 0) = 2.123456;
  matrix_2(0, 1) = 4.543564;
  matrix_2(1, 0) = 2.546356;
  matrix_2(1, 1) = 5.454325;
  EXPECT_FALSE(matrix_1.EqMatrix(matrix_2));
}

TEST(MatrixTest, Equal_2) {
  s21::S21Matrix matrix_1(3, 2);
  matrix_1(0, 0) = 1.123456;
  matrix_1(0, 1) = 4.543564;
  matrix_1(1, 0) = 2.546356;
  matrix_1(1, 1) = 5.454325;

  s21::S21Matrix matrix_2(3, 2);
  matrix_2(0, 0) = 1.123456;
  matrix_2(0, 1) = 4.543564;
  matrix_2(1, 0) = 2.546356;
  matrix_2(1, 1) = 5.454325;
  EXPECT_TRUE(matrix_1 == matrix_2);
}

TEST(MatrixTest, NotEqual_2) {
  s21::S21Matrix matrix_1(3, 2);
  matrix_1(0, 0) = 1.123456;
  matrix_1(0, 1) = 4.543564;
  matrix_1(1, 0) = 2.546356;
  matrix_1(1, 1) = 5.454325;

  s21::S21Matrix matrix_2(3, 2);
  matrix_2(0, 0) = 2.123456;
  matrix_2(0, 1) = 4.543564;
  matrix_2(1, 0) = 2.546356;
  matrix_2(1, 1) = 5.454325;
  EXPECT_FALSE(matrix_1 == matrix_2);
}