// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem15.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end() );
        int n = nums.size();
        
        vector< vector<int >> res;
        for(int i=0;i<n;i++) {
            if(nums[i] > 0) break;
            if (i>0 &&nums[i] == nums[i-1]) continue;
            int a= nums[i];

            
            int l = i+1,r = n-1;
            while(l <r ) {
                int b = nums[l],c = nums[r];
                if (a+b+c == 0) {
                    res.push_back({a,b,c});
                    while(l<r && nums[l] == nums[l+1]) ++l;
                    while(l<r && nums[r] == nums[r-1]) --r;
                    
                    
                    ++l;
                }else if (a+b+c>0) {

                    --r;

                }else {
                    //<0
                    ++l;
                }
            }
        }
        return res;
    }
};
// @lc code=end
