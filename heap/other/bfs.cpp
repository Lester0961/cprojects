#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

class BFS {
public:
    std::unordered_map<int, std::vector<int>> graph;

    void addEdge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }

    void bfs(int start) {
        std::queue<int> q;
        std::unordered_set<int> visited;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            std::cout << node << " ";

            for (int neighbor : graph[node]) {
                if (visited.find(neighbor) == visited.end()) { 
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        std::cout << std::endl; 
    }
};

int main() {
    BFS bfs;
    bfs.addEdge(1, 2);
    bfs.addEdge(1, 3);
    bfs.addEdge(2, 4);
    bfs.bfs(3);

    return 0;
}