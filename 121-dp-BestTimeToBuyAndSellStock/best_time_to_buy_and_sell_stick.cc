/******************************************
* File  : best_time_to_buy_and_sell_stick.cc
* Date  : 2018-03-27
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include <vector>
#include <iostream>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }

        int max_profit = 0;
        int max = prices[0];
        int min = prices[0];
        for (auto item : prices) {
            if (item < min) {
                min = item;
                max = item;
            } else if (item > max) {
                max = item;
                if (max - min > max_profit) {
                    max_profit = max -min;
                }
            }
        }

        return max_profit;
    }
};

int main(void) {
    //std::vector<int> prices = {7, 1, 5, 3, 6, 4}; // 5
    std::vector<int> prices = {7, 6, 4, 3, 1}; // 0
    Solution s;
    std::cout << s.maxProfit(prices) << std::endl;
}
