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
   * 递增路径的最大长度
   * @param matrix int整型vector<vector<>> 描述矩阵的每个数
   * @return int整型
   */
  int solve(vector<vector<int>> &a) {
    // write code here
    int n = a.size();
    if (!n)
      return 0;
    int m = a[0].size();
    if (!m)
      return 0;
    int ans=0;
    vector<vector<int> > tmp(n,vector<int>(m,-1) );
    for(int i=0;i<n;i++) 
      for(int j=0;j<m;j++)
        ans = max(ans,dfs(a,tmp,i,j,n,m));
    return ans;
  }
  bool cmp(vector<vector<int> > &a,int val,int x,int y ) {
    int n = a.size();
    int m = a[0].size();
    if(x<0||x>=n || x<0 || y >= m) return false;
    return val > a[x][y];
  }
  int dfs(vector<vector<int> > &map,vector<vector<int> > &len,int i,int j,int n,int m ) {
    if(i<0||i>=n || j<0 || j >= m) return 0;
    if(len[i][j]!=-1) return len[i][j];
    vector<vector<int> >  dir{
      {-1,0},{1,0},{0,-1},{0,1}
    };
    for(auto &a : dir) {
      int x = i+a[0],y = j+a[1];
      if(cmp(map,map[i][j],x,y))
        len[i][j] = max(len[i][j],dfs(map,len,x,y,n,m)+1);
    }
    len[i][j] = max(len[i][j],1);
    return len[i][j];
  }
};

#ifdef debug

int main() {
  cout << __FILE__ << endl;
  Solution k;
  vector<vector<int> > nums{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  println(k.solve(nums));
  return 0;
}

#endif