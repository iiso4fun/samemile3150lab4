#include "linked_list.h"
#include <iostream>
#include <vector>
#include <stdexcept>


ListNode::ListNode(const ListNode& other)
    : value(other.value),
      pNext(other.pNext ? new ListNode(*other.pNext) : nullptr)
{ }


ListNode::~ListNode() {
    delete pNext;
}


ListNode::ListNode(ListNode&& other) noexcept
    : value(other.value),
      pNext(other.pNext)
{
    other.pNext = nullptr; 
}


ListNode& ListNode::operator=(ListNode&& other) noexcept {
    if (this != &other) {
        delete pNext;       
        value = other.value;
        pNext = other.pNext;
        other.pNext = nullptr;
    }
    return *this;
}


ListNode* create_list(const std::vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->pNext = newNode;
            tail = newNode;
        }
    }
    return head;
}


void display_list(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->value << " -> ";
        current = current->pNext;
    }
    std::cout << "nullptr" << std::endl;
}


void clear_list(ListNode*& head) {
    delete head;
    head = nullptr;
}


int retrieve_value(ListNode* head, int index) {
    ListNode* current = head;
    int idx = 0;
    while (current) {
        if (idx == index) {
            return current->value;
        }
        current = current->pNext;
        ++idx;
    }
    throw std::out_of_range("Index out of range for linked list.");
}


void remove_node(ListNode*& head, int index) {
    if (!head) {
        throw std::out_of_range("Cannot remove from an empty list.");
    }

    if (index == 0) {
        ListNode* toRemove = head;
        head = head->pNext;
     
        toRemove->pNext = nullptr;
        delete toRemove;
        return;
    }

    ListNode* current = head;
    for (int i = 0; current && i < index - 1; i++) {
        current = current->pNext;
    }

    if (!current || !current->pNext) {
        throw std::out_of_range("Index out of range for linked list removal.");
    }

    ListNode* toRemove = current->pNext;
    current->pNext = toRemove->pNext;
    toRemove->pNext = nullptr; 
    delete toRemove;
}
