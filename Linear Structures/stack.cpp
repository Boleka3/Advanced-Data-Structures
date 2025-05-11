#include<bits/stdc++.h>
typedef long long ll;
#define speedy iostream::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define file ::freopen("#######.in","r",stdin);
using namespace std;

                        /*  don't cheat codes But if You do  */
                                /* Better Call Saul */



template <typename T>

class linked_Stack {
private:
    int size {0};
    
    struct Node {
        T data { };
        Node* next { };
        Node(T data) :data(data) {}
    };

    Node *head { };	// Aka Top Element

public:

    ~linked_Stack() {
        while (!isEmpty()){
            pop();}
    }

    void push(T element) {
        Node* item = new Node(element);
        item->next = head;
        head = item;
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

    T pop() {
        assert(!isEmpty());
        T element = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return element;
    }

    T top() {
        assert(!isEmpty());
        T element = head->data;
        return element;
    }

    int stackSize(){
        return size;
    }

    void clear(){
        while (!isEmpty()){
            pop();}
    }
};

int main() {

    linked_Stack <int>st;
    linked_Stack <char>stk;
    for (int i = 0; i < 5; ++i){
        st.push(i);
    }
    st.print();

    cout<<st.stackSize()<<"\n"<<st.isEmpty()<<"\n"<<st.top()<<"\n";
    cout<<"Top Element Removed: "<<st.pop()<<"\n";
    st.print();
    cout<<st.stackSize()<<"\n"<<st.isEmpty()<<"\n"<<st.top()<<"\n";
    cout<<"\n===========================================================\n\n";
    stk.push('A');
    stk.push('B');
    stk.push('C');
    stk.push('D');
    stk.push('E');
    stk.print();
    cout<<stk.stackSize()<<"\n"<<stk.isEmpty()<<"\n"<<stk.top()<<"\n";
    cout<<"Top Element Removed: "<<stk.pop()<<"\n";
    stk.print();
    cout<<stk.stackSize()<<"\n"<<stk.isEmpty()<<"\n"<<stk.top()<<"\n";
    cout<<"\n===========================NoRTE===========================\n";
    return 0;
}

//prevent closing .exe
//system("PAUSE");

