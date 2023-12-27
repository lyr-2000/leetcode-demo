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
 * @lc app=leetcode.cn id=2925 lang=cpp
 *
 * [2925] 在树上执行操作以后得到的最大分数
 *
 * https://leetcode.cn/problems/maximum-score-after-applying-operations-on-a-tree/description/
 *
 * algorithms
 * Medium (47.02%)
 * Likes:    22
 * Dislikes: 0
 * Total Accepted:    3.8K
 * Total Submissions: 8.1K
 * Testcase Example:  '[[0,1],[0,2],[0,3],[2,4],[4,5]]\n[5,2,5,2,1,1]'
 *
 * 有一棵 n 个节点的无向树，节点编号为 0 到 n - 1 ，根节点编号为 0 。给你一个长度为 n - 1 的二维整数数组 edges
 * 表示这棵树，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 有一条边。
 * 
 * 同时给你一个长度为 n 下标从 0 开始的整数数组 values ，其中 values[i] 表示第 i 个节点的值。
 * 
 * 一开始你的分数为 0 ，每次操作中，你将执行：
 * 
 * 
 * 选择节点 i 。
 * 将 values[i] 加入你的分数。
 * 将 values[i] 变为 0 。
 * 
 * 
 * 如果从根节点出发，到任意叶子节点经过的路径上的节点值之和都不等于 0 ，那么我们称这棵树是 健康的 。
 * 
 * 你可以对这棵树执行任意次操作，但要求执行完所有操作以后树是 健康的 ，请你返回你可以获得的 最大分数 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：edges = [[0,1],[0,2],[0,3],[2,4],[4,5]], values = [5,2,5,2,1,1]
 * 输出：11
 * 解释：我们可以选择节点 1 ，2 ，3 ，4 和 5 。根节点的值是非 0 的。所以从根出发到任意叶子节点路径上节点值之和都不为 0
 * 。所以树是健康的。你的得分之和为 values[1] + values[2] + values[3] + values[4] + values[5] =
 * 11 。
 * 11 是你对树执行任意次操作以后可以获得的最大得分之和。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [20,10,9,7,4,3,5]
 * 输出：40
 * 解释：我们选择节点 0 ，2 ，3 和 4 。
 * - 从 0 到 4 的节点值之和为 10 。
 * - 从 0 到 3 的节点值之和为 10 。
 * - 从 0 到 5 的节点值之和为 3 。
 * - 从 0 到 6 的节点值之和为 5 。
 * 所以树是健康的。你的得分之和为 values[0] + values[2] + values[3] + values[4] = 40 。
 * 40 是你对树执行任意次操作以后可以获得的最大得分之和。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= n <= 2 * 10^4
 * edges.length == n - 1
 * edges[i].length == 2
 * 0 <= ai, bi < n
 * values.length == n
 * 1 <= values[i] <= 10^9
 * 输入保证 edges 构成一棵合法的树。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        
    }
};
// @lc code=end

int main() {
    cout << " * [2925] 在树上执行操作以后得到的最大分数" << endl;
    Solution k;
    

    return 0;
}
