# Problem
## Descrition
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.



## Example
Input: 58
Output: "LVIII"
Explanation: C = 100, L = 50, XXX = 30 and III = 3.


Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

# Solutions
初级解决方案：
```C++
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
```

最高效的解决方案：
```C++
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
```