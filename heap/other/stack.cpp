#include <iostream>
#include <list>
#include <istream>

class Stack {
private:
    std::list<int> stack;
    std::istream& in; 

public:
    Stack(std::istream& input) : in(input) {} 

    void push() {
        std::cout << "\nEnter a number to push: ";
        int value;
        in >> value;
        stack.push_front(value); 
        std::cout << "\n" << value << " added to stack" << std::endl;
    }

    void pop() {
        if (stack.empty()) {
            std::cout << "Empty" << std::endl;
        } else {
            int removed = stack.front(); 
            stack.pop_front();          
            std::cout << "\n" << removed << " removed from stack" << std::endl;
        }
    }

    void display() {
        std::cout << "\n\nThe stack: ";
        for (int element : stack) { 
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    void run() {
        while (true) {
            std::cout << "\n1. push \n2. pop \n3. display \n4. exit" << std::endl;
            std::cout << "\nChoose an option: ";
            int choice;
            in >> choice;

            switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4: {
                std::cout << "Exit" << std::endl;
                return;
            }
            default:
                std::cout << "invalid choice" << std::endl;
            }
        }
    }
};

int main() {
    Stack thestack(std::cin); 
    thestack.run();

    return 0;
}