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
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.


## Example
Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


# Solutions

初级解决方案，只能打败5%的答案

```C++
class Solution {
public:
    Solution() {
        table_.emplace("M", 1000);
        table_.emplace("CM", 900);
        table_.emplace("D", 500);
        table_.emplace("CD", 400);
        table_.emplace("C", 100);
        table_.emplace("XC", 90);
        table_.emplace("L", 50);
        table_.emplace("XL", 40);
        table_.emplace("X", 10);
        table_.emplace("IX", 9);
        table_.emplace("V", 5);
        table_.emplace("IV", 4);
        table_.emplace("I", 1);
    }

    int romanToInt(std::string s) {
        if (s.empty()) {
            return 0;
        }

        int ret = 0;
        int pos = 0;
        while (pos  < s.size()) {
            if (pos + 1 < s.size()) {
                std::string sub_str(s.substr(pos, 2));
                auto find_iter = table_.find(sub_str);
                if (find_iter != table_.end()) {
                    ret += find_iter->second;
                    pos += 2;
                    continue;
                }
            }
            std::string sub_str(s.substr(pos, 1));
            auto find_iter = table_.find(sub_str);
            if (find_iter != table_.end()) {
                ++pos;
                ret += find_iter->second;
            }
        }

        return ret;
    }

private:
    std::unordered_map<std::string,int> table_;
};
```

更高效解决方案，能够打败97%的答案
```C++
class Solution {
    int Thousands(const std::string& s, int* start) {
        int& pos = *start;
        int ret = 0;
        while (pos < s.size() && s[pos] == 'M') {
            ret += 1000;
            pos += 1;
        }
        return ret;
    }
    int Hundreds(const std::string& s, int* start) {
        int& pos = *start;
        int ret = 0;
        if (s[pos] == 'D') {
            ret += 500;
            pos += 1;
        }
        while (pos < s.size() && s[pos] == 'C') {
            if (pos+1 < s.size()) {
                if (s[pos+1] == 'M') {
                    ret += 900;
                    pos += 2;
                    continue;
                }
                if (s[pos+1] == 'D') {
                    ret += 400;
                    pos += 2;
                    continue;
                }
            }
            ret += 100;
            pos += 1;
        }
        return ret;
    }
    int Decades(const std::string& s, int* start) {
        int& pos = *start;
        int ret = 0;
        if (s[pos] == 'L') {
            ret += 50;
            pos += 1;
        }
        while (pos < s.size() && s[pos] == 'X') {
            if (pos+1 < s.size()) {
                if (s[pos+1] == 'L') {
                    ret += 40;
                    pos += 2;
                    continue;
                }
                if (s[pos+1] == 'C') {
                    ret += 90;
                    pos += 2;
                    continue;
                }
            }
            ret += 10;
            pos += 1;
        }
        return ret;
    }
    int Units(const std::string& s, int* start) {
        int& pos = *start;
        int ret = 0;
        if (s[pos] == 'V') {
            ret += 5;
            pos += 1;
        }
        while (pos < s.size() && s[pos] == 'I') {
            if (pos + 1 < s.size()) {
                if (s[pos+1] == 'V') {
                    ret += 4;
                    pos += 2;
                    continue;
                }
                if (s[pos+1] == 'X') {
                    ret += 9;
                    pos += 2;
                    continue;
                }
            }
            ret += 1;
            pos += 1;
        }
        return ret;
    }
public:
    int romanToInt(std::string s) {
        if (s.empty()) {
            return 0;
        }

        int ret = 0;
        int pos = 0;
        while (pos  < s.size()) {
            switch(s[pos]) {
                case 'M':
                    ret += Thousands(s, &pos);
                    break;
                case 'C':
                case 'D':
                    ret += Hundreds(s, &pos);
                    break;
                case 'L':
                case 'X':
                    ret += Decades(s, &pos);
                    break;
                case 'I':
                case 'V':
                    ret += Units(s, &pos);
            }
        }

        return ret;
    }
};

```