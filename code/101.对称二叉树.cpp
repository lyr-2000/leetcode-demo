/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        return testSymmetric(root,root);
    }
    #define Node TreeNode
    bool testSymmetric(Node* l,Node* r) {
        if(l&& r) {
            if(l->val != r->val ) {
                return false;
            }
            return testSymmetric(l->left,r->right) &&
                testSymmetric(l->right,r->left);
        }

        return  l==NULL && r==NULL;
    }
};
// @lc code=end

