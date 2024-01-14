#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
#define debug 1
void print() {}
template<typename Head, typename... Args>
void print(const Head& head, const Args&... args ) { cout << head << " "; print(args...); }
#define println(...) print(__VA_ARGS__),cout <<endl
template <typename T>
void printa(vector<T> const &a,string fl="") { for(auto w:a) print(w); println(fl);}
template <typename T>
void printa(vector<vector<T>> const &a) { for (auto f:a) printa(f); }
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makeLinkedList(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
void printl(ListNode *h) { while(h) { print(h->val); h = h->next; } println("");}
string bin(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }
/* clang-format on */

/*

<!-- @lc app=leetcode.cn id=2896 lang=cpp -->

[leetcode
2896.执行操作使两个字符串相等](https://leetcode.cn/problems/apply-operations-to-make-two-strings-equal/description/)


algorithms
Medium (31.27%)
Likes:    44
Dislikes: 0
Total Accepted:    3.8K
Total Submissions: 12.1K
Testcase Example:  '"1100011000"\n"0101001010"\n2'

给你两个下标从 0 开始的二进制字符串 s1
和 s2 ，两个字符串的长度都是 n ，再给你一个正整数 x 。

你可以对字符串 s1 执行以下操作 任意次 ：


选择两个下标 i 和 j ，将 s1[i] 和 s1[j] 都反转，操作的代价为 x 。
选择满足 i < n - 1 的下标 i ，反转 s1[i] 和 s1[i + 1] ，操作的代价为 1 。


请你返回使字符串 s1 和 s2 相等的 最小 操作代价之和，如果无法让二者相等，返回 -1 。

注意 ，反转字符的意思是将 0 变成 1 ，或者 1 变成 0 。



示例 1：


输入：s1 = "1100011000", s2 = "0101001010", x = 2
输出：4
解释：我们可以执行以下操作：
- 选择 i = 3 执行第二个操作。结果字符串是 s1 = "1101111000" 。
- 选择 i = 4 执行第二个操作。结果字符串是 s1 = "1101001000" 。
- 选择 i = 0 和 j = 8 ，执行第一个操作。结果字符串是 s1 = "0101001010" = s2 。
总代价是 1 + 1 + 2 = 4 。这是最小代价和。


示例 2：


输入：s1 = "10110", s2 = "00011", x = 4
输出：-1
解释：无法使两个字符串相等。




提示：


n == s1.length == s2.length
1 <= n, x <= 500
s1 和 s2 只包含字符 '0' 和 '1' 。




 */

// @lc code=start
class Solution {
public:
  int count1(string &s, char f = '1') {
    int a = 0;
    for (auto u : s) {
      if (u == f) {
        ++a;
      }
    }
    return a;
  }
  vector<vector<vector<int>>> memo;
//   string s1;
//   string s2;
//   int x;
  int minOperations(string s1, string s2, int x) {
    if (count1(s1) % 2 != count1(s2) % 2) {
      return -1;
    }
    int n = s1.size(), m = s2.size();
    if (n != m)
      return -1;
    // memo = vector<vector<vector<int>>>(
    //     n, vector<vector<int>>(n + 1, vector<int>(2, -1)));
    // int l = dfstree(n - 1, 0, false,s1,s2,x);
    // if (l == INT_MAX)
    //   return -1;
    vector<int> dp ;
    for (int i=0;i<n;i++) {
        if (s1[i] != s2[i]) dp.push_back(i);
    }
    if(dp.size() % 2) return -1;
    int func1=x, func2=0;
    for (int i=1;i<dp.size();i++) {
        int fcost = min(func1 + x, func2 + (dp[i] - dp[i-1]) * 2);
        func2 = func1 ;
        func1 = fcost;
    }
    return func1/2;
  }

  int dfstree(int p, int xcount, bool prev_flip,string &s1,string &s2,int x) {
    #define dfs(p,xcount,prev_flip) dfstree(p,xcount,prev_flip,s1,s2,x)
    if (p < 0) {
      if (xcount || prev_flip)
        return INT_MAX / 2;
      return 0;
    }
    if (memo[p][xcount][prev_flip] > 0) {
      return memo[p][xcount][prev_flip];
    }

    if ((s1[p] == s2[p]) == !prev_flip) {
      return dfs(p - 1, xcount, false);
    }
    // x
    int l = dfs(p - 1, xcount + 1, false) + x;
    int r = dfs(p - 1, xcount, true) + 1;
    int res = min(l, r);
    if (xcount > 0) {
      res = min(res, dfs(p - 1, xcount - 1, false));
    }
    memo[p][xcount][prev_flip] = res;
    return res;
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [2896] 执行操作使两个字符串相等" << endl;
#endif

  Solution k;
  println(k.minOperations("1100011000", "0101001010", 2));
  return 0;
}
