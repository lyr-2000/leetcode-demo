import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=49 lang=java
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (58.63%)
 * Likes:    193
 * Dislikes: 0
 * Total Accepted:    31.7K
 * Total Submissions: 54K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */

// @lc code=start
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,LinkedList<String>> map = new HashMap<>();

        for(String s:strs)
        {
            char[] cs = s.toCharArray();
            Arrays.sort(cs);
            
            String key = String.valueOf(cs);
            LinkedList<String> arr = map.getOrDefault(key,new  LinkedList<String>());
            arr.add(s);
            map.put(key, arr);

        }
         return new LinkedList<>(map.values());



    }
}
// @lc code=end

