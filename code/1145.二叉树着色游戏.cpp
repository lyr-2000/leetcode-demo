#include<bits/stdc++.h>
using namespace std;

void printa(vector<vector<int>> &a) { int n = a.size(); for (int i = 0; i < n; i++) { for (int j = 0; j < a[i].size(); j++) { cout << a[i][j] << " "; } cout << endl; } }
void print0(vector<int> &a) { for(int w:a) cout << w << " "; }
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* toTreeNode(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }


/*
 * @lc app=leetcode.cn id=1145 lang=cpp
 *
 * [1145] 二叉树着色游戏
 *
 * https://leetcode.cn/problems/binary-tree-coloring-game/description/
 *
 * algorithms
 * Medium (55.37%)
 * Likes:    205
 * Dislikes: 0
 * Total Accepted:    27K
 * Total Submissions: 48.8K
 * Testcase Example:  '[1,2,3,4,5,6,7,8,9,10,11]\n11\n3'
 *
 * 有两位极客玩家参与了一场「二叉树着色」的游戏。游戏中，给出二叉树的根节点 root，树上总共有 n 个节点，且 n 为奇数，其中每个节点上的值从 1 到
 * n 各不相同。
 * 
 * 最开始时：
 * 
 * 
 * 「一号」玩家从 [1, n] 中取一个值 x（1 <= x <= n）；
 * 「二号」玩家也从 [1, n] 中取一个值 y（1 <= y <= n）且 y != x。
 * 
 * 
 * 「一号」玩家给值为 x 的节点染上红色，而「二号」玩家给值为 y 的节点染上蓝色。
 * 
 * 之后两位玩家轮流进行操作，「一号」玩家先手。每一回合，玩家选择一个被他染过色的节点，将所选节点一个 未着色
 * 的邻节点（即左右子节点、或父节点）进行染色（「一号」玩家染红色，「二号」玩家染蓝色）。
 * 
 * 如果（且仅在此种情况下）当前玩家无法找到这样的节点来染色时，其回合就会被跳过。
 * 
 * 若两个玩家都没有可以染色的节点时，游戏结束。着色节点最多的那位玩家获得胜利 ✌️。
 * 
 * 现在，假设你是「二号」玩家，根据所给出的输入，假如存在一个 y 值可以确保你赢得这场游戏，则返回 true ；若无法获胜，就请返回 false 。
 * 
 * 
 * 示例 1 ：
 * 
 * 
 * 输入：root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
 * 输出：true
 * 解释：第二个玩家可以选择值为 2 的节点。
 * 
 * 示例 2 ：
 * 
 * 
 * 输入：root = [1,2,3], n = 3, x = 1
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目为 n
 * 1 <= x <= n <= 100
 * n 是奇数
 * 1 <= Node.val <= n
 * 树中所有值 互不相同
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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode *p = find(root,x);
        if(p==NULL) return false;
        int l=countt(p->left);
        int r = countt(p->right);
        int t = n - 1 - l -r;
     
        // return u >= n/2;
        int w =  max({l,r,t});
        return w > n-w;
    }
    int countt(TreeNode *p) {
        if(p==NULL) return 0;
        return 1+ countt(p->left) + countt(p->right);
    }
    TreeNode* find(TreeNode *root,int val) {
        if (root==NULL) return NULL;
        if(val == root->val) return root;
        TreeNode *l = find(root->left,val);
        if(l) return l;
        return find(root->right,val);
    }
};
// @lc code=end


int main() {
    cout << " * [1145] 二叉树着色游戏" << endl;
    Solution k;
    vector<int> w = {1,2,3} ;
    TreeNode *r = toTreeNode(w);
    printt("",r,false);
    cout << k.btreeGameWinningMove(r,w.size(),2)<<endl;
    return 0;
}
