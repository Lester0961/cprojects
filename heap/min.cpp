#include <iostream>
#include <queue>
#include <vector>
#include <functional> 

class Min_heap {
private:
    std::priority_queue<int> min_heap; 
    std::istream& in; 

public:
    Min_heap(std::istream& input) : in(input) {} 

    void Add() {
        std::cout << "\nEnter a value: ";
        int value;
        in >> value;
        min_heap.push(value);
        std::cout << "\n" << value << " is added\n" << std::endl;
    }

    void remove() {
        if (min_heap.empty()) {
            std::cout << "Empty" << std::endl;
        } else {
            int removed = min_heap.top();
            min_heap.pop();
            std::cout << "\n" << removed << " is removed" << std::endl;
        }
    }

    void display() {
        std::priority_queue<int> tempHeap = min_heap; 
        std::cout << "\nThe min heap: ";
        while (!tempHeap.empty()) {
            std::cout << tempHeap.top() << " ";
            tempHeap.pop();
        }
        std::cout << "\n" << std::endl;
    }

    void run() {
        while (true) {
            std::cout << "Your options are: " << std::endl;
            std::cout << "\n1. Add a value \n2. Remove a value \n3. Display \n4. Exit" << std::endl;
            std::cout << "\nChoose: ";
            int choice;
            in >> choice;

            switch (choice) {
            case 1:
                Add();
                break;
            case 2:
                remove();
                break;
            case 3:
                display();
                break;
            case 4: {
                std::cout << "Exit" << std::endl;
                return;
            }
            default:
                std::cout << "Invalid choice" << std::endl;
            }
        }
    }
};

int main() {
    Min_heap mp(std::cin);
    mp.run();

    return 0;
}