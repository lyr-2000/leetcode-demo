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
 * @lc app=leetcode.cn id=1325 lang=cpp
 *
 * [1325] 删除给定值的叶子节点
 *
 * https://leetcode.cn/problems/delete-leaves-with-a-given-value/description/
 *
 * algorithms
 * Medium (73.24%)
 * Likes:    116
 * Dislikes: 0
 * Total Accepted:    18.8K
 * Total Submissions: 25.7K
 * Testcase Example:  '[1,2,3,2,null,2,4]\n2'
 *
 * 给你一棵以 root 为根的二叉树和一个整数 target ，请你删除所有值为 target 的 叶子节点 。
 * 
 * 注意，一旦删除值为 target 的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是 target ，那么这个节点也应该被删除。
 * 
 * 也就是说，你需要重复此过程直到不能继续删除。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：root = [1,2,3,2,null,2,4], target = 2
 * 输出：[1,null,3,null,4]
 * 解释：
 * 上面左边的图中，绿色节点为叶子节点，且它们的值与 target 相同（同为 2 ），它们会被删除，得到中间的图。
 * 有一个新的节点变成了叶子节点且它的值与 target 相同，所以将再次进行删除，从而得到最右边的图。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：root = [1,3,3,3,2], target = 3
 * 输出：[1,3,null,null,2]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：root = [1,2,null,2,null,2], target = 2
 * 输出：[1]
 * 解释：每一步都删除一个绿色的叶子节点（值为 2）。
 * 
 * 示例 4：
 * 
 * 输入：root = [1,1,1], target = 1
 * 输出：[]
 * 
 * 
 * 示例 5：
 * 
 * 输入：root = [1,2,3], target = 1
 * 输出：[1,2,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= target <= 1000
 * 每一棵树最多有 3000 个节点。
 * 每一个节点值的范围是 [1, 1000] 。
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
    bool dfs(TreeNode *root,int x) {
        if(!root) return true;
        bool h = dfs(root->left,x);
        bool l = dfs(root->right,x);
        if (h) root->left = NULL;
        if(l) root->right = NULL;
        if (x == root->val && h && l) {
            return true;
        }
        return false;

    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (dfs(root,target)) {
            return NULL;
        }
        return root;
    }
};
// @lc code=end

int main() {
    cout << " * [1325] 删除给定值的叶子节点" << endl;
    Solution k;
    

    return 0;
}
