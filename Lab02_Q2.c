// Leetcode 232: Implement Queue using Stacks
/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

Example 1:
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    // Create 2 stacks
    // stack1 acts as the input stack, stack2 as an output stack
    // stack2 will hold same order for the elements as queue
    int *stack1;
    int *stack2;
    // Make note of the indicies of the 2 stacks and their respective capacity
    int top1;
    int top2;
    int capacity;
} MyQueue;

MyQueue *myQueueCreate()
{
    MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
    queue->capacity = 100; // Adjust as needed
    // Allocate memory for the stacks
    queue->stack1 = (int *)malloc(queue->capacity * sizeof(int));
    queue->stack2 = (int *)malloc(queue->capacity * sizeof(int));
    // Initialize the stacks to be empty
    queue->top1 = -1;
    queue->top2 = -1;
    return queue;
}

void myQueuePush(MyQueue *obj, int x)
{
    // Push onto stack1
    // Input all the elements
    obj->stack1[++(obj->top1)] = x;
}

int myQueuePop(MyQueue *obj)
{
    // If stack2 is empty, transfer elements from stack1
    // Flips / Reverses the order at which the elements can be popped out (LIFO to FIFO like a Queue)
    if (obj->top2 == -1)
    {
        while (obj->top1 >= 0)
        {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
    // Pop from stack2 / output stack
    return obj->stack2[(obj->top2)--];
}

int myQueuePeek(MyQueue *obj)
{
    // If stack2 is empty, transfer elements from stack1
    if (obj->top2 == -1)
    {
        while (obj->top1 >= 0)
        {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
    // Peek at stack2
    // See what element is currently at the top
    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue *obj)
{
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue *obj)
{
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}