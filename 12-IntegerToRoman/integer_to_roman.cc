/******************************************
* File  : integer_to_roman.cc
* Date  : 2017-12-19
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include <iostream>
#include <vector>
#include <string>

// 初级方案
/*
class Solution {
public:
    Solution() {
        table_.emplace_back(1000, "M");
        table_.emplace_back(900, "CM");
        table_.emplace_back(500, "D");
        table_.emplace_back(400, "CD");
        table_.emplace_back(100, "C");
        table_.emplace_back(90, "XC");
        table_.emplace_back(50, "L");
        table_.emplace_back(40, "XL");
        table_.emplace_back(10, "X");
        table_.emplace_back(9, "IX");
        table_.emplace_back(5, "V");
        table_.emplace_back(4, "IV");
        table_.emplace_back(1, "I");
    }

    std::string intToRoman(int num) {
        if (num < 1 || num > 3999) {
            return "MMMDCDXCIX";
        }

        std::string ret;
        ret.reserve(32);
        for (auto item : table_) {
            if (num >= item.value) {
                int n = num / item.value;
                for (int i = 0; i < n; ++i) {
                    ret.append(item.roman_str);
                }
                num = num % item.value;
            }
        }

        return ret;
    }

private:
    struct Item {
        Item(int val, const char * str)
            : value(val), roman_str(str) {
        }

        int value;
        std::string roman_str;
    };

    std::vector<Item> table_;
};
*/

// 高效方案
class Solution {
public:
    std::string intToRoman(int num) {
        static std::vector<std::string> thousands = {"", "M", "MM", "MMM"};
        static std::vector<std::string> hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        static std::vector<std::string>  decades = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        static std::vector<std::string> units = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        // 这么写会多构造几次临时的string，比前面的运行时开销还高 ：（
        //return thousands[num/1000] + hundreds[(num%1000)/100] + decades[(num%100)/10] + units[(num%10)];

        std::string ret;
        ret.reserve(32);
        // 只用构造一次string，可以击败91%的解决方案
        return ret.append(thousands[num/1000]).append(hundreds[(num%1000)/100])
                .append(decades[(num%100)/10]).append( units[(num%10)]);
    }
};

int main(int argc, char ** argv) {
    int num = 58;
    Solution s;
    std::cout << num << " : " << s.intToRoman(num) << std::endl;

    return 0;
}
