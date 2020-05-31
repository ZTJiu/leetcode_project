#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::cout << "n: " << n << std::endl;
        res_.clear();
        max_ = n;
        std::string str;
        str.reserve(2 * n);
        backtrack(str, 0, 0);
        return res_;
    }

    void backtrack(std::string& str, int l, int r) {
        if (r > l) return;
        if (l == max_ && r == max_) {
            res_.push_back(str);
            return;
        }
        if (l < max_) {
            str.push_back('(');
            backtrack(str, l + 1, r);
            str.pop_back();
        }
        if (r < max_) {
            str.push_back(')');
            backtrack(str, l, r + 1);
            str.pop_back();
        }
    }

private:
    std::vector<std::string> res_;
    int max_;
};

int main(int argc, char** argv) {
    Solution s;
    int num = 3;
    std::cout << num << std::endl;
    auto results = s.generateParenthesis(num);
    for (auto& res : results) {
        std::cout << res << "\n";
    }
}
