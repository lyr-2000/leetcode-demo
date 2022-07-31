/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.size(), m = p.size();
        if(!n || !m) return false;

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = true; //传递
        for (int i = 1; i <= m; i ++)
        {
            if (p[i-1] == '*') dp[0][i] =  dp[0][i - 2];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // case 1: p== *
                // case 2: p== .
                // case 3: p==s
                // char pp = p[j - 1], ss = s[i - 1];
                if ( p[j-1] == '.' || p[j-1] == s[i-1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if ( p[j-1] == '*'  )
                {
                    // match 1
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
                    {
                        // s="aa"
                        // p=".*"
                        dp[i][j] = dp[i][j-2] || dp[i-1][j-2]||dp[i-1][j];
                    }
                    else
                    {
                        // empty match
                        // "aaaa"
                        // "aaaa*"

                        dp[i][j] = dp[i][j - 2]; // 不匹配
                    }
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end
