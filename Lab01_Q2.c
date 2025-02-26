/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

#include <stdlib.h>

/**
 * Reverses a singly linked list.
 * struct ListNode is already defined.
*/

struct ListNode* reverseList(struct ListNode* head) {
    // Initialize 3 ptrs
    // Track previous nodes, initialized NULL b/c the new last node should be NULL
    struct ListNode* prev = NULL;
    // Track the node being processed, initialized head b/c it is the beginning of the list
    struct ListNode* current = head;
    // Store the next node temporarily to prevent losing track of the order of the list
    struct ListNode* next = NULL;

    // while loop to iterate through all nodes in list
    while (current != NULL) {
        // Store the next node
        // Do not modify it or else
        next = current->next;
        // Reverse the link
        // Changes the direction of the links the opposite way
        // Instead of pointing forward, point backward to the previous node
        current->next = prev;
        // Move prev to the current node
        // Keep track of the reversed parts of the list
        prev = current;
        // Move current to the next node
        // Once done processing a node, continue to the next one
        current = next;
    }
    
    // New head of the reversed list
    return prev;
}
