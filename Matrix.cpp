//
// Created by 222100209_李炎东 on 2022/4/1.
//

#include "Matrix.h"

Matrix::Matrix(int r, int c) : row(r), col(c) {
    matrix = new int*[r];
    for (int i = 0; i < r; ++i) {
        matrix[i] = new int[c];
    }
}

Matrix::Matrix(const Matrix &obj) : row(obj.row), col(obj.col){
    matrix = new int*[obj.row];
    for (int i = 0; i < obj.row; ++i) {
        matrix[i] = new int[obj.col];
    }
    for (int i = 0; i < obj.row; ++i) {
        for (int j = 0; j < obj.col; ++j) {
            matrix[i][j] = obj.matrix[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < row; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

istream &operator>>(istream &in, Matrix &matrix) {
    for (int i = 0; i < matrix.row; ++i) {
        for (int j = 0; j < matrix.col; ++j) {
            in >> matrix.matrix[i][j];
        }
    }
    return in;
}

ostream &operator<<(ostream &out, const Matrix &matrix) {
    for (int i = 0; i < matrix.row; ++i) {
        for (int j = 0; j < matrix.col; ++j) {
            out << matrix.matrix[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

Matrix Matrix::operator+(const Matrix &m) {
    Matrix result(*this);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &m) {
    Matrix result(*this);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &m) {
    Matrix result(row,m.col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < m.col; ++j) {
            int sum = 0;
            for (int k = 0; k < col; ++k) {
                sum += matrix[i][k] + m.matrix[k][j];
            }
            result.matrix[i][j] = sum;
        }
    }
    return result;
}

Matrix Matrix::operator*(int num) {
    Matrix result(*this);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.matrix[i][j] = matrix[i][j] * num;
        }
    }
    return result;
}

Matrix &operator+=(Matrix &m1, const Matrix &m2) {
    m1 = m1+m2;
    return m1;
}

Matrix &operator-=(Matrix &m1, const Matrix &m2) {
    m1 = m1-m2;
    return m1;
}

Matrix &operator*=(Matrix &m1, int num) {
    m1 = m1 * num;
    return m1;
}





