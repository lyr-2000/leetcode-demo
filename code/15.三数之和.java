import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=15 lang=java
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.13%)
 * Likes:    1430
 * Dislikes: 0
 * Total Accepted:    104.8K
 * Total Submissions: 434.4K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        LinkedList<List<Integer>> ans = new LinkedList<>();
        if(nums.length<3)
        {
            return ans;
        }

        Arrays.sort(nums);
        int m ,r ;
        for(int l=0;l<nums.length;++l)
        {
            if(nums[l]>0) break;
            if(l>0&&nums[l]==nums[l-1]) continue;
            m = l+1;
            r  = nums.length-1;
            while(m<r)
            {
                if(m>l+1&&nums[m]==nums[m-1])
                {
                    ++m;
                }else if(r<nums.length-1&&nums[r]==nums[r+1])
                {
                    --r;
                }else{
                    int d = nums[l]+nums[m]+nums[r];
                    if(d>0)
                    {
                        --r;
                    }else if(d<0)
                    {
                        ++m;
                    }else{
                        LinkedList<Integer> res = new LinkedList<>();
                        res.add(nums[l]);
                        res.add(nums[m++]);
                        res.add(nums[r--]);
                        ans.add(res);
                    }
                }
            }
        }
        return (List)ans;



    }
}
// @lc code=end

