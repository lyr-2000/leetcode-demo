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

<!-- @lc app=leetcode.cn id=2897 lang=cpp -->

[leetcode
2897.对数组执行操作使平方和最大](https://leetcode.cn/problems/apply-operations-on-array-to-maximize-sum-of-squares/description/)


algorithms
Hard (57.22%)
Likes:    13
Dislikes: 0
Total Accepted:    2.3K
Total Submissions: 4.1K
Testcase Example:  '[2,6,5,8]\n2'

给你一个下标从 0 开始的整数数组 nums 和一个 正 整数 k 。

你可以对数组执行以下操作 任意次 ：


选择两个互不相同的下标 i 和 j ，同时 将 nums[i] 更新为 (nums[i] AND nums[j])
且将 nums[j] 更新为 (nums[i] OR nums[j]) ，OR 表示按位 或 运算，AND 表示按位
与 运算。


你需要从最终的数组里选择 k 个元素，并计算它们的 平方 之和。

请你返回你可以得到的 最大 平方和。

由于答案可能会很大，将答案对 10^9 + 7 取余 后返回。



示例 1：


输入：nums = [2,6,5,8], k = 2
输出：261
解释：我们可以对数组执行以下操作：
- 选择 i = 0 和 j = 3 ，同时将 nums[0] 变为 (2 AND 8) = 0 且 nums[3] 变为 (2 OR
8) = 10 ，结果数组为 nums = [0,6,5,10] 。
- 选择 i = 2 和 j = 3 ，同时将 nums[2] 变为 (5 AND 10) = 0 且 nums[3] 变为 (5 OR
10) = 15 ，结果数组为 nums = [0,6,0,15] 。 从最终数组里选择元素 15 和 6
，平方和为 15^2 + 6^2 = 261 。 261 是可以得到的最大结果。


示例 2：


输入：nums = [4,5,4,7], k = 3
输出：90
解释：不需要执行任何操作。
选择元素 7 ，5 和 4 ，平方和为 7^2 + 5^2 + 4^2 = 90 。
90 是可以得到的最大结果。




提示：


1 <= k <= nums.length <= 10^5
1 <= nums[i] <= 10^9




 */

// @lc code=start
class Solution {
public:
  int maxSum(vector<int> &nums, int k) {
    int blen = 30;
    // n = nums.size();
    vector<int> cnt(blen, 0);
    for (int x : nums) {
      for (int i = 0; i < blen; i++) {
        cnt[i] += (x >> i) & 1;
      }
    }
    long long ans = 0;
    const int MOD = 1e9+7;
    while (k-- > 0) {
      int x = 0;
      for (int i = 0; i < blen; i++) {
        if (cnt[i]) {
          cnt[i] -= 1;
          x |= 1 << i;
        }
      }
      ans = (ans + (long long)x * x) % MOD;
    }
    return ans;
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [2897] 对数组执行操作使平方和最大" << endl;
#endif

  Solution k;
  int u = 2;
  vector<int> nums = {2, 6, 5, 8};
  println(k.maxSum(nums, u));
  return 0;
}
