#include "s21_matrix_oop.h"

namespace s21 {
S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols)
    : rows_(rows), cols_(cols), matrix_(nullptr) {
  if (rows < 0 || cols < 0) {
    throw std::invalid_argument("rows or columns less or equal to zero");
  }
  CreateMatrix();
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  CreateMatrix();
  CopyMatrix(other);
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : rows_(other.rows_), cols_(other.cols_) {
  CreateMatrix();
  CopyMatrix(other);
  other.RemoveMatrix();
}

S21Matrix::~S21Matrix() { RemoveMatrix(); }

void S21Matrix::CreateMatrix() {
  matrix_ = new double *[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

void S21Matrix::RemoveMatrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      if (matrix_[i] != nullptr) {
        delete[] matrix_[i];
        matrix_[i] = nullptr;
      }
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
  rows_ = 0;
  cols_ = 0;
}

void S21Matrix::CopyMatrix(const S21Matrix &other) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::set_rows(int new_rows) {
  if (new_rows < 0) {
    throw std::invalid_argument(
        "Incorrect input, rows should be greater then 0");
  }
  SetDimensions(new_rows, cols_);
}

void S21Matrix::set_cols(int new_cols) {
  if (new_cols < 0) {
    throw std::invalid_argument(
        "Incorrect input, cols should be greater then 0");
  }
  SetDimensions(rows_, new_cols);
}

int S21Matrix::get_rows() const noexcept { return rows_; }

int S21Matrix::get_cols() const noexcept { return cols_; }

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (*this == other) return *this;
  RemoveMatrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  CreateMatrix();
  CopyMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  if (*this == other) return *this;
  *this = other;
  other.RemoveMatrix();
  return *this;
}

bool S21Matrix::operator==(const S21Matrix other) { return EqMatrix(other); }

double &S21Matrix::operator()(int row, int col) {
  if (row < 0 || col < 0 || row >= rows_ || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}

double S21Matrix::operator()(int row, int col) const {
  if (row < 0 || col < 0 || row >= rows_ || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}

void S21Matrix::operator+=(const S21Matrix other) { SumMatrix(other); }

S21Matrix S21Matrix::operator+(const S21Matrix other) {
  S21Matrix result = S21Matrix(*this);
  result.SumMatrix(other);
  return result;
}

void S21Matrix::operator-=(const S21Matrix other) { SubMatrix(other); }

S21Matrix S21Matrix::operator-(const S21Matrix other) {
  S21Matrix result = S21Matrix(*this);
  result.SubMatrix(other);
  return result;
}

void S21Matrix::operator*=(const S21Matrix other) { MulMatrix(other); }

S21Matrix S21Matrix::operator*(const S21Matrix other) {
  S21Matrix result = S21Matrix(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double n) {
  S21Matrix result = S21Matrix(*this);
  result.MulNumber(n);
  return result;
};

S21Matrix operator*(const double n, const S21Matrix &matrix) {
  S21Matrix temp = matrix;
  return temp * n;
}

void S21Matrix::operator*=(const double n) { MulNumber(n); }

bool S21Matrix::EqMatrix(const S21Matrix other) {
  bool result = true;
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    result = false;
  }
  for (int i = 0; i < other.get_rows(); i++) {
    for (int j = 0; j < other.get_cols(); j++) {
      if (result && fabs(this->matrix_[i][j] - other.matrix_[i][j]) > 1e-7) {
        result = false;
      }
    }
  }
  return result;
}

S21Matrix S21Matrix::SumMatrix(const S21Matrix other) {
  this->MatrixOperation(other, 1);
  return *this;
}

S21Matrix S21Matrix::SubMatrix(const S21Matrix other) {
  this->MatrixOperation(other, -1);
  return *this;
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "first matrix rows and second matrix cols don't match");
  }
  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = result;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = this->matrix_[i][j];
    }
  }

  return result;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix must be square");
  }
  double result = 0.0;
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    S21Matrix minor(rows_ - 1, cols_ - 1);

    for (int j = 0; j < cols_; j++) {
      double temp_det = 0.0;
      S21Matrix minor = GetMinor(0, j);
      temp_det = minor.Determinant();
      int sign = ((j + 1) % 2 == 0) ? -1 : 1;
      result += sign * matrix_[0][j] * temp_det;
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix must be square");
  }

  S21Matrix result(rows_, cols_);
  if (rows_ == 1) {
    result.matrix_[0][0] = 1.0 / matrix_[0][0];
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        S21Matrix minor = GetMinor(i, j);
        double det = minor.Determinant();
        result.matrix_[i][j] = det * pow(-1, i + j + 2);
      }
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();
  if (det == 0.0) {
    throw std::invalid_argument("Determinant must not be zero");
  }
  S21Matrix result;
  if (rows_ == 1) {
    result.set_rows(1);
    result.set_cols(1);
    result.matrix_[0][0] = 1.0 / matrix_[0][0];
  } else {
    result.set_rows(rows_);
    result.set_cols(cols_);
    result = CalcComplements().Transpose();
    result.MulNumber(1.0 / det);
  }
  return result;
}

void S21Matrix::MatrixOperation(const S21Matrix other, int coefficient) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range("Different sizes of matrices");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += (other.matrix_[i][j] * coefficient);
    }
  }
}

void S21Matrix::SetDimensions(int rows, int cols) {
  int rows_limit = std::min(rows_, rows);
  int cols_limit = std::min(cols_, cols);
  S21Matrix temp(rows, cols);
  for (int i = 0; i < rows_limit; i++) {
    for (int j = 0; j < cols_limit; j++) {
      temp.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = temp;
}

S21Matrix S21Matrix::GetMinor(int ex_row, int ex_col) {
  S21Matrix minor(rows_ - 1, cols_ - 1);
  int i = 0, j = 0;
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < cols_; col++) {
      if (row != ex_row && col != ex_col) {
        minor.matrix_[i][j] = matrix_[row][col];
        j++;
        if (j == cols_ - 1) {
          j = 0;
          i++;
        }
      }
    }
  }
  return minor;
}

S21Matrix operator*(const double n, S21Matrix matrix) {
  matrix.MulNumber(n);
  return matrix;
};
}  // namespace s21
