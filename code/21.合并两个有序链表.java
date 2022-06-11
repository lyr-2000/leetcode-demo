import javax.management.ListenerNotFoundException;

/*
 * @lc app=leetcode.cn id=21 lang=java
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (57.64%)
 * Likes:    661
 * Dislikes: 0
 * Total Accepted:    123.8K
 * Total Submissions: 214.6K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode ans = head;
        ListNode l = l1;
        ListNode r = l2;
        while(l!=null&&r!=null)
        {
            if(l.val>r.val)
            {
                head.next = new ListNode(r.val);
                r = r.next;
            }else{
                head.next = new ListNode(l.val);
                l = l.next;
            }
            head = head.next;
        }
        while(l!=null)
        {
            head.next = new ListNode(l.val);
            head = head.next;
            l = l.next;
        }
        while(r!=null)
        {
            head.next = new ListNode(r.val);
            head = head.next;
            r = r.next;

        }
        return ans.next;
    }
}
// @lc code=end

