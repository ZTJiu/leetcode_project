/******************************************
* File  : maximum_subarray.cc
* Date  : 2018-03-22
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include <vector>
#include <iostream>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        int sum = 0;
        int max_sum = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum > max_sum) {
                max_sum = sum;
            }
            if (sum <= 0) {
                sum = nums[i] > 0 ? nums[i] : 0;
            }
        }

        return max_sum;
    }
};

int main(void) {
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    std::cout << s.maxSubArray(nums) << std::endl;
    return 0;
}
