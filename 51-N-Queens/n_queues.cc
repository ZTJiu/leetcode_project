#include <vector>
#include <string>
#include <iostream>

/*class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::string> result(n, std::string(n, '.'));
        //for (auto& r : result) { std::cout << r << std::endl; }
        BackTrack(result, 0, n);
        return results_;
    }

private:
    void BackTrack(std::vector<std::string>& tmp, int row, int n) {
        if (row == n) {
            results_.push_back(tmp);
            return;
        }
        for (int col = 0; col < n; ++col) {
            tmp[row][col] = 'Q';
            if (Valid(tmp, row, col, n)) {
                BackTrack(tmp, row + 1, n);
            }
            tmp[row][col] = '.';
        }
    }

    bool Valid(const std::vector<std::string>& tmp, int row, int col, int n) {
        for (int i = 0; i < row; ++i) {
            if (tmp[i][col] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (tmp[i][j] == 'Q') {
                return false;
            } 
        }

        for (int i = row - 1, j = col + 1; i >=0 && j <= n; --i, ++j) {
            if (tmp[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    std::vector<std::vector<std::string>> results_;
};*/

class Solution {
public:
    std::vector<std::vector<int>> Permutations(std::vector<int>& nums) {
        BackTrack(nums, 0);
        return results_;
    }

private:
    void BackTrack(std::vector<int>& nums, int pos) {
        if (pos == nums.size()) {
            results_.emplace_back(nums);
            return;
        }

        for (int i = pos; i < nums.size(); ++i) {
            std::swap(nums[pos], nums[i]);
            BackTrack(nums, pos + 1);
            std::swap(nums[pos], nums[i]);
        }
    }

    std::vector<std::vector<int>> results_;
};

int main(int argc, char** argv) {
    Solution s;
    /*int n = 4;
    auto results = s.solveNQueens(n);
    for (auto& res : results) {
        for (auto& str : res)
            std::cout << str << "\n";
        std::cout << "-------------" << std::endl;
    }*/
    std::vector<int> nums = {1, 2, 3};
    auto results = s.Permutations(nums);
    for (const auto& result : results) {
        for (auto num : result) std::cout << num << "\t";
        std::cout << std::endl;
    }
    return 0;
}
