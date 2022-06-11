/*
 * @lc app=leetcode.cn id=926 lang=cpp
 *
 * [926] 将字符串翻转到单调递增
 */

// @lc code=start
class Solution
{
public:
    int minFlipsMonoIncr(string str)
    {
        int n = str.size();
        vector<int> s(n+1) ;
        for (int i = 1; i <= n; i++)
        {
            s[i] = s[i-1] + (str[i-1] - '0');
        }
        int cnt0_ = n - s[n];//0的个数
        int res = cnt0_;//  000xxx  1111 xxxx
        for(int i=1;i<=n;i++) {
            //枚举分界点
            //前面1的个数
            int cnt1 = s[i];
            int cnt0 = (n-i) - (s[n] - s[i]);//后面0的个数
            res = min(res,cnt1+cnt0);
        }
        return res;
        
    }
};
// @lc code=end
