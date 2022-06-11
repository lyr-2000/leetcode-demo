import java.util.Arrays;
import java.util.LinkedList;

/*
 * @lc app=leetcode.cn id=18 lang=java
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (36.02%)
 * Likes:    294
 * Dislikes: 0
 * Total Accepted:    35.2K
 * Total Submissions: 97.6K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution{ 
public List<List<Integer>> fourSum(int[] nums, int target) {
    List<List<Integer>> ans = new LinkedList<>();
    Arrays.sort(nums);
    int m,r=nums.length-1;
    boolean c = target>0;
    boolean a = target>0&&nums[nums.length-1]<=0;
    boolean b = target<0&&nums[0]>=0;
    if(a||b)
    {
        return ans;
    }
    for(int i=0;i<nums.length;++i)
    {
      
        if(i>0&&nums[i]==nums[i-1]) continue;
   
        for(int l=i+1;l<nums.length;++l)
        {
            if(l>i+1&&nums[l]==nums[l-1]) continue;
           

            m = l+1;
            r = nums.length-1;
            while(m<r)
            {
                
                int t = nums[i] + nums[l] + nums[m]+nums[r];
                if(t==target)
                {
                   
                    List<Integer> res = new LinkedList<>();
                    res.add(nums[i]);
                    res.add(nums[l]);
                    res.add(nums[m]);
                    res.add(nums[r]);
                    ans.add(res);
                    while(m<r&&nums[m]==nums[m+1]) ++m;
                    while(m<r&&nums[r]==nums[r-1])--r;
                    
                    
                    ++m;
                    --r;
                    
                }else if(t>target)
                {
                    r--;

                }else{
                    m++;
                }

                

                

            }
        }
    }

    return ans;
}
}