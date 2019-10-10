# Problem
## Descrition
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

## Example
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

# Solutions
初级解决方案，只击败了63%的答案

```c++
class Solution {
public:
    int longestValidParentheses(const std::string & s) {
        if (s.size() < 2) {
            return 0;
        }

        int max_len = 0;
        int last_len = 0;
        int current_len = 0;
        int un_match_len = 0;
        std::vector<char> stack;
        stack.reserve(s.size());
        for (auto c : s) {
            if (c == '(') {
                ++un_match_len;
                stack.emplace_back(c);
            } else if (c == ')') {
                if (not stack.empty() && stack.back() == '(') {
                    stack.pop_back();
                    current_len += 2;
                    --un_match_len;

                    if (un_match_len == 0) {
                        current_len += last_len;
                        last_len = 0;
                    } else {
                        if (last_len == 0) {
                            last_len = current_len;
                            un_match_len = 0;
                        }
                    }

                    if (current_len > max_len) {
                        max_len = current_len;
                    }
                } else {
                    current_len = 0;
                    last_len = 0;
                    stack.clear();
                }
            } else {
                current_len = 0;
                last_len = 0;
                stack.clear();
            }
        }
        return max_len;
    }
};
```

最高效的解决方案，击败了100%的其他答案
```C++
// 最高效的解决方案，击败了100%的其他答案
// 最后计算不匹配元素的数量的时候，边界条件特别复杂，一定要想清楚。
class Solution {
public:
    int longestValidParentheses(const std::string& s) {
        if (s.size() < 2) {
            return 0;
        }

        std::vector<int> stack;
        stack.reserve(s.size() + 1);
        for (int pos = 0; pos < s.size(); ++pos) {
            if (s[pos] == '(') {
                stack.emplace_back(pos);
            } else {
                if (not stack.empty() && s[stack.back()] == '(') {
                        // matchs
                        stack.pop_back();
                } else {
                    stack.emplace_back(pos);
                }
            }
        }
        
        int max_len = 0;
        if (stack.empty()) {
            max_len = s.size();
            return max_len;
        }

        int last_pos = (stack.front() == 0 ? 0 : -1);
        int len = 0;
        for (auto cur_pos : stack) {
            len = cur_pos - last_pos - 1;
            if (len > max_len) {
                max_len = len;
            }
            last_pos = cur_pos;
        }
        if (last_pos != s.size() - 1) {
            len = s.size() - last_pos - 1;
            if (len > max_len) {
                max_len = len;
            }
        }
        
        return max_len;
    }
};
```