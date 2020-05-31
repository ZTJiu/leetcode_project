#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max_left = 0;
        int max_right = 0;
        int res = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                if (max_left > height[l])
                    res += max_left - height[l];
                else
                    max_left = height[l];
                ++l;
            } else {
                if (max_right > height[r])
                    res += max_right - height[r];
                else
                    max_right = height[r];
                --r;
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << s.trap(height) << std::endl;
    return 0;
}
