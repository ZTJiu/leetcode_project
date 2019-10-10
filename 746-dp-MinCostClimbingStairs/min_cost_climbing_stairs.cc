/******************************************
* File  : min_cost_climbing_stairs.cc
* Date  : 2018-03-20
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include <vector>
#include <iostream>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        std::vector<int> total_cost(cost.size() + 1, 0);
        for (int i = 0; i < total_cost.size(); ++i) {
            if (i > 1) {
                total_cost[i] = std::min(total_cost[i - 1] + cost[i - 1], total_cost[i - 2] + cost[i - 2]);
            } else {
                total_cost[i] = 0;
            }
        }
        return total_cost[cost.size()];
    }
};

int main(void) {
    std::vector<int> cost = {10, 15, 20};
    //std::vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution s;
    std::cout << s.minCostClimbingStairs(cost) << std::endl;
    return 0;
}
