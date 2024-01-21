#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
#define debug 1
void print() {}
template <typename T>
void echo(const T &t) { cout << t << " "; }
template <typename T>
void echo(vector<T> const &t) {for (auto w: t) echo(w); }
template <typename T>
void echo(vector<vector<T>> const &a) { for (auto f:a) echo(f); }
template<typename Head, typename... Args>
void print(const Head& head, const Args&... args ) { echo(head); print(args...); }
#define println(...) print(__VA_ARGS__),cout <<endl
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
void echo(const ListNode *h) { while(h) { echo(h->val); h = h->next; } println("");}
void print(const TreeNode *node) { printt("",node,false);}
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makeLinkedList(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
string bin(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }
/* clang-format on */


/*

<!-- @lc app=leetcode.cn id=2816 lang=cpp -->

[leetcode 2816.翻倍以链表形式表示的数字](https://leetcode.cn/problems/double-a-number-represented-as-a-linked-list/description/)


algorithms
Medium (57.46%)
Likes:    19
Dislikes: 0
Total Accepted:    7.3K
Total Submissions: 12.6K
Testcase Example:  '[1,8,9]'

给你一个 非空 链表的头节点 head ，表示一个不含前导零的非负数整数。

将链表 翻倍 后，返回头节点 head 。



示例 1：


输入：head = [1,8,9]
输出：[3,7,8]
解释：上图中给出的链表，表示数字 189 。返回的链表表示数字 189 * 2 = 378 。

示例 2：


输入：head = [9,9,9]
输出：[1,9,9,8]
解释：上图中给出的链表，表示数字 999 。返回的链表表示数字 999 * 2 = 1998 。




提示：


链表中节点的数目在范围 [1, 10^4] 内
0 <= Node.val <= 9
生成的输入满足：链表表示一个不含前导零的数字，除了数字 0 本身。




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
    ListNode* doubleIt(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->val >= 5) {
            head = new ListNode(0,head);
        }
        ListNode *p = head;
        while(p) {
            p->val = p->val *2 %10;
            if(p->next && p->next->val >= 5) {
                p->val ++;
            }
            p=p->next;
        }
        return head;
        
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2816] 翻倍以链表形式表示的数字" << endl;
    #endif

    Solution k;
    auto p=k.doubleIt(makeLinkedList(vector<int>{1,8,9} ));

    print(p);
    return 0;
}
