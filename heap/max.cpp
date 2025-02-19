#include <iostream>
#include <queue>
#include <vector>
#include <functional> 

class Max_Heap {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> maxheap; 
    std::istream& in; 

public:
    Max_Heap(std::istream& input) : in(input) {}

    void add() {
        std::cout << "\nEnter a value: ";
        int value;
        in >> value;
        maxheap.push(-value); 
        std::cout << "\nvalue " << value << " added" << std::endl;
    }

    void remove() {
        if (maxheap.empty()) {
            std::cout << "Empty" << std::endl;
        } else {
            int removed = -maxheap.top(); 
            maxheap.pop();
            std::cout << "\nremoved " << removed << std::endl;
        }
    }

    void display() {
        std::priority_queue<int, std::vector<int>, std::greater<int>> tempHeap = maxheap; 
        std::cout << "\nThe max heap: ";
        while (!tempHeap.empty()) {
            std::cout << -tempHeap.top() << " ";
            tempHeap.pop();
        }
        std::cout << std::endl;
    }

    void run() {
        while (true) {
            std::cout << "\nYour options are:" << std::endl;
            std::cout << "\n1. Add a value \n2. Remove a value \n3. Display \n4. Exit" << std::endl;
            std::cout << "\nchoose: ";
            int choice;
            in >> choice;

            switch (choice) {
            case 1:
                add();
                break;
            case 2:
                remove();
                break;
            case 3:
                display();
                break;
            case 4:
                std::cout << "Exit" << std::endl;
                return;
            default:
                std::cout << "\nInvalid Choice" << std::endl;
            }
        }
    }
};

int main() {
    Max_Heap mp(std::cin); 
    mp.run();

    return 0;
}