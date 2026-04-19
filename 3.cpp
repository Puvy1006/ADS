
#include <iostream>
using namespace std;

#define MAX 100

// MIN HEAP
class MinHeap {
    int arr[MAX];
    int size;

public:
    MinHeap() { size = 0; }

    int getSize() { return size; }

    int getMin() {
        if (size == 0) return -1;
        return arr[0];
    }

    void insert(int value) {
        if (size == MAX) {
            cout << "MinHeap Overflow\n";
            return;
        }

        int i = size;
        arr[i] = value;
        size++;

        while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        while (true) {
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && arr[left] < arr[smallest])
                smallest = left;

            if (right < size && arr[right] < arr[smallest])
                smallest = right;

            if (smallest != i) {
                swap(arr[i], arr[smallest]);
                i = smallest;
            } else break;
        }
    }

    int removeMin() {
        if (size <= 0) return -1;

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;

        heapifyDown(0);
        return root;
    }
};

// MAX HEAP
class MaxHeap {
    int heap[MAX];
    int size;

public:
    MaxHeap() { size = 0; }

    int getSize() { return size; }

    int getMax() {
        if (size == 0) return -1;
        return heap[0];
    }

    void insert(int value) {
        if (size == MAX) {
            cout << "MaxHeap Overflow\n";
            return;
        }

        int i = size;
        heap[i] = value;
        size++;

        while (i != 0 && heap[i] > heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && heap[left] > heap[largest])
                largest = left;

            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

    int removeMax() {
        if (size <= 0) return -1;

        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;

        heapifyDown(0);
        return root;
    }
};

// MEDIAN SYSTEM
class MedianFinder {
    MaxHeap leftHeap;
    MinHeap rightHeap;

public:

    void insertNumber(int num) {

        if (leftHeap.getSize() == 0 || num <= leftHeap.getMax())
            leftHeap.insert(num);
        else
            rightHeap.insert(num);

        // balance
        if (leftHeap.getSize() > rightHeap.getSize() + 1) {
            int moved = leftHeap.removeMax();
            rightHeap.insert(moved);
        }
        else if (rightHeap.getSize() > leftHeap.getSize()) {
            int moved = rightHeap.removeMin();
            leftHeap.insert(moved);
        }

        printMedian();
    }

    void printMedian() {
        if (leftHeap.getSize() == rightHeap.getSize()) {
            float median = (leftHeap.getMax() + rightHeap.getMin()) / 2.0;
            cout << "Current Median = " << median << endl;
        } else {
            cout << "Current Median = " << leftHeap.getMax() << endl;
        }
    }
};

// MAIN 
int main() {
    MedianFinder mf;

    int choice, num;

    do {
        cout << "\n MENU \n";
        cout << "1. Insert number\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter number: ";
            cin >> num;
            mf.insertNumber(num);
            break;

        case 2:
            cout << "End\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 2);

    return 0;
}
