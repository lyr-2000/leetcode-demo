import java.awt.List;
import java.lang.Character.Subset;

/*
 * @lc app=leetcode.cn id=93 lang=java
 *
 * [93] 复原IP地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (45.18%)
 * Likes:    144
 * Dislikes: 0
 * Total Accepted:    16.6K
 * Total Submissions: 36.9K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 * 
 * 示例:
 * 
 * 输入: "25525511135"
 * 输出: ["255.255.11.135", "255.255.111.35"]
 * 
 */

// @lc code=start
class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new LinkedList();
        List<String> carry = new LinkedList();
        backTracking(s,0,carry,ans);
        return ans;
    }

    private void backTracking(String s,int pos,List<String>tmp,List<String> ans)
    {
        if(tmp.size()>=4)
        {
            if(pos==s.length())
            {
                ans.add(String.join(".", tmp));
                
            }
            return;
            
        }

        for(int i=1;i<=3;++i)
        {
            if(pos+i>s.length()) break;
            String tmpString = s.substring(pos, i+pos);
            if((tmpString.startsWith("0")&&tmpString.length()>1)||((i==3&&Integer.valueOf(tmpString)>255)))
            {
                continue;
            }
            tmp.add(tmpString);
            backTracking(s,pos+i,tmp,ans);
            tmp.remove(tmp.size()-1);
        }
        


    }

}
// @lc code=end

