# Problem
## Descrition
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
You have the following 3 operations permitted on a word:
Insert a character
Delete a character
Replace a character

## Example
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

# Solutions
这是一道需要用动态规划来求解的题。首先，定义问题的解：
M = word1.size(), N = word2.size()。
S[i][j]（0 <= i <= M, 0 <= j <= N）表示word1.substr(i)到word2.substr(j)的Edit Distance;
S[i][j]可能的取值分如下几种情况：
1. word1[i-1] == word2[j-1]: S[i][j] = S[i-1][j-1]
2. word1[i-1] != word2[j-1]: S[i][j] = min(S[i][j-1]+1, S[i-1][j]+1, S[i-1][j-1]+1)
3. i == 0: S[i][j] = j
4. j == 0: S[i][j] = i
## Solution 1

```C++
// 解决方案一时间复杂度和空间复杂度都是O(M*N)
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
```

## Solution 2

```C++
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
```