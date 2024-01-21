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

<!-- @lc app=leetcode.cn id=2849 lang=cpp -->

[leetcode 2849.判断能否在给定时间到达单元格](https://leetcode.cn/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/)


algorithms
Medium (25.50%)
Likes:    16
Dislikes: 0
Total Accepted:    6.4K
Total Submissions: 25.1K
Testcase Example:  '2\n4\n7\n7\n6'

给你四个整数 sx、sy、fx、fy  以及一个 非负整数 t 。

在一个无限的二维网格中，你从单元格 (sx, sy) 开始出发。每一秒，你 必须 移动到任一与之前所处单元格相邻的单元格中。

如果你能在 恰好 t 秒 后到达单元格 (fx, fy) ，返回 true ；否则，返回  false 。

单元格的 相邻单元格 是指该单元格周围与其至少共享一个角的 8 个单元格。你可以多次访问同一个单元格。



示例 1：


输入：sx = 2, sy = 4, fx = 7, fy = 7, t = 6
输出：true
解释：从单元格 (2, 4) 开始出发，穿过上图标注的单元格，可以在恰好 6 秒后到达单元格 (7, 7) 。 


示例 2：


输入：sx = 3, sy = 1, fx = 7, fy = 3, t = 3
输出：false
解释：从单元格 (3, 1) 开始出发，穿过上图标注的单元格，至少需要 4 秒后到达单元格 (7, 3) 。 因此，无法在 3 秒后到达单元格 (7,
3) 。




提示：


1 <= sx, sy, fx, fy <= 10^9
0 <= t <= 10^9




 */

// @lc code=start
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
       if(sx ==fx && fy == sy) 
        return t>1||t<=0 ;
       return max(abs(fx-sx),abs(sy-fy)) <=t;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2849] 判断能否在给定时间到达单元格" << endl;
    #endif

    Solution k;

    return 0;
}
