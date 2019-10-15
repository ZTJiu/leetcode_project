#include <vector>
#include <iostream>

class Solution {
public:
    int numTrees(int n) {
        std::vector<int> results(n + 1, 0);       
        results[0] = 1;
        results[1] = 1;
        for (int i = 2; i < n + 1; ++i) {
            for (int j = 0; j < i; ++j) {
                results[i] += results[j] * results[i - j - 1];
            }
        }
        return results[n];
    }
};

int main(int argc, char** argv) {
    Solution s;
    int n = 3;
    std::cout << s.numTrees(n);
    return 0;
}
