#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void shuffleArray(int arr[], int n) {
    srand(time(0)); 

    for (int i = n - 1; i > 0; i--) {
 
        int j = rand() % (i + 1);

        swap(arr[i], arr[j]);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    shuffleArray(arr, n);

    cout << "Shuffled array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}