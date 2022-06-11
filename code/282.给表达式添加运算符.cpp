/*
 * @lc app=leetcode.cn id=282 lang=cpp
 *
 * [282] 给表达式添加运算符
 */

// @lc code=start
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string path;
        path.resize(100);
        dfs(res,path,0,num,0,0,1,target);
        return res;
    }

    void dfs(vector<string> &res,string &path,int len,string &nums,int cur,long long a,long long b,int target) {
        if(cur>nums.size()) return;
        if(cur == nums.size()) {
            if(target == a) res.push_back(path.substr(0,len-1));
            return;
        }
        long long c=0;
        int n = nums.size();
        for(int i=cur;i<n;i++) {
            c = c*10+(nums[i] - '0');
            path[len++] = nums[i];
            path[len] = '+';
            /*
                 +, a+b*c + ()  a+b+1*(?)
                 -, a+b*c - ()  => a+b -1*(?)
                 *, a+b*c* ()  =>  a+ (b*c)*(?)
            */
            dfs(res,path,len+1,nums,i+1,a+b*c,1,target);
            // dfs(res,path,num,i+1,sum,)
            if(i+1<n) {
                path[len] = '-';
                dfs(res,path,len+1,nums,i+1,a+b*c,-1,target);
                path[len] = '*';
                dfs(res,path,len+1,nums,i+1,a,b*c,target);

            }
            if(nums[cur] == '0') break;
        }   
    }
};
// @lc code=end

