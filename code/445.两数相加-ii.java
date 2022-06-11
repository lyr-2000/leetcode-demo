import java.util.ArrayList;

/*
 * @lc app=leetcode.cn id=445 lang=java
 *
 * [445] 两数相加 II
 *
 * https://leetcode-cn.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (51.30%)
 * Likes:    91
 * Dislikes: 0
 * Total Accepted:    8.4K
 * Total Submissions: 16.3K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * 给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
 * 
 * 
 * 
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 * 
 * 进阶:
 * 
 * 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
 * 
 * 示例:
 * 
 * 
 * 输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出: 7 -> 8 -> 0 -> 7
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ArrayList<Integer> l = new ArrayList<>();
        ArrayList<Integer> r = new ArrayList<>();
        while(l1!=null)
        {
            l.add(l1.val);
            l1 = l1.next;
        }
        while(l2!=null)
        {
            r.add(l2.val);
            l2 = l2.next;
        }
        ArrayList<Integer> carry = new ArrayList<>();
        int j = l.size()-1,k = r.size()-1;
        int temp=0;
        while(j>=0||k>=0||temp>0)
        {
            if(j>=0) temp+=l.get(j--);
            if(k>=0) temp+=r.get(k--);
            carry.add(temp%10);
            temp/=10;
        }
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;
        for(int t=carry.size()-1;t>=0;--t)
        {
            cur.next = new ListNode(carry.get(t));
            cur = cur.next;

        }
        return dummy.next;


    }
}
// @lc code=end

