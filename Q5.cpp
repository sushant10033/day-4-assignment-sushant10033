6  A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].
Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. There are three types of matched pairs of brackets: [], {}, and ().
A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For example, {[(])} is not balanced because the contents in between { and } are not balanced. The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ].
By this logic, we say a sequence of brackets is balanced if the following conditions are met:
It contains no unmatched brackets.
The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.
Given n  strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, return YES. Otherwise, return NO.
Function Description
Complete the function isBalanced in the editor below.
isBalanced has the following parameter(s):
string s: a string of brackets
Returns
string: either YES or NO

#include <string>
#include <stack>
#include <unordered_map>
#include <iostream>

std::string isBalanced(const std::string& s) {
    /**
     * Determine whether the given string of brackets is balanced.
     * @param s: a string of brackets
     * @return: "YES" if the string is balanced, otherwise "NO"
     */

    std::stack<char> stack;
    std::unordered_map<char, char> matching_bracket = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char ch : s) {
        // If it's a closing bracket
        if (matching_bracket.count(ch)) {
            // Check if the stack is non-empty and the top matches the opening bracket
            if (!stack.empty() && stack.top() == matching_bracket[ch]) {
                stack.pop();
            } else {
                return "NO";
            }
        } else {
            // Push opening brackets onto the stack
            stack.push(ch);
        }
    }

    // If the stack is empty, all brackets were matched
    return stack.empty() ? "YES" : "NO";
}


