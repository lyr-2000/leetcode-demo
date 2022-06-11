import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=16 lang=java
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (41.77%)
 * Likes:    273
 * Dislikes: 0
 * Total Accepted:    48.4K
 * Total Submissions: 116K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start

class Solution {

    public int threeSumClosest(int[] nums, int target) {
        
        int m,r;
        int d = Integer.MAX_VALUE;
        int min = Integer.MAX_VALUE;
        Arrays.sort(nums);

        for(int l=0;l<nums.length;++l)
        {
            m = l+1;
            r = nums.length-1;
            while(m<r)
            {
                int t = nums[m]+nums[r]+nums[l];
                if(t==target)
                {
                    return t;
                }else{
                    if(m>l+1&&nums[m]==nums[m-1]) ++m;
                    if(r<nums.length-1&&nums[r]==nums[r-1]) --r;
                    int move = t-target;

                    if(move>0)
                    {
                        r--;

                    }else{
                        m++;
                        move = -move;
                    }

                    
                    if(d>move)
                    {
                        d = move;
                        min = t;
                    }
                    
                }
                    
            } 



        }

        return min;
        
    }


}
// @lc code=end

