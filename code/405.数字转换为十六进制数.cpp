/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution {
public:
    string toHex(int k) {
        if(!k) return "0";
        string res;
        unsigned int num = k;
        while(num) {
            res += buildNum(num % 16);
            num >>= 4;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    char buildNum(int a) {
        // if(a<0) {
        //     a = (a+16) % 16;
        // }
        if(a>=0 && a<16) {
            if(a<=9) {
                return a+'0';
            }
            //10 -15, a-f
            return a-10 + 'a';
        }
         

        printf("error");


        return '0';
    }
};
// @lc code=end

