#ifndef __S21MATRIX_OOP_H__
#define __S21MATRIX_OOP_H__

#include <cmath>
#include <iostream>

namespace s21 {
class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  void set_rows(int new_rows);
  void set_cols(int new_cols);

  int get_rows() const noexcept;
  int get_cols() const noexcept;

  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  bool operator==(const S21Matrix other);

  double& operator()(int row, int col);
  double operator()(int row, int col) const;

  void operator+=(const S21Matrix other);
  S21Matrix operator+(const S21Matrix other);

  void operator-=(const S21Matrix other);
  S21Matrix operator-(const S21Matrix other);

  void operator*=(const S21Matrix other);
  S21Matrix operator*(const S21Matrix other);

  void operator*=(const double n);
  S21Matrix operator*(const double n);

  friend S21Matrix operator*(const double n, const S21Matrix& matrix);

  bool EqMatrix(const S21Matrix other);
  S21Matrix SumMatrix(const S21Matrix other);
  S21Matrix SubMatrix(const S21Matrix other);
  void MulNumber(double num);
  void MulMatrix(const S21Matrix other);
  S21Matrix Transpose();
  double Determinant();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

 private:
  int rows_, cols_;
  double** matrix_;

  void CreateMatrix();
  void RemoveMatrix();
  void CopyMatrix(const S21Matrix& other);
  void MatrixOperation(const S21Matrix other, int coefficient);
  void SetDimensions(int rows, int cols);
  S21Matrix GetMinor(int ex_row, int ex_col);
};
}  // namespace s21

#endif  // __S21MATRIX_OOP_H__
