//#include <climit>
#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (divisor == 0) return 0;
        long dvd = std::labs(dividend);
        long dvs = std::labs(divisor);
        long res = 0;
        bool nagtive = (dividend > 0) ^ (divisor > 0) ? true : false;
        while (dvd >= dvs) {
            long multi_dvs = dvs;
            long count = 0;
            while (multi_dvs << 1 <= dvd) {
                ++count;
                multi_dvs <<= 1;
            }
            dvd -= multi_dvs;
            res += (1 << count);
        }
        //std::cout << nagtive << std::endl;
        if (nagtive) return -res;
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    int dvd = -2147483648;
    int dvs = -1;
    std::cout << dvd << " / " << dvs << " = " << s.divide(dvd, dvs) << std::endl;
    return 0;
}
