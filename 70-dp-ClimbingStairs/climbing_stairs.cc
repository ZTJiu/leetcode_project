/******************************************
* File  : climbing_stairs.cc
* Date  : 2018-03-22
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include <vector>
#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if (n < 1) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; ++i) {
            int temp = second;
            second += first;
            first = temp;
        }
        return second;
    }
};

int main(void) {
    int n = 3;
    Solution s;
    std::cout << s.climbStairs(n) << std::endl;
    return 0;
}
