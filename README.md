# samemile3150lab4

# samemile3150lab4

## Linked List Project

A simple C++ project demonstrating a singly linked list with **move semantics**, **copy constructor**, and **destructor**.

### Overview

- **ListNode Structure**: Stores a single `int` and a pointer (`pNext`) to the next node.  
- **Copy Constructor**: Creates a deep copy of the entire chain.  
- **Move Constructor / Move Assignment**: Efficiently transfers ownership of the list without copying every node.  
- **Destructor**: Recursively deletes all nodes.  

**Helper Functions**:
- `create_list(...)` — builds a list from a `std::vector<int>`.  
- `display_list(...)` — prints the list like `10 -> 20 -> nullptr`.  
- `retrieve_value(...)` — gets the value at a specific 0-based index.  
- `remove_node(...)` — deletes a node by index.  
- `clear_list(...)` — deletes the entire list and sets the head pointer to `nullptr`.

### File Structure

1. **linked_list.h**  
   Declarations for the `ListNode` structure and utility functions.  
2. **linked_list.cpp**  
   Definitions for the `ListNode`’s copy/move constructors, destructor, and utility functions.  
3. **linked_list_test.cpp**  
   Test suite using the [doctest](https://github.com/doctest/doctest) framework.  
4. **doctest.h**  
   The doctest testing framework header.

### How to Compile

1. Open a terminal in the project directory.  
2. Run:
   ```bash
   g++ -std=c++17 -o linkedlist linked_list_test.cpp linked_list.cpp
