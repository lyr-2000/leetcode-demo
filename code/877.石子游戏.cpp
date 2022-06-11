/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */

// @lc code=start
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        //dp[1][n] > 0 表示 Alice 能赢，把比较 问题变成正负号的问题
        for(int i=0;i<n;i++) 
            for(int j=1;j<=n;j++) dp[i][j] = piles[i];
        for(int i=n-1;i>=0;i--) {
            for(int j=i+1;j<n;j++) {
                //i j
                dp[i][j] = max(piles[i] - dp[i+1][j],piles[j] - dp[i][j-1]);
            }
        }
        return dp[0][n-1] >= 0;

    }
};
// @lc code=end

