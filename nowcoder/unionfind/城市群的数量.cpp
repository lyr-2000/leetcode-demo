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

 


class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param m int整型vector<vector<>>
     * @return int整型
     */
    int citys(vector<vector<int> >& m) {
        // write code here
        int n = m.size();
        initf(n);
        sz.assign(n,1);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a = m[i][j];
                int x = find(i), y = find(j);
                if ( a && x != y && i != j) {
                    p[x] = y;
                    sz[y] += sz[x];
                }
            }
        }
        int ccnt = 0;
        for(int i=0;i<n;i++) {
            int j =  find(i);
            if(sz[j]>0) {
                ccnt+=1;
                sz[j] = -sz[j];
            }
        }
        return ccnt;

    }
    vector<int> p;
    vector<int> sz; 
    int find(int x) {
        int y = p[x];
        if (y != x)
            return p[x] = find(p[x]);
        return y;
    }
    void initf(int x) {
        p.assign(x , 0);
        for (int i = 0; i < x; i++)
            p[i] = i;
    }

};

#ifdef debug


int main() {
    cout << __FILE__ << endl;
    Solution k;
    vector<vector<int> > nums{
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    println(k.citys(nums));
    return 0;
}


#endif
