import java.util.PriorityQueue;

/*
 * @lc app=leetcode.cn id=23 lang=java
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (47.62%)
 * Likes:    358
 * Dislikes: 0
 * Total Accepted:    49.1K
 * Total Submissions: 103.2K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for(ListNode node:lists)
        {
            while(node!=null)
            {
                q.add(node.val);
                node = node.next;
            }
        }
        ListNode ans = new ListNode(0);
        ListNode head = ans;
        while(!q.isEmpty())
        {
            ans.next = new ListNode(q.poll());
            ans = ans.next;
        }
        return head.next;

    }
}
// @lc code=end

