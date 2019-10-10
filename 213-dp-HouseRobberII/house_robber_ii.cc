/******************************************
* File  : house_robber_ii.cc
* Date  : 2018-03-21
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return std::max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
    }
private:
    int rob(std::vector<int>& nums, int beg, int end) {
        if (beg >= end) {
            return 0;
        }

        int first = nums[beg];
        int second = nums[beg];
        if (end - beg > 1) {
            if (nums[beg] < nums[beg + 1]) {
                second = nums[beg + 1];
            }
        }

        for (int i = beg + 2; i < end; ++i) {
            int temp = second;
            second = std::max(first + nums[i], second);
            first = temp;
        }

        return second;
    }
};

int main(void) {
    std::vector<int> nums = {2, 5, 1, 8};
    Solution s;
    std::cout << s.rob(nums) << std::endl;
    return 0;
}
