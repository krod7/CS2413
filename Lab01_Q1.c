// Leetcode 203: Remove Linked List Elements
/*
Given the head of a linked list and an integer val,
remove all the nodes of the linked list that has
Node.val == val, and return the new head.

Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:
Input: head = [], val = 1
Output: []

Example 3:
Input: head = [7,7,7,7], val = 7
Output: []
*/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>
struct ListNode *removeElements(struct ListNode *head, int val)
{
    // Create a dummy node to handle edge cases
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    // The dummy updates the head
    dummy->next = head;

    // Pointer to traverse the list
    struct ListNode *current = dummy;

    while (current->next)
    {
        if (current->next->val == val)
        {
            // Store node to be deleted
            struct ListNode *temp = current->next;
            // Remove the node
            current->next = current->next->next;
            // Free the memory
            free(temp);
        }
        else
        {
            // Move to the next node
            current = current->next;
        }
    }

    // Update head
    head = dummy->next;
    // Free dummy node
    free(dummy);
    return head;
}