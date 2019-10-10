/******************************************
* File  : permutations.cc
* Date  : 2018-10-22
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        permuteInternal(nums, 0, res);
        return res;
    }

private:
    void permuteInternal(std::vector<int>& nums, int beg, std::vector<std::vector<int>>& res) {
        if (beg >= nums.size()) {
            res.emplace_back(nums);
            return;
        }

        int first = beg;
        for (int i = beg; i < nums.size(); ++i) {
            std::swap(nums[first], nums[i]);
            permuteInternal(nums, beg + 1, res);
            std::swap(nums[first], nums[i]);
        }
    }
};


int main(void) {
    std::vector<int> nums = {1, 2, 3};

    Solution s;
    auto res = s.permute(nums);

    std::for_each(res.begin(), res.end(), [](const std::vector<int> elem) {
        std::for_each(elem.begin(), elem.end(), [](int num) { std::cout << num << "\t"; });
        std::cout << std::endl;
    });

    return 0;
}
