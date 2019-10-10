/******************************************
* File  : 3sum.cc
* Date  : 2018-01-04
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <iostream>

class Solution0 {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> rets;
        std::unordered_set<std::string> strs;
        int max_pos = nums.size();

        if (max_pos < 3) {
            return rets;
        }

        for (int i = 0; i < max_pos; ++i) {
            for (int j = i + 1; j < max_pos; ++j) {
                for (int k = j + 1; k < max_pos; ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        std::vector<int> zero_sums = {nums[i], nums[j], nums[k]};
                        std::sort(zero_sums.begin(), zero_sums.end());
                        std::string str;
                        str.reserve(64);
                        for (auto item : zero_sums) {
                            str.append(std::to_string(item));
                        }
                        if (strs.count(str) == 1) {
                            continue;
                        }
                        rets.emplace_back(std::move(zero_sums));
                        strs.emplace(std::move(str));
                    }
                }
            }
        }

        return rets;
    }
};

class Solution1 {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        std::vector<std::vector<int>> rets;
        int nums_size = nums.size();

        if (nums_size < 3) {
            return rets;
        }

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums_size - 2; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int l = i + 1;
                int r = nums_size - 1;
                while (l < r) {
                    int sum = nums[i] + nums[l] + nums[r];
                    if (sum == 0) {
                        std::vector<int> zero_nums = {nums[i], nums[l], nums[r]};
                        rets.emplace_back(std::move(zero_nums));
                        do { ++l; } while (l < r && nums[l] == nums[l - 1]);
                        do { --r; } while (l < r && nums[r] == nums[r + 1]);
                    } else if (sum > 0) {
                        do { --r; } while (l < r && nums[r] == nums[r + 1]);
                    } else {
                        do { ++l; } while (l < r && nums[l] == nums[l - 1]);
                    }
                }
            }
        }

        return rets;
    }
};

class Solution {
public:
    std::vector<std::vector<int>> threeSum (std::vector<int>& nums) {
        std::vector<std::vector<int>> rets;
        if (nums.size() < 3) { return rets; }
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if ((i > 0 && nums[i-1] != nums[i]) || i == 0) {
                int beg = i + 1;
                int end = nums.size() - 1;
                while (beg < end) {
                    int sum = nums[i] + nums[beg] + nums[end];
                    if (sum == 0) {
                        std::vector<int> elem = {nums[i], nums[beg], nums[end]};
                        rets.emplace_back(std::move(elem));
                        do { ++beg; } while (beg < end && nums[beg] == nums[beg - 1]);
                        do { --end; } while (end > beg && nums[end] == nums[end + 1]);
                        continue;
                    }
                    if (sum > 0) {
                        --end;
                    } else {
                        ++beg;
                    }
                }
            }
        }
        return rets;
    }
};

int main(void) {
    //std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    //std::vector<int> nums = {1, 0, -1, -1};
    //std::vector<int> nums = {-2,0,0,2,2};
    std::vector<int> nums = {0,0,0,0,0};
    Solution s;
    auto rets = s.threeSum(nums);
    for (auto item : rets) {
        std::for_each(item.begin(), item.end(), [] (int & n) { std::cout << n << "\t"; });
        std::cout << std::endl;
    }

    return 0;
}
