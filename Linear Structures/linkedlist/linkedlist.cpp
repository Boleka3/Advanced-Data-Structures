#include "linkedlist.h"
template <typename t>
 linkedlist<t>::linkedlist() {
     head = NULL;
 }
 //======================================================================
 template <typename t>
void linkedlist<t>::insertAtHead(t newvalue){
    Node<t> *newnode = new Node<t>();
    newnode->data = newvalue;
    if (isempty()){
        newnode->next = NULL;
        head = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
}
//======================================================================
template <typename t>
void linkedlist<t>::insertAtTail(t newvalue){
    if (isempty())
        insertAtHead(newvalue);
    else {
        Node<t> *newnode = new Node<t>();
        newnode->data = newvalue;
        Node<t> *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
}
//======================================================================
template <typename t>
void linkedlist<t>::insertAt(t newvalue,int index) {
    if (index < linkedListSize()) {
        Node<t> *newnode = new Node<t>();
        newnode->data = newvalue;
        Node<t> *temp = head;
        int num = 0;
        while (num != index-1){
            num++;
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
        cout<<"not found";
}
//======================================================================
template <typename t>
void linkedlist<t>::removeAtHead() {
    if (head == nullptr) {
        cout << "empty list" << endl;
        return;
    }
    Node<t> *temp = head;
    head = head->next;
    delete temp;
}
//======================================================================
template <typename t>
void linkedlist<t>::removeAtTail() {
    if (head == nullptr) {
        cout << "Empty list" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node<t> *current = head;
    while (current->next != nullptr && current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}
//======================================================================
template <typename t>
void linkedlist<t>::removeAt(int index) {
    if (head == nullptr) {
        cout << "empty list" << endl;
        return;
    }

    if (index == 0) {
        Node<t> *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node<t> *current = head;
    Node<t> *previous = nullptr;
    int count = 0;

    while (current != nullptr && count != index) {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "Index doesnt exist" << endl;
        return;
    }
    previous->next = current->next;
    delete current;
    }
//======================================================================
template <typename t>
void linkedlist<t>::retrieveAt (int index){
    int num = 0; //++ to eqaul index
    Node<t> *temp = head;
    int cnt = linkedListSize();
    if (cnt < index){
        cout<<"index bigger than linkedlist lenth";
        return;
    }
    else {
        while (num != index) {
            num++;
            temp = temp->next;
        }
        cout << temp->data << " ";
    }
}
//======================================================================
template <typename t>
void linkedlist<t>::replaceAt (t newElement, int index){
    int num = 0; //++ to eqaul index
    Node<t> *temp = head;
    int cnt = linkedListSize();
    if (cnt < index){
        cout<<"index bigger than linkedlist lenth";
        return;
    }
    while (num != index){
        num++;
        temp = temp->next;
    }
    temp->data = newElement;
}
//======================================================================
template <typename t>
bool linkedlist<t>::isExist(t item){
    bool found = false;
    Node<t> *temp = head;
    while (temp != NULL){
        if (temp->data == item)
            found = true;
        temp = temp->next;
    }
    return found;
}
//======================================================================
template <typename t>
bool linkedlist<t>::isItemAtEqual (t element, int index) {
    int num = 0; //++ to eqaul index
    Node<t> *temp = head;
    int cnt = linkedListSize();
    if (cnt < index){
        cout<<"index bigger than linkedlist lenth";
        return false;
    }
    while (num != index){
        num++;
        temp = temp->next;
    }
    if (temp->data == element)
        return true;
    else
        return false;
}
//======================================================================
template <typename t>
void linkedlist<t>::swap (int index1, int index2){
    int size = linkedListSize();
    if (size == 0 || index1 < 0 || index2 < 0 || index1 >= size || index2 >= size) {
        cout << "Invalid indices or empty list." << endl;
        return;
    }
    if (index1 == index2) {
        return;
    }
    if (index1 > index2)
        swap(index2, index1);

    Node<t> *prev1 = nullptr, *prev2 = nullptr;
    Node<t> *curr1 = head, *curr2 = head;
    for (int i = 0; i < index1; i++) {
        prev1 = curr1;
        curr1 = curr1->next;
    }
    for (int i = 0; i < index2; i++) {
        prev2 = curr2;
        curr2 = curr2->next;
    }
    if (prev1)
        prev1->next = curr2;
    else
        head = curr2;

    if (prev2)
        prev2->next = curr1;
    else
        head = curr1;

    Node<t> *temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
}
//======================================================================
template <typename t>
bool linkedlist<t>::isempty(){
    return (head == NULL);
}
//======================================================================
template <typename t>
int linkedlist<t>::linkedListSize() {
    int counter = 0;
    Node<t> *temp = head;
    while (temp != NULL){
        counter++;
        temp = temp->next;
    }
    return counter;
};
//======================================================================
template <typename t>
void linkedlist<t>::clear (){
    int cnt = linkedListSize();
    for (int i = 0; i < cnt; ++i) {
        Node<t> *delptr = head;
        head = head->next;
        delete delptr;
    }
}
//======================================================================
template <typename t>
void linkedlist<t>::print() {
    Node<t> *temp = head;
    while (temp != NULL){
        cout<< temp->data<<" ";
        temp = temp->next;
    }
}
//======================================================================
