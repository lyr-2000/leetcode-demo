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

<!-- @lc app=leetcode.cn id=2500 lang=cpp -->

[leetcode
2500.删除每行中的最大值](https://leetcode.cn/problems/delete-greatest-value-in-each-row/description/)


algorithms
Easy (83.75%)
Likes:    59
Dislikes: 0
Total Accepted:    32.9K
Total Submissions: 39.3K
Testcase Example:  '[[1,2,4],[3,3,1]]'

给你一个 m x n 大小的矩阵 grid ，由若干正整数组成。

执行下述操作，直到 grid 变为空矩阵：


从每一行删除值最大的元素。如果存在多个这样的值，删除其中任何一个。
将删除元素中的最大值与答案相加。


注意 每执行一次操作，矩阵中列的数据就会减 1 。

返回执行上述操作后的答案。



示例 1：




输入：grid = [[1,2,4],[3,3,1]]
输出：8
解释：上图展示在每一步中需要移除的值。
- 在第一步操作中，从第一行删除 4 ，从第二行删除 3（注意，有两个单元格中的值为 3
，我们可以删除任一）。在答案上加 4 。
- 在第二步操作中，从第一行删除 2 ，从第二行删除 3 。在答案上加 3 。
- 在第三步操作中，从第一行删除 1 ，从第二行删除 1 。在答案上加 1 。
最终，答案 = 4 + 3 + 1 = 8 。


示例 2：




输入：grid = [[10]]
输出：10
解释：上图展示在每一步中需要移除的值。
- 在第一步操作中，从第一行删除 10 。在答案上加 10 。
最终，答案 = 10 。




提示：


m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 100




 */

// @lc code=start
class Solution {
public:
  int deleteGreatestValue(vector<vector<int>> &grid) {
    int n = grid.size();
    for (int i = 0; i < n; i++)
      sort(grid[i].begin(), grid[i].end());
    if(!n) return 0;
    int m = grid[0].size();
    int total=0;
    while(m-->0) {
        int maxval=0;
        for (int i=0;i<n;i++) {
            if(grid[i][m] >maxval)
                maxval = grid[i][m];
        }
        total+= maxval;
    }
    return total;
  }
  int deleteGreatestValueV0(vector<vector<int>> &grid) {
    int n = grid.size();
    if (!n)
      return 0;
    int m = grid[0].size();
    vector<multiset<int>> s(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        s[i].insert(grid[i][j]);
      }
    }
    int all = n * m;
    int total = 0;
    while (true) {
      int maxval = 0;
      for (int i = 0; i < n; i++) {
        if (!s[i].size()) {
          break;
        }
        auto maxvalue = prev(s[i].end());
        int val = *maxvalue;
        s[i].erase(maxvalue);
        if (val > maxval)
          maxval = val;
      }
      total += maxval;
      if (s[0].size() == 0)
        break;
    }
    return total;
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [2500] 删除每行中的最大值" << endl;
#endif

  Solution k;
  vector<vector<int>> grid{{1, 2, 4}, {3, 3, 1}};
  println(k.deleteGreatestValue(grid));
  return 0;
}
