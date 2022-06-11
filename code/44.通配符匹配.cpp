/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 *
 * https://leetcode.cn/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (33.23%)
 * Likes:    878
 * Dislikes: 0
 * Total Accepted:    105.9K
 * Total Submissions: 318.6K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
 * 
 * '?' 可以匹配任何单个字符。
 * '*' 可以匹配任意字符串（包括空字符串）。
 * 
 * 
 * 两个字符串完全匹配才算匹配成功。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "*"
 * 输出: true
 * 解释: '*' 可以匹配任意字符串。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "cb"
 * p = "?a"
 * 输出: false
 * 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
 * 
 * 
 * 示例 4:
 * 
 * 输入:
 * s = "adceb"
 * p = "*a*b"
 * 输出: true
 * 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "acdcb"
 * p = "a*c?b"
 * 输出: false
 * 
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
       int n = s.size(), m = p.size();
       
       int i=0,j=0;
       int wildcard = -1;
       int last = 0;
       while(i< n) {
           if(s[i] == p[j] || p[j] == '?') {
               i++;j++;
               continue;
           }
           if (p[j] == '*') {
               //wildcard
               wildcard = j++; // not match , and  test  p[i] is match p[j+1] 
               last = i;
               continue;
           }
           //not match any
           if(wildcard!=-1) {//无法匹配，就回溯到 上一个 * 
               j =wildcard+1;
               i = ++last; //假设 p[wildcard] 和 s[last] 匹配，那么就 继续 test  p[wildcard] 和 s[last+1]
               continue;
           }
           // 找不到
           return false;
       }
       while(j<m && p[j] == '*')  j++;
       return j == m;
    }
};
// @lc code=end

