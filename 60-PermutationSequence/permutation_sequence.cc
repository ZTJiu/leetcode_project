#include <vector>
#include <string>
#include <iostream>


/* wrong solution


class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::string result;
        result.reserve(n);
        int total = 1;
        for (int i = 0; i < n; ++i) {
            result.push_back('1' + i);
            total *= i + 1;
        } 
        k--;
        for (int i = 0, j = n; i < n - 1; ++i, --j) {
            total /= j;
            int pos = k / total;
            std::swap(result[i], result[i + pos]);
            k -= pos * total;
        }
        return result;
    }
};

*/

class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::string result;
        result.reserve(n);
        int total = 1;
        for (int i = 0; i < n; ++i) {
            result.push_back('1' + i);
            total *= i + 1;
        } 
        k--;
        for (int i = 0; i < n - 1; ++i) {
            total /= (n - i);
            int pos = k / total;
            char tmp = result[i + pos];
            for (int j = pos + i; j > i; --j) {
                result[j] = result[j - 1];
            }
            result[i] = tmp;
            k %= total;
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    int n = 4;
    int k = 9;
    for (int i = 1; i <= k; ++i)
        std::cout << "[" << i << "]: " << s.getPermutation(n, i) << std::endl;
    return 0;
}
