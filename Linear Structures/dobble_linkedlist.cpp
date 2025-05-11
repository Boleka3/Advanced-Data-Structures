#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
    };

    Node* head;
public:
    DoublyLinkedList() : head(nullptr) {}
    void insertAtHead(const T& newvalue) {
        Node* newnode = new Node(); 
        newnode->data = newvalue;  
        newnode->prev = nullptr;    
        newnode->next = head;  

        if (head != nullptr)
            head->prev = newnode; 

        head = newnode; 
    }
//====================================================
    void insertAtTail(const T& newvalue) {
        if (isEmpty()) {
            insertAtHead(newvalue);
            return;
        }

        Node* newnode = new Node();
        newnode->data = newvalue;
        newnode->next = nullptr;

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }
//====================================================
    void insertAt(const T& newvalue, int index) {
        if (index == 0) {
            insertAtHead(newvalue);
            return;
        }

        Node* newnode = new Node(); 
        newnode->data = newvalue;   

        Node* temp = head; 
        for (int i = 0; i < index - 1 && temp != nullptr; ++i)
            temp = temp->next;  

        if (temp == nullptr) {
            cout << "index out of range" << endl;
            return;
        }

        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != nullptr)
            temp->next->prev = newnode;
        temp->next = newnode;
    }
//====================================================
    void removeAtHead() {
        if (head == nullptr) {
            cout << "list fadya already" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        delete temp;
    }
//====================================================
    void removeAtTail() {
        if (head == nullptr) {
            cout << "list fadya already" << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr; 
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->prev->next = nullptr; 
     
        delete temp;    
    }
//====================================================
    void removeAt(int index) {
        if (index == 0) {
            removeAtHead();
            return;
        }

        Node* temp = head;
       
        for (int i = 0; temp != nullptr && i < index - 1; ++i)
            temp = temp->next;

        
        if (temp == nullptr || temp->next == nullptr) {
            cout << "bara l range" << endl;
            return;
        }

        Node* Bdeleted = temp->next;   
        temp->next = Bdeleted->next;
        if (Bdeleted->next != nullptr)
            Bdeleted->next->prev = temp;    
        delete Bdeleted;   
    }
//====================================================
    T retrieveAt(int index) {
        Node* temp = head;
        
        for (int i = 0; temp != nullptr && i < index; ++i)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "bara l range" << endl;
            exit(0);
        }

        return temp->data;
    }
//====================================================
    void replaceAt(const T& newElement, int index) {
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < index; ++i)
            temp = temp->next;

        if (temp == nullptr) {
            cerr << "bara l range" << endl;
            exit(0);
        }

        temp->data = newElement;
    }
//====================================================
    bool isExist(const T& item) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == item)
                return true;
            temp = temp->next;
        }
        return false;
    }
//====================================================
    bool isItemAtEqual(const T& element, int index) {
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < index; ++i)
            temp = temp->next;

        if (temp == nullptr) {
            cerr << "bara l range" << endl;
            exit(0);
        }

        return temp->data == element;
    }
//====================================================
    void swap(int index1, int index2) {
        if (index1 == index2)
            return;

       //traverse kol temp
        Node* temp1 = head;
        for (int i = 0; temp1 != nullptr && i < index1; ++i)
            temp1 = temp1->next;

        Node* temp2 = head;
        for (int i = 0; temp2 != nullptr && i < index2; ++i)
            temp2 = temp2->next;
        
        if (temp1 == nullptr || temp2 == nullptr) {
            cerr << "bara l range" << endl;
            exit(0);
        }


        if (temp1->prev != nullptr) 
            temp1->prev->next = temp2;  
        if (temp2->prev != nullptr)
            temp2->prev->next = temp1;

 
        if (temp1->next != nullptr)
            temp1->next->prev = temp2;
        if (temp2->next != nullptr)
            temp2->next->prev = temp1;

       
        Node* temp = temp1->prev;   
        temp1->prev = temp2->prev;
        temp2->prev = temp;

        temp = temp1->next;
        temp1->next = temp2->next;
        temp2->next = temp;

        // Update head if necessary
        if (head == temp1)
            head = temp2;
        else if (head == temp2)
            head = temp1;
    }
    //=======================================
    bool isEmpty() const {
        return head == nullptr;
    }
//====================================================
    int linkedListSize() const {
        int counter = 0;
        Node* temp = head;
        while (temp != nullptr) {
            ++counter;
            temp = temp->next;
        }
        return counter;
    }
//====================================================
    void clear() {
        while (head != nullptr)
            removeAtHead();
    }
//====================================================
    void print() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList<int> myList;
    int option;
    do {
        cout << "Menu:" << endl;
        cout << "1.InsertAtHead" << endl;
        cout << "2.insertAtTail" << endl;
        cout << "3.insertAt" << endl;
        cout << "4.removeAtHead" << endl;
        cout << "5.removeAtTail" << endl;
        cout << "6.removeAt" << endl;
        cout << "7.retrieveAt" << endl;
        cout << "8.replaceAt" << endl;
        cout << "9.isExist" << endl;
        cout << "10.isItemAtEqual" << endl;
        cout << "11.swap" << endl;
        cout << "12.isEmpty" << endl;
        cout << "13.linkedListSize" << endl;
        cout << "14.clear" << endl;
        cout << "15.Print" << endl;
        cout << "0.Exit" << endl;
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1: {
                int newValue;
                cout << "Enter the value to insert at the head: ";
                cin >> newValue;
                myList.insertAtHead(newValue);
                cout << "Linked List: ";
                myList.print();
                break;
            }
            case 2: {
                int newValue;
                cout << "Enter the value to insert at the tail: ";
                cin >> newValue;
                myList.insertAtTail(newValue);
                cout << "Linked List: ";
                myList.print();
                break;
            }
            case 3: {
                int newValue;
                int index;
                cout << "Enter the value: ";
                cin >> newValue;
                cout << "Enter index: ";
                cin >> index;
                myList.insertAt(newValue, index);
                cout << "Linked List: ";
                myList.print();
                break;
            }
            case 4: {
                cout << "removed head ";
                myList.removeAtHead();
                cout << "Linked List: ";
                myList.print();
                break;
            }
            case 5: {
                cout << "removed tail ";
                myList.removeAtTail();
                cout << "Linked List: ";
                myList.print();
                break;
            }
            case 6: {
                int newValue;
                cout << "remove at index: ";
                cin >> newValue;
                myList.removeAt(newValue);
                cout << "Linked List: ";
                myList.print();
                break;
            }
            case 7: {
                int newValue;
                cout << "retrieve at index: ";
                cin >> newValue;

                cout<<"the data retrieved: "<<myList.retrieveAt(newValue)<<endl;
                cout << "Linked List: ";
                myList.print();
                break;
            }
            case 8: {
                int newElement;
                int index;
                cout << "enter new value: ";
                cin >> newElement;
                cout << "replace at index: ";
                cin >> index;
                myList.replaceAt(newElement, index);
                cout << "Linked List: ";
                myList.print();
                break;
            }
            case 9: {
                int newValue;
                cout << "enter value: ";
                cin >> newValue;
                if (!myList.isExist(newValue))
                    cout << "not Exist" << endl;
                else
                    cout << "yes is Exist" << endl;
                break;
            }
            case 10: {
                int index;
                int element;
                cout << "enter value: ";
                cin >> element;
                cout << "enter index: ";
                cin >> index;
                if (!myList.isItemAtEqual(element, index))
                    cout << "no" << endl;
                else
                    cout << "yes" << endl;
                break;
            }
            case 11: {
                int newValue;
                int newValue2;
                cout << "enter first index: ";
                cin >> newValue;
                cout << "enter second index: ";
                cin >> newValue2;
                myList.swap(newValue, newValue2);
                cout << "Linked List: ";
                myList.print();
                break;
            }
            case 12: {
                if (myList.isEmpty())
                    cout << "yes" << endl;
                else
                    cout << "no" << endl;
                break;
            }
            case 13: {
                cout << "size is: ";
                cout << myList.linkedListSize() << endl;
                break;
            }
            case 14: {
                myList.clear();
                cout << "Linked List: ";
                myList.print();
                break;
            }
            case 15: {
                cout << "Linked List: ";
                myList.print();
                break;
            }
            case 0:
                cout << "closing menu" << endl;
                break;
            default:
                cout << "wrong option please choose from the menu" << endl;
        }
    } while (option != 0);

    return 0;
}
