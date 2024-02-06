#include <iostream>
#include <vector>

// Function to add two matrices
std::vector<std::vector<int>> addMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int rows = A.size();
    int cols = A[0].size();
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();
    std::vector<std::vector<int>> result(rowsA, std::vector<int>(colsB, 0));

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Function to transpose a matrix
std::vector<std::vector<int>> transposeMatrix(const std::vector<std::vector<int>>& A) {
    int rows = A.size();
    int cols = A[0].size();
    std::vector<std::vector<int>> result(cols, std::vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = A[i][j];
        }
    }
    return result;
}

// Function to display a matrix
void displayMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> A = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    std::vector<std::vector<int>> B = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };

    std::cout << "Matrix A:" << std::endl;
    displayMatrix(A);
    std::cout << std::endl;

    std::cout << "Matrix B:" << std::endl;
    displayMatrix(B);
    std::cout << std::endl;

    std::cout << "Matrix A + B:" << std::endl;
    displayMatrix(addMatrices(A, B));
    std::cout << std::endl;

    std::cout << "Matrix A * B:" << std::endl;
    displayMatrix(multiplyMatrices(A, B));
    std::cout << std::endl;

    std::cout << "Transpose of Matrix A:" << std::endl;
    displayMatrix(transposeMatrix(A));
    std::cout << std::endl;

    return 0;
}
