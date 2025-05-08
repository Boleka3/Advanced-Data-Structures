#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Heap {
private:
    vector<int> heap;

    // this function using the downwards moving method to maintain heapify
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        // Check the left child
        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        // Check the right child
        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }


        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    // Same function of heapify but with upwards property
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;

        // Move up if the current node is larger than the parent
        if (index && heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            heapifyUp(parent);
        }
    }

public:
    // Inserting process into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);  // heapifyUp function applied
    }

    // Extract the root of the max-heap
    int extractMax() {
        if (heap.size() == 0) {
            return -1;
        }

        int maxElem = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxElem;
    }

    // Extract minimum element
    int extractMin() {
        if (heap.size() == 0) {
            return -1;
        }

        return *min_element(heap.begin(), heap.end());
    }


    bool isEmpty() const {
        return heap.empty();
    }


    void printHeap() const {
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

///==================================


class PriorityQueue {
private:
    Heap heap;

public:
    // Inserting into the priority queue
    void insert(int value) {
        heap.insert(value);
    }

    // Extract the maximum element (high priority element)
    int extractHighestPriority() {
        return heap.extractMax();
    }


    bool isEmpty() const {
        return heap.isEmpty();
    }


    void printQueue() const {
        heap.printHeap();
    }
};

///=============================

void heapSort(vector<int>& arr) {
    Heap heap;

    // Build a max heap from the array
    for (int i = 0; i < arr.size(); ++i) {
        heap.insert(arr[i]);
    }

    // Extract the max element from the heap and place it in the array
    for (int i = arr.size() - 1; i >= 0; --i) {
        arr[i] = heap.extractMax();
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;


    heapSort(arr);

    cout << "Sorted array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;


    PriorityQueue pq;
    pq.insert(10);
    pq.insert(20);
    pq.insert(5);
    pq.insert(15);

    cout << "Priority Queue: ";
    pq.printQueue();

    cout << "Extracted highest priority element: " << pq.extractHighestPriority() << endl;
    cout << "Priority Queue after extraction: ";
    pq.printQueue();

    return 0;
}