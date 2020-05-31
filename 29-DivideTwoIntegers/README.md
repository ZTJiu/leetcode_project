# Problem
## Description
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

# Solutions

// 初级解决方案

```c++
class Solution {
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
```

// 更优化的解决方案

```c++
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
```