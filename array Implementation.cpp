#include <iostream>
#include <vector>

class SparseMatrix {
public:
    SparseMatrix(int rows, int cols) : rows(rows), cols(cols) {}

    void extractNonZeroElements(const std::vector<std::vector<int>>& matrix) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int value = matrix[i][j];
                if (value != 0) {
                    rowIndices.push_back(i);
                    colIndices.push_back(j);
                    values.push_back(value);
                }
            }
        }
    }

    void display() {
        if (rowIndices.empty()) {
            std::cout << "No non-zero elements to display." << std::endl;
            return;
        }

        std::cout << "row" << " ";
        for (size_t i = 0; i < rowIndices.size(); ++i) {
            std::cout << rowIndices[i]<<" ";
        }
        std::cout << ""<< std::endl;
        std::cout << "column" << " ";
        for (size_t i = 0; i < colIndices.size(); ++i) {
            std::cout << colIndices[i] << " ";
        }
        std::cout << ""<< std::endl;
        std::cout << "value" << " ";
        for (size_t i = 0; i < values.size(); ++i) {
            std::cout << values[i] << " ";
        }
    }

private:
    int rows;
    int cols;
    std::vector<int> rowIndices;
    std::vector<int> colIndices;
    std::vector<int> values;
};

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

    std::cout << "Enter the matrix elements row by row:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    SparseMatrix sparseMatrix(rows, cols);
    sparseMatrix.extractNonZeroElements(matrix);

    std::cout << "Non-Zero Elements Table:" << std::endl;
    sparseMatrix.display();

    return 0;
}