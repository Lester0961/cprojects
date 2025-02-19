#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class Circular_LinkedList {
public:
    Node* head;

    Circular_LinkedList() : head(nullptr) {}

    void insertEnd(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            head->next = head;
            return;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertBeginning(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    void display() {
        if (head == nullptr) {
            std::cout << "empty." << std::endl;
            return;
        }

        Node* temp = head;
        do {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        std::cout << "head" << std::endl;
    }

    ~Circular_LinkedList() {
        if (head == nullptr) return;

        Node* current = head;
        Node* nextNode;

        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);

        head = nullptr; 
    }
};

int main() {
    Circular_LinkedList cll;

    cll.insertBeginning(1);
    cll.insertEnd(4);
    cll.insertEnd(3);
    cll.display();

    return 0;
}