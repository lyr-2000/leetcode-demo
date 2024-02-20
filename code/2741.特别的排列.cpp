#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
#define debug 1
void print() {}
template <typename T>
void echo(const T &t) { cout << t << " "; }
template <typename T>
void echo(vector<T> const &t) {for (auto w: t) echo(w); }
template <typename T>
void echo(vector<vector<T>> const &a) { for (auto f:a) echo(f); }
template<typename Head, typename... Args>
void print(const Head& head, const Args&... args ) { echo(head); print(args...); }
#define println(...) print(__VA_ARGS__),cout <<endl
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
void print(const ListNode *h) { while(h) { print(h->val); h = h->next; } println("");}
void print(const TreeNode *node) { printt("",node,false);}
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makeLinkedList(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
string bin(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }
/* clang-format on */


/*

<!-- @lc app=leetcode.cn id=2741 lang=cpp -->

[leetcode 2741.特别的排列](https://leetcode.cn/problems/special-permutations/description/)


algorithms
Medium (36.58%)
Likes:    38
Dislikes: 0
Total Accepted:    4.6K
Total Submissions: 12.6K
Testcase Example:  '[2,3,6]'

给你一个下标从 0 开始的整数数组 nums ，它包含 n 个 互不相同 的正整数。如果 nums
的一个排列满足以下条件，我们称它是一个特别的排列：


对于 0 <= i < n - 1 的下标 i ，要么 nums[i] % nums[i+1] == 0 ，要么 nums[i+1] % nums[i]
== 0 。


请你返回特别排列的总数目，由于答案可能很大，请将它对 10^9 + 7 取余 后返回。



示例 1：

输入：nums = [2,3,6]
输出：2
解释：[3,6,2] 和 [2,6,3] 是 nums 两个特别的排列。


示例 2：

输入：nums = [1,4,3]
输出：2
解释：[3,1,4] 和 [4,1,3] 是 nums 两个特别的排列。




提示：


2 <= nums.length <= 14
1 <= nums[i] <= 10^9




 */

// @lc code=start
class Solution {
public:
    const int MOD = 1e9 + 7;
    int specialPerm(vector<int>& nums) {
        int maxsize = 15;
        int n = nums.size();
        if(n<=1) return n;
        int all1 = (1<<n) -1;
        vector<vector<int> > dp(1<<n,vector<int>(n,0));
        //f[mask][end] = f[mask][end] + f[prev_mask][prev_end]
        for(int i=0;i<n;i++) dp[0][i] = 1;
        for(int i=1;i<= all1;i++) {
            for(int j=0;j<n;j++) { //父节点
                for(int k=0;k<n;k++) { //子节点
                    if(((i>>k) & 1)>0  && (nums[j] % nums[k] == 0 or nums[k] % nums[j] == 0) ) {
                        dp[i][j] = (dp[i][j] + dp[i ^ (1<<k)][k]) % MOD;
                    }
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++) {
            // 0 1  => 1
            // 1 1  => 0
            // 0 0  => 1
            res = (res + dp[all1 ^ (1<<i)][i] ) % MOD;
        }
        return res;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2741] 特别的排列" << endl;
    #endif

    Solution k;
    vector<int> nums{2,3,6} ;
    cout << k.specialPerm(nums) <<endl;
    return 0;
}
