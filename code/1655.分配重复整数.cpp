#include<bits/stdc++.h>
using namespace std;

#define print(a) cout << a <<" "
void printa2(vector<vector<int>> &a) { int n = a.size(); for (int i = 0; i < n; i++) { for (int j = 0; j < a[i].size(); j++) { print(a[i][j]); } print("\n"); } }
void printa(vector<int> &a) { for(int w:a) print(w); print("\n");}
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }

/*
 * @lc app=leetcode.cn id=1655 lang=cpp
 *
 * [1655] 分配重复整数
 *
 * https://leetcode.cn/problems/distribute-repeating-integers/description/
 *
 * algorithms
 * Hard (39.88%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    4.4K
 * Total Submissions: 11.1K
 * Testcase Example:  '[1,2,3,4]\n[2]'
 *
 * 给你一个长度为 n 的整数数组 nums ，这个数组中至多有 50 个不同的值。同时你有 m 个顾客的订单 quantity ，其中，整数
 * quantity[i] 是第 i 位顾客订单的数目。请你判断是否能将 nums 中的整数分配给这些顾客，且满足：
 * 
 * 
 * 第 i 位顾客 恰好 有 quantity[i] 个整数。
 * 第 i 位顾客拿到的整数都是 相同的 。
 * 每位顾客都满足上述两个要求。
 * 
 * 
 * 如果你可以分配 nums 中的整数满足上面的要求，那么请返回 true ，否则返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,4], quantity = [2]
 * 输出：false
 * 解释：第 0 位顾客没办法得到两个相同的整数。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,3], quantity = [2]
 * 输出：true
 * 解释：第 0 位顾客得到 [3,3] 。整数 [1,2] 都没有被使用。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,1,2,2], quantity = [2,2]
 * 输出：true
 * 解释：第 0 位顾客得到 [1,1] ，第 1 位顾客得到 [2,2] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= n <= 10^5
 * 1 <= nums[i] <= 1000
 * m == quantity.length
 * 1 <= m <= 10
 * 1 <= quantity[i] <= 10^5
 * nums 中至多有 50 个不同的数字。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isok(int ned,int state,vector<int> qu,int m)  
    {
        for (int i=0;i<m;i++) 
        {
            if ((state >> i) & 1) {
                ned -= qu[i];
            }
            if (ned < 0) return false;
        }
        return ned >= 0;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        int m = quantity.size();
        unordered_map<int,int> mp;
        for(auto d: nums ) mp[d]++;
        vector<int> cnt;
        for(auto d: mp ) cnt.push_back(d.second);
        int n= cnt.size();
        vector<vector<bool> > dp(n+1,vector<bool> (1<<m));
        vector<int> sum(1<<m); 
        for (int j=0;j<1<<m;j++) {
            for(int i=0;i< m;i++) {
               if ((j>>i) & 1) {
                 sum[j] += quantity[i];
               }
            }
        }
        for(int i=0;i< n;i++) {
            dp[i][0] = 1;
        }
        for (int i=1;i<=n;i++) {
            // n个物品循环去试
            for (int state = 1; state < (1<<m); state ++) {
                if(dp[i-1][state]) { 
                    dp[i][state] = true;
                    continue;
                }
                for (int sub = state;sub ; sub = (sub-1) & state) {

                    // printf("sub: %d | %d \n",state - sub,state);
                    // 求子集
                    // if(!dp[i-1][state - sub]) continue;
                    if (cnt[i-1] >= sum[sub] && dp[i-1][state - sub]) {
                        dp[i][state] = 1;
                    }
                    // if(isok(cnt[i-1],sub,quantity,m)) 
                    //     dp[i][state] = 1;
                }
            }
        }
        return dp[n][(1<<m)-1];
    }
};
// @lc code=end

int main() {
    cout << " * [1655] 分配重复整数" << endl;
    Solution k;
    vector<int> a = {1,2,3,4,4,1,1,2,2};
    vector<int> b  = {2,2};
    auto f= k.canDistribute(a,b);
    print(f);
    return 0;
}


