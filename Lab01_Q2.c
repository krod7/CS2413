// Leetcode 206: Reverse Linked List
/*
Given the head of a singly linked list, reverse the list,
and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []
*/

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

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *next = NULL;

    while (current != NULL)
    {
        // Store the next node
        next = current->next;
        // Reverse the link
        current->next = prev;
        // Move prev to the current node
        prev = current;
        // Move current to the next node
        current = next;
    }

    // New head of the reversed list
    return prev;
}