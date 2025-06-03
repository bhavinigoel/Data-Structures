#include <iostream>
using namespace std;

int **Sparse_mat1, **Sparse_mat2, **Sum_mat, m1, n1, m2, n2, count1, count2, sumCount;

void create_matrix(int **&mat, int &count, int m, int n) {
    int i, j;
    mat = new int *[m];
    for (i = 0; i < m; i++) {
        mat[i] = new int[n];
    }

    cout << "Enter values of Matrix:" << endl;
    count = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> mat[i][j];
            if (mat[i][j] != 0) {
                count++;
            }
        }
    }
}

void create_TRIPLET(int **Sparse_mat, int m, int n, int count, int **&TRIP) {
    int i, j, k = 1;

    TRIP = new int *[count + 1];
    for (i = 0; i < count + 1; i++) {
        TRIP[i] = new int[3];
    }

    TRIP[0][0] = m;
    TRIP[0][1] = n;
    TRIP[0][2] = count;

    k = 1;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (Sparse_mat[i][j] != 0) {
                TRIP[k][0] = i;
                TRIP[k][1] = j;
                TRIP[k][2] = Sparse_mat[i][j];
                k++;
            }
        }
    }
}

int **add_matrices(int **Trip_A, int **Trip_B, int count1, int count2, int &sumCount) {
    int i = 1, j = 1, k = 1;
    sumCount = 0;

    while (i <= count1 && j <= count2) {
        if (Trip_A[i][0] < Trip_B[j][0] || (Trip_A[i][0] == Trip_B[j][0] && Trip_A[i][1] < Trip_B[j][1])) {
            sumCount++;
            i++;
        } else if (Trip_A[i][0] > Trip_B[j][0] || (Trip_A[i][0] == Trip_B[j][0] && Trip_A[i][1] > Trip_B[j][1])) {
            sumCount++;
            j++;
        } else {
            sumCount++;
            i++;
            j++;
        }
    }

    int **Sum = new int *[sumCount + 1];
    for (i = 0; i < sumCount + 1; i++) {
        Sum[i] = new int[3];
    }

    i = 1;
    j = 1;
    k = 1;

    while (i <= count1 && j <= count2) {
        if (Trip_A[i][0] < Trip_B[j][0] || (Trip_A[i][0] == Trip_B[j][0] && Trip_A[i][1] < Trip_B[j][1])) {
            Sum[k][0] = Trip_A[i][0];
            Sum[k][1] = Trip_A[i][1];
            Sum[k][2] = Trip_A[i][2];
            i++;
            k++;
        } else if (Trip_A[i][0] > Trip_B[j][0] || (Trip_A[i][0] == Trip_B[j][0] && Trip_A[i][1] > Trip_B[j][1])) {
            Sum[k][0] = Trip_B[j][0];
            Sum[k][1] = Trip_B[j][1];
            Sum[k][2] = Trip_B[j][2];
            j++;
            k++;
        } else {
            Sum[k][0] = Trip_A[i][0];
            Sum[k][1] = Trip_A[i][1];
            Sum[k][2] = Trip_A[i][2] + Trip_B[j][2];
            i++;
            j++;
            k++;
        }
    }

    return Sum;
}

int main() {
    cout << "Enter the dimensions of the first matrix (m1 n1): ";
    cin >> m1 >> n1;

    cout << "Enter the dimensions of the second matrix (m2 n2): ";
    cin >> m2 >> n2;

    if (m1 != m2 || n1 != n2) {
        cout << "Matrix dimensions do not match for addition. Exiting." << endl;
        return 1;
    }

    create_matrix(Sparse_mat1, count1, m1, n1);
    create_matrix(Sparse_mat2, count2, m2, n2);

    create_TRIPLET(Sparse_mat1, m1, n1, count1, Sparse_mat1);
    create_TRIPLET(Sparse_mat2, m2, n2, count2, Sparse_mat2);

    Sum_mat = add_matrices(Sparse_mat1, Sparse_mat2, count1, count2, sumCount);

    cout << "\nSum of Matrices (in triplet form):\n";
    for (int i = 1; i <= sumCount; i++) {
        for (int j = 0; j < 3; j++) {
            cout << Sum_mat[i][j] << " ";
        }
        cout << endl;
    }


    for (int i = 0; i < m1; i++) {
        delete[] Sparse_mat1[i];
    }
    delete[] Sparse_mat1;

    for (int i = 0; i < m2; i++) {
        delete[] Sparse_mat2[i];
    }
    delete[] Sparse_mat2;

    for (int i = 0; i < sumCount + 1; i++) {
        delete[] Sum_mat[i];
    }
    delete[] Sum_mat;

    return 0;
}