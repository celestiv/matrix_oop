#include "unit_test.h"

TEST(MatrixTest, ConstructorTest1) {
  s21::S21Matrix m1(4, 5);

  EXPECT_EQ(m1.get_rows(), 4);
  EXPECT_EQ(m1.get_cols(), 5);
}

TEST(MatrixTest, ConstructorTest2) {
  s21::S21Matrix m1(4, 5);
  s21::S21Matrix matrix_2(m1);
  EXPECT_EQ(matrix_2.get_rows(), 4);
  EXPECT_EQ(matrix_2.get_cols(), 5);
}

TEST(MatrixTest, ConstructorTest3) {
  s21::S21Matrix m1(4, 5);
  s21::S21Matrix matrix_2 = m1;
  EXPECT_EQ(matrix_2.get_rows(), 4);
  EXPECT_EQ(matrix_2.get_cols(), 5);
}

TEST(MatrixTest, ConstructorTest4) {
  s21::S21Matrix m1;

  EXPECT_EQ(m1.get_rows(), 0);
  EXPECT_EQ(m1.get_cols(), 0);
}

TEST(MatrixTest, Copy_1) {
  s21::S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  int rows = 3;
  int cols = 3;
  s21::S21Matrix matrix_2 = matrix_1;
  matrix_2.set_rows(rows);
  matrix_2.set_cols(cols);
  matrix_2(0, 0) = 12.4;
  matrix_2(0, 1) = 24.8;
  matrix_2(0, 2) = 24.8;
  matrix_2(1, 0) = 37.2;
  matrix_2(1, 1) = 37.2;
  matrix_2(1, 2) = 50.0;
  matrix_2(2, 0) = 37.2;
  matrix_2(2, 1) = 37.2;
  matrix_2(2, 2) = 50.0;

  matrix_1 = matrix_2;

  EXPECT_TRUE(matrix_1 == matrix_2);
}

TEST(MatrixTest, Move_1) {
  s21::S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  s21::S21Matrix matrix_2 = std::move(matrix_1);
  s21::S21Matrix result(2, 2);
  result(0, 0) = 1.0;
  result(0, 1) = 2.0;
  result(1, 0) = 3.0;
  result(1, 1) = 4.0;

  EXPECT_TRUE(matrix_2 == result);
  EXPECT_EQ(matrix_2.get_cols(), 2);
  EXPECT_EQ(matrix_2.get_rows(), 2);
}

TEST(MatrixTest, throw_1) {
  int rows = -3;
  int cols = 5;
  EXPECT_THROW(s21::S21Matrix matrix_1(rows, cols), std::invalid_argument);
}