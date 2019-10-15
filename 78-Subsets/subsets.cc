#include <vector>
#include <iostream>

/*
class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
       std::vector<std::vector<int>> results = {{}};
       if (nums.empty()) return results; 
       for (auto num : nums) {
           int total_size = results.size();
           for (int i = 0; i < total_size; ++i) {
               auto tmp = results[i];
               tmp.push_back(num);
               results.emplace_back(std::move(tmp));
           }
       }
       return results;
    }
};
*/

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        int n = nums.size();
        int res_num = 1 << n;
        std::cout << "total_result num: " << res_num << std::endl;
        std::vector<std::vector<int>> rets;
        for (int i = 0; i < res_num; ++i) {
            std::vector<int> new_res;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    new_res.push_back(nums[j]);
                } 
            }
            rets.emplace_back(std::move(new_res));
        }
        return rets;
    }
};

int main(int argc, char** argv) {
    Solution s;
    std::vector<int> nums = {2, 3};
    auto results = s.subsets(nums);
    for (auto& res : results) {
        for (auto num : res) {
            std::cout << num << "\t";
        }
        std::cout << std::endl;
    }
}
