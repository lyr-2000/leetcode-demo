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

<!-- @lc app=leetcode.cn id=2503 lang=cpp -->

[leetcode 2503.矩阵查询可获得的最大分数](https://leetcode.cn/problems/maximum-number-of-points-from-grid-queries/description/)


algorithms
Hard (44.72%)
Likes:    40
Dislikes: 0
Total Accepted:    4.5K
Total Submissions: 10.2K
Testcase Example:  '[[1,2,3],[2,5,7],[3,5,1]]\n[5,6,2]'

给你一个大小为 m x n 的整数矩阵 grid 和一个大小为 k 的数组 queries 。

找出一个大小为 k 的数组 answer ，且满足对于每个整数 queries[i] ，你从矩阵 左上角 单元格开始，重复以下过程：


如果 queries[i] 严格 大于你当前所处位置单元格，如果该单元格是第一次访问，则获得 1 分，并且你可以移动到所有 4
个方向（上、下、左、右）上任一 相邻 单元格。
否则，你不能获得任何分，并且结束这一过程。


在过程结束后，answer[i] 是你可以获得的最大分数。注意，对于每个查询，你可以访问同一个单元格 多次 。

返回结果数组 answer 。



示例 1：


输入：grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
输出：[5,8,1]
解释：上图展示了每个查询中访问并获得分数的单元格。

示例 2：


输入：grid = [[5,2,1],[1,1,2]], queries = [3]
输出：[0]
解释：无法获得分数，因为左上角单元格的值大于等于 3 。




提示：


m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 10^5
k == queries.length
1 <= k <= 10^4
1 <= grid[i][j], queries[i] <= 10^6




 */

// @lc code=start
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2503] 矩阵查询可获得的最大分数" << endl;
    #endif

    Solution k;

    return 0;
}
