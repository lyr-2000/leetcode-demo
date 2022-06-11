/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mp;
        int sum = 0;
        int res=0;
        int j = 0;
        for(int i=0,n=s.size();i<n;i++) {
            if(mp.count(s[i])) {
                while(mp[s[i]]) {
                    mp[s[j]]--;
                    j++;
                }
                mp[s[i]] ++;
                res = max(res,i-j+1);

            }else {
                mp[s[i]] += 1;
                // sum ++;
                res = max(res,i-j+1);
            }
        }

        return res;

    }
};
// @lc code=end

