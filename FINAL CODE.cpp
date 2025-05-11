#include<bits/stdc++.h>
#include"Heaps.cpp"
#include"AVL Trees.cpp"
#include"Product.cpp"
#include"binarysearch.cpp"
using namespace std;

void bst();
void avl();
void heap(bool isMaxHeap);
void displayMenu();
bool frstdisplayMenu();

int main() {
    cout<<"Welcome to super marco\nchoose your data structure(:"<<endl;
    int sort;
    cout << "1. BST" << endl;
    cout << "2. AVL" << endl;
    cout << "3. Heap" << endl;
    cin>>sort;
    switch (sort)
    {
    case 1:
        bst();
        break;
    case 2: 
        avl();
        break;  
    case 3:
        int choice;
    do {
        cout << "\nMain Menu:\n";
        cout << "1. Use Max Heap\n";
        cout << "2. Use Min Heap\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                heap(true);
                break;
            case 2:
                heap(false);
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
        break;
    default:
        cout<<"invalid input\n";
        break;
    }
    return 0;
}

bool frstdisplayMenu() {
    int choice;
    bool manualInput = false;
    string filename;
    cout << "Do you want to input items manually or from a text file?\n1-for manual\n2-for text file:\n";
    cin >> choice;
    return  choice == 2;
}
void displayMenu(){
    cout << "\nMenu:" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. Add item" << endl;
    cout << "2. Remove item" << endl;
    cout << "3. Display all items" << endl;
    cout << "4. Display items sorted by name ascending" << endl;
    cout << "5. Display items sorted by name descending" << endl;
    cout << "6. Display items sorted by price ascending" << endl;
    cout << "7. Display items sorted by price descending" << endl;
    cout << "0. Exit" << endl;
    cout << "----------------------------------------" << endl;
}

void heap(bool isMaxHeap) {
    bool valid = frstdisplayMenu();
    Heap heap(isMaxHeap);
    if (valid) {
        string filename;
        cout << "Enter the filename: ";
        cin >> filename;
        filename += ".txt";
        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "Error opening file." << endl;
            return;
        }
        string name, category;
        int price;
        int n;
        inputFile >> n;
        while (n--) {
            inputFile.ignore();
            getline(inputFile, name);
            inputFile >> category >> price;
            Product item(name, category, price);
            heap.insert(item);
        }
    }
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        string name,kind;
        int price;
        switch (choice) {
            case 1:
                cout<<"put name : ";
                cin.ignore();
                getline(cin,name);
                cout<<"put kind : ";
                cin>>kind;
                cout<<"put price : ";
                cin>>price;
                heap.insert(Product(name,kind,price));
                break;
            case 2:
                heap.remove();
                break;
            case 3:
                heap.Normally_display();
                break;
            case 4:
                heap.sortByName(true);
                break;
            case 5:
                heap.sortByName(false);
                break;
            case 6:
                heap.sortByPrice(true);
                break;
            case 7:
                heap.sortByPrice(false);
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }while (choice);
    

}

void avl() {
    bool valid = frstdisplayMenu();
    AVLTree Tree;
    if (valid) {
        string filename;
        cout << "Enter the filename: ";
        cin >> filename;
        filename += ".txt";
        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "Error opening file." << endl;
            return;
        }
        string name, category;
        int price;
        int n;
        inputFile >> n;
        while (n--) {
            inputFile.ignore();
            getline(inputFile, name);
            inputFile >> category >> price;
            Product item(name, category, price);
            Tree.addProduct(item);
        }
    }
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string name,kind;
                int price;
                cout<<"put name : ";
                cin.ignore();
                getline(cin,name);
                cout<<"put kind : ";
                cin>>kind;
                cout<<"put price : ";
                cin>>price;
                Product item(name,kind,price);
                Tree.addProduct(item);
                break;
            }
            case 2: {
                string name, category;
                int price;
                cout<<"\ninput item's name you want to remove: ";
                cin.ignore();
                getline(cin,name);
                cout<<"put item's category you want to remove: ";
                cin>>category;
                cout<<"put item's price you want to remove: ";
                cin>>price;
                Product item(name, category, price);
                Tree.removeProduct(item);
                break;
            }
            case 3: {
                Tree.displayNormal();
                break;
            }
            case 4: {
                Tree.displayByNameAscending();
                break;
            }
            case 5: {
                Tree.displayByNameDescending();
                break;
            }
            case 6: {
                Tree.displayByPriceAscending();
                break;
            }
            case 7: {
                Tree.displayByPriceDescending();
                break;
            }
            case 0:
                cout << "closing menu" << endl;
                break;
            default:
                cout << "wrong choice please choose from the menu" << endl;
        }
    } while (choice != 0);
}

void bst() {
    bool valid = frstdisplayMenu();
    binarysearch list;
    binarysearch listp;
    if (valid) {
        string filename;
        cout << "Enter the filename: ";
        cin >> filename;
        filename += ".txt";
        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "Error opening file." << endl;
            return;
        }
        string name, category;
        int price;
        int n;
        inputFile >> n;
        while (n--) {
            inputFile.ignore();
            getline(inputFile, name);
            inputFile >> category >> price;
            Product item(name, category, price);
            list.insert(item);
            listp.insert_pri(item);
        }
        inputFile.close();
    }
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string name,kind;
                int price;
                cout<<"put name : ";
                cin.ignore();
                getline(cin,name);
                cout<<"put kind : ";
                cin>>kind;
                cout<<"put price : ";
                cin>>price;
                Product item(name,kind,price);
                list.insert(item);
                listp.insert_pri(item);
                break;
            }
            case 2: {
                string name, category;
                int price;
                cout<<"\ninput item's name you want to remove: ";
                cin.ignore();
                getline(cin,name);
                cout<<"put item's category you want to remove: ";
                cin>>category;
                cout<<"put item's price you want to remove: ";
                cin>>price;
                Product item(name, category, price);
                list.remove(item);
                listp.remove_pri(item);
                break;
            }
            case 3: {
                list.printNormally();
                break;
            }
            case 4: {
                list.print();
                break;
            }
            case 5: {
                list.printfl();
                break;
            }
            case 6: {
                listp.print_pri();
                break;
            }
            case 7: {
                listp.printfl_pri();
                break;
            }
            case 0:
                cout << "closing menu" << endl;
                break;
            default:
                cout << "wrong choice please choose from the menu" << endl;
        }
    } while (choice != 0);
}
