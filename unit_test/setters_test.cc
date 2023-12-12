#include "unit_test.h"

TEST(MatrixTest, setByIndex) {
  s21::S21Matrix matrix_1 = s21::S21Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  matrix_1(0, 0) = 5.0;
  EXPECT_EQ(matrix_1(0, 0), 5.0);
}

TEST(MatrixTest, SettersTest1) {
  s21::S21Matrix m1(4, 4);
  m1.set_rows(3);
  EXPECT_EQ(m1.get_rows(), 3);
  EXPECT_EQ(m1.get_cols(), 4);
}

TEST(MatrixTest, SettersTest2) {
  s21::S21Matrix m1(4, 4);
  m1.set_cols(5);
  EXPECT_EQ(m1.get_rows(), 4);
  EXPECT_EQ(m1.get_cols(), 5);
}

TEST(MatrixTest, SettersTest_throw_rows) {
  s21::S21Matrix m1(4, 4);
  EXPECT_THROW(m1.set_rows(-4), std::invalid_argument);
}

TEST(MatrixTest, SettersTest_throw_cols) {
  s21::S21Matrix m1(4, 4);
  EXPECT_THROW(m1.set_cols(-4), std::invalid_argument);
}

TEST(MatrixTest, RowsGreaterSize) {
  s21::S21Matrix matrix_1 = s21::S21Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  int rows_new = 4;
  matrix_1.set_rows(rows_new);

  s21::S21Matrix result = s21::S21Matrix(rows_new, 2);
  result(0, 0) = 1.0;
  result(0, 1) = 2.0;
  result(1, 0) = 3.0;
  result(1, 1) = 4.0;
  result(2, 0) = 0.0;
  result(2, 1) = 0.0;
  result(3, 0) = 0.0;
  result(3, 1) = 0.0;

  EXPECT_TRUE(result == matrix_1);
}

TEST(MatrixTest, RowsLessSize) {
  s21::S21Matrix matrix_1 = s21::S21Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;
  int rows_new = 1;
  matrix_1.set_rows(rows_new);

  s21::S21Matrix result = s21::S21Matrix(rows_new, 2);
  result(0, 0) = 1.0;
  result(0, 1) = 2.0;

  EXPECT_TRUE(result == matrix_1);
}
//
TEST(MatrixTest, ColsGreaterSize) {
  s21::S21Matrix matrix_1 = s21::S21Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  int cols_new = 4;
  matrix_1.set_cols(cols_new);

  s21::S21Matrix result = s21::S21Matrix(2, cols_new);
  result(0, 0) = 1.0;
  result(0, 1) = 2.0;
  result(0, 2) = 0.0;
  result(0, 3) = 0.0;
  result(1, 0) = 3.0;
  result(1, 1) = 4.0;
  result(1, 2) = 0.0;
  result(1, 3) = 0.0;

  EXPECT_TRUE(result == matrix_1);
}

TEST(MatrixTest, ColsLessSize) {
  s21::S21Matrix matrix_1 = s21::S21Matrix(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  int cols_new = 1;
  matrix_1.set_cols(cols_new);

  s21::S21Matrix result = s21::S21Matrix(2, cols_new);
  result(0, 0) = 1.0;
  result(1, 0) = 3.0;

  EXPECT_TRUE(result == matrix_1);
}