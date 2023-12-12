#include "unit_test.h"

TEST(MatrixTest, get_rows_1) {
  int rows = 5;
  int cols = 3;
  s21::S21Matrix matrix_1(rows, cols);
  EXPECT_EQ(matrix_1.get_rows(), rows);
}

TEST(MatrixTest, get_cols_1) {
  int rows = 3;
  int cols = 5;
  s21::S21Matrix matrix_1(rows, cols);
  EXPECT_EQ(matrix_1.get_cols(), cols);
}

TEST(MatrixTest, index_operator_const) {
  int rows = 3;
  int cols = 5;
  const s21::S21Matrix matrix_1(rows, cols);
  EXPECT_EQ(matrix_1(0, 1), 0);
}

TEST(MatrixTest, index_operator_out_of_range_1) {
  int rows = 3;
  int cols = 5;
  s21::S21Matrix matrix_1(rows, cols);
  EXPECT_THROW(matrix_1(0, -1), std::out_of_range);
}

TEST(MatrixTest, index_operator_out_of_range_const) {
  int rows = 3;
  int cols = 5;
  const s21::S21Matrix matrix_1(rows, cols);
  EXPECT_THROW(matrix_1(0, -1), std::out_of_range);
}