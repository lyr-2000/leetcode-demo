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

<!-- @lc app=leetcode.cn id=215 lang=cpp -->

[leetcode
215.数组中的第K个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array/description/)


algorithms
Medium (62.15%)
Likes:    2401
Dislikes: 0
Total Accepted:    984.8K
Total Submissions: 1.6M
Testcase Example:  '[3,2,1,5,6,4]\n2'

给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。



示例 1:


输入: [3,2,1,5,6,4], k = 2
输出: 5


示例 2:


输入: [3,2,3,1,2,4,5,5,6], k = 4
输出: 4



提示：


1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4




 */

// @lc code=start
class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    // 0 1 ,1
    return qselect(nums,0,nums.size()-1,nums.size() - k+1);
  }
  int qselect(vector<int> &nums, int l, int r, int k) {
    if(r<=l) return nums[l];
    int i = l - 1, j = r + 1;
    int piv = nums[(i + j) / 2];
    while (i < j) {
      do
        ++i;
      while (nums[i] < piv);
      do
        --j;
      while (nums[j] > piv);
      if (i < j) {
        swap(nums[i], nums[j]);
      }
    }
    int ranksz = j - l + 1;
    if (k <= ranksz)
      return qselect(nums, l, j, k);
    //     1,1
    return qselect(nums, j + 1, r, k - ranksz);
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [215] 数组中的第K个最大元素" << endl;
#endif

  Solution k;

  return 0;
}
