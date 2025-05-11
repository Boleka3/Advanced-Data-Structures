#include "binarysearch.h"
#include<algorithm>
using namespace std;
binarysearch::binarysearch() {
    root = nullptr;
}
//=================================================
bool binarysearch::isEmpty() {
    return root == nullptr;
}
//=================================================
void binarysearch::insert(Product item) {
    chronological.push_back(item);
    node* p = root, *prev = nullptr;
    while (p != nullptr){
        prev = p;
        if (p->item < item)
            p = p->right;
        else
            p = p->left;
    }
    if (root == nullptr)
        root = new node(item);
    else if (prev->item < item)
        prev->right = new node(item);
    else
        prev->left = new node(item);
}
void binarysearch::insert_pri(Product item) {
    chronological.push_back(item);
    node* p = root, *prev = nullptr;
    while (p != nullptr){
        prev = p;
        if (p->item.getPrice() < item.getPrice())
            p = p->right;
        else
            p = p->left;
    }
    if (root == nullptr)
        root = new node(item);
    else if (prev->item.getPrice() < item.getPrice())
        prev->right = new node(item);
    else
        prev->left = new node(item);
}
//=================================================

void binarysearch::remove(Product item) {
    auto it = find(chronological.begin(), chronological.end(), item);
    if(it != chronological.end()){
        chronological.erase(it);
    }
    if (root == nullptr)
        return;
    node* currentNode = root;
    node* parent = nullptr;
    if (search(item) == 0)
        return;
    while (currentNode != nullptr && currentNode->item != item) {
        parent = currentNode;
        if (item < currentNode->item)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;
    }

    // Case 1 dont have children
    if (currentNode->left == nullptr && currentNode->right == nullptr) {
        if (currentNode != root) {
            if (parent->left == currentNode)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        } else {
            root = nullptr;
        }
        delete currentNode;
    }
        // Case 2 have one children
    else if (currentNode->left == nullptr || currentNode->right == nullptr) {
        node* child = (currentNode->left != nullptr) ? currentNode->left : currentNode->right;
        if (currentNode != root) {
            if (parent->left == currentNode)
                parent->left = child;
            else
                parent->right = child;
        } else {
            root = child;
        }
        delete currentNode;
    }
        // Case 3 have two children
    else {
        node* successor = currentNode->right;
        parent = nullptr;
        // find minim
        while (successor->left != nullptr) {
            parent = successor;
            successor = successor->left;
        }

        // Copy minim data to the current node
        currentNode->item = successor->item;

        // Remove minim
        if (parent != nullptr)
            parent->left = successor->right;
        else
            currentNode->right = successor->right;

        delete successor;
    }
}
void binarysearch::remove_pri(Product item) {
    if (root == nullptr)
        return;
    node* currentNode = root;
    node* parent = nullptr;
    if (search(item) == 0)
        return;
    while (currentNode != nullptr && currentNode->item.getPrice() != item.getPrice()) {
        parent = currentNode;
        if (item < currentNode->item)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;
    }

    // Case 1 dont have children
    if (currentNode->left == nullptr && currentNode->right == nullptr) {
        if (currentNode != root) {
            if (parent->left == currentNode)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        } else {
            root = nullptr;
        }
        delete currentNode;
    }
        // Case 2 have one children
    else if (currentNode->left == nullptr || currentNode->right == nullptr) {
        node* child = (currentNode->left != nullptr) ? currentNode->left : currentNode->right;
        if (currentNode != root) {
            if (parent->left == currentNode)
                parent->left = child;
            else
                parent->right = child;
        } else {
            root = child;
        }
        delete currentNode;
    }
        // Case 3 have two children
    else {
        node* successor = currentNode->right;
        parent = nullptr;
        // find minim
        while (successor->left != nullptr) {
            parent = successor;
            successor = successor->left;
        }

        // Copy minim data to the current node
        currentNode->item = successor->item;

        // Remove minim
        if (parent != nullptr)
            parent->left = successor->right;
        else
            currentNode->right = successor->right;

        delete successor;
    }
}
//=================================================
void binarysearch::printNormally() {
    for(auto i : chronological){
        cout<<i;
    }
}

//=================================================

void binarysearch::print() {
    printInOrder(root);
}
//=================================================

void binarysearch::printInOrder(node *currentNode) {
    if (currentNode != nullptr) {
        printInOrder(currentNode->left);
        cout <<"item : "<<currentNode->item;
        printInOrder(currentNode->right);
    }
}
//=================================================

void binarysearch::printfl() {
    printInOrderfl(root);
}
//=================================================

void binarysearch::printInOrderfl(node *currentNode) {
    if (currentNode != nullptr) {
        printInOrderfl(currentNode->right);
        cout <<"item : "<<currentNode->item;
        printInOrderfl(currentNode->left);
    }
}
//=================================================

void binarysearch::print_pri() {
    printInOrder_pri(root);
}
//=================================================

void binarysearch::printInOrder_pri(node *currentNode) {
    if (currentNode != nullptr) {
        printInOrder_pri(currentNode->left);
        cout <<"price : "<<currentNode->item;
        printInOrder_pri(currentNode->right);
    }
}
//=================================================

void binarysearch::printfl_pri() {
    printInOrderfl_pri(root);
}
//=================================================

void binarysearch::printInOrderfl_pri(node *currentNode) {
    if (currentNode != nullptr) {
        printInOrderfl_pri(currentNode->right);
        cout <<"price : "<<currentNode->item;
        printInOrderfl_pri(currentNode->left);
    }
}
//=================================================

bool binarysearch::search(Product item) {
    node *p = root;
    while (p != nullptr) {
        if (item.getName() == p->item.getName())
            return 1;
        else if (item < p->item)
            p = p->left;
        else
            p = p->right;
    }
    return 0;
}
bool binarysearch::search_pri(Product item) {
    node *p = root;
    while (p != nullptr) {
        if (item.getPrice() == p->item.getPrice())
            return 1;
        else if (item.getPrice() < p->item.getPrice())
            p = p->left;
        else
            p = p->right;
    }
    return 0;
}

