#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
/*
 * @lc app=leetcode.cn id=659 lang=cpp
 *
 * [659] 分割数组为连续子序列
 */

// @lc code=start
class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto f : nums)
            mp[f]++;
        for (auto f : nums)
        {
            if (mp[f] == 0)
                continue;
            int freq = mp[f], curr = f, len = 0;
            while (mp.count(curr) && freq <= mp[curr])
            {
                freq = max(freq, mp[curr]);
                mp[curr]--;
                len++;
                curr++;
            }
            if (len < 3)
                return false;
        }
        return true;
    }
};
// @lc code=end

int main()
{
    Solution k;
    vector<int> vc = {1, 2, 3, 3, 4, 5};
    bool res = k.isPossible(vc);
    cout << "out " << res << endl;
    cout << " * [659] 分割数组为连续子序列" << endl;
}
