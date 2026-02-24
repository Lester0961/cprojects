# 📚 C++ Data Structures & Algorithms

A collection of core data structure and algorithm implementations written in C++. This repo covers everything from linked lists to graph traversal — clean, beginner-friendly, and ready to compile.

---

## 📁 Project Structure

```
cprojects/
├── heap/
│   ├── max.cpp          # Max Heap implementation
│   ├── min.cpp          # Min Heap implementation
│   └── other/
│       ├── bfs.cpp      # Breadth-First Search
│       ├── bst.cpp      # Binary Search Tree
│       ├── graph.cpp    # Graph (Adjacency List)
│       ├── priority.cpp # Priority Queue
│       ├── queue.cpp    # Queue
│       └── stack.cpp    # Stack
├── linkedlist/
│   ├── circular.cpp     # Circular Linked List
│   ├── doubly.cpp       # Doubly Linked List
│   └── singly.cpp       # Singly Linked List
├── asciinema            # Terminal demo recording
└── README.md
```

---

## 🧩 Implementations

### 🔗 Linked Lists (`linkedlist/`)

| File | Description |
|------|-------------|
| `singly.cpp` | Insert at beginning, end, or position; search; display |
| `doubly.cpp` | Bidirectional traversal; insert/delete by value or position |
| `circular.cpp` | Circular structure; insert at beginning or end; safe destructor |

### 🌲 Trees & Heaps (`heap/`)

| File | Description |
|------|-------------|
| `bst.cpp` | Binary Search Tree with recursive insert and inorder traversal |
| `max.cpp` | Max Heap — always removes the largest element first |
| `min.cpp` | Min Heap — always removes the smallest element first |

### 📊 Graphs & Traversal (`heap/other/`)

| File | Description |
|------|-------------|
| `graph.cpp` | Undirected graph using an adjacency list |
| `bfs.cpp` | Breadth-First Search from a starting node |

### 🗂️ Abstract Data Types (`heap/other/`)

| File | Description |
|------|-------------|
| `stack.cpp` | LIFO stack with push, pop, and display |
| `queue.cpp` | FIFO queue with enqueue, dequeue, and display |
| `priority.cpp` | Priority queue — lower priority number = processed first |

---

## ▶️ Getting Started

### Prerequisites

- A C++ compiler (g++, clang++, or MSVC)
- C++11 or later

### Compile & Run

```bash
# Example: compile and run the singly linked list
g++ -std=c++11 linkedlist/singly.cpp -o singly
./singly
```

```bash
# Example: compile and run BFS
g++ -std=c++11 heap/other/bfs.cpp -o bfs
./bfs
```

---


## 📖 Concepts Covered

- **Singly Linked List** — Sequential node traversal, O(n) insertion at position
- **Doubly Linked List** — Forward and backward traversal with `prev` pointers
- **Circular Linked List** — Tail points back to head; careful destructor to avoid infinite loops
- **Binary Search Tree** — Left < root < right invariant; recursive insert and inorder traversal
- **Max / Min Heap** — Priority-based structures using `std::priority_queue` under the hood
- **Graph** — Undirected adjacency list using `std::unordered_map`
- **BFS** — Level-order graph traversal using a queue and visited set
- **Stack** — LIFO using `std::list`
- **Queue** — FIFO using `std::list`
- **Priority Queue** — Min-priority ordering with interactive menu

---

## 👤 Author

**Lester** — [github.com/Lester0961](https://github.com/Lester0961)
