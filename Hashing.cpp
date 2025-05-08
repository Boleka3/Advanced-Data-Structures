#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class HashTable {
private:
    // Node class for chaining
    struct Node {
        int key;
        int value;
        Node* next;
        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };
    
    // Entry structure for open addressing
    struct Entry {
        int key;
        int value;
        bool isOccupied;
        bool isDeleted;
        
        Entry() : key(0), value(0), isOccupied(false), isDeleted(false) {}
    };
    
    int size;
    Node** chainTable;
    Entry* probeTable;
    int count;
    
    // Basic hash functions
    int divisionHash(int key) {
        return key % size;
    }
    
    int multiplicationHash(int key) {
        const double A = 0.618033988749895;
        double product = key * A;
        double fractional = product - floor(product);
        return floor(size * fractional);
    }
    
    int midSquareHash(int key) {
        long long squared = (long long)key * key;
        string str = to_string(squared);
        while(str.length() < 8) {
            str = "0" + str;
        }
        int mid = str.length() / 2;
        string midStr = str.substr(mid-2, 4);
        return stoi(midStr) % size;
    }
    
    int foldingHash(int key) {
        string str = to_string(key);
        int sum = 0;
        for(size_t i = 0; i < str.length(); i += 2) {
            string part = str.substr(i, min((size_t)2, str.length() - i));
            sum += stoi(part);
        }
        return sum % size;
    }
    
    int doubleHash(int key, int i) {
        int h1 = divisionHash(key);  // 5
        int h2 = 1 + (key % (size - 1));  //8
        return (h1 + i * h2) % size;
    }

public:
    HashTable(int tableSize) {
        size = tableSize;
        count = 0;
        chainTable = new Node*[size]();
        probeTable = new Entry[size];
    }
    
    ~HashTable() {
        
        for(int i = 0; i < size; i++) {
            Node* current = chainTable[i];
            while(current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] chainTable;
        delete[] probeTable;
    }
    
    // 1. Chaining Method
    void insertChaining(int key, int value) {
        int index = divisionHash(key);
        Node* newNode = new Node(key, value);
        newNode->next = chainTable[index];
        chainTable[index] = newNode;
    }
    
    int searchChaining(int key) {
        int index = divisionHash(key);
        Node* current = chainTable[index];
        while(current != nullptr) {
            if(current->key == key)
                return current->value;
            current = current->next;
        }
        return -1;
    }
    
    // 2. Linear Probing
    bool insertLinearProbing(int key, int value) {
        if(count == size) return false;
        
        int index = divisionHash(key);
        int i = 0;
        
        while(i < size) {
            int currentIndex = (index + i) % size;
            if(!probeTable[currentIndex].isOccupied ||
               probeTable[currentIndex].isDeleted) {
                probeTable[currentIndex].key = key;
                probeTable[currentIndex].value = value;
                probeTable[currentIndex].isOccupied = true;
                probeTable[currentIndex].isDeleted = false;
                count++;
                return true;
            }
            i++;
        }
        return false;
    }
    
    int searchLinearProbing(int key) {
        int index = divisionHash(key);
        int i = 0;
        
        while(i < size) {
            int currentIndex = (index + i) % size;
            if(!probeTable[currentIndex].isOccupied)
                return -1;
            if(probeTable[currentIndex].isOccupied &&
               !probeTable[currentIndex].isDeleted &&
               probeTable[currentIndex].key == key)
                return probeTable[currentIndex].value;
            i++;
        }
        return -1;
    }
    
    // 3. Double Hashing
    bool insertDoubleHashing(int key, int value) {
        if(count == size) return false;
        
        for(int i = 0; i < size; i++) {
            int index = doubleHash(key, i);
            if(!probeTable[index].isOccupied ||
               probeTable[index].isDeleted) {
                probeTable[index].key = key;
                probeTable[index].value = value;
                probeTable[index].isOccupied = true;
                probeTable[index].isDeleted = false;
                count++;
                return true;
            }
        }
        return false;
    }
    
    int searchDoubleHashing(int key) {
        for(int i = 0; i < size; i++) {
            int index = doubleHash(key, i);
            if(!probeTable[index].isOccupied)
                return -1;
            if(probeTable[index].isOccupied &&
               !probeTable[index].isDeleted &&
               probeTable[index].key == key)
                return probeTable[index].value;
        }
        return -1;
    }
    
    void printChainTable() {
        cout << "\nChaining Table:" << endl;
        for(int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* current = chainTable[i];
            while(current != nullptr) {
                cout << "(" << current->key << "," << current->value << ") -> ";
                current = current->next;
            }
            cout << "null" << endl;
        }
    }
    
    void printProbeTable() {
        cout << "\nProbe Table:" << endl;
        for(int i = 0; i < size; i++) {
            if(probeTable[i].isOccupied && !probeTable[i].isDeleted) {
                cout << i << ": (" << probeTable[i].key << ","
                     << probeTable[i].value << ")" << endl;
            }
        }
    }
};

int main() {
    HashTable ht(10);
    
    // Chaining
    cout << "\nTesting Chaining:" << endl;
    ht.insertChaining(5, 50);
    ht.insertChaining(15, 150);
    ht.insertChaining(25, 250);
    ht.printChainTable();
    cout << "Search 15: " << ht.searchChaining(15) << endl;
    
    // Linear
    cout << "\nTesting Linear Probing:" << endl;
    ht.insertLinearProbing(5, 50);
    ht.insertLinearProbing(15, 150);
    ht.insertLinearProbing(25, 250);
    ht.printProbeTable();
    cout << "Search 15: " << ht.searchLinearProbing(15) << endl;
    
    // Double
    cout << "\nTesting Double Hashing:" << endl;
    HashTable ht2(10);  // جدول جديد للاختبار
    ht2.insertDoubleHashing(5, 50);
    ht2.insertDoubleHashing(15, 150);
    ht2.insertDoubleHashing(25, 250);
    ht2.printProbeTable();
    cout << "Search 15: " << ht2.searchDoubleHashing(15) << endl;
    
    return 0;
}