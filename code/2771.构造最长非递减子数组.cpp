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

<!-- @lc app=leetcode.cn id=2771 lang=cpp -->

[leetcode
2771.构造最长非递减子数组](https://leetcode.cn/problems/longest-non-decreasing-subarray-from-two-arrays/description/)


algorithms
Medium (34.79%)
Likes:    27
Dislikes: 0
Total Accepted:    5.7K
Total Submissions: 16.5K
Testcase Example:  '[2,3,1]\n[1,2,1]'

给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，长度均为 n 。

让我们定义另一个下标从 0 开始、长度为 n 的整数数组，nums3 。对于范围 [0, n - 1]
的每个下标 i ，你可以将 nums1[i] 或 nums2[i] 的值赋给 nums3[i] 。

你的任务是使用最优策略为 nums3 赋值，以最大化 nums3 中 最长非递减子数组 的长度。

以整数形式表示并返回 nums3 中 最长非递减 子数组的长度。

注意：子数组 是数组中的一个连续非空元素序列。



示例 1：

输入：nums1 = [2,3,1], nums2 = [1,2,1]
输出：2
解释：构造 nums3 的方法之一是：
nums3 = [nums1[0], nums2[1], nums2[2]] => [2,2,1]
从下标 0 开始到下标 1 结束，形成了一个长度为 2 的非递减子数组 [2,2] 。
可以证明 2 是可达到的最大长度。

示例 2：

输入：nums1 = [1,3,2,1], nums2 = [2,2,3,4]
输出：4
解释：构造 nums3 的方法之一是：
nums3 = [nums1[0], nums2[1], nums2[2], nums2[3]] => [1,2,3,4]
整个数组形成了一个长度为 4 的非递减子数组，并且是可达到的最大长度。


示例 3：

输入：nums1 = [1,1], nums2 = [2,2]
输出：2
解释：构造 nums3 的方法之一是：
nums3 = [nums1[0], nums1[1]] => [1,1]
整个数组形成了一个长度为 2 的非递减子数组，并且是可达到的最大长度。




提示：


1 <= nums1.length == nums2.length == n <= 10^5
1 <= nums1[i], nums2[i] <= 10^9




 */

// @lc code=start
class Solution {
public:
  int maxNonDecreasingLength(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    if (n <= 0)
      return 0;
    vector<vector<int> > memo (n,vector<int>(2,INT_MIN) );
    function<int(int,int)> dfs = [&](int i,int j) -> int {
        if(i==0) return 1;
        if (memo[i][j] != INT_MIN) return memo[i][j];
        int ans = 1;
        int num = j==0?  nums1[i]: nums2[i];
        if(num >= nums1[i-1]) ans = dfs(i-1,0) +1;
        if(num >= nums2[i-1]) ans = max(ans,dfs(i-1,1) + 1);
        return memo[i][j] = ans;
    };
    int res=1;
    for(int start=1;start<n;start++) {
        res = max({res,dfs(start,0),dfs(start,1)});
    }
    return res;
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [2771] 构造最长非递减子数组" << endl;
#endif

  Solution k;
  vector<int> a{ 1,3,2,1  };
  vector<int> b{ 2,2,3,4 };
  cout << k.maxNonDecreasingLength(a, b) << endl;
  return 0;
}
