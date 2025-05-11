#include "Circular_LinkedList.h"
template <typename T>
circular_linkedlist<T>::circular_linkedlist() : last(nullptr) {
}
//======================================================================
template <typename T>
void circular_linkedlist<T>::insertAtHead(T newvalue) {
    Node<T> *newnode = new Node<T>();
    newnode->data = newvalue;
    if (last == nullptr) {
        last = newnode;
        last->next = last;
    } else {
        newnode->next = last->next;
        last->next = newnode;
    }
}
//======================================================================
template <typename t>
void circular_linkedlist<t>::insertAtTail(t newvalue){
    if (isempty())
        insertAtHead(newvalue);
    else {
        Node<t> *newnode = new Node<t>();
        newnode->data = newvalue;
        newnode->next = last->next;
        last->next = newnode;
        last = last->next;
    }
}
//======================================================================
template <typename t>
void circular_linkedlist<t>::insertAt(t newvalue,int index) {
    if (index == 0){
        insertAtHead(newvalue);
    } else if (index == (linkedListSize())){
        insertAtTail(newvalue);
    }
    else if (index < linkedListSize()) {
        Node<t> *newnode = new Node<t>();
        newnode->data = newvalue;
        Node<t> *temp = last->next;
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
template <typename T>
void circular_linkedlist<T>::print() {
    if (last != nullptr) {
        Node<T>* first = last->next;
        Node<T>* temp = first;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != first);
    }
}
//======================================================================
template <typename t>
void circular_linkedlist<t>::removeAtHead() {
    if (last == nullptr) {
        cout << "empty list" << endl;
        return;
    }
    if (last->next == last) {
        delete last;
        last = nullptr;
        return;
    }
    Node<t> *temp = last->next;
    last->next = temp->next;
    delete temp;
}
//======================================================================
template <typename t>
void circular_linkedlist<t>::removeAtTail() {//jm
    if (last == nullptr) {
        cout << "Empty list" << endl;
        return;
    }
    if (last->next == last) {
        delete last;
        last = nullptr;
        return;
    }
    Node<t> *current = last->next;
    while (current->next != last) {
        current = current->next;
    }
    current->next = last->next;
    delete last;
    last = current;
}
//======================================================================
template <typename t>
void circular_linkedlist<t>::removeAt(t index) {
    if (last == nullptr) {
        cout << "empty list" << endl;
        return;
    }
    int listSize = linkedListSize()-1;
    if (index < 0 || index > listSize) {
        cout << "Index biger than lenth" << endl;
        return;
    }
    if (index == 0) {
        removeAtHead();
        return;
    } else if(listSize == index){
        removeAtTail();
        return;
    }
    Node<t> *current = last->next;
    for (int i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    Node<t> *temp = current->next;
    current->next = temp->next;
    delete temp;
}
//======================================================================
template <typename t>
void circular_linkedlist<t>::retrieveAt (t index){
    int num = 0; //++ to eqaul index
    Node<t> *temp = last->next;
    int cnt = linkedListSize()-1;
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
void circular_linkedlist<t>::replaceAt (t newElement, int index){
    int num = 0; //++ to eqaul index
    Node<t> *temp = last->next;
    int cnt = linkedListSize()-1;
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
bool circular_linkedlist<t>::isExist(t item){
    if (last == NULL)
        return false;
    Node<t> *temp = last;
    do {
        if (temp->data == item)
            return true;
        temp = temp->next;
    } while (temp != last);
    return false;
}
//======================================================================
template <typename t>
bool circular_linkedlist<t>::isItemAtEqual (t element, int index) {
    int num = 0; //++ to eqaul index
    Node<t> *temp = last->next;
    int cnt = linkedListSize()-1;
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
void circular_linkedlist<t>::swap (int index1, int index2){
    if (index1 > index2)
        swap(index1,index2);
    int num = 0; //++ to eqaul index
    Node<t> *temp1 = last->next;
    Node<t> *temp2 = last->next;
    int cnt = linkedListSize();
    if (cnt < index2){
        cout<<"index2 bigger than linkedlist lenth";
        return ;
    }
    while (num != index1-1){
        num++;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (num != index2-1){
        num++;
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    //shift
    temp1 = temp1->next;
    temp2 = temp2->next;
    //swap
    Node<t> *temp1_next = temp1->next;
    temp1->next = temp2->next;
    temp2->next = temp1_next;
}
//======================================================================
template <typename t>
bool circular_linkedlist<t>::isempty(){
    return (last == NULL);
}
//======================================================================
template <typename t>
int circular_linkedlist<t>::linkedListSize() {
    int counter = 0;
    Node<t> *temp = last->next;
    while (temp != last){
        counter++;
        temp = temp->next;
    }
    counter++;
    return counter;
};
//======================================================================
template <typename t>
void circular_linkedlist<t>::clear (){
    if (last == nullptr)
        return;
    Node<t> *current = last->next;
    while (current != last) {
        Node<t> *temp = current;
        current = current->next;
        delete temp;
    }
    delete last;
    last = nullptr;
}
//======================================================================
