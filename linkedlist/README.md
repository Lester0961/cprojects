# Linked List Implementations in C++

This repository contains C++ implementations of three common types of linked lists:

- Singly Linked List (`singly.cpp`)
- Doubly Linked List (`doubly.cpp`)
- Circular Linked List (`circular.cpp`)

## Overview

A linked list is a linear collection of data elements, called nodes, each of which points to the next node in the sequence. Unlike arrays, linked lists do not store elements in contiguous memory locations. This allows for efficient insertion and deletion of elements at any position in the list, but accessing elements by index can be slower.

## Singly Linked List (`singly.cpp`)

A singly linked list is the simplest type of linked list, where each node contains a data element and a pointer to the next node in the sequence. The last node in the list points to `nullptr`.

### Code Explanation

- **`Node` Class:** Represents a node in the list, containing an integer `data` and a pointer `next` to the next node.
- **`singlyLinkedList` Class:** Represents the linked list itself, with a pointer `head` to the first node.
  - **`insertEnd(int data)`:** Inserts a new node with the given data at the end of the list.
  - **`insertBeginning(int data)`:** Inserts a new node with the given data at the beginning of the list.
  - **`insertAt(int data, int position)`:** Inserts a new node with the given data at the specified position in the list.
  - **`search(int key)`:** Searches for a node with the given data in the list and returns `true` if found, `false` otherwise.
  - **`display()`:** Prints the data of each node in the list, separated by "->", followed by "null".
  - **`~singlyLinkedList()`:** Destructor that deallocates all nodes in the list to prevent memory leaks.

### Example Usage

```c++
singlyLinkedList sll;
sll.insertEnd(30);
sll.insertEnd(40);
sll.insertBeginning(10);
sll.insertAt(20, 2);
sll.display(); // Output: 10 -> 20 -> 30 -> 40 -> null
std::cout << std::boolalpha << sll.search(10) << std::endl; // Output: true
```

## Doubly Linked List (`doubly.cpp`)

A doubly linked list is similar to a singly linked list, but each node also contains a pointer to the previous node in the sequence. This allows for efficient traversal of the list in both directions.

### Code Explanation

- **`Node` Class:** Represents a node in the list, containing an integer `data` and pointers `next` and `prev` to the next and previous nodes, respectively.
- **`doublyLinkedlist` Class:** Represents the linked list itself, with a pointer `head` to the first node.
  - **`insertEnd(int data)`:** Inserts a new node with the given data at the end of the list.
  - **`insertBeginning(int data)`:** Inserts a new node with the given data at the beginning of the list.
  - **`insertAt(int data, int position)`:** Inserts a new node with the given data at the specified position in the list.
  - **`deletionByValue(int key)`:** Deletes the first node with the given data from the list.
  - **`search(int key)`:** Searches for a node with the given data in the list and returns `true` if found, `false` otherwise.
  - **`displayForward()`:** Prints the data of each node in the list, starting from the head and moving forward.
  - **`displayBackwards()`:** Prints the data of each node in the list, starting from the tail and moving backward.
  - **`~doublyLinkedlist()`:** Destructor that deallocates all nodes in the list to prevent memory leaks.

### Example Usage

```c++
doublyLinkedlist dll;
dll.insertEnd(50);
dll.insertEnd(40);
dll.insertBeginning(5);
dll.insertAt(30, 2);
dll.displayForward(); // Output: 5 -> 30 -> 50 -> 40 -> null
dll.displayBackwards(); // Output: 40 -> 50 -> 30 -> 5 -> null
dll.deletionByValue(40);
std::cout << std::boolalpha << dll.search(40) << std::endl; // Output: false
```

## Circular Linked List (`circular.cpp`)

A circular linked list is a variation of a singly linked list where the last node in the list points back to the first node, creating a circular structure.

### Code Explanation

- **`Node` Class:** Represents a node in the list, containing an integer `data` and a pointer `next` to the next node.
- **`Circular_LinkedList` Class:** Represents the linked list itself, with a pointer `head` to the first node.
  - **`insertEnd(int data)`:** Inserts a new node with the given data at the end of the list.
  - **`insertBeginning(int data)`:** Inserts a new node with the given data at the beginning of the list.
  - **`display()`:** Prints the data of each node in the list, separated by "->", followed by "head".
  - **`~Circular_LinkedList()`:** Destructor that deallocates all nodes in the list to prevent memory leaks.

### Example Usage

```c++
Circular_LinkedList cll;
cll.insertBeginning(1);
cll.insertEnd(4);
cll.insertEnd(3);
cll.display(); // Output: 1 -> 4 -> 3 -> head
```

## Building and Running the Code

You will need a C++ compiler (such as g++) and a suitable development environment to compile and run the code. 

1. Save the code in a file with a `.cpp` extension (e.g., `singly.cpp`, `doubly.cpp`, `circular.cpp`).
2. Open a terminal or command prompt and navigate to the directory where you saved the file.
3. Compile the code using the following command:

   ```bash
   g++ <filename>.cpp -o <filename>
   ```

   Replace `<filename>` with the name of your file (e.g., `g++ singly.cpp -o singly`).

4. Run the executable using the following command:

   ```bash
   ./<filename>
   ```

   Replace `<filename>` with the name of your file (e.g., `./singly`).

## Memory Management

The code includes destructors (`~singlyLinkedList()`, `~doublyLinkedlist()`, `~Circular_LinkedList()`) to deallocate the memory used by the linked lists when they are no longer needed. This is crucial to prevent memory leaks.

## Further Exploration

- **Time and Space Complexity:** Analyze the time and space complexity of the different operations on each type of linked list.
- **Applications:** Research real-world applications of linked lists in data structures and algorithms.
- **Variations:** Explore other linked list variations, such as skip lists or unrolled linked lists.