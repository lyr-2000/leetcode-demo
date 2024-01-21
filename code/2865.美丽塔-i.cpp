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

<!-- @lc app=leetcode.cn id=2865 lang=cpp -->

[leetcode 2865.美丽塔
I](https://leetcode.cn/problems/beautiful-towers-i/description/)


algorithms
Medium (49.24%)
Likes:    12
Dislikes: 0
Total Accepted:    6K
Total Submissions: 12.1K
Testcase Example:  '[5,3,4,1,1]'

给你一个长度为 n 下标从 0 开始的整数数组 maxHeights 。

你的任务是在坐标轴上建 n 座塔。第 i 座塔的下标为 i ，高度为 heights[i] 。

如果以下条件满足，我们称这些塔是 美丽 的：


1 <= heights[i] <= maxHeights[i]
heights 是一个 山脉 数组。


如果存在下标 i 满足以下条件，那么我们称数组 heights 是一个 山脉 数组：


对于所有 0 < j <= i ，都有 heights[j - 1] <= heights[j]
对于所有 i <= k < n - 1 ，都有 heights[k + 1] <= heights[k]


请你返回满足 美丽塔 要求的方案中，高度和的最大值 。



示例 1：


输入：maxHeights = [5,3,4,1,1]
输出：13
解释：和最大的美丽塔方案为 heights = [5,3,3,1,1] ，这是一个美丽塔方案，因为：
- 1 <= heights[i] <= maxHeights[i]
- heights 是个山脉数组，峰值在 i = 0 处。
13 是所有美丽塔方案中的最大高度和。

示例 2：


输入：maxHeights = [6,5,3,9,2,7]
输出：22
解释： 和最大的美丽塔方案为 heights = [3,3,3,9,2,2] ，这是一个美丽塔方案，因为：
- 1 <= heights[i] <= maxHeights[i]
- heights 是个山脉数组，峰值在 i = 3 处。
22 是所有美丽塔方案中的最大高度和。

示例 3：


输入：maxHeights = [3,2,5,5,2,3]
输出：18
解释：和最大的美丽塔方案为 heights = [2,2,5,5,2,2] ，这是一个美丽塔方案，因为：
- 1 <= heights[i] <= maxHeights[i]
- heights 是个山脉数组，最大值在 i = 2 处。
注意，在这个方案中，i = 3 也是一个峰值。
18 是所有美丽塔方案中的最大高度和。




提示：


1 <= n == maxHeights <= 10^3
1 <= maxHeights[i] <= 10^9


下面把 maxHeights\textit{maxHeights}maxHeights 简记为 aaa。

计算从 a[0] 到 a[i]形成山状数组的左侧递增段，元素和最大是多少，记到数组 pre[i]中。
计算从 a[i] 到 a[n−1] 形成山状数组的右侧递减段，元素和最大是多少，记到数组 suf[i] 中。
那么答案就是 pre[i]+suf[i+1]的最大值。

如何计算 pre 和 suf 呢？

作者：灵茶山艾府
链接：https://leetcode.cn/problems/beautiful-towers-i/solutions/2456565/on-qian-hou-zhui-fen-jie-dan-diao-zhan-p-w3g0/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */

// @lc code=start
#define ll long long
class Solution {
public:
  long long maximumSumOfHeights(vector<int> &maxHeights) {
    int n = maxHeights.size();
    if (!n)
      return 0;
    vector<ll> sumleft(n + 1);
    vector<ll> sumright(n+1) ;
    stack<int> s;
    for (int i = 0; i < n; i++) {
      int curr = maxHeights[i];
      while (s.size() && curr < maxHeights[s.top()]) {
        // 把 前面的数变成 curr 然后求和
        s.pop();
      }
      int top = s.empty()? -1: s.top();
      s.push(i);
      sumleft[i+1] = sumleft[top+1] + curr*1ll * (i - top);
    }
    while(s.size()) s.pop();
    for (int i=n-1;i>=0;i--) {
        int curr = maxHeights[i];
        while(s.size() && curr < maxHeights[s.top()]) s.pop();
        //维护一个 从左到右 升序的序列
        int top = s.empty()? n: s.top();
        s.push(i);
        sumright[i] = sumright[top] + curr*1ll * (top - i);
    }
    #ifdef debug 
        println(sumleft);
        println(sumright);
    #endif
    ll maxx = 0;
    for (int i=0;i<n;i++) maxx = max(maxx , sumleft[i] + sumright[i]);
    return maxx;
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [2865] 美丽塔 I" << endl;
#endif

  Solution k;
  vector<int> nums{5,3,4,1,1} ;
  println(k.maximumSumOfHeights(nums));

  return 0;
}
