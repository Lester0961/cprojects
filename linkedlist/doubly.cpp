#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class doublyLinkedlist {
public:
    Node* head;

    doublyLinkedlist() : head(nullptr) {}

    void insertEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAt(int data, int position) {
        Node* newNode = new Node(data);
        if (position == 0) {
            insertBeginning(data);
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) return;
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deletionByValue(int key) {
        if (head == nullptr) return;
        if (head->data == key) {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }
        if (temp == nullptr) return;
        if (temp->next != nullptr) temp->next->prev = temp->prev;
        if (temp->prev != nullptr) temp->prev->next = temp->next;
        delete temp; 
    }

    bool search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "Null" << std::endl;
    }

    void displayBackwards() {
        if (head == nullptr) return;
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->prev;
        }
        std::cout << "Null" << std::endl;
    }

    ~doublyLinkedlist() {
        Node* current = head;
        Node* nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr; 
    }
};

int main() {
    doublyLinkedlist dll;
    dll.insertEnd(50);
    dll.insertEnd(40);
    dll.insertBeginning(5);
    dll.insertAt(30, 2);
    dll.displayForward();
    dll.displayBackwards();
    dll.deletionByValue(40);
    std::cout << std::boolalpha << dll.search(40) << std::endl; 
    return 0;
}