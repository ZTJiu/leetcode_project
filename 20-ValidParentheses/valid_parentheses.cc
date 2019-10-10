/******************************************
* File  : valid_parentheses.cc
* Date  : 2018-10-17
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include <vector>
#include <iostream>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        if (s.empty()) { return true; }
        if (s.size() < 2) { return false; }

        std::vector<char> st;
        st.reserve(s.size());

        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push_back(c);
                continue;
            }
            if (c == ')') {
                if (!st.empty() && st.back() == '(') {
                    st.pop_back();
                    continue;
                }
                return false;
            }
            if (c == '}') {
                if (!st.empty() && st.back() == '{') {
                    st.pop_back();
                    continue;
                }
                return false;
            }
            if (c == ']') {
                if (!st.empty() && st.back() == '[') {
                    st.pop_back();
                    continue;
                }
                return false;
            }
            return false;
        }

        return st.empty();
    }
};

int main(void) {
    std::string s = "()[]{}";

    Solution sl;
    std::cout << sl.isValid(s) << std::endl;

    return 0;
}
