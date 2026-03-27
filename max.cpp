#include <iostream>
using namespace std;
#define MAX 100
class MaxHeap {
int heap[MAX];
int size;
public:
MaxHeap() {
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
heap[i] = value;
size++;
cout<<"value inserted"<<" "<<value<<" "<<" "<<"size="<<size<<endl;
// Heapify up
while (i > 1 && heap[i] > heap[(i - 1) / 2])
{
swap(heap[i], heap[(i - 1) / 2]);
i = (i - 1) / 2;
}
}
// Heapify down
void heapify(int i) {
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < size && heap[left] > heap[largest])
largest = left;
if (right < size && heap[right] > heap[largest])

largest = right;
if (largest != i) {
swap(heap[i], heap[largest]);
heapify(largest);
}
}
// Delete root (max element)
void deleteRoot() {
if (size <= 0) {
cout << "Heap Underflow\n";
return;
}
cout<< heap[0]<<"and"<< heap[size - 1];
heap[0] = heap[size - 1];
size--;
heapify(0);
}
// Print heap
void printHeap() {
for (int i = 0; i < size; i++)
cout << heap[i] << " ";
cout << endl;
}
};
// Main function
int main() {
MaxHeap h;
h.insert(50);
h.insert(30);
h.insert(40);
h.insert(10);
h.insert(5);
h.insert(20);
h.insert(60);
cout << "Max Heap: ";
h.printHeap();
// h.deleteRoot();

// cout << "After deleting root: ";
// h.printHeap();
return 0;
}
