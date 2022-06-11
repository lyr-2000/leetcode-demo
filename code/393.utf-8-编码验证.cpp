/*
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 */

// @lc code=start
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        #define len1 0b10000000
        #define len2 0b11000000
        #define len3 0b11100000
        #define len4 0b11110000
        #define len5 0b11111000
        
        for(int i=0;i<n;i++) {
            int len=0;
            if((data[i] & len1) == 0) {
                len=1; // 第1位是0
            }else if((data[i] & len3) == len2 ) {
                len=2;
            }else if((data[i] & len4) == len3) {
                len=3;
            }else if((data[i] & len5) == len4) {
                len = 4;
            }else return false;
            for(int j=1;j<len;j++) {
                int t=i+j;
                if(t>=n) return false;
                if((data[t] & len2) != len1 ) {
                    return false;
                }
            }
            i+=len-1;   
            
        }
        return true;
    }
    
     
};
// @lc code=end

