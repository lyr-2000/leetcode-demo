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
void print(const ListNode *h) { while(h) { print(h->val); h = h->next; } println("");}
void print(const TreeNode *node) { printt("",node,false);}
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makeLinkedList(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
string bin(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }
/* clang-format on */


/*

<!-- @lc app=leetcode.cn id=1019 lang=cpp -->

[leetcode 1019.链表中的下一个更大节点](https://leetcode.cn/problems/next-greater-node-in-linked-list/description/)


algorithms
Medium (64.49%)
Likes:    326
Dislikes: 0
Total Accepted:    57.5K
Total Submissions: 89.2K
Testcase Example:  '[2,1,5]'

给定一个长度为 n 的链表 head

对于列表中的每个节点，查找下一个 更大节点 的值。也就是说，对于每个节点，找到它旁边的第一个节点的值，这个节点的值 严格大于 它的值。

返回一个整数数组 answer ，其中 answer[i] 是第 i 个节点( 从1开始 )的下一个更大的节点的值。如果第 i
个节点没有下一个更大的节点，设置 answer[i] = 0 。



示例 1：




输入：head = [2,1,5]
输出：[5,5,0]


示例 2：




输入：head = [2,7,4,3,5]
输出：[7,0,5,5,0]




提示：


链表中节点数为 n
1 <= n <= 10^4
1 <= Node.val <= 10^9




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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> s;
        ListNode *p =head;
        int n=0;
        while(p) {
            p=p->next;
            n++;
        }
        vector<int> res(n);
        int i=0;
        while(head) {
            res[i++] = (-head->val);
            head =head->next;
        }
        for (int i=0;i<n;i++) {
            while(s.size() && res[i] < res[s.top()]) {
                int j = s.top();
                s.pop();
                res[j] = -res[i];
            }
            s.push(i);
        }
        for (int i=0;i<n;i++) if(res[i] <0) res[i] =0;
        return res;
         

    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [1019] 链表中的下一个更大节点" << endl;
    #endif

    Solution k;
    println(k.nextLargerNodes(makeLinkedList(vector<int> {2,1,5} )));

    return 0;
}
