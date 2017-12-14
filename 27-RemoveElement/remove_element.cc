/******************************************
* File  : remove_element.cc
* Date  : 2017-12-14
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int start_pos = -1;
        int next_pos = 0;
        int len = nums.size();
        int remove_num = 0;
        while (next_pos < len) {
            if (nums[next_pos] != val) {
                nums[++start_pos] = nums[next_pos++];
            } else {
                ++next_pos;
                ++remove_num;
            }
        }

        while (remove_num-- > 0) {
            nums.pop_back();
        }

        return nums.size();
    }
};

int main(void) {
    //std::vector<int> nums = {2,3,4,2,5,2,6};
    std::vector<int> nums = {3,4,3,5,5,6};
    std::cout << "Before remove, numbers: ";
    std::for_each(nums.begin(), nums.end(), [](int & num) { std::cout << num << "\t"; });
    std::cout << std::endl;

    Solution s;
    std::cout << "After remove, has " << s.removeElement(nums, 2) << " number:" << std::endl;
    std::for_each(nums.begin(), nums.end(), [](int & num) { std::cout << num << "\t"; });
    std::cout << std::endl;

    return 0;
}

