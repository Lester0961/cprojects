#include <iostream>
#include <vector>
#include <unordered_map>

class Graphs {
private:
    std::unordered_map<int, std::vector<int>> adjList;

public:
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    void display() {
        for (const auto& pair : adjList) { 
            int node = pair.first;
            std::cout << node << "->";
            for (int neighbor : pair.second) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graphs graphs;
    graphs.addEdge(1, 2);
    graphs.addEdge(1, 3);
    graphs.addEdge(2, 4);
    graphs.addEdge(4, 5);
    graphs.display();

    return 0;
}