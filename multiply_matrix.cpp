#include <iostream>
using namespace std;

struct Triplet {
    int row;
    int col;
    int value;
};

int main() {
    int m1, n1, count1, m2, n2, count2;


    cout << "Enter dimensions of the first matrix (m1 n1): ";
    cin >> m1 >> n1;
    cout << "Enter the number of non-zero elements in the first matrix: ";
    cin >> count1;

    
    cout << "Enter dimensions of the second matrix (m2 n2): ";
    cin >> m2 >> n2;
    cout << "Enter the number of non-zero elements in the second matrix: ";
    cin >> count2;

 
    if (n1 != m2) {
        cout << "Matrix dimensions are not compatible for multiplication. Exiting." << endl;
        return 1;
    }

   
    Triplet *matrix1 = new Triplet[count1];
    cout << "Enter triplets for the first matrix (row col value):" << endl;
    for (int i = 0; i < count1; i++) {
        cin >> matrix1[i].row >> matrix1[i].col >> matrix1[i].value;
    }

    Triplet *matrix2 = new Triplet[count2];
    cout << "Enter triplets for the second matrix (row col value):" << endl;
    for (int i = 0; i < count2; i++) {
        cin >> matrix2[i].row >> matrix2[i].col >> matrix2[i].value;
    }


    int resultRows = m1;
    int resultCols = n2;
    int resultCount = 0;
    Triplet *resultMatrix = new Triplet[resultRows * resultCols];

    for (int i = 0; i < count1; i++) {
        for (int j = 0; j < count2; j++) {
            if (matrix1[i].col == matrix2[j].row) {
                resultMatrix[resultCount].row = matrix1[i].row;
                resultMatrix[resultCount].col = matrix2[j].col;
                resultMatrix[resultCount].value += matrix1[i].value * matrix2[j].value;
                resultCount++;
            }
        }
    }

    cout << "\nResult of matrix multiplication (in triplet form):" << endl;
    cout << resultRows << " " << resultCols << " " << resultCount << endl;
    for (int i = 0; i < resultCount; i++) {
        cout << resultMatrix[i].row << " " << resultMatrix[i].col << " " << resultMatrix[i].value << endl;
    }

    
    delete[] matrix1;
    delete[] matrix2;
    delete[] resultMatrix;

    return 0;
}