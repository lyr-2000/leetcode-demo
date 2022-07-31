/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
#define Node TreeNode
class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        if (!root)
            return;

        Node *prev = NULL, *l = NULL, *r = NULL;
        makeTree(root, prev, l, r);
        swap(l->val, r->val);

        return;
    }

    void makeTree(Node *root, Node *&pre, Node * &l, Node * &r)
    {
        if (!root)
            return;
        makeTree(root->left, pre, l, r);
        if (pre)
        {
            // compare current , pre
            if (root->val < pre->val)
            {
                if (!l)
                    l = pre;
                r = root;
            }
        }
        pre = root;
        makeTree(root->right,pre,l,r);
    }
};
// @lc code=end
