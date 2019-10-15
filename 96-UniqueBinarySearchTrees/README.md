# Problem
## Description
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


# Solutions

// 初级解决方案

```c++
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
```

// 更优化的解决方案

```c++
class Solution {
public:
};
```