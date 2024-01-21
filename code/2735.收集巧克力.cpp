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

<!-- @lc app=leetcode.cn id=2735 lang=cpp -->

[leetcode 2735.收集巧克力](https://leetcode.cn/problems/collecting-chocolates/description/)


algorithms
Medium (54.80%)
Likes:    92
Dislikes: 0
Total Accepted:    16.9K
Total Submissions: 30.7K
Testcase Example:  '[20,1,15]\n5'

给你一个长度为 n、下标从 0 开始的整数数组 nums，nums[i] 表示收集位于下标 i
处的巧克力成本。每个巧克力都对应一个不同的类型，最初，位于下标 i 的巧克力就对应第 i 个类型。

在一步操作中，你可以用成本 x 执行下述行为：


同时修改所有巧克力的类型，将巧克力的类型 i^th 修改为类型 ((i + 1) mod n)^th。


假设你可以执行任意次操作，请返回收集所有类型巧克力所需的最小成本。



示例 1：


输入：nums = [20,1,15], x = 5
输出：13
解释：最开始，巧克力的类型分别是 [0,1,2] 。我们可以用成本 1 购买第 1 个类型的巧克力。
接着，我们用成本 5 执行一次操作，巧克力的类型变更为 [1,2,0] 。我们可以用成本 1 购买第 2 个类型的巧克力。
然后，我们用成本 5 执行一次操作，巧克力的类型变更为 [2,0,1] 。我们可以用成本 1 购买第 0 个类型的巧克力。
因此，收集所有类型的巧克力需要的总成本是 (1 + 5 + 1 + 5 + 1) = 13 。可以证明这是一种最优方案。


示例 2：


输入：nums = [1,2,3], x = 4
输出：6
解释：我们将会按最初的成本收集全部三个类型的巧克力，而不需执行任何操作。因此，收集所有类型的巧克力需要的总成本是 1 + 2 + 3 = 6
。




提示：


1 <= nums.length <= 1000
1 <= nums[i] <= 10^9
1 <= x <= 10^9




 */

// @lc code=start
class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2735] 收集巧克力" << endl;
    #endif

    Solution k;

    return 0;
}
