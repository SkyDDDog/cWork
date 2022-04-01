//
// Created by 222100209_李炎东 on 2022/4/1.
//

#ifndef MATRIXCLASS_MATRIX_H
#define MATRIXCLASS_MATRIX_H

#include <iostream>

using namespace std;

class Matrix {
private:
    int **matrix;
    int row;
    int col;
public:
    explicit Matrix(int r=3,int c=3);
    Matrix(const Matrix &obj);
    ~Matrix();
    friend istream &operator>>(istream &in,Matrix &matrix);
    friend ostream &operator<<(ostream &out,const Matrix &matrix);
    Matrix operator+(const Matrix &m);
    Matrix operator-(const Matrix &m);
    Matrix operator*(const Matrix &m);
    Matrix operator*(int num);
    friend Matrix &operator+=(Matrix &m1,const Matrix &m2);
    friend Matrix &operator-=(Matrix &m1,const Matrix &m2);
    friend Matrix &operator*=(Matrix &m1,int num);
};


#endif //MATRIXCLASS_MATRIX_H
