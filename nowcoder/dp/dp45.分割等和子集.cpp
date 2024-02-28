/*
描述
给定一个只包含正整数的数组 nums ，请问能否把这个数组取出若干个数使得取出的数之和和剩下的数之和相同。
第一行输入一个正整数 n ，表示数组 nums 的长度。
第二行输入 n 个正整数，表示数组中的值。

4
1 5 11 5

true
*/


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
void printt(const string &prefix, TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
void print(ListNode *h) { while(h) { print(h->val); h = h->next; } println("");}
void print(TreeNode *node) { printt("",node,false);}
TreeNode* maketree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makelist(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
string bin(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }
/* clang-format on */




int main()
{
    int n;
    scanf("%d",&n);
    int total=0;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]); 
        total += a[i];
    }
    if(total % 2!=0) {
        puts("false");
        return 0;
    }
    int mx = (1<<31)-2;
    total /=2;
    vector<int> dp(total,mx);
    dp[0] = 0;
    for(int i=0;i<n;i++) {
        for(int j=total;j>=a[i];j--) {
            dp[j] = min(dp[j-a[i]]+1,dp[j]);
        }
    } 
    if(dp[total] == mx) {
        puts("false");
    }else puts("true");
    return 0;
}

