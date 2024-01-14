#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
#define debug 1
#define array vector<int> 
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

<!-- @lc app=leetcode.cn id=2895 lang=cpp -->

[leetcode
2895.最小处理时间](https://leetcode.cn/problems/minimum-processing-time/description/)


algorithms
Medium (77.12%)
Likes:    9
Dislikes: 0
Total Accepted:    5.2K
Total Submissions: 6.8K
Testcase Example:  '[8,10]\n[2,2,3,1,8,7,4,5]'

你有 n 颗处理器，每颗处理器都有 4 个核心。现有 n * 4
个待执行任务，每个核心只执行 一个 任务。

给你一个下标从 0 开始的整数数组 processorTime
，表示每颗处理器最早空闲时间。另给你一个下标从 0 开始的整数数组 tasks
，表示执行每个任务所需的时间。返回所有任务都执行完毕需要的 最小时间 。

注意：每个核心独立执行任务。



示例 1：


输入：processorTime = [8,10], tasks = [2,2,3,1,8,7,4,5]
输出：16
解释：
最优的方案是将下标为 4, 5, 6, 7 的任务分配给第一颗处理器（最早空闲时间 time =
8），下标为 0, 1, 2, 3 的任务分配给第二颗处理器（最早空闲时间 time = 10）。
第一颗处理器执行完所有任务需要花费的时间 = max(8 + 8, 8 + 7, 8 + 4, 8 + 5) = 16
。 第二颗处理器执行完所有任务需要花费的时间 = max(10 + 2, 10 + 2, 10 + 3, 10 +
1) = 13 。 因此，可以证明执行完所有任务需要花费的最小时间是 16 。

示例 2：


输入：processorTime = [10,20], tasks = [2,3,1,2,5,8,4,3]
输出：23
解释：
最优的方案是将下标为 1, 4, 5, 6 的任务分配给第一颗处理器（最早空闲时间 time =
10），下标为 0, 2, 3, 7 的任务分配给第二颗处理器（最早空闲时间 time = 20）。
第一颗处理器执行完所有任务需要花费的时间 = max(10 + 3, 10 + 5, 10 + 8, 10 + 4) =
18 。 第二颗处理器执行完所有任务需要花费的时间 = max(20 + 2, 20 + 1, 20 + 2, 20
+ 3) = 23 。 因此，可以证明执行完所有任务需要花费的最小时间是 23 。




提示：


1 <= n == processorTime.length <= 25000
1 <= tasks.length <= 10^5
0 <= processorTime[i] <= 10^9
1 <= tasks[i] <= 10^9
tasks.length == 4 * n




 */

// @lc code=start
class Solution {
public:
  int minProcessingTime(vector<int> &processorTime, vector<int> &tasks) {
    sort(processorTime.begin(), processorTime.end());
    sort(tasks.begin(), tasks.end(), greater<int>());
#ifdef debug
    printa(tasks);
#endif

    int mx = INT_MIN;
    int n = processorTime.size();
    int k = 0;
    for (int i = 0; i < n; i++) {
      mx = max(tasks[i * 4] + processorTime[i], mx);
      // for (int j=0;j<4;j++) {
      //     mx = max(tasks[k]+ processorTime[i],mx);
      //     k += 1;
      // }
    }
    return mx;
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [2895] 最小处理时间" << endl;
#endif

  Solution k;
  array processorTime = {8, 10}, tasks = {2, 2, 3, 1, 8, 7, 4, 5};
  println(k.minProcessingTime(processorTime, tasks));
  return 0;
}
