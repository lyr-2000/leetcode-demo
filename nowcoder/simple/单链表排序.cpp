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
void print(ListNode *h) { while(h) { print(h->val); h = h->next; } println("");}
void print(const TreeNode *node) { printt("",node,false);}
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makeLinkedList(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
string bin(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }
/* clang-format on */




/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        if(!head) return NULL;
        // write code here
        
        auto res= sortx(head);
        return res;
    }
    ListNode *link(ListNode*begin,ListNode *p) {
        p->next = begin;
        return p;
    }
    void printlist(ListNode*x,string msg) {
        printf("%s",msg.c_str());
        while(x) {
            printf("%d -> ",x->val);
            x = x->next;
        }
        printf("\n");
    }
    ListNode *calcTarget(ListNode *l ) {
        /*
        auto lmin = l->val,rmax = l->val;
        while(p!=r) {
            if(p->val < lmin) lmin = p->val;
            if(p->val > rmax) rmax = p->val;
            p = p->next;
        }
        return (1ll * lmin+rmax)/2;
        */
        if(l==NULL) return NULL;
        auto p = l->next,q = l;
        while(p && p->next ) {
            p = p->next->next;
            q = q->next;
        }
        return q;
    }
     
    ListNode * sortx(ListNode *l) {
        if(l==NULL||l->next==NULL) return l;
        auto extra = calcTarget(l);
        auto t = extra->next;
        extra->next = NULL;
        auto L = sortx(l);
        auto R = sortx(t);
        ListNode head(0);
        auto p = &head;
        while(L && R) {
            if(L->val <= R->val) {
                p->next = L;
                L=L->next;
            }else {
                p->next = R;
                R=R->next;
            }
            p=p->next;
        }
        if(L) p->next = L;
        else p->next = R;
        return head.next;
    }
};
int main(void) {

    Solution k;
    println(k.sortInList(makeLinkedList({1,3,2,4,5})) );
}