#include <iostream>
using namespace std;
#define MAX 100
class MinHeap {
int arr[MAX];
int size;
public:
MinHeap() {
size = 0;
}
// Insert element
void insert(int value) {
if (size == MAX) {
cout << "Heap Overflow\n";
return;
}
// Insert at end
int i = size;
arr[i] = value;
size++;
// Heapify up (for Min Heap)
while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
swap(arr[i], arr[(i - 1) / 2]);
i = (i - 1) / 2;
}
}
// Heapify down
void heapify(int i) {
int smallest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;

if (left < size && arr[left] < arr[smallest])
smallest = left;
if (right < size && arr[right] < arr[smallest])
smallest = right;
if (smallest != i) {
swap(arr[i], arr[smallest]);
heapify(smallest);
}
}
// Delete root (minimum element)
void deleteRoot() {
if (size <= 0) {
cout << "Heap Underflow\n";
return;
}
arr[0] = arr[size - 1];
size--;
heapify(0);
}
// Print heap
void printHeap() {
for (int i = 0; i < size; i++)
cout << arr[i] << " ";
cout << endl;
}
};
// Main function
int main() {
MinHeap h;
h.insert(40);
h.insert(20);
h.insert(30);
h.insert(10);
h.insert(15);
cout << "Min Heap: ";
h.printHeap();

// h.deleteRoot();
// cout << "After deleting root: ";
// h.printHeap();
return 0;
}
