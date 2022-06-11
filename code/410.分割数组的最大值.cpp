/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<long long> sum(nums.size()+1);
        int n = nums.size();
        for(int i=1;i<=n;i++) sum[i] += (sum[i-1] + nums[i-1]);
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,LONG_MAX));        
        for(int i=1;i<=n;i++) {
            dp[i][1] = sum[i];// 前i 个 1组
            // 前 i个 一共 m组
            for(int j=1;j<=min(i,m);j++) {
                for(int k=0;k<i;k++) {
                    dp[i][j] = min(dp[i][j],max(dp[k][j-1], sum[i] - sum[k]));

                }
            }
        }
        
        return dp[n][m];
    }

   
};
// @lc code=end

