#include<bits/stdc++.h>
typedef long long ll;
#define speedy iostream::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define file ::freopen("#######.in","r",stdin);
using namespace std;

                        /*  don't cheat codes But if You do  */
                                /* Better Call Saul */



template <typename T>

class Queue {
private:
    int size {0};

    struct Node {
        T data { };
        Node* next { };
        Node(T data) :data(data) {}
    };

    Node *head { };	// Aka First Element
    Node *tail { };	// Aka Last Element

public:

    ~Queue() {
        while (!isEmpty()){
            dequeue();}
    }

    void enqueue(T element) {
        Node* item = new Node(element);
        if (!head){
            head = tail = item;}
        else{
            tail->next = item, tail = item;}
        size++;
    }

    bool isEmpty() {
        return !head;
    }

    void print() {
        for (Node* curNode = head; curNode; curNode = curNode->next){
            cout << curNode->data << " ";}
        cout << "\n";
    }

    T dequeue() {
        assert(!isEmpty());
        T element = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return element;
    }

    T first() {
        assert(!isEmpty());
        T element = head->data;
        return element;
    }

    int queueSize(){
        return size;
    }

    void clear(){
        while (!isEmpty()){
            dequeue();}
    }
};

int main() {

    Queue <int>queue1;
    Queue <char>queue2;
    for (int i = 0; i < 5; ++i){
        queue1.enqueue(i);
    }
    queue1.print();

    cout<<queue1.queueSize()<<"\n"<<queue1.isEmpty()<<"\n"<<queue1.first()<<"\n";
    cout<<"first Element Removed: "<<queue1.dequeue()<<"\n";
    queue1.print();
    cout<<queue1.queueSize()<<"\n"<<queue1.isEmpty()<<"\n"<<queue1.first()<<"\n";
    cout<<"\n===========================================================\n\n";
    queue2.enqueue('A');
    queue2.enqueue('B');
    queue2.enqueue('C');
    queue2.enqueue('D');
    queue2.enqueue('E');
    queue2.print();
    cout<<queue2.queueSize()<<"\n"<<queue2.isEmpty()<<"\n"<<queue2.first()<<"\n";
    cout<<"first Element Removed: "<<queue2.dequeue()<<"\n";
    queue2.print();
    cout<<queue2.queueSize()<<"\n"<<queue2.isEmpty()<<"\n"<<queue2.first()<<"\n";
    cout<<"\n===========================NoRTE===========================\n";
    return 0;
}

//prevent closing .exe
//system("PAUSE");

