/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int w = height.size();
        int l=0,r = w-1;
        int expect = 0;
        int calc_area=0;
        while(l<r) {
            calc_area = (r-l) * min(height[l],height[r]);
            if(expect < calc_area) {
                expect = calc_area;
            }
            if(height[l] >= height[r]) --r;
            else l++;
        }

        return expect;
    }
};
// @lc code=end

