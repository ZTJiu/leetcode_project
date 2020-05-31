#include <vector>
#include <iostream>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int l = 0;
        int r = 1;
        while (r < nums.size()) {
            if (nums[r] != nums[l]) {
                if (l + 1 < r)
                    nums [l + 1] = nums[r];
                ++l;
            }
            ++r;
        }
        return l + 1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    auto res = s.removeDuplicates(nums);
    std::copy(nums.begin(), nums.begin() + res, std::ostream_iterator<int>(std::cout, " "));
    return 0;
}
