/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* result = new(ListNode);
        ListNode fake;
        ListNode *p = &fake;
        int sum = 0;
        while(l1 || l2) {
            auto u = makeNode(l1,l2);
            if (u == NULL) break;
            sum += u->val;
            u->val = sum % 10;
            sum /=10;
            p -> next = u;
            p = p->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;


        }
        if (sum) p->next = new ListNode(sum);


        return fake.next;
    }


    ListNode* makeNode(ListNode *l1,ListNode *l2) {
        if(l1==NULL && l2 == NULL) return NULL ;
        if(l1 && l2) {
            int val = l1->val + l2->val;
            ListNode *p = new ListNode(val);
            return p;
        }
        if(l1) {
            return new ListNode(l1->val);
        }
       
        return new ListNode(l2->val);
    }
};


// @lc code=end

