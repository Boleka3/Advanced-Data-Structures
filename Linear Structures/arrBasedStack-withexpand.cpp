#include<bits/stdc++.h>
#include <algorithm>
typedef long long ll;
#define speedy iostream::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define file ::freopen("#######.in","r",stdin);
using namespace std;

                        /*  don't cheat codes But if You do  */
                                /* Better Call Saul */



template <typename T>
class arr_Based_Stack {

private:
    int capacity{0};
    int size {0};
    int topElement {};
    T* arr {nullptr};
    void expand_capacity() {
        // Double the actual array size
        capacity *= 2;
        cout << "Expand capacity to "
             << capacity << "\n";
        T *arr2 = new T[capacity] { };
        for (int i = 0; i < size; ++i)
            arr2[i] = arr[i];	// copy data
        swap(arr, arr2);
        delete[] arr2;
    }
public:

    arr_Based_Stack(int capacity) : capacity(capacity), topElement(-1) {
        arr = new T[capacity];
    }

    ~arr_Based_Stack() {
        delete[] arr;
        arr = nullptr;
    }

    void push(T element) {
        if (size == capacity)
        {expand_capacity();}
        arr[++topElement] = element;
        size++;
    }

    bool isEmpty() {
        return topElement == -1;
    }

    void print() {
        for (int i = topElement; i >= 0; i--){
            cout << arr[i] << " ";}
        cout << "\n";
    }

    void clear(){
        delete[] arr;
        arr = nullptr;
    }

    T pop() {
        assert(!isEmpty());
        size--;
        return arr[topElement--];
    }

    T top() {
        assert(!isEmpty());
        return arr[topElement];
    }

    int stackSize(){
        return topElement+1;
    }

};

int main() {

    arr_Based_Stack <int>st(5);
    arr_Based_Stack <char>stk(5);
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
    stk.push('F');
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

