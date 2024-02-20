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

<!-- @lc app=leetcode.cn id=2742 lang=cpp -->

[leetcode
2742.给墙壁刷油漆](https://leetcode.cn/problems/painting-the-walls/description/)


algorithms
Hard (37.12%)
Likes:    38
Dislikes: 0
Total Accepted:    3.4K
Total Submissions: 9.1K
Testcase Example:  '[1,2,3,2]\n[1,2,3,2]'

给你两个长度为 n 下标从 0 开始的整数数组 cost
和 time ，分别表示给 n 堵不同的墙刷油漆需要的开销和时间。你有两名油漆匠：


一位需要
付费 的油漆匠，刷第 i 堵墙需要花费 time[i] 单位的时间，开销为 cost[i] 单位的钱。
一位 免费 的油漆匠，刷
任意 一堵墙的时间为 1 单位，开销为 0 。但是必须在付费油漆匠 工作 时，免费油漆匠才会工作。


请你返回刷完 n 堵墙最少开销为多少。



示例 1：

输入：cost = [1,2,3,2], time = [1,2,3,2]
输出：3
解释：下标为 0 和 1 的墙由付费油漆匠来刷，需要 3
单位时间。同时，免费油漆匠刷下标为 2 和 3 的墙，需要 2 单位时间，开销为 0
。总开销为 1 + 2 = 3 。


示例 2：

输入：cost = [2,3,4,2], time = [1,1,1,1]
输出：4
解释：下标为 0 和 3 的墙由付费油漆匠来刷，需要 2
单位时间。同时，免费油漆匠刷下标为 1 和 2 的墙，需要 2 单位时间，开销为 0
。总开销为 2 + 2 = 4 。




提示：


1 <= cost.length <= 500
cost.length == time.length
1 <= cost[i] <= 10^6
1 <= time[i] <= 500

## 思路 : 选和不选

 */

// @lc code=start
class Solution {
public:
  int paintWalls(vector<int> &cost, vector<int> &time) {
    int n = cost.size();
    if (n <= 0)
      return 0;
    //前N个物品，体积和至少是N，最小化cost 
    //f[i][j]  
    vector<int> dp(n+1,0x3f3f3f3f) ;
    dp[0] = 0;
    for(int i=0;i<n;i++) {
        for (int j=n;j;j--) {
           dp[j] = min(dp[max(j - (time[i]+1),0)] + cost[i],dp[j]);
        }
    }
    return dp[n];

  }
  int paintWalls_DFS(vector<int> &cost, vector<int> &time) {
    int n = cost.size();
    if (n <= 0)
      return 0;
    vector<vector<int>> memo(n, vector<int>(n*2+1, -1));
    function<int(int, int)> dfs = [&](int i, int j) -> int {
      if (j > i)
        return 0;
      if (i < 0)
        return 0x3f3f3f3f;
      if (memo[i][j+n] != -1)
        return memo[i][j+n];
      //   int l = ;
      long long res = 0;
      res = min({1ll * dfs(i - 1, j + time[i]) + cost[i], 1ll * dfs(i - 1, j - 1)});
      return memo[i][j+n] = res;
    };

    return dfs(n - 1, 0);
  }
  // dfs(i,j) -> 0~i面墙 ，免费刷j面墙
  // 付费 dfs(i,j) = dfs(i-1,j+time[i]) + cost[i]
  // free dfs(i,j) = min(dfs(i-1,j+time[i]) + cost[i] , dfs(i-1,j-1))
  /**
  if(j>i) return 0
  */
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [2742] 给墙壁刷油漆" << endl;
#endif

  Solution k;
  vector<int>a{1,2,3,2} ;
  vector<int>b{1,2,3,2} ;
    cout << k.paintWalls(a,b)<<endl;
  return 0;
}
