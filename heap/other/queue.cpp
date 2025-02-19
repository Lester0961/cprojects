#include <iostream>
#include <list> 
#include <istream> 

class Queue {
private:
    std::list<int> queue;
    std::istream& in; 
public:
    Queue(std::istream& input) : in(input) {} 

    void enqueue() {
        std::cout << "\nEnter an element to add to the queue: ";
        int value;
        in >> value;
        queue.push_back(value); 
        std::cout << "\n" << value << " added to queue" << std::endl;
    }

    void dequeue() {
        if (queue.empty()) {
            std::cout << "Empty" << std::endl;
        } else {
            int removed = queue.front(); 
            queue.pop_front();          
            std::cout << "\n" << removed << " removed" << std::endl;
        }
    }

    void display() {
        std::cout << "\nThe queue: ";
        for (int element : queue) { 
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    void run() {
        while (true) {
            std::cout << "\n1. Add \n2. Remove \n3. Display \n4. Exit" << std::endl;
            std::cout << "\nChoose an option: ";
            int choice;
            in >> choice;

            switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4: {
                std::cout << "Exit" << std::endl;
                return;
            }
            default:
                std::cout << "\nInvalid Choice." << std::endl;
            }
        }
    }
};

int main() {
    Queue queue(std::cin); 
    queue.run();

    return 0;
}