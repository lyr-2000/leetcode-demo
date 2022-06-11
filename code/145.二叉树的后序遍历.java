import java.util.LinkedList;
import java.util.Stack;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode.cn id=145 lang=java
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (68.12%)
 * Likes:    183
 * Dislikes: 0
 * Total Accepted:    35.7K
 * Total Submissions: 52.2K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        // LinkedList<Integer> arr = new LinkedList<>();
        if(root==null) return new LinkedList();
        return (List<Integer>)getList(root);
    }

    // private void dfs(TreeNode root,LinkedList<Integer> list)
    // {
    //     if(root==null) return;
    //     if(root.left!=null) dfs(root.left,list);


    //     if(root.right!=null) dfs(root.right,list);
    //     list.addLast(root.val);
    // }
    
    private LinkedList<Integer> getList(TreeNode root)
    {
        Stack<TreeNode> s = new Stack<>();
        LinkedList<Integer> ans = new LinkedList<>();
        s.push(root);

        while(!s.isEmpty())
        {
            TreeNode tmp = s.pop();
            ans.addFirst(tmp.val);
            if(tmp.left!=null) s.push(tmp.left);
            if(tmp.right!=null) s.push(tmp.right);
            
            
        }
        

        return ans;

    }



}
// @lc code=end

