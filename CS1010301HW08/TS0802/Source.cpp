#include <iostream>
#include <vector>
#include <string>

using namespace std;

void inputMatrix(int**& ary, int row, int col)
{
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> ary[i][j];
			//cout << ary[i][j] << ' ';
		}
	}
	//cout << "//";
}

int** multiply(int** matrix1, int row1, int col1, int** matrix2, int row2, int col2) {
	int** result;
	result = new int* [row1];
	for (int i = 0; i < row1; i++) {
		result[i] = new int[col2];
	}
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			result[i][j] = 0;
			for (int k = 0; k < col1; k++) {
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	return result;
}

void output(int** matrix, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col - 1; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << matrix[i][col - 1];
		cout << endl;
	}
}

int main() {
	int row1, col1, row2, col2;
	while (cin >> row1 >> col1 >> row2 >> col2) {
		//cout << row1 << ' ' << col1 << ' ' << row2 << ' ' << col2 << "//";
		if (col1 != row2) {
			cout << "Matrix multiplication failed." << endl;
			return 0;
		}
		else {
			int** A;
			int** B;
			A = new int* [row1];
			for (int i = 0; i < row1; i++) {
				A[i] = new int[col1];
			}
			B = new int* [row2];
			for (int i = 0; i < row2; i++) {
				B[i] = new int[col2];
			}
			inputMatrix(A, row1, col1);
			inputMatrix(B, row2, col2);
			output(multiply(A, row1, col1, B, row2, col2), row1, col2);
		}
	}
}