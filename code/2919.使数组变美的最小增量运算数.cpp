#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
#define debug 1
#define print(a) cout << a <<" "
#define printn(a) cout << a << endl
void printa(vector<int> &a,string fl="") { for(int w:a) print(w); printn(fl);}
void printa2(vector<vector<int>> &a) { for (auto f:a) printa(f); }
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makeLinkedList(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
void printl(ListNode *h) { while(h) { print(h->val); h = h->next; } printn("");}
string bin(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }
/* clang-format on */


/*

<!-- @lc app=leetcode.cn id=2919 lang=cpp -->

[leetcode 2919.使数组变美的最小增量运算数](https://leetcode.cn/problems/minimum-increment-operations-to-make-array-beautiful/description/)


algorithms
Medium (39.07%)
Likes:    34
Dislikes: 0
Total Accepted:    4.1K
Total Submissions: 10.6K
Testcase Example:  '[2,3,0,0,2]\n4'

给你一个下标从 0 开始、长度为 n 的整数数组 nums ，和一个整数 k 。

你可以执行下述 递增 运算 任意 次（可以是 0 次）：


从范围 [0, n - 1] 中选择一个下标 i ，并将 nums[i] 的值加 1 。


如果数组中任何长度 大于或等于 3 的子数组，其 最大 元素都大于或等于 k ，则认为数组是一个 美丽数组 。

以整数形式返回使数组变为 美丽数组 需要执行的 最小 递增运算数。

子数组是数组中的一个连续 非空 元素序列。



示例 1：


输入：nums = [2,3,0,0,2], k = 4
输出：3
解释：可以执行下述递增运算，使 nums 变为美丽数组：
选择下标 i = 1 ，并且将 nums[1] 的值加 1 -> [2,4,0,0,2] 。
选择下标 i = 4 ，并且将 nums[4] 的值加 1 -> [2,4,0,0,3] 。
选择下标 i = 4 ，并且将 nums[4] 的值加 1 -> [2,4,0,0,4] 。
长度大于或等于 3 的子数组为 [2,4,0], [4,0,0], [0,0,4], [2,4,0,0], [4,0,0,4], [2,4,0,0,4]
。
在所有子数组中，最大元素都等于 k = 4 ，所以 nums 现在是美丽数组。
可以证明无法用少于 3 次递增运算使 nums 变为美丽数组。
因此，答案为 3 。


示例 2：


输入：nums = [0,1,3,3], k = 5
输出：2
解释：可以执行下述递增运算，使 nums 变为美丽数组：
选择下标 i = 2 ，并且将 nums[2] 的值加 1 -> [0,1,4,3] 。
选择下标 i = 2 ，并且将 nums[2] 的值加 1 -> [0,1,5,3] 。
长度大于或等于 3 的子数组为 [0,1,5]、[1,5,3]、[0,1,5,3] 。
在所有子数组中，最大元素都等于 k = 5 ，所以 nums 现在是美丽数组。
可以证明无法用少于 2 次递增运算使 nums 变为美丽数组。 
因此，答案为 2 。


示例 3：


输入：nums = [1,1,2], k = 1
输出：0
解释：在这个示例中，只有一个长度大于或等于 3 的子数组 [1,1,2] 。
其最大元素 2 已经大于 k = 1 ，所以无需执行任何增量运算。
因此，答案为 0 。




提示：


3 <= n == nums.length <= 10^5
0 <= nums[i] <= 10^9
0 <= k <= 10^9




 */

// @lc code=start
class Solution {
    /**
    思路： 每个元素选或者不选 
dfs(i,j) 表示nums[i] 右边有 j个数字没选

选择： dfs(i,j) = dfs(i-1,0) + max(k - nums[i], 0)    
不选： dfs(i,j) = dfs(i-1,j+1)

从右到左遍历：
入口： dfs(n-1,0)
    */
public:
#define ll  long long
    long long minIncrementOperations(vector<int>& nums, int k) {
        // int n = nums.size();
        // memo = vector<vector<ll> > (n,vector<ll> (3,-1) ) ;
        // return dfs(nums,n-1,0,k);                
        int n = nums.size();
        // memo = vector<vector<ll> > (n,vector<ll> (3,-1) ) ;
        // return dfs(nums,n-1,0,k);                
        vector<vector<ll> > dp(n+1,vector<ll> (3,0)) ;
        for(int i=0;i<n;i++) {
            for (int j=0 ;j<3 ; j++) {
                dp[i+1][j] = dp[i][0] + max(k-nums[i],0);
                if (j<2) {
                    dp[i+1][j] = min(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[n][0];
    }
    // vector<vector<ll> > memo; 
    // ll dfs(vector<int> &nums ,int i,int j,int k) {
    //     if (i<0) return 0;
    //     if (memo[i][j] != -1) return memo[i][j];
    //     // 选择 
    //     ll res= dfs(nums,i-1,0,k) + max(k - nums[i],0);
    //     if(j < 2) {
    //         // 不选择
    //         res = min(res,dfs(nums,i-1,j+1,k));
    //     }
    //     memo[i][j] = res;
    //     return res;
    // }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2919] 使数组变美的最小增量运算数" << endl;
    #endif

    Solution k;
    vector<int> a = {0,1,3,3};
    print(k.minIncrementOperations(a,5));
    return 0;
}
