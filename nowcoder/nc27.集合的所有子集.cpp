#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
#define debug 1
void print() {}
template <typename T>
void echo(const T &t) { cout << t << " "; }
template <typename T>
void echo(vector<T> const &t) {for (auto w: t) echo(w);printf("\n"); }
template <typename T>
void echo(vector<vector<T>> const &a) { for (auto f:a) echo(f);printf("\n"); }
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


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param S int整型vector 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > subsets(vector<int>& S) {
        // write code here
        int full = 1<<(S.size());
        //全1 
        vector<vector<int> > res;
        for(int i=0;i<full;i++) {
            res.push_back(make(i,S));
        }
        sort(res.begin(),res.end(),cmp);
        return res;
    }
    static bool cmp(const vector<int> &a,const vector<int>&b  ) {
        if(a.size() != b.size())  return a.size() < b.size();
        // return a<b;
        for(int i=0;i<a.size();i++) {
            if(a[i] != b[i]) return a[i] < b[i];
        }
        return false;
    }
    vector<int> make(int sta,vector<int> &s ) {
        int n = s.size();
        vector<int> res; 
        // println(bin(sta));
        for(int i=0;i<n;i++) {
            if((sta) & (1<<i)) {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};


#ifdef debug



int main()
{
    cout << " * [421] 数组中两个数的最大异或值" << endl;
    Solution k;
    vector<int>  ans = {1,2,3};

    // cout << "result:  " <<  << endl;
    println(k.subsets(ans));
    return 0;
}

#endif