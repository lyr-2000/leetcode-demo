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

<!-- @lc app=leetcode.cn id=1673 lang=cpp -->

[leetcode
1673.找出最具竞争力的子序列](https://leetcode.cn/problems/find-the-most-competitive-subsequence/description/)


algorithms
Medium (40.47%)
Likes:    114
Dislikes: 0
Total Accepted:    12.9K
Total Submissions: 31.8K
Testcase Example:  '[3,5,2,6]\n2'

给你一个整数数组 nums 和一个正整数 k ，返回长度为 k 且最具 竞争力 的 nums
子序列。

数组的子序列是从数组中删除一些元素（可能不删除元素）得到的序列。

在子序列 a 和子序列 b 第一个不相同的位置上，如果 a 中的数字小于 b
中对应的数字，那么我们称子序列 a 比子序列 b（相同长度下）更具 竞争力 。
例如，[1,3,4] 比 [1,3,5]
更具竞争力，在第一个不相同的位置，也就是最后一个位置上， 4 小于 5 。



示例 1：


输入：nums = [3,5,2,6], k = 2
输出：[2,6]
解释：在所有可能的子序列集合 {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}
中，[2,6] 最具竞争力。


示例 2：


输入：nums = [2,4,3,3,5,4,9,6], k = 4
输出：[2,3,3,4]




提示：


1
0
1




 */

// @lc code=start
class Solution {
public:
  vector<int> mostCompetitive(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> seq(k);
    int idx = -1;
    for (int i = 0; i < n; i++) {
      while (idx >= 0 && seq[idx] > nums[i] && i < (n - (k - (idx + 1))))
        --idx;
      if (idx + 1 < k)
        seq[++idx] = nums[i];
    }
    return seq;
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [1673] 找出最具竞争力的子序列" << endl;
#endif

  Solution k;
  vector<int> nums{2, 4, 3, 3, 5, 4, 9, 6};
  int n = 4;
  println(k.mostCompetitive(nums, n));
  return 0;
}
