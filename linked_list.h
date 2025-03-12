#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <vector>
#include <stdexcept>

struct ListNode {
    int value;
    ListNode* pNext;

    
    ListNode(int val) : value(val), pNext(nullptr) {}

    
    ListNode(const ListNode& other);

  
    ~ListNode();


    ListNode(ListNode&& other) noexcept;

   
    ListNode& operator=(ListNode&& other) noexcept;
};


ListNode* create_list(const std::vector<int>& values);
void display_list(ListNode* head);
void clear_list(ListNode*& head);
int retrieve_value(ListNode* head, int index);
void remove_node(ListNode*& head, int index);

#endif 