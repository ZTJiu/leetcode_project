#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

// 解决方案一：时间复杂度和空间复杂度都是O(M*N)
/*
class Solution {
public:
    int minDistance(std::string word1, std::string word2){
        size_t m = word1.size() + 1;
        size_t n = word2.size() + 1;
        std::vector<std::vector<int>> S(m, std::vector<int>(n));
        for (size_t i = 0; i < m; ++i)
            S[i][0] = i;
        for (size_t j = 0; j < n; ++j)
            S[0][j] = j;
        for (size_t i = 1; i < m; ++i)
            for (size_t j = 1; j < n; ++j) {
                if (word1[i-1] == word2[j-1])
                    S[i][j] = S[i-1][j-1];
                else
                    S[i][j] = std::min({S[i-1][j] + 1, S[i][j-1] + 1, S[i-1][j-1] + 1});
            }
        return S[m-1][n-1];
    }
};
*/

// 解决方案二： 带备忘录的解法，优化了空间复杂度，使得空间复杂度降为O(N)
class Solution {
public:
    int minDistance(std::string word1, std::string word2){
        int m = word1.size() + 1;
        int n = word2.size() + 1;
        std::vector<int> upper_line(n, 0);
        int current = 0;
        for (int j = 0; j < n; ++j) upper_line[j] = j;
        for (size_t i = 1; i < m; ++i) {
            int upper_pre = upper_line[0];
            // now upper_line[0] is pre of current line
            upper_line[0] = i;
            for (size_t j = 1; j < n; ++j) {
                int upper = upper_line[j];
                if (word1[i-1] == word2[j-1])
                    // now upper_line[j] record value of current line
                    upper_line[j] = upper_pre;
                else
                    // now upper_line[j] record value of current line
                    upper_line[j] = std::min({upper_line[j-1] + 1, upper + 1, upper_pre + 1});
                upper_pre = upper;
                
            }
        }
        return upper_line[n-1];
    }
};

int main(void) {
    std::string word1 = "intention";
    std::string word2 = "execution";
    Solution s;
    std::cout << s.minDistance(word1, word2) << "\t";
}