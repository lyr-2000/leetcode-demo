import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=131 lang=java
 *
 * [131] 分割回文串
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (64.05%)
 * Likes:    176
 * Dislikes: 0
 * Total Accepted:    15.1K
 * Total Submissions: 23.6K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 
 * 返回 s 所有可能的分割方案。
 * 
 * 示例:
 * 
 * 输入: "aab"
 * 输出:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 */

// @lc code=start
class Solution {

    private boolean check(String s)
    {
        int l=0,r=s.length()-1;
        while(l<r)
        {
            if(s.charAt(l)!=s.charAt(r))
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    private void backTrack(List<List<String>> res,String s,ArrayList<String> tmp)
    {
        if(s==null||s.length()==0) res.add(new ArrayList<>(tmp));
        for(int i=1;i<=s.length();++i)
        {
            String temp = s.substring(0,i);
            if(check(temp))
            {
                tmp.add(temp);
                backTrack(res, s.substring(i,s.length()), tmp);
                tmp.remove(tmp.size()-1);
            }
        }
    }


    public List<List<String>> partition(String s) {
        List<List<String>> res = new LinkedList();
        backTrack(res, s, new ArrayList<>());
        return res;
    }
}
// @lc code=end

