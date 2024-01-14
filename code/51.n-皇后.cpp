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

<!-- @lc app=leetcode.cn id=51 lang=cpp -->

[leetcode 51.N 皇后](https://leetcode.cn/problems/n-queens/description/)


algorithms
Hard (73.94%)
Likes:    2007
Dislikes: 0
Total Accepted:    359.3K
Total Submissions: 485.8K
Testcase Example:  '4'

按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

n 皇后问题 研究的是如何将 n 个皇后放置在 n×n
的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。



每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.'
分别代表了皇后和空位。



示例 1：


输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。


示例 2：


输入：n = 1
输出：[["Q"]]




提示：


1 <= n <= 9






 */

// @lc code=start
class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<int> row;
    dfs(row, 0, n);
    return res;
  }
  unordered_set<int> col,d1,d2;
  vector<vector<string>> res;
  void dfs(vector<int> &row, int k, int n) {
    if (k == n) {
      vector<string> tmp;
      for (int u : row) {
        string s(n, '.');
        s[u] = 'Q';
        tmp.push_back(s);
      }
      res.push_back(tmp);
      return;
    }
    for (int i = 0; i < n; i++) {
        if (col.count(i)) {
            continue;
        }
        if (d1.count(k+i) ){
            continue;
        }
        if (d2.count(k-i)) {
            continue;
        }
        col.insert(i);
        d1.insert(k+i);
        d2.insert(k-i);
        row.push_back(i);
        dfs(row,k+1,n);
        row.pop_back();
        col.erase(i);
        d1.erase(k+i);
        d2.erase(k-i);
    }
    return;
  }
  bool canput(int prev, int idx) {
   
    return true;
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [51] N 皇后" << endl;
#endif

  Solution k;
  printa(k.solveNQueens(4));
  return 0;
}
