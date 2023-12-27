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
 * @lc app=leetcode.cn id=2923 lang=cpp
 *
 * [2923] 找到冠军 I
 *
 * https://leetcode.cn/problems/find-champion-i/description/
 *
 * algorithms
 * Easy (76.02%)
 * Likes:    7
 * Dislikes: 0
 * Total Accepted:    6.1K
 * Total Submissions: 8.1K
 * Testcase Example:  '[[0,1],[0,0]]'
 *
 * 一场比赛中共有 n 支队伍，按从 0 到  n - 1 编号。
 *
 * 给你一个下标从 0 开始、大小为 n * n 的二维布尔矩阵 grid 。对于满足 0 <= i, j
 * <= n - 1 且 i != j 的所有 i, j ：如果 grid[i][j] == 1，那么 i 队比 j 队 强
 * ；否则，j 队比 i 队 强 。
 *
 * 在这场比赛中，如果不存在某支强于 a 队的队伍，则认为 a 队将会是 冠军 。
 *
 * 返回这场比赛中将会成为冠军的队伍。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：grid = [[0,1],[0,0]]
 * 输出：0
 * 解释：比赛中有两支队伍。
 * grid[0][1] == 1 表示 0 队比 1 队强。所以 0 队是冠军。
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [[0,0,1],[1,0,1],[0,0,0]]
 * 输出：1
 * 解释：比赛中有三支队伍。
 * grid[1][0] == 1 表示 1 队比 0 队强。
 * grid[1][2] == 1 表示 1 队比 2 队强。
 * 所以 1 队是冠军。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == grid.length
 * n == grid[i].length
 * 2 <= n <= 100
 * grid[i][j] 的值为 0 或 1
 * 对于所有 i， grid[i][i] 等于 0.
 * 对于满足 i != j 的所有 i, j ，grid[i][j] != grid[j][i] 均成立
 * 生成的输入满足：如果 a 队比 b 队强，b 队比 c 队强，那么 a 队比 c 队强
 *
 *
 */

// @lc code=start
class Solution {
public:
  int findChampion(vector<vector<int>> &grid) {
    int n = grid.size();
    if (n == 0)
      return 0;
    if (n == 1)
      return 0;
    int m = grid[0].size();
    for (int i = 0; i < m; i++) {
      int ok = false;
      for (int j = 0; j < n; j++) {
        if (grid[j][i] == 1 && j != i) {
          // j > i
          ok = true;
          break;
        }
        // j<=i
      }
      if (!ok) {
        return i;
      }
    }
    return 0;
  }
};
// @lc code=end

int main() {
  cout << " * [2923] 找到冠军 I" << endl;
  Solution k;
  vector<vector<int>> grid = {{0, 0, 1}, {1, 0, 1}, {0, 0, 0}};
  print(k.findChampion(grid));
  return 0;
}
