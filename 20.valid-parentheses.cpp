/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (char c : s) {
            switch (c) {
                case ('('):
                case ('['):
                case ('{'):
                    stack.push(c);
                    break;
                case (')'):
                    if (stack.empty() || stack.top() != '(') {
                        return false;
                    }
                    stack.pop();
                    break;
                case (']'):
                    if (stack.empty() || stack.top() != '[') {
                        return false;
                    }
                    stack.pop();
                    break;
                case ('}'):
                    if (stack.empty() || stack.top() != '{') {
                        return false;
                    }
                    stack.pop();
                    break;  
            }
        }
        return stack.empty();
    }
};
// @lc code=end

