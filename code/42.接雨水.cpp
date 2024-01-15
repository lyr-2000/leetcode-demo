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

<!-- @lc app=leetcode.cn id=42 lang=cpp -->

[leetcode 42.接雨水](https://leetcode.cn/problems/trapping-rain-water/description/)


algorithms
Hard (63.21%)
Likes:    4967
Dislikes: 0
Total Accepted:    843.6K
Total Submissions: 1.3M
Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'

给定 n 个非负整数表示每个宽度为 1
的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



示例 1：




输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接
6 个单位的雨水（蓝色部分表示雨水）。


示例 2：


输入：height = [4,2,0,3,2,5]
输出：9




提示：


n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5




 */

// @lc code=start
class Solution {
public:
  int trap(vector<int> &height) {
    stack<int> s;
    int n = height.size();
    if(!n) return 0;
    int area = 0;
    for (int i = 0; i < n; i++) {
      // v 结构, 递减栈
      while (!s.empty() && height[i] > height[s.top()]) {
        int lowh = s.top();
        s.pop();
        if (s.empty())
          break;
        int L = s.top();
        int w = i - L - 1;
        int h = (min(height[i], height[L]) - height[lowh]);
        area += w * h;
      }
      s.push(i);
    }
    return area;
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [42] 接雨水" << endl;
#endif

  Solution k;
  vector<int> a = {4,2,0,3,2,5};
  println(k.trap(a));

  return 0;
}
