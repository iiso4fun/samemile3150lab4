# samemile3150lab4

Linked List Project

A simple C++ project demonstrating a singly linked list with move semantics, copy constructor, and destructor.

Overview

ListNode Structure: Stores one int and a pointer to the next node (pNext).
Copy Constructor: Makes a deep copy of the entire list.
Move Constructor / Move Assignment: Efficiently transfers ownership of the list without copying all elements.
Destructor: Recursively deletes all nodes.
Helper Functions:
create_list(...) to build a list from a std::vector<int>.
display_list(...) to print the list in a friendly format (e.g. 10 -> 20 -> nullptr).
retrieve_value(...) to get a value at a specific (0-based) index.
remove_node(...) to delete a node by index.
clear_list(...) to delete the entire list and reset the pointer to nullptr.
File Structure

linked_list.h
Declarations for the ListNode structure and utility functions.
linked_list.cpp
Definitions for the ListNode’s copy/move constructors, destructor, and utility functions.
linked_list_test.cpp
Test suite using doctest. It checks list operations and move semantics.
doctest.h
The testing framework header (obtained from the doctest project).
How to Compile

Open a terminal in the project directory.
Run:
g++ -std=c++17 -o linkedlist linked_list_test.cpp linked_list.cpp
This produces an executable named linkedlist.
How to Run Tests

Run the executable:
./linkedlist
The tests will run automatically. If successful, they all pass with a summary at the end.
Notes

All indices are 0-based (first node is at index 0).
Move operations help avoid unnecessary copying when dealing with temporary lists.
Make sure you have a C++17-capable compiler.
