4 Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
Implement the MyQueue class:
void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:
You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
#include <stack>
#include <iostream>

class MyQueue {
private:
    std::stack<int> stack_in;
    std::stack<int> stack_out;

    /**
     * Transfer elements from stack_in to stack_out if stack_out is empty.
     */
    void transfer() {
        while (!stack_in.empty()) {
            stack_out.push(stack_in.top());
            stack_in.pop();
        }
    }

public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack_in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (stack_out.empty()) {
            transfer();
        }
        int front = stack_out.top();
        stack_out.pop();
        return front;
    }

    /** Get the front element. */
    int peek() {
        if (stack_out.empty()) {
            transfer();
        }
        return stack_out.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stack_in.empty() && stack_out.empty();
    }
};


