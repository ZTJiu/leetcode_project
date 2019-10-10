/******************************************
* File  : range_sum_query_immutable.cc
* Date  : 2018-03-27
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include <vector>
#include <iostream>

class NumArray {
public:
    NumArray(std::vector<int> nums): nums_(nums) {
        for (auto num : nums_) {
            if (from_begin_sum_.size() > 0) {
                from_begin_sum_.emplace_back(from_begin_sum_.back() + num);
            } else {
                from_begin_sum_.emplace_back(num);
            }
        }
    }

    int sumRange(int i, int j) {
        if (i > j || j >= nums_.size()) {
            return 0;
        }
        if (i == j) {
            return nums_[i];
        }

        return from_begin_sum_[j] - from_begin_sum_[i] + nums_[i];
    }
private:
    std::vector<int> nums_;
    std::vector<int> from_begin_sum_;
};


int main(void) {
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray na(nums);
    std::cout << na.sumRange(0,2) << std::endl;
    std::cout << na.sumRange(2,5) << std::endl;
    std::cout << na.sumRange(0,5) << std::endl;
    return 0;
}
