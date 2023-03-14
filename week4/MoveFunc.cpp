#include <iostream>
#include "Header.h"

void Matrix::destroy() {
	for (int i = 0; i < m_rows; i++) {
		delete[] m_data[i];
	}
	delete[] m_data;
}
void Matrix::copy(const Matrix& other) {
	m_rows = other.m_rows;
	m_cols = other.m_cols;
	if (other.m_cols == 0 && other.m_rows == 0) {
		m_data = nullptr;
	}
	else {
		*m_data = new int[m_rows];
		for (int i = 0; i < m_rows; i++)
			m_data[i] = new int[m_cols];
		for (int i = 0; i < m_rows; i++) {
			for (int j = 0; j < m_cols; j++) {
				m_data[i] = other.m_data[i];
			}
		}
	}
}
Matrix::Matrix(int rows, int cols) {
	m_rows = rows;
	m_cols = cols;
	m_data = new int* [m_rows];
	for (int i = 0; i < m_rows; i++) {
		m_data[i] = new int[m_cols];
		for (int j = 0; j < m_cols; j++) {
			m_data[i][j] = 0;
		}
	}
}
Matrix::~Matrix() {
	if (m_cols == 0 && m_rows == 0)
		delete[] m_data;
	else {
		destroy();
	}
}
Matrix::Matrix(const Matrix& other) {
	copy(other);
}

Matrix& Matrix::operator=(const Matrix& other) {
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}

Matrix::Matrix(Matrix&& other) {
	m_rows = other.m_rows;
	other.m_data = nullptr;
}

Matrix& Matrix::operator=(Matrix&& other) {
	if (this != &other) {
		destroy();
		m_rows = other.m_rows;
		m_cols = other.m_cols;
		m_data = other.m_data;
		other.m_cols = 0;
		other.m_rows = 0;
		other.m_data = nullptr;
	}
	return *this;
}

int& Matrix::operator()(int row, int col) {

}

Matrix Matrix::operator+(const Matrix& other) const {
	if (other.m_cols == m_cols && other.m_rows == m_rows) {
		Matrix sum(m_rows, m_cols);
		for(int i = 0; i<m_rows;i++){
			for (int j = 0; j < m_cols; j++) {
				sum.m_data[i][j] = other.m_data[i][j] + m_data[i][j];
			}
		}
	}
}

Matrix Matrix::operator-(const Matrix& other) const {
	if (other.m_cols == m_cols && other.m_rows == m_rows) {
		Matrix sum(m_rows, m_cols);
		for (int i = 0; i < m_rows; i++) {
			for (int j = 0; j < m_cols; j++) {
				sum.m_data[i][j] = other.m_data[i][j] - m_data[i][j];
			}
		}
	}
}

Matrix Matrix::operator*(const Matrix& other) const {
	if (other.m_cols == m_rows) {
		Matrix sum(m_rows, m_cols);
		for (int i = 0; i < m_rows; i++) {
			for (int j = 0; j < m_cols; j++) {
				sum.m_data[i][j] = other.m_data[i][j] * m_data[j][i];
			}
		}
	}
}

