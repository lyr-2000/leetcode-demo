/*
 * @lc app=leetcode.cn id=1140 lang=cpp
 *
 * [1140] 石子游戏 II
 */

// @lc code=start
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        //dp[i][M]
        int len = piles.size();
        vector<int,int> dp(len+1,len+1);
        int sum = 0;
        
        for(int i=len-1;i>=1;i--) {
            sum += piles[i];
            for(int M=1;M<=len;M++) {
                if(i+2*M >= len) {
                    dp[i][M] = sum;
                }else {
                    
                }
            } 
        }
    }
};
// @lc code=end

