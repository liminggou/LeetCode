/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 */

// @lc code=start
class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            string num = to_string(i);
            bool valid = true, diff = false;
            for (char ch: num) {
                if (check[ch - '0'] == -1) {
                    valid = false;
                }
                else if (check[ch - '0'] == 1) {
                    diff = true;
                }
            }
            if (valid && diff) {
                ++ans;
            }
        }
        return ans;
    }

private:
    static constexpr int check[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
};


// @lc code=end

