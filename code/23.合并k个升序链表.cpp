/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
#define HeapItem pair<int, ListNode *>
#define less(l, r) l.first >= r.first
        struct Compare
        {
            bool operator()(HeapItem &l, HeapItem &r){
                return less(l, r)};
        };
        priority_queue<HeapItem, vector<HeapItem>, Compare> q;
        for (auto lstNode : lists)
        {
            if (lstNode)
                q.push({lstNode->val, lstNode});
        }
        ListNode head;
        ListNode *p = &head;
        while (q.size())
        {
            auto temp = q.top();
            q.pop();
            ListNode *lst = temp.second;
            p->next = lst;
            p = p->next;
            if (lst->next)
            {
                q.push({lst->next->val, lst->next});
            }
        }

        return head.next;
    }
};
// @lc code=end
