/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> result ={-1,-1};
        unordered_map<int,int> mp;
        for(int i=0;i< nums.size();i++) {
            int a = target - nums[i];
            if (mp.count(a)) {
                return {mp[a],i};
            }
            mp[nums[i]] = i;
        }
         

            
        


        return {-1,-1};
    }
};
// @lc code=end

