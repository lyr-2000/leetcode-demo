#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
#define debug 1
#define print(a) cout << a <<" "
#define printn(a) cout << a << endl
template <typename T>
void printa(vector<T> const &a,string fl="") { for(auto w:a) print(w); printn(fl);}
template <typename T>
void printa2(vector<vector<T>> const &a) { for (auto f:a) printa(f); }
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makeLinkedList(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
void printl(ListNode *h) { while(h) { print(h->val); h = h->next; } printn("");}
string bin(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }
/* clang-format on */

/*

<!-- @lc app=leetcode.cn id=14 lang=cpp -->

[leetcode 14.最长公共前缀](https://leetcode.cn/problems/longest-common-prefix/description/)


algorithms
Easy (43.69%)
Likes:    3042
Dislikes: 0
Total Accepted:    1.2M
Total Submissions: 2.8M
Testcase Example:  '["flower","flow","flight"]'

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。



示例 1：


输入：strs = ["flower","flow","flight"]
输出："fl"


示例 2：


输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。



提示：


1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] 仅由小写英文字母组成




 */

// @lc code=start
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string res;
    int n = strs.size();
    if (!n)
      return res;
    if(n==1) return strs[0];
    int col = strs[0].size();
    for (int j = 0; j < col; j++) {
      auto f = strs[0][j];
      for (int i = 1; i < n; i++) {
        auto &d = strs[i];
        if (d.size() <= j)
          return res;
        if (d[j] != f)
          return res;
      }
      res += f;
    }
    return res;
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [14] 最长公共前缀" << endl;
#endif

  Solution k;

  return 0;
}
