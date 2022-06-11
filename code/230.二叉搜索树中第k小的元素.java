import java.util.PriorityQueue;
import java.util.Stack;

/*
 * @lc app=leetcode.cn id=230 lang=java
 *
 * [230] 二叉搜索树中第K小的元素
 *
 * https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (66.30%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    24.8K
 * Total Submissions: 37.3K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * 给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
 * 
 * 说明：
 * 你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
 * 
 * 示例 1:
 * 
 * 输入: root = [3,1,4,null,2], k = 1
 * ⁠  3
 * ⁠ / \
 * ⁠1   4
 * ⁠ \
 * 2
 * 输出: 1
 * 
 * 示例 2:
 * 
 * 输入: root = [5,3,6,2,4,null,null,1], k = 3
 * ⁠      5
 * ⁠     / \
 * ⁠    3   6
 * ⁠   / \
 * ⁠  2   4
 * ⁠ /
 * ⁠1
 * 输出: 3
 * 
 * 进阶：
 * 如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
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
    private int k;
    public int kthSmallest(TreeNode root, int k) {
        Stack<Integer> s = new Stack();
        this.k = k;
        dfs(root,s);
        return s.pop();
        
       



    }

    public void dfs(TreeNode root,Stack<Integer> s)
    {
        if(root==null) return;
        if(root.left!=null)
        {
            dfs(root.left,s);
        }
        if(s.size()>=this.k)
        {
            return;
        }
        s.push(root.val);

        if(root.right!=null)
        {
            dfs(root.right,s);
        }
        

    }
}
// @lc code=end

