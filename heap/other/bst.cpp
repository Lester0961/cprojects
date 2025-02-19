#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int item) : key(item), left(nullptr), right(nullptr) {}
};

class Binary_search_tree {
public:
    Node* root;

    Binary_search_tree() : root(nullptr) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

private:
    Node* insertRec(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }

        if (key < root->key) {
            root->left = insertRec(root->left, key);
        } else if (key > root->key) {
            root->right = insertRec(root->right, key);
        }
        return root;
    }

public:
    void inorder() {
        inorderRec(root);
        std::cout << std::endl;
    }

private:
    void inorderRec(Node* root) {
        if (root != nullptr) {
            inorderRec(root->left);
            std::cout << root->key << " ";
            inorderRec(root->right);
        }
    }

    ~Binary_search_tree() {
        destroyTree(root);
    }

private:
    void destroyTree(Node* node) {
        if (node == nullptr) return;

        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
};

int main() {
    Binary_search_tree bst;
    bst.insert(30);
    bst.insert(32);
    bst.insert(25);
    bst.insert(40);
    bst.insert(10);
    bst.inorder();

    return 0;
}