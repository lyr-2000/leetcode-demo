#include<bits/stdc++.h>
using namespace std;

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


/*
 * @lc app=leetcode.cn id=2812 lang=cpp
 *
 * [2812] 找出最安全路径
 *
 * https://leetcode.cn/problems/find-the-safest-path-in-a-grid/description/
 *
 * algorithms
 * Medium (28.01%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    4.4K
 * Total Submissions: 15.7K
 * Testcase Example:  '[[1,0,0],[0,0,0],[0,0,1]]'
 *
 * 给你一个下标从 0 开始、大小为 n x n 的二维矩阵 grid ，其中 (r, c) 表示：
 * 
 * 
 * 如果 grid[r][c] = 1 ，则表示一个存在小偷的单元格
 * 如果 grid[r][c] = 0 ，则表示一个空单元格
 * 
 * 
 * 你最开始位于单元格 (0, 0) 。在一步移动中，你可以移动到矩阵中的任一相邻单元格，包括存在小偷的单元格。
 * 
 * 矩阵中路径的 安全系数 定义为：从路径中任一单元格到矩阵中任一小偷所在单元格的 最小 曼哈顿距离。
 * 
 * 返回所有通向单元格 (n - 1, n - 1) 的路径中的 最大安全系数 。
 * 
 * 单元格 (r, c) 的某个 相邻 单元格，是指在矩阵中存在的 (r, c + 1)、(r, c - 1)、(r + 1, c) 和 (r - 1,
 * c) 之一。
 * 
 * 两个单元格 (a, b) 和 (x, y) 之间的 曼哈顿距离 等于 | a - x | + | b - y | ，其中 |val| 表示 val
 * 的绝对值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [[1,0,0],[0,0,0],[0,0,1]]
 * 输出：0
 * 解释：从 (0, 0) 到 (n - 1, n - 1) 的每条路径都经过存在小偷的单元格 (0, 0) 和 (n - 1, n - 1) 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [[0,0,1],[0,0,0],[0,0,0]]
 * 输出：2
 * 解释：
 * 上图所示路径的安全系数为 2：
 * - 该路径上距离小偷所在单元格（0，2）最近的单元格是（0，0）。它们之间的曼哈顿距离为 | 0 - 0 | + | 0 - 2 | = 2 。
 * 可以证明，不存在安全系数更高的其他路径。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
 * 输出：2
 * 解释：
 * 上图所示路径的安全系数为 2：
 * - 该路径上距离小偷所在单元格（0，3）最近的单元格是（1，2）。它们之间的曼哈顿距离为 | 0 - 1 | + | 3 - 2 | = 2 。
 * - 该路径上距离小偷所在单元格（3，0）最近的单元格是（3，2）。它们之间的曼哈顿距离为 | 3 - 3 | + | 0 - 2 | = 2 。
 * 可以证明，不存在安全系数更高的其他路径。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length == n <= 400
 * grid[i].length == n
 * grid[i][j] 为 0 或 1
 * grid 至少存在一个小偷
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
    }
};
// @lc code=end

int main() {
    cout << " * [2812] 找出最安全路径" << endl;
    Solution k;
    

    return 0;
}
