5  You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.
Note that:
●	The valid operators are '+', '-', '*', and '/'.
●	Each operand may be an integer or another expression.
●	The division between two integers always truncates toward zero.
●	There will not be any division by zero.
●	The input represents a valid arithmetic expression in a reverse polish notation.
●	The answer and all the intermediate calculations can be represented in a 32-bit integer.

  #include <vector>
#include <string>
#include <stack>
#include <iostream>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stack;

        for (const auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop the top two operands from the stack
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();

                // Perform the operation and push the result back onto the stack
                if (token == "+") {
                    stack.push(a + b);
                } else if (token == "-") {
                    stack.push(a - b);
                } else if (token == "*") {
                    stack.push(a * b);
                } else if (token == "/") {
                    stack.push(a / b);
                }
            } else {
                // Push the operand (converted to integer) onto the stack
                stack.push(std::stoi(token));
            }
        }

        // The result is the only element left on the stack
        return stack.top();
    }
};
