#include <iostream>
using namespace std;

class MaxHeap
{
    const static int MAX_SIZE = 20;
    int heap[MAX_SIZE];
    int size;

public:
    int BinaryHeap()
    {
        size = 0;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int leftChild(int i)
    {
        return 2 * i + 1;
    }

    int rightChild(int i)
    {
        return 2 * i + 2;
    }

     void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }


    void maxheapify( ){

    }
};
