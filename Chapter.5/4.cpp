#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
	int row;
	int col;
	double** mat; // 2차원 행렬

public:
	Matrix(int _row, int _col) : row(_row), col(_col) {
		mat = new double* [row];
		int rowLen = col * sizeof(double);
		for (int i = 0; i < row; ++i) {
			mat[i] = new double[col];
			memset(mat[i], 0, rowLen);
		}
	}

	Matrix(const Matrix& mat) {
		row = mat.row;
		col = mat.col;
		this->mat = new double* [row];
		int rowLen = col * sizeof(double);
		for (int i = 0; i < row; ++i) {
			this->mat[i] = new double[col];
		}

		for (int i = 0; i < mat.GetRows(); ++i) {
			for (int j = 0; j < mat.GetCols(); ++j) {
				SetValue(i, j, mat.mat[i][j]);
			}
		};
	}

	~Matrix() {
		for (int i = 0; i < row; i++) {
			delete[] mat[i];
		}
		delete[] mat;
	}

	void Print() const{
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	int GetRows() const{
		return row;
	}

	int GetCols() const{
		return col;
	}

	void SetValue(int _row, int _col, double value){
		mat[_row][_col] = value;
	}

	Matrix operator+(const Matrix& mat) const;
	Matrix operator-(const Matrix& mat) const;
	Matrix operator*(const Matrix& mat) const;

	Matrix& operator=(const Matrix& mat);
};

Matrix Matrix::operator+(const Matrix& mat) const {
	Matrix tmp(mat.GetRows(), mat.GetCols());
	for (int i = 0; i < mat.GetRows(); ++i) {
		for (int j = 0; j < mat.GetCols(); ++j) {
			tmp.SetValue(i, j, this->mat[i][j] + mat.mat[i][j]);
		}
	};
	return tmp;
}

Matrix Matrix::operator-(const Matrix& mat) const {
	Matrix tmp(mat.GetRows(), mat.GetCols());
	for (int i = 0; i < mat.GetRows(); ++i) {
		for (int j = 0; j < mat.GetCols(); ++j) {
			tmp.SetValue(i, j, this->mat[i][j] - mat.mat[i][j]);
		}
	};
	return tmp;
}

/// <summary>
/// 행렬의 스칼라 곱
/// </summary>
/// <param name="mat"곱해질 행렬</param>
/// <returns>스칼라 곱의 결과</returns>
Matrix Matrix::operator*(const Matrix& mat) const {
	Matrix tmp(mat.GetRows(), mat.GetCols());
	for (int i = 0; i < mat.GetRows(); ++i) {
		for (int j = 0; j < mat.GetCols(); ++j) {
			tmp.SetValue(i, j, this->mat[i][j] * mat.mat[i][j]);
		}
	};
	return tmp;
}

Matrix& Matrix::operator=(const Matrix& mat) {
	if (row != mat.row || col != mat.col) {
		for (int i = 0; i < row; i++) {
			delete[] this->mat[i];
		}
		delete[] this->mat;

		this->mat = new double* [mat.row];
		int rowLen = mat.col * sizeof(double);
		for (int i = 0; i < mat.row; ++i) {
			this->mat[i] = new double[mat.col];
			memset(this->mat[i], 0, rowLen);
		}

		row = mat.row;
		col = mat.col;
	}

	for (int i = 0; i < mat.row; ++i) {
		for (int j = 0; j < mat.col; ++j) {
			SetValue(i, j, mat.mat[i][j]);
		}
	};
	return *this;
}

void MatInit(Matrix& mat, double k) {
	for (int i = 0; i < mat.GetRows(); ++i) {
		for (int j = 0; j < mat.GetCols(); ++j) {
			mat.SetValue(i, j, k);
			++k;
		}
	};
}

int main() {
	auto mat1 = Matrix(2, 3);
	auto mat2 = Matrix(2, 3);

	MatInit(mat1, 0);
	MatInit(mat2, 5);

	cout << "행렬 초기값" << endl;
	mat1.Print();
	mat2.Print();

	cout << "행렬 사칙연산" << endl;
	(mat1 + mat2).Print();
	(mat1 - mat2).Print();
	(mat1 * mat2).Print(); // 스칼라 곱

	cout << "대입연산" << endl;
	auto mat3 = Matrix(1, 1);
	mat3 = mat1;
	mat3.Print();

	auto mat4 = Matrix(1, 1);
	mat4 = mat1 + mat2;
	mat4.Print();

	return 0;
}
