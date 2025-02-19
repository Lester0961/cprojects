

```markdown
# Data Structures and Algorithms in C++

This repository contains C++ implementations of several fundamental data structures and algorithms. Each implementation includes a user-friendly menu for easy interaction.

## Contents

1. **Heaps:**
   - `max.cpp`: Implementation of a Max Heap.
   - `min.cpp`: Implementation of a Min Heap.

2. **Linear Structures:**
   - `queue.cpp`: Implementation of a Queue.
   - `stack.cpp`: Implementation of a Stack.

3. **Graphs:**
   - `graph.cpp`: Implementation of an undirected Graph (adjacency list).
   - `bfs.cpp`: Breadth-First Search (BFS) algorithm on a graph.

4. **Trees:**
   - `bst.cpp`: Implementation of a Binary Search Tree (BST).

5. **Priority Queue:**
   - `priority.cpp`: Implementation of a Priority Queue.

## Code Explanations

### Heaps (`max.cpp`, `min.cpp`)

Both Max Heap and Min Heap are built using the `std::priority_queue` container.

- **`max.cpp`**: To simulate a Max Heap, we store *negated* values. The largest original value becomes the smallest negated value, thus staying at the top of the priority queue.
  ```cpp
  #include <queue>      // Include for priority_queue
  #include <functional> // Include for std::greater (used to create a min-heap which we then use to simulate the max-heap)

  std::priority_queue<int, std::vector<int>, std::greater<int>> maxheap; 
  // Declares a priority queue of integers named 'maxheap'. 
  // It uses a vector<int> as the underlying container. 
  // std::greater<int> is a comparator that makes the priority queue behave like a min-heap. 
  // This is how we will simulate the max-heap: by storing negated values. 

  maxheap.push(-value); // Negate the value before adding it.

  int removed = -maxheap.top(); // Retrieve the top element (which is negated), and negate it again to get the actual max value.
  ```

- **`min.cpp`**: A standard Min Heap implementation.
  ```cpp
  std::priority_queue<int> min_heap; // A standard min-heap (priority queue is a max-heap by default)
  min_heap.push(value); // Add the value directly.
  ```

### Linear Structures (`queue.cpp`, `stack.cpp`)

- **`queue.cpp`**: Implemented using `std::list` for efficient insertion and deletion at both ends.
  ```cpp
  #include <list> // Include for std::list (doubly linked list)

  std::list<int> queue; // A queue implemented using a doubly linked list.

  queue.push_back(value);   // Add to the rear.
  queue.pop_front();      // Remove from the front.
  ```

- **`stack.cpp`**: Also implemented using `std::list`, but we only operate on one end.
  ```cpp
  stack.push_front(value); // Add to the front.
  stack.pop_front();    // Remove from the front.
  ```

### Graphs (`graph.cpp`, `bfs.cpp`)

- **`graph.cpp`**: Represents an undirected graph using an adjacency list.
  ```cpp
  #include <unordered_map> // Include for std::unordered_map (hash table)
  #include <vector>      // Include for std::vector (dynamic array)

  std::unordered_map<int, std::vector<int>> adjList; 
  // An adjacency list implemented using an unordered map. 
  // For each node (key), we store a vector of its neighbors.

  adjList[u].push_back(v); // Add an edge between u and v (undirected).
  adjList[v].push_back(u); // Add an edge between v and u (undirected).
  ```

- **`bfs.cpp`**: Performs Breadth-First Search on a graph.
  ```cpp
  #include <queue>          // Include for std::queue (FIFO queue)
  #include <unordered_set>  // Include for std::unordered_set (hash set)

  std::queue<int> q;         // The queue for BFS.
  std::unordered_set<int> visited; // To keep track of visited nodes.

  q.push(start);         // Start with the starting node.
  visited.insert(start);    // Mark it as visited.

  while (!q.empty()) {
      int node = q.front();   // Get the next node.
      // ... (process node) ...
      for (int neighbor : graph[node]) {
          if (visited.find(neighbor) == visited.end()) { // If neighbor is not visited
              visited.insert(neighbor); // Mark as visited.
              q.push(neighbor);    // Add to the queue.
          }
      }
  }
  ```

### Trees (`bst.cpp`)

- **`bst.cpp`**: Implements a Binary Search Tree.
  ```cpp
  struct Node {
      int key;
      Node* left;
      Node* right;
  };

  Node* insertRec(Node* root, int key) {
      if (root == nullptr) {
          return new Node(key); // Create a new node if the tree is empty.
      }
      if (key < root->key) {
          root->left = insertRec(root->left, key); // Insert in the left subtree.
      } else if (key > root->key) {
          root->right = insertRec(root->right, key); // Insert in the right subtree.
      }
      return root;
  }

  void inorderRec(Node* root) {
      if (root != nullptr) {
          inorderRec(root->left);  // Traverse left subtree.
          std::cout << root->key << " "; // Process current node.
          inorderRec(root->right); // Traverse right subtree.
      }
  }
  ```

### Priority Queue (`priority.cpp`)

- **`priority.cpp`**: Implements a Priority Queue using `std::priority_queue`.
  ```cpp
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
  // A priority queue of pairs (priority, value).
  // It uses a vector of pairs as the underlying container.
  // std::greater is used to make it a min-heap (so that the element with the smallest priority is at the top).

  pq.push({priority, value}); // Add an element with its priority.
  ```

## Build and Run

To compile and run the code:

1.  **Compile:**
    ```bash
    g++ max.cpp -o max
    g++ min.cpp -o min
    g++ queue.cpp -o queue 
    g++ stack.cpp -o stack
    g++ graph.cpp -o graph
    g++ bfs.cpp -o bfs
    g++ bst.cpp -o bst
    g++ priority.cpp -o priority
    ```

2.  **Run:**
    ```bash
    ./max    # Run the Max Heap program
    ./min    # Run the Min Heap program
    ./queue  # Run the Queue program
    ./stack  # Run the Stack program
    ./graph  # Run the Graph program
    ./bfs    # Run the BFS program
    ./bst    # Run the BST program
    ./priority # Run the Priority Queue program
    ```

