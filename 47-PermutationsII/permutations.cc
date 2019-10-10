/******************************************
* File  : permutations.cc
* Date  : 2018-10-22
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>


class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        //std::sort(nums.begin(), nums.end());
        std::unordered_set<int> used;
        permuteInternal(nums, 0, used, res);
        return res;
    }

private:
    /*void permuteInternal(std::vector<int>& nums, int beg, std::vector<std::vector<int>>& res) {
        if (beg >= nums.size()) {
            res.emplace_back(nums);
            return;
        }

        for (int i = beg; i < nums.size(); ++i) {
            // swap 以后，有序的假设不成立了，所以这种解法会失败
            if (i - 1 >= beg && nums[i-1] == nums[i]) continue;
            std::swap(nums[beg], nums[i]);
            permuteInternal(nums, beg + 1, res);
            std::swap(nums[beg], nums[i]);
        }
    }*/

    void permuteInternal(std::vector<int>& nums, int beg, std::unordered_set<int>& used, std::vector<std::vector<int>>& res) {
        if (beg >= nums.size()) {
            res.emplace_back(nums);
            return;
        }

        for (int i = beg; i < nums.size(); ++i) {
            if (used.count(nums[i]) == 1) continue;
            std::swap(nums[beg], nums[i]);
            used.emplace(nums[i]);
            permuteInternal(nums, beg + 1, used, res);
            used.erase(nums[i]);
            std::swap(nums[beg], nums[i]);
        }
    }
};


int main(void) {
    //std::vector<int> nums = {1, 1, 2};
    std::vector<int> nums = {0, 1, 0, 0, 9};

    Solution s;
    auto res = s.permuteUnique(nums);

    std::for_each(res.begin(), res.end(), [](const std::vector<int> elem) {
        std::for_each(elem.begin(), elem.end(), [](int num) { std::cout << num << "\t"; });
        std::cout << std::endl;
    });

    return 0;
}
