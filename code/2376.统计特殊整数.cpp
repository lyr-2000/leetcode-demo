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

<!-- @lc app=leetcode.cn id=2376 lang=cpp -->

[leetcode
2376.统计特殊整数](https://leetcode.cn/problems/count-special-integers/description/)


algorithms
Hard (54.05%)
Likes:    76
Dislikes: 0
Total Accepted:    11.1K
Total Submissions: 20K
Testcase Example:  '20'

如果一个正整数每一个数位都是 互不相同 的，我们称它是 特殊整数 。

给你一个 正 整数 n ，请你返回区间 [1, n] 之间特殊整数的数目。



示例 1：


输入：n = 20
输出：19
解释：1 到 20 之间所有整数除了 11 以外都是特殊整数。所以总共有 19 个特殊整数。


示例 2：


输入：n = 5
输出：5
解释：1 到 5 所有整数都是特殊整数。


示例 3：


输入：n = 135
输出：110
解释：从 1 到 135 总共有 110 个整数是特殊整数。
不特殊的部分数字为：22 ，114 和 131 。



提示：


1 <= n <= 2 * 10^9




## 数位DP原理


n = 1 2  3

f(i,mask)



*/

// @lc code=start
class Solution {
public:
  vector<vector<int>> dp;
  int m;
  string s;
  int f(int i, int mask, bool islimit, bool isnum) { 
    if (i == m) {
        return isnum;
    }
    if(!islimit && isnum && dp[i][mask]>=0) {
        return dp[i][mask];
    }
    int res=0;
    if(!isnum) {
        res = f(i+1,mask,false,false);
    }
    int up = islimit? s[i]-'0': 9;
    for(int j=1-isnum;j<=up;j++) {
        if((mask >> j & 1 )==0) {
           res += f(i+1,mask|(1<<j),islimit && j == up,true) ;
        }
    }
    if(!islimit && isnum)
        dp[i][mask] = res;
    return res;
  }
  int countSpecialNumbers(int n) {
    s = to_string(n);
    m = s.size();
    dp = vector<vector<int>>(m, vector<int>(1 << 10,-1));
    return f(0,0,true,false);
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [2376] 统计特殊整数" << endl;
#endif

  Solution k;

  return 0;
}
