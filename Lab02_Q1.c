// Leetcode 225: Implement Stack using Queues
/*
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

Example 1:
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    // Create 2 queues
    // q1 for storing elements in stack order and q2 used temporarily during push operation
    int *q1;
    int *q2;
    // Make note of the indicies of the 2 queues and their respective capacity
    int front1;
    int rear1;
    int front2;
    int rear2;
    int capacity;
} MyStack;

MyStack *myStackCreate()
{
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    stack->capacity = 100; // Adjust as needed
    // Allocate memory for the queues
    stack->q1 = (int *)malloc(stack->capacity * sizeof(int));
    stack->q2 = (int *)malloc(stack->capacity * sizeof(int));
    // Initialize the front and rear pointers of q1 and q2 to be 0
    // Start with empty queues
    stack->front1 = stack->rear1 = 0;
    stack->front2 = stack->rear2 = 0;
    return stack;
}

void myStackPush(MyStack *obj, int x)
{
    obj->q2[obj->rear2++] = x; // Push new element (x) into q2

    while (obj->front1 < obj->rear1)
    {
        // Move everything from q2 to q1
        obj->q2[obj->rear2++] = obj->q1[obj->front1++];
    }

    // Swap the queues
    int *temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;

    // Reset q2
    obj->front1 = 0;
    obj->rear1 = obj->rear2;
    obj->front2 = obj->rear2 = 0;
}

int myStackPop(MyStack *obj)
{
    // Pop from front of q1
    return obj->q1[obj->front1++];
}

int myStackTop(MyStack *obj)
{
    // Peek front of q1
    return obj->q1[obj->front1];
}

bool myStackEmpty(MyStack *obj)
{
    return obj->front1 == obj->rear1;
}

void myStackFree(MyStack *obj)
{
    free(obj->q1);
    free(obj->q2);
    free(obj);
}