
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
  题解: https://www.nowcoder.com/discuss/589593953008091136
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   * find median in two sorted array
   * @param arr1 int整型vector the array1
   * @param arr2 int整型vector the array2
   * @return int整型
   */

  int findMedianinTwoSortedAray(vector<int> &arr1, vector<int> &arr2) {
    int n = arr1.size(), m = arr2.size();
    if (n != m)
      return -1;
    if(n==0) return 0;
    if(n==1) return min(arr1[0],arr2[0]);
    int l = 0,r =n-1,x=0,y = n-1;
    while(l<r) {
        int even = (r-l) % 2 !=0;//偶数为1，奇数为0 ,例如{0,1} => 1-0=1 % 2 != 0
        int m = l+(r-l)/2;
        int m2 = x+(y-x)/2;
        if(arr1[m] == arr2[m2])
             return arr1[m];
        else if(arr1[m] < arr2[m2]) {
            l = m+even; //长度为偶数的子区间中值后一位才是右半部分的起点
            y = m2;
        }else {
            r = m;
            x = m2 + even;
        }
    }
    return min(arr1[l],arr2[x]);
  }

  int _findMedianinTwoSortedAray(vector<int> &arr1, vector<int> &arr2) {
    // write code here
    int n = arr1.size(), m = arr2.size();
    int total = n + m;
    int K = (total / 2);
    // if(total %2==0) K++;
    // println("K",K);
    //第K个最大数
    priority_queue<int> q;
    int l = 0, r = 0;
    while (q.size() < K) {
      if (arr1[l] <= arr2[r]) {
        q.push(arr1[l++]);
      } else {
        q.push(arr2[r++]);
      }
    }
    // if(total % 2==0) {
    //     int l = q.top(),q.pop();
    //     return (l+q.top()) /2;
    // }
    return q.top();
  }
};

#ifdef debug

int main(void) {

  Solution k;
  vector<int> a{1,9,19};
  vector<int> b{2,5,10};
  //   1 2 3  (3 4) 4 5 6
  println(k.findMedianinTwoSortedAray(a, b));
}

#endif
