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
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */
    int solve(string s) {
        // write code here
        int n = s.size();
        int i=0;
        stack<char>op;
        stack<int> sk;
        unordered_map<char,int> f ;
        f['+'] = f['-'] = 1;
        f['*'] = f['/'] =2;
        while(i<n) {
            if(s[i]==' '){
                i++;
                continue;
            }
            if(s[i] == '(') {
                op.push(s[i++]);
            }else if(s[i] == ')') {
                while(op.size() && op.top() != '(' && f[op.top()] >= f[s[i]]) 
                    sk.push(todo(sk,op));
                if(op.top() == '(')
                    op.pop();
                i++;
            }else if(s[i]>='0' && s[i]<='9') {
                int val = eat(s,i);
                sk.push(val);
            }else {
                if(i==0) sk.push(0);
                while(op.size() && op.top() != '(' && f[op.top()] >= f[s[i]]) 
                    sk.push(todo(sk,op));
                op.push(s[i++]);
            }
        }
        while(op.size())
            sk.push(todo(sk,op));
        return sk.top();
    }
    int todo(stack<int> &sk,stack<char> &op) {
        int a = sk.top();sk.pop();
        int b = sk.top();sk.pop();
        char p = op.top();op.pop();
        printf("%d %c %d\n",b,p,a);
        switch (p) {
            case '+': return b+a;
            case '-': return b-a;
            case '*': return b*a;
            case '/': return b/a;
            case '(': {
                puts("error");
            }
        }
        return -1;
    }
    int eat(string &s,int &i) {
        int val = 0;
        while(s[i]>='0' && s[i]<='9')
        {
            val = val*10 + (s[i++]-'0');
        }
        return val;
    }
};

#ifdef debug


int main()
{
    cout << " * " << endl;
    Solution k;
    auto arr = {1, 2, 3, 3, 5};
    cout << "result:  " << k.solve("3+2*3*4-1") << endl;
    return 0;
}


#endif