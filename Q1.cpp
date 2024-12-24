Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
●	MinStack() initializes the stack object.
●	void push(int val) pushes the element val onto the stack.
●	void pop() removes the element on the top of the stack.
●	int top() gets the top element of the stack.
●	int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.


#include <stack>
#include <limits.h>

class MinStack {
private:
    std::stack<int> main_stack;
    std::stack<int> min_stack;

public:
    /** Initialize the stack object. */
    MinStack() {
        // Initialize min_stack with a large value to handle edge cases.
        min_stack.push(INT_MAX);
    }

    /** Push the element val onto the stack. */
    void push(int val) {
        main_stack.push(val);
        if (val <= min_stack.top()) {
            min_stack.push(val);
        }
    }

    /** Remove the element on the top of the stack. */
    void pop() {
        if (!main_stack.empty()) {
            if (main_stack.top() == min_stack.top()) {
                min_stack.pop();
            }
            main_stack.pop();
        }
    }

    /** Get the top element of the stack. */
    int top() {
        if (!main_stack.empty()) {
            return main_stack.top();
        }
        return -1; // Return -1 if the stack is empty.
    }

    /** Retrieve the minimum element in the stack. */
    int getMin() {
        return min_stack.top();
    }
};


