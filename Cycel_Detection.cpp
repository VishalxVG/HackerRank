#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int hasCycle(ListNode* head) {
    // Using Floyd's Cycle Detection Algorithm (Tortoise and Hare)
    if (!head || !head->next) {
        // If the list has 0 or 1 nodes, it cannot have a cycle
        return 0;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;         // Move one step at a time
        fast = fast->next->next;   // Move two steps at a time

        if (slow == fast) {
            // If slow and fast pointers meet, there is a cycle
            return 1;
        }
    }

    // If the loop completes without meeting, there is no cycle
    return 0;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head;  // Creating a cycle

    int result = hasCycle(head);
    std::cout << "Result: " << result << std::endl;

    // Remember to free the memory allocated for the linked list
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
