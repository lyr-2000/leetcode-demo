#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
#define print(a) cout << a <<" "
#define printn(a) cout << a << endl
void printa(vector<int> &a) { for(int w:a) print(w); printn("");}
void printa2(vector<vector<int>> &a) { for (auto f:a) printa(f); }
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makeLinkedList(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
void printl(ListNode *h) { while(h) { print(h->val); h = h->next; } printn("");}
string itoa2(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }
/* clang-format on */

/*
 * @lc app=leetcode.cn id=2924 lang=cpp
 *
 * [2924] 找到冠军 II
 *
 * https://leetcode.cn/problems/find-champion-ii/description/
 *
 * algorithms
 * Medium (56.27%)
 * Likes:    5
 * Dislikes: 0
 * Total Accepted:    5.4K
 * Total Submissions: 9.6K
 * Testcase Example:  '3\n[[0,1],[1,2]]'
 *
 * 一场比赛中共有 n 支队伍，按从 0 到  n - 1 编号。每支队伍也是
 * 有向无环图（DAG） 上的一个节点。
 *
 * 给你一个整数 n 和一个下标从 0 开始、长度为 m 的二维整数数组 edges
 * 表示这个有向无环图，其中 edges[i] = [ui, vi] 表示图中存在一条从 ui 队到 vi
 * 队的有向边。
 *
 * 从 a 队到 b 队的有向边意味着 a 队比 b 队 强 ，也就是 b 队比 a 队 弱 。
 *
 * 在这场比赛中，如果不存在某支强于 a 队的队伍，则认为 a 队将会是 冠军 。
 *
 * 如果这场比赛存在 唯一 一个冠军，则返回将会成为冠军的队伍。否则，返回 -1 。
 *
 * 注意
 *
 *
 * 环 是形如 a1, a2, ..., an, an+1 的一个序列，且满足：节点 a1 与节点 an+1
 * 是同一个节点；节点 a1, a2, ..., an 互不相同；对于范围 [1, n] 中的每个 i
 * ，均存在一条从节点 ai 到节点 ai+1 的有向边。 有向无环图
 * 是不存在任何环的有向图。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：n = 3, edges = [[0,1],[1,2]]
 * 输出：0
 * 解释：1 队比 0 队弱。2 队比 1 队弱。所以冠军是 0 队。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：n = 4, edges = [[0,2],[1,3],[1,2]]
 * 输出：-1
 * 解释：2 队比 0 队和 1 队弱。3 队比 1 队弱。但是 1 队和 0
 * 队之间不存在强弱对比。所以答案是 -1 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 100
 * m == edges.length
 * 0 <= m <= n * (n - 1) / 2
 * edges[i].length == 2
 * 0 <= edge[i][j] <= n - 1
 * edges[i][0] != edges[i][1]
 * 生成的输入满足：如果 a 队比 b 队强，就不存在 b 队比 a 队强
 * 生成的输入满足：如果 a 队比 b 队强，b 队比 c 队强，那么 a 队比 c 队强
 *
 *
 */

// @lc code=start
class Solution {
public:
  int findChampion(int n, vector<vector<int>> &edges) {
    vector<int> indeg(n, 0);
    for (auto ve : edges) {
      auto ne = ve[1];
      indeg[ne]++;
      // 入度+1
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
      if (indeg[i] == 0) {
        if (ans != -1)
          return -1;
        ans = i;
      }
    }
    return ans;
  }
};
// @lc code=end

int main() {
  cout << " * [2924] 找到冠军 II" << endl;
  Solution k;
  vector<vector<int>> v = {{0, 2}, {1, 3}, {1, 2}};
  print(k.findChampion(4, v));
  return 0;
}
