/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start


class Solution {
public:
    bool calc(int u) {
        long long x=0;
        int y = u;
        while(u) {
            x = (x*10)+ (u%10);
            u/=10;
        }
        return x == y;
    }
    bool isPalindrome(int x) {
        return x<0 ? false: calc(x);
    }
};
// @lc code=end

