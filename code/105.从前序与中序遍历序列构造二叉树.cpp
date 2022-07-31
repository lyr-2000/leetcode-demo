/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        if (n != inorder.size())
        {
            return NULL;
        }
        return create(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    Node *create(vector<int> &p, vector<int> &q, int ps, int pe, int is, int ie)
    {
        if (ps > pe)
            return NULL;
        // pre order,in order
        //  根 左右，  左 根右
        Node *root = new Node(p[ps]);
        // left - root - right
        int iroot_pos = is;
        for (int i = is; i <= ie; i++)
        {
            if (q[i] == p[ps])
            {
                iroot_pos = i;
                break;
            }
        }
        int dx = iroot_pos - is;
        root->left = create(p, q, ps + 1, ps + dx, is, iroot_pos - 1);
        root->right = create(p, q, ps + dx + 1, pe, iroot_pos + 1, ie);

        return root;
    }
};
// @lc code=end
