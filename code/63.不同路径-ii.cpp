/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n = a.size();
        if(!n)  return 0;
        int m = a[0].size();
        if(!m) return 0;
        if(a[0][0]) return 0;        
        vector<vector<int> >dp(n+1,vector<int> (m+1)) ;
        // dp[0][0] = 1;
        for(int i=0;i<n && a[i][0]==0;i++) 
            dp[i][0] = 1;
        
        for(int j=1;j<m && a[0][j] == 0;j++) 
            dp[0][j] = 1;

        for(int i=1;i<n;i++) 
            for(int j=1;j<m;j++) {
                if(a[i][j]) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        return dp[n-1][m-1];

    }
};
// @lc code=end

