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

<!-- @lc app=leetcode.cn id=2419 lang=cpp -->

[leetcode 2419.按位与最大的最长子数组](https://leetcode.cn/problems/longest-subarray-with-maximum-bitwise-and/description/)


algorithms
Medium (42.93%)
Likes:    22
Dislikes: 0
Total Accepted:    9.1K
Total Submissions: 21.3K
Testcase Example:  '[1,2,3,3,2,2]'

给你一个长度为 n 的整数数组 nums 。

考虑 nums 中进行 按位与（bitwise AND）运算得到的值 最大 的 非空 子数组。


换句话说，令 k 是 nums 任意 子数组执行按位与运算所能得到的最大值。那么，只需要考虑那些执行一次按位与运算后等于 k 的子数组。


返回满足要求的 最长 子数组的长度。

数组的按位与就是对数组中的所有数字进行按位与运算。

子数组 是数组中的一个连续元素序列。



示例 1：


输入：nums = [1,2,3,3,2,2]
输出：2
解释：
子数组按位与运算的最大值是 3 。
能得到此结果的最长子数组是 [3,3]，所以返回 2 。


示例 2：


输入：nums = [1,2,3,4]
输出：1
解释：
子数组按位与运算的最大值是 4 。 
能得到此结果的最长子数组是 [4]，所以返回 1 。




提示：


1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6




 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=0;
        for(int u:nums)
            if(u>mx) mx = u;
        int res=0,cnt=0;
        for(int w:nums) {
            if(w==mx) {
                cnt++;
                if(cnt > res) res = cnt;
            }else {
                cnt=0;
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2419] 按位与最大的最长子数组" << endl;
    #endif

    Solution k;
    vector<int>  nums{1,2,3,3,2,2};
    println(k.longestSubarray(nums));

    return 0;
}
