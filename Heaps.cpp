#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include"Product.h"
using namespace std;


class Heap {
private:
    vector<Product> heap;
    vector<Product> chronological;
bool isMaxHeap;

    void heapifyUp(int index) {
        if (index && compare(heap[parent(index)], heap[index])) {
            swap(heap[index], heap[parent(index)]);
            heapifyUp(parent(index));
        }
    }

    void heapifyDown(int index) {
        int leftChild = left(index);
        int rightChild = right(index);
        int swapIndex = index;

        if (leftChild < heap.size() && compare(heap[swapIndex], heap[leftChild])) {
            swapIndex = leftChild;
        }

        if (rightChild < heap.size() && compare(heap[swapIndex], heap[rightChild])) {
            swapIndex = rightChild;
        }

        if (swapIndex != index) {
            swap(heap[index], heap[swapIndex]);
            heapifyDown(swapIndex);
        }
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    bool compare(const Product& a, const Product& b) {
        if (isMaxHeap) {
            return a.getPrice() < b.getPrice();
        } else {
            return a.getPrice() > b.getPrice();
        }
    }

public:
    Heap(bool maxHeap) : isMaxHeap(maxHeap) {}

    void insert(const Product& item) {
        heap.push_back(item);
        chronological.push_back(item);
        heapifyUp(heap.size() - 1);
    }

    void remove() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return;
        }
        auto it = find(chronological.begin(), chronological.end(), heap.back());
        if(it != chronological.end()){
            chronological.erase(it);
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display() const {
        for (const auto& item : heap) {
            cout<<item;
        }
    }
    void Normally_display() {
        for (const auto& item : chronological) {
            cout<<item;
        }
    }

    void sortByName(bool ascending) {
        auto heapCopy = heap;
        sort(heapCopy.begin(), heapCopy.end(), [ascending](const Product& a, const Product& b) {
            return ascending ? a.getName() < b.getName() : a.getName() > b.getName();
        });
        for (const auto& item : heapCopy) {
            cout<<item;
        }
    }

    void sortByPrice(bool ascending) {
        auto heapCopy = heap;
        sort(heapCopy.begin(), heapCopy.end(), [ascending](const Product& a, const Product& b) {
            return ascending ? a.getPrice() < b.getPrice() : a.getPrice() > b.getPrice();
        });
        for (const auto& item : heapCopy) {
            cout<<item;
        }
    }
};

// int main() {
//     Heap minHeap, maxHeap;
//     int choice;
//     bool manualInput = false;
//     string filename;

//     cout << "Do you want to input items manually or from a text file? (1 for manual, 2 for text file): ";
//     cin >> choice;
//     if (choice == 2) {
//         manualInput = false;
//         cout << "Enter the filename: ";
//         cin >> filename;
//     } else {
//         manualInput = true;
//     }

//     if (!manualInput) {
//         ifstream inputFile(filename);
//         if (!inputFile) {
//             cerr << "Error opening file." << endl;
//             return 1;
//         }
//         string name, category;
//         int price;
//         while (inputFile >> name >> category >> price) {
//             Product newProduct(name, category, price);
//             minHeap.addProduct(newProduct, true);
//             maxHeap.addProduct(newProduct, false);
//         }
//     } else {
//         cout << "Enter items in the format: Name Category Price. Enter 'done' to finish." << endl;
//         string name, category;
//         int price;
//         while (true) {
//             cout << "Enter item: ";
//             cin >> name;
//             if (name == "done")
//                 break;
//             cin >> category >> price;
//             Product newProduct(name, category, price);
//             minHeap.addProduct(newProduct, true);
//             maxHeap.addProduct(newProduct, false);
//         }
//     }

//     while (true) {
//         cout << "\nChoose an option:" << endl;
//         cout << "1. Min Heap" << endl;
//         cout << "2. Max Heap" << endl;
//         cout << "3. Exit" << endl;
//         cin >> choice;

//         switch (choice) {
//             case 1: {
//                 cout << "\nChoose an operation for Min Heap:" << endl;
//                 cout << "1. Add item data" << endl;
//                 cout << "2. Remove item data" << endl;
//                 cout << "3. Display the item data normally" << endl;
//                 cout << "4. Display all the items sorted by their name ascending" << endl;
//                 cout << "5. Display all the items sorted by their name descending" << endl;
//                 cout << "6. Display all the items sorted by their prices ascending" << endl;
//                 cout << "7. Display all the items sorted by their prices descending" << endl;
//                 cin >> choice;

//                 switch (choice) {
//                     case 1: {
//                         cout << "Enter item details (Name Category Price): ";
//                         string name, category;
//                         int price;
//                         cin >> name >> category >> price;
//                         Product newProduct(name, category, price);
//                         minHeap.addProduct(newProduct, true);
//                         break;
//                     }
//                     case 2:
//                         minHeap.removeProduct(true);
//                         break;
//                     case 3:
//                         minHeap.display();
//                         break;
//                     case 4:
//                         minHeap.sortHeap(true);
//                         minHeap.display();
//                         break;
//                     case 5:
//                         minHeap.sortHeap(false);
//                         minHeap.display();
//                         break;
//                     case 6:
//                         minHeap.sortHeap(true);
//                         minHeap.display();
//                         break;
//                     case 7:
//                         minHeap.sortHeap(false);
//                         minHeap.display();
//                         break;
//                     default:
//                         cout << "Invalid option." << endl;
//                 }
//                 break;
//             }
//             case 2: {
//                 cout << "\nChoose an operation for Max Heap:" << endl;
//                 cout << "1. Add item data" << endl;
//                 cout << "2. Remove item data" << endl;
//                 cout << "3. Display the item data normally" << endl;
//                 cout << "4. Display all the items sorted by their name ascending" << endl;
//                 cout << "5. Display all the items sorted by their name descending" << endl;
//                 cout << "6. Display all the items sorted by their prices ascending" << endl;
//                 cout << "7. Display all the items sorted by their prices descending" << endl;
//                 cin >> choice;

//                 switch (choice) {
//                     case 1: {
//                         cout << "Enter item details (Name Category Price): ";
//                         string name, category;
//                         int price;
//                         cin >> name >> category >> price;
//                         Product newProduct(name, category, price);
//                         maxHeap.addProduct(newProduct, false);
//                         break;
//                     }
//                     case 2:
//                         maxHeap.removeProduct(false);
//                         break;
//                     case 3:
//                         maxHeap.display();
//                         break;
//                     case 4:
//                         maxHeap.sortHeap(true);
//                         maxHeap.display();
//                         break;
//                     case 5:
//                         maxHeap.sortHeap(false);
//                         maxHeap.display();
//                         break;
//                     case 6:
//                         maxHeap.sortHeap(true);
//                         maxHeap.display();
//                         break;
//                     case 7:
//                         maxHeap.sortHeap(false);
//                         maxHeap.display();
//                         break;
//                     default:
//                         cout << "Invalid option." << endl;
//                 }
//                 break;
//             }
//             case 3:
//                 return 0;
//             default:
//                 cout << "Invalid option." << endl;
//         }
//     }

//     return 0;
// }