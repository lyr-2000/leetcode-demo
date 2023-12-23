#include<bits/stdc++.h>
using namespace std;

#define print(a) cout << a <<" "
#define printn(a) cout << a << endl
void printa(vector<int> &a) { for(int w:a) print(w); print("\n");}
void printa2(vector<vector<int>> &a) { for (auto f:a) printa(f); }
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }

/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 *
 * [1315] 祖父节点值为偶数的节点和
 *
 * https://leetcode.cn/problems/sum-of-nodes-with-even-valued-grandparent/description/
 *
 * algorithms
 * Medium (81.72%)
 * Likes:    93
 * Dislikes: 0
 * Total Accepted:    19.1K
 * Total Submissions: 23.4K
 * Testcase Example:  '[6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]'
 *
 * 给你一棵二叉树，请你返回满足以下条件的所有节点的值之和：
 * 
 * 
 * 该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。）
 * 
 * 
 * 如果不存在祖父节点值为偶数的节点，那么返回 0 。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 * 输出：18
 * 解释：图中红色节点的祖父节点的值为偶数，蓝色节点为这些红色节点的祖父节点。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在 1 到 10^4 之间。
 * 每个节点的值在 1 到 100 之间。
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int u=0;
        dfs(root,NULL,NULL,u);
        return u;
    }
    void dfs(TreeNode* p, TreeNode *g,TreeNode *x,int &u) {
        if(!p) return;
        if(x) {
            if(x->val % 2 == 0) {
                u+= p->val;
            }
        }
        if(p->left) dfs(p->left,p,g,u);
        if(p->right) dfs(p->right,p,g,u);
    }
};
// @lc code=end

int main() {
    cout << " * [1315] 祖父节点值为偶数的节点和" << endl;
    Solution k;
    
    TreeNode *p = makeTree(vector<int> {6,7,8,2,7,1,3,9,-1,1,4,-1,-1,-1,5});
    printt("-",p,false);
    printn( k.sumEvenGrandparent(p) );
    return 0;
}
