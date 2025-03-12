#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"
#include <sstream>
#include <vector>

static std::string capture_display(ListNode* head) {
    std::stringstream buffer;
    std::streambuf* old_buf = std::cout.rdbuf(buffer.rdbuf());
    display_list(head);
    std::cout.rdbuf(old_buf);
    return buffer.str();
}

TEST_CASE("Linked List - Basic Operations") {
    std::vector<int> vals = {10, 20, 30, 40};
    ListNode* head = create_list(vals);

    CHECK(capture_display(head) == "10 -> 20 -> 30 -> 40 -> nullptr\n");
    CHECK(retrieve_value(head, 2) == 30);

    remove_node(head, 1); 
    CHECK(capture_display(head) == "10 -> 30 -> 40 -> nullptr\n");

    clear_list(head);
    CHECK(head == nullptr);
}

TEST_CASE("Linked List - Move Constructor") {
    std::vector<int> vals = {1, 2, 3, 4, 5};
    ListNode* original = create_list(vals);

   
    ListNode moved(std::move(*original));

    
    CHECK(capture_display(&moved) == "1 -> 2 -> 3 -> 4 -> 5 -> nullptr\n");


    CHECK(capture_display(original) == "1 -> nullptr\n");


    delete original;
}

TEST_CASE("Linked List - Move Assignment Operator") {
    std::vector<int> set1 = {100, 200, 300};
    std::vector<int> set2 = {10, 20, 30, 40};

    ListNode* firstList = create_list(set1);
    ListNode* secondList = create_list(set2);


    ListNode n1(std::move(*firstList));
    ListNode n2(std::move(*secondList));

    n1 = std::move(n2);

    CHECK(capture_display(&n1) == "10 -> 20 -> 30 -> 40 -> nullptr\n");


    CHECK(capture_display(&n2) == "10 -> nullptr\n");

    delete firstList;
    delete secondList;
}
