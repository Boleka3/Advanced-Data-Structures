#ifndef CIRCULAR_LINKEDLIST_CIRCULAR_LINKEDLIST_H
#define CIRCULAR_LINKEDLIST_CIRCULAR_LINKEDLIST_H
#include <iostream>
using namespace std;
template <typename t>
class Node{
public:
    t data;
    Node<t> *next;
    Node() : data(NULL),next(NULL){};
    Node(t x) : data(x),next(NULL){};
};
template <typename t>
class circular_linkedlist {
public:
    Node<t>* last;
    circular_linkedlist();
    void insertAtHead(t newvalue);
    void insertAtTail(t newvalue);
    void insertAt(t newvalue, int index);
    void removeAtHead ();
    void removeAtTail ();
    void removeAt (t index);
    void retrieveAt (t index);
    void replaceAt (t newElement, int index);
    bool isExist(t item);
    bool isItemAtEqual (t element, int index);
    void swap (int index1, int index2);
    bool isempty();
    int linkedListSize();
    void clear ();
    void print();
};
#endif
