/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

/**
 * Removes all nodes with the given value from the linked list
 * struct ListNode is already defined
*/

#include <stdlib.h>
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create a dummy node to handle edge cases
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    // The dummy updates the head
    dummy->next = head;
    
    // Pointer to traverse the list
    // Initialize pointer to the dummy node
    struct ListNode* current = dummy;

    // while loop to iterate through all nodes in the linked list
    while (current->next) {
        // Check if nodes in the list = val
        if (current->next->val == val) {
            // If yes: Store node to be deleted
            struct ListNode* temp = current->next;
            // Remove the node
            current->next = current->next->next;
            // Free the memory
            free(temp);
        } else {
            // If no: Move to the next node
            current = current->next;
        }
    }
    
    // Update head
    head = dummy->next;
    // Free dummy node
    free(dummy);
    return head;
}
