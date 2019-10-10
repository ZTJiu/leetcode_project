/******************************************
* File  : 3sum_closet.cc
* Date  : 2018-01-15
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        if (nums.size() < 3) {
            return 0;
        }

        std::vector<int> temp;

        std::sort(nums.begin(), nums.end());

        int result = 0;
        int abs_diff = std::numeric_limits<int>::max();


        for (uint32_t i = 0; i < nums.size() - 2; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) {
                // skip duplicated numbers
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                // only have exactly one result
                if (sum == target) return sum;

                int diff = sum > target ? sum - target : target - sum;
                if (diff < abs_diff) {
                    result = sum;
                    abs_diff = diff;

                    temp.clear();
                    temp.emplace_back(std::move(nums[i]));
                    temp.emplace_back(std::move(nums[l]));
                    temp.emplace_back(std::move(nums[r]));

                    //do { --r; } while (r > l && nums[r] == nums[nums.size() - 1]);
                    //do { ++l; } while (l < r && nums[l] == nums[i+1]);
                } //else {
                    if (sum > target) {
                        do { --r; } while (r > l && nums[r] == nums[nums.size() - 1]);
                    } else {
                        do { ++l; } while (l < r && nums[l] == nums[i+1]);
                    }
                //}
            }
        }

        std::for_each(temp.begin(), temp.end(), [](int elem) { std::cout << elem << "\t"; });
        std::cout << std::endl;
        std::cout << "result=" << result << std::endl;
        return result;
    }
};

int main(int argc, char ** argv) {
    //std::vector<int> nums = {-1, 2, 1, -4};
    std::vector<int> nums = {0,2,1,-3};
    int target = 1;

    std::cout << "target=" << target << "nums: " << std::endl;
    std::for_each(nums.begin(), nums.end(), [](int elem) { std::cout << elem << "\t"; });
    std::cout << std::endl;

    Solution s;
    std::cout << "results: " << std::endl;
    std::cout << s.threeSumClosest(nums, target) << std::endl;

    return 0;
}
