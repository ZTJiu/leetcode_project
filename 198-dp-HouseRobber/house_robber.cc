/******************************************
* File  : house_robber.cc
* Date  : 2018-03-20
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include <vector>
#include <iostream>

class Solution {
    public:
        int rob(std::vector<int>& nums) {
            if (nums.size() == 0)
                return 0;
            int first = nums[0];
            int second = nums[0];
            if (nums.size() > 1) {
                if (nums[0] >= nums[1]) {
                    second = nums[0];
                } else {
                    second = nums[1];
                }
            }
            for (int i = 2; i < nums.size(); ++i) {
                int temp = second;
                second = std::max(second, first + nums[i]);
                first = temp;
            }
            return second;
        }
};

int main(void) {
    std::vector<int> nums = {1,4,2,6,7};
    Solution s;
    std::cout << s.rob(nums) << std::endl;
    return 0;
}
