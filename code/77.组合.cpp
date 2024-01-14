#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
#define debug 1
void print() {}
template<typename Head, typename... Args>
void print(const Head& head, const Args&... args ) { cout << head << " "; print(args...); }
#define println(...) print(__VA_ARGS__),cout <<endl
template <typename T>
void printa(vector<T> const &a,string fl="") { for(auto w:a) print(w); println(fl);}
template <typename T>
void printa(vector<vector<T>> const &a) { for (auto f:a) printa(f); }
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makeLinkedList(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
void printl(ListNode *h) { while(h) { print(h->val); h = h->next; } println("");}
string bin(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }
/* clang-format on */


/*

<!-- @lc app=leetcode.cn id=77 lang=cpp -->

[leetcode 77.组合](https://leetcode.cn/problems/combinations/description/)


algorithms
Medium (77.07%)
Likes:    1570
Dislikes: 0
Total Accepted:    640.6K
Total Submissions: 831.2K
Testcase Example:  '4\n2'

给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。



示例 1：


输入：n = 4, k = 2
输出：
[
⁠ [2,4],
⁠ [3,4],
⁠ [2,3],
⁠ [1,2],
⁠ [1,3],
⁠ [1,4],
]

示例 2：


输入：n = 1, k = 1
输出：[[1]]



提示：


1 
1 




 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int all = (1<<n)-1;
        int s = all;
        vector<vector<int> > res  ;
        do {
            s = (s-1) & all;
            if (countbin(k,s)) {
                res.push_back(makeVec(s,n));
            }

        }while(s != all);
        return res ;
    }
    vector<int> makeVec(int state,int n) {
        vector<int> res ;
        for (int i=0;i<n;i++) {
            if ( state>>i & 1) {
                res.push_back(i+1);
            }
        }
        return res;
    } 
    bool countbin(int k,int state) {
        while(state) {
            state -= state & (-state);
            k--;
            if(k<0) return false;
        }
        return k == 0;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [77] 组合" << endl;
    #endif

    Solution k;
    printa(k.combine(4,2));

    return 0;
}
