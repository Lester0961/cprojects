#include <iostream>
#include <queue>
#include <vector>
#include <functional> 
#include <algorithm> 

class PriorityQueueClass {
private:
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    std::istream& in; 

public:
    PriorityQueueClass(std::istream& input) : in(input) {} 

    void enqueue() {
        std::cout << "\nEnter a number to queue: ";
        int value;
        in >> value;
        std::cout << "Enter its priority (High = processed first): ";
        int priority;
        in >> priority;

        pq.push({priority, value}); 
        std::cout << "\n" << value << " added to queue" << std::endl;
    }

    void dequeue() {
        if (pq.empty()) {
            std::cout << "\nPriority queue is empty." << std::endl;
        } else {
            std::pair<int, int> removed = pq.top();
            pq.pop();
            std::cout << "\n" << removed.second << " removed from priority queue." << std::endl;
        }
    }

    void display() {
        std::vector<std::pair<int, int>> temp;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq_copy = pq;

        while(!pq_copy.empty()){
            temp.push_back(pq_copy.top());
            pq_copy.pop();
        }

        std::sort(temp.begin(), temp.end(), std::greater<std::pair<int, int>>());

        for (const auto& item : temp) {
            std::cout << item.second << " ";
        }

        std::cout << std::endl;
    }

    void run() {
        while (true) {
            std::cout << "\n1. Add to Queue \n2. Remove from Queue \n3. Display \n4. Exit" << std::endl;
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
                std::cout << "Exiting..." << std::endl;
                return;
            }
            default:
                std::cout << "Invalid choice." << std::endl;
            }
        }
    }
};

int main() {
    PriorityQueueClass pq(std::cin); 
    pq.run();

    return 0;
}