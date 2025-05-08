#include <iostream>
#include <string>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int value;
    Color nodeColor;
    Node *leftChild, *rightChild, *parent;

    Node(int value) : value(value), nodeColor(RED), leftChild(nullptr), rightChild(nullptr), parent(nullptr) {}
};

class RedBlackTree {
    Node *root;

    void rotateLeft(Node *&root, Node *&currentNode) {
        Node *newParent = currentNode->rightChild;
        currentNode->rightChild = newParent->leftChild;
        if (newParent->leftChild) newParent->leftChild->parent = currentNode;
        newParent->parent = currentNode->parent;
        if (!currentNode->parent) root = newParent;
        else if (currentNode == currentNode->parent->leftChild) currentNode->parent->leftChild = newParent;
        else currentNode->parent->rightChild = newParent;
        newParent->leftChild = currentNode;
        currentNode->parent = newParent;
    }

    void rotateRight(Node *&root, Node *&currentNode) {
        Node *newParent = currentNode->leftChild;
        currentNode->leftChild = newParent->rightChild;
        if (newParent->rightChild) newParent->rightChild->parent = currentNode;
        newParent->parent = currentNode->parent;
        if (!currentNode->parent) root = newParent;
        else if (currentNode == currentNode->parent->rightChild) currentNode->parent->rightChild = newParent;
        else currentNode->parent->leftChild = newParent;
        newParent->rightChild = currentNode;
        currentNode->parent = newParent;
    }

    void fixInsert(Node *&root, Node *&node) {
        while (node->parent && node->parent->nodeColor == RED) {
            Node *nodeParent = node->parent, *nodeGrandParent = nodeParent->parent;
            if (nodeParent == nodeGrandParent->leftChild) {
                Node *nodeUncle = nodeGrandParent->rightChild;
                if (nodeUncle && nodeUncle->nodeColor == RED) {
                    nodeGrandParent->nodeColor = RED;
                    nodeParent->nodeColor = nodeUncle->nodeColor = BLACK;
                    node = nodeGrandParent;
                } else {
                    if (node == nodeParent->rightChild) {
                        rotateLeft(root, nodeParent);
                        node = nodeParent;
                        nodeParent = node->parent;
                    }
                    rotateRight(root, nodeGrandParent);
                    swap(nodeParent->nodeColor, nodeGrandParent->nodeColor);
                    node = nodeParent;
                }
            } else {
                Node *nodeUncle = nodeGrandParent->leftChild;
                if (nodeUncle && nodeUncle->nodeColor == RED) {
                    nodeGrandParent->nodeColor = RED;
                    nodeParent->nodeColor = nodeUncle->nodeColor = BLACK;
                    node = nodeGrandParent;
                } else {
                    if (node == nodeParent->leftChild) {
                        rotateRight(root, nodeParent);
                        node = nodeParent;
                        nodeParent = node->parent;
                    }
                    rotateLeft(root, nodeGrandParent);
                    swap(nodeParent->nodeColor, nodeGrandParent->nodeColor);
                    node = nodeParent;
                }
            }
        }
        root->nodeColor = BLACK;
    }

    void deleteNode(Node *&root, Node *nodeToDelete) {
        if (!nodeToDelete) return;

        Node *successor = nodeToDelete;
        Node *replacementNode = nullptr;
        Color deletedColor = successor->nodeColor;

        if (!nodeToDelete->leftChild) {
            replacementNode = nodeToDelete->rightChild;
            transplant(root, nodeToDelete, nodeToDelete->rightChild);
        } else if (!nodeToDelete->rightChild) {
            replacementNode = nodeToDelete->leftChild;
            transplant(root, nodeToDelete, nodeToDelete->leftChild);
        } else {
            successor = minValue(nodeToDelete->rightChild);
            deletedColor = successor->nodeColor;
            replacementNode = successor->rightChild;
            if (successor->parent == nodeToDelete) {
                if (replacementNode) replacementNode->parent = successor;
            } else {
                transplant(root, successor, successor->rightChild);
                successor->rightChild = nodeToDelete->rightChild;
                if (successor->rightChild) successor->rightChild->parent = successor;
            }
            transplant(root, nodeToDelete, successor);
            successor->leftChild = nodeToDelete->leftChild;
            if (successor->leftChild) successor->leftChild->parent = successor;
            successor->nodeColor = nodeToDelete->nodeColor;
        }

        delete nodeToDelete;

        if (deletedColor == BLACK) {
            fixDelete(root, replacementNode);
        }
    }

    void fixDelete(Node *&root, Node *&replacementNode) {
        while (replacementNode != root && (!replacementNode || replacementNode->nodeColor == BLACK)) {
            if (replacementNode == replacementNode->parent->leftChild) {
                Node *brotherNode = replacementNode->parent->rightChild;
                if (brotherNode && brotherNode->nodeColor == RED) {
                    brotherNode->nodeColor = BLACK;
                    replacementNode->parent->nodeColor = RED;
                    rotateLeft(root, replacementNode->parent);
                    brotherNode = replacementNode->parent->rightChild;
                }
                if ((!brotherNode || brotherNode->leftChild == nullptr || brotherNode->leftChild->nodeColor == BLACK) &&
                    (!brotherNode || brotherNode->rightChild == nullptr || brotherNode->rightChild->nodeColor == BLACK)) {
                    if (brotherNode) brotherNode->nodeColor = RED;
                    replacementNode = replacementNode->parent;
                } else {
                    if (!brotherNode->rightChild || brotherNode->rightChild->nodeColor == BLACK) {
                        if (brotherNode->leftChild) brotherNode->leftChild->nodeColor = BLACK;
                        if (brotherNode) brotherNode->nodeColor = RED;
                        rotateRight(root, brotherNode);
                        brotherNode = replacementNode->parent->rightChild;
                    }
                    if (brotherNode) brotherNode->nodeColor = replacementNode->parent->nodeColor;
                    replacementNode->parent->nodeColor = BLACK;
                    if (brotherNode->rightChild) brotherNode->rightChild->nodeColor = BLACK;
                    rotateLeft(root, replacementNode->parent);
                    replacementNode = root;
                }
            } else {
                Node *brotherNode = replacementNode->parent->leftChild;
                if (brotherNode && brotherNode->nodeColor == RED) {
                    brotherNode->nodeColor = BLACK;
                    replacementNode->parent->nodeColor = RED;
                    rotateRight(root, replacementNode->parent);
                    brotherNode = replacementNode->parent->leftChild;
                }
                if ((!brotherNode || brotherNode->leftChild == nullptr || brotherNode->leftChild->nodeColor == BLACK) &&
                    (!brotherNode || brotherNode->rightChild == nullptr || brotherNode->rightChild->nodeColor == BLACK)) {
                    if (brotherNode) brotherNode->nodeColor = RED;
                    replacementNode = replacementNode->parent;
                } else {
                    if (!brotherNode->leftChild || brotherNode->leftChild->nodeColor == BLACK) {
                        if (brotherNode->rightChild) brotherNode->rightChild->nodeColor = BLACK;
                        if (brotherNode) brotherNode->nodeColor = RED;
                        rotateLeft(root, brotherNode);
                        brotherNode = replacementNode->parent->leftChild;
                    }
                    if (brotherNode) brotherNode->nodeColor = replacementNode->parent->nodeColor;
                    replacementNode->parent->nodeColor = BLACK;
                    if (brotherNode->leftChild) brotherNode->leftChild->nodeColor = BLACK;
                    rotateRight(root, replacementNode->parent);
                    replacementNode = root;
                }
            }
        }
        if (replacementNode) replacementNode->nodeColor = BLACK;
    }

    Node* minValue(Node *temp) {
        while (temp && temp->leftChild) temp = temp->leftChild;
        return temp;
    }

    void transplant(Node *&root, Node *nodeFrom, Node *nodeTo) {
        if (!nodeFrom->parent) root = nodeTo;
        else if (nodeFrom == nodeFrom->parent->leftChild) nodeFrom->parent->leftChild = nodeTo;
        else nodeFrom->parent->rightChild = nodeTo;
        if (nodeTo) nodeTo->parent = nodeFrom->parent;
    }

    void printTree(Node *node, string space, bool isLeftChild) {
        if (node) {
            cout << space;
            if (isLeftChild) cout << "L----";
            else cout << "R----";
            cout << node->value << " (" << (node->nodeColor == RED ? "red" : "black") << ")" << endl;
            printTree(node->leftChild, space + (isLeftChild ? "|     " : "      "), true);
            printTree(node->rightChild, space + (isLeftChild ? "|     " : "      "), false);
        }
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int value) {
        Node *node = new Node(value), *parent = nullptr, *temp = root;
        while (temp) {
            parent = temp;
            if (value < temp->value) temp = temp->leftChild;
            else temp = temp->rightChild;
        }
        node->parent = parent;
        if (!parent) root = node;
        else if (value < parent->value) parent->leftChild = node;
        else parent->rightChild = node;
        fixInsert(root, node);
    }

    void remove(int value) {
        Node *temp = root;
        while (temp && temp->value != value) {
            temp = (value < temp->value) ? temp->leftChild : temp->rightChild;
        }
        if (temp) deleteNode(root, temp);
    }

    void print() {
        if (root) printTree(root, "", false);
        else cout << "Tree is empty!" << endl;
    }
};

int main() {
    RedBlackTree rbt;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);
    rbt.insert(25);
    rbt.insert(35);
    rbt.insert(5);

    cout << "Insertion:" << endl;
    rbt.print();

    rbt.remove(5);
    cout << "\nDeletion:" << endl;
    rbt.print();

    cout << "\nNwrt ya Gameel ;)" << endl;

    return 0;
}