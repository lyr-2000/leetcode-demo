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

<!-- @lc app=leetcode.cn id=2772 lang=cpp -->

[leetcode
2772.使数组中的所有元素都等于零](https://leetcode.cn/problems/apply-operations-to-make-all-array-elements-equal-to-zero/description/)


algorithms
Medium (37.08%)
Likes:    35
Dislikes: 0
Total Accepted:    5.5K
Total Submissions: 14.9K
Testcase Example:  '[2,2,3,1,1,0]\n3'

给你一个下标从 0 开始的整数数组 nums 和一个正整数 k 。

你可以对数组执行下述操作 任意次 ：


从数组中选出长度为 k 的 任一 子数组，并将子数组中每个元素都 减去 1 。


如果你可以使数组中的所有元素都等于 0 ，返回  true ；否则，返回 false 。

子数组 是数组中的一个非空连续元素序列。



示例 1：

输入：nums = [2,2,3,1,1,0], k = 3
输出：true
解释：可以执行下述操作：
- 选出子数组 [2,2,3] ，执行操作后，数组变为 nums = [1,1,2,1,1,0] 。
- 选出子数组 [2,1,1] ，执行操作后，数组变为 nums = [1,1,1,0,0,0] 。
- 选出子数组 [1,1,1] ，执行操作后，数组变为 nums = [0,0,0,0,0,0] 。


示例 2：

输入：nums = [1,3,1,1], k = 2
输出：false
解释：无法使数组中的所有元素等于 0 。




提示：


1 <= k <= nums.length <= 10^5
0 <= nums[i] <= 10^6




 */

// @lc code=start
class Solution {
public:
  bool checkArray(vector<int> &nums, int k) {
    int n = nums.size();
    if (!n)
      return false;
    vector<int> d(n + 3);
    d[0] = nums[0];
    for (int i = 1; i < n; i++) d[i] = nums[i] - nums[i - 1];
    d[n] = -nums[n - 1];
#ifdef debug

    printa(d);
#endif

    for (int i = 0; i + k <= n; i++) {
      if (d[i] == 0)
        continue;
      if (d[i] < 0) {
        return false;
      }
      int x = d[i];
      d[i] -= x;
      d[i + k] += x;
    }
    for (int i=n-k+1;i<=n;i++) {
        if(d[i]) return false;
    }
    return true;
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [2772] 使数组中的所有元素都等于零" << endl;
#endif

  Solution k;
  vector<int> a = {2, 2, 3, 1, 1, 0};
  println(k.checkArray(a, 3));

  return 0;
}
