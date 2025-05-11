
#include <iostream>
#include <vector>
#include <algorithm>
#include"Product.h"
using namespace std;

class AVLNode {
public:
    Product item;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(Product item) : item(item), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree{
private:
    AVLNode* root;
    vector<Product> chronological;
    int height(AVLNode* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int balanceFactor(AVLNode* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* temp = x->right;

        x->right = y;
        y->left = temp;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* temp = y->left;

        y->left = x;
        x->right = temp;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    AVLNode* insertNode(AVLNode* node, Product item) {
        chronological.push_back(item);
        if (node == nullptr) return new AVLNode(item);

        if (item < node->item)
            node->left = insertNode(node->left, item);
        else
            node->right = insertNode(node->right, item);

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        if (balance > 1 && item < node->left->item)
            return rightRotate(node);
        if (balance < -1 && item > node->right->item)
            return leftRotate(node);
        if (balance > 1 && item > node->left->item) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && item < node->right->item) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    AVLNode* deleteNode(AVLNode* root, Product key) {
        if (root == nullptr) return root;

        if (key < root->item)
            root->left = deleteNode(root->left, key);
        else if (key > root->item)
            root->right = deleteNode(root->right, key);
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                AVLNode* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;

                delete temp;
            } else {
                AVLNode* temp = minValueNode(root->right);
                root->item = temp->item;
                root->right = deleteNode(root->right, temp->item);
            }
            auto it = find(chronological.begin(), chronological.end(),key);
            if(it != chronological.end()){
                chronological.erase(it);
            }
        }

        if (root == nullptr) return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = balanceFactor(root);

        if (balance > 1 && balanceFactor(root->left) >= 0)
            return rightRotate(root);
        if (balance > 1 && balanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && balanceFactor(root->right) <= 0)
            return leftRotate(root);
        if (balance < -1 && balanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

   void NormalTraversal(AVLNode* root) {
        if (!root) return;
       NormalTraversal(root->right);
       cout << root->item;
       NormalTraversal(root->left);
   }

    void displayByNameAscending(AVLNode* root) {
        if (root == nullptr) return;
        displayByNameAscending(root->left);
        cout << root->item;
        displayByNameAscending(root->right);
    }

    // Function to display items sorted by name descending
    void displayByNameDescending(AVLNode* root) {
        if (root == nullptr) return;
        displayByNameDescending(root->right);
        cout << root->item;
        displayByNameDescending(root->left);
    }
    void collectItemsInOrder(AVLNode* node, vector<Product>& items) {
        if (node == nullptr) return;
        collectItemsInOrder(node->left, items); // Traverse the left subtree
        items.push_back(node->item);            // Visit the node
        collectItemsInOrder(node->right, items); // Traverse the right subtree
    }
    // Function to display items sorted by price ascending
    void displayByPriceAscending(AVLNode* root) {
        if (root == nullptr) return;
        vector<Product> items;
        collectItemsInOrder(root, items);
        sort(items.begin(), items.end(), [](const Product& a, const Product& b) {
            return a.getPrice() < b.getPrice();
        });

        for (const auto& item : items) {
            cout << item ;
        }
    }

    void displayByPriceDescending(AVLNode* root) {
        if (root == nullptr) return;
        vector<Product> items;
        collectItemsInOrder(root, items);
        sort(items.begin(), items.end(), [](const Product& a, const Product& b) {
            return a.getPrice() > b.getPrice();
        });

        for (const auto& item : items) {
            cout << item ;
        }
    }
    
public:
    AVLTree() : root(nullptr) {}

    void addProduct(Product item) {
        root = insertNode(root, item);
    }

    void removeProduct(Product item) {
        root = deleteNode(root, item);
    }

    void displayNormal() {
        chronological.erase(unique(chronological.begin(), chronological.end()), chronological.end());
            for (const auto& item : chronological) {
                cout<<item;
            }
    }

    // Function to display items sorted by name ascending
    void displayByNameAscending() {
        displayByNameAscending(root);
    }
    // Function to display items sorted by name descending
    void displayByNameDescending() {
        displayByNameDescending(root);
    }
    // Function to display items sorted by price ascending
    void displayByPriceAscending() {
        displayByPriceAscending(root);
    }
    // Function to display items sorted by price descending
    void displayByPriceDescending() {
        displayByPriceDescending(root);
    }
};
//
// int main() {
//     AVLTree tree;
//
//     // Add some items
//     tree.addProduct(Product("Apple", "Fruit", 10));
//     tree.addProduct(Product("Carrot", "Vegetable", 3));
//     tree.addProduct(Product("Banana", "Fruit", 2));
//     tree.addProduct(Product("Milk", "Dairy", 4));
//
//     cout << "Products Normal:" << endl;
//     tree.displayNormal();
//
//     cout << "Products sorted by name ascending:" << endl;
//     tree.displayByNameAscending();
//
//     cout << "\nProducts sorted by name descending:" << endl;
//     tree.displayByNameDescending();
//
//     cout << "\nProducts sorted by price ascending:" << endl;
//     tree.displayByPriceAscending();
//
//     cout << "\nProducts sorted by price descending:" << endl;
//     tree.displayByPriceDescending();
//
//     Product ToRemove("Banana", "Fruit", 2);
//     tree.removeProduct(ToRemove);
//
//     cout << "Products Normal:" << endl;
//     tree.displayNormal();
//
//
//     return 0;
//
// }