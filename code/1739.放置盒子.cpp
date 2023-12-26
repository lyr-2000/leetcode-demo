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
 * @lc app=leetcode.cn id=1739 lang=cpp
 *
 * [1739] 放置盒子
 *
 * https://leetcode.cn/problems/building-boxes/description/
 *
 * algorithms
 * Hard (64.10%)
 * Likes:    94
 * Dislikes: 0
 * Total Accepted:    13.2K
 * Total Submissions: 20.6K
 * Testcase Example:  '3'
 *
 * 有一个立方体房间，其长度、宽度和高度都等于 n 个单位。请你在房间里放置 n 个盒子，每个盒子都是一个单位边长的立方体。放置规则如下：
 * 
 * 
 * 你可以把盒子放在地板上的任何地方。
 * 如果盒子 x 需要放置在盒子 y 的顶部，那么盒子 y 竖直的四个侧面都 必须 与另一个盒子或墙相邻。
 * 
 * 
 * 给你一个整数 n ，返回接触地面的盒子的 最少 可能数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：n = 3
 * 输出：3
 * 解释：上图是 3 个盒子的摆放位置。
 * 这些盒子放在房间的一角，对应左侧位置。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：n = 4
 * 输出：3
 * 解释：上图是 3 个盒子的摆放位置。
 * 这些盒子放在房间的一角，对应左侧位置。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 
 * 输入：n = 10
 * 输出：6
 * 解释：上图是 10 个盒子的摆放位置。
 * 这些盒子放在房间的一角，对应后方位置。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minimumBoxes(int n) {

    }
};
// @lc code=end

int main() {
    cout << " * [1739] 放置盒子" << endl;
    Solution k;
    

    return 0;
}
