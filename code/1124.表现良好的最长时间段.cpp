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

<!-- @lc app=leetcode.cn id=1124 lang=cpp -->

[leetcode 1124.表现良好的最长时间段](https://leetcode.cn/problems/longest-well-performing-interval/description/)


algorithms
Medium (39.53%)
Likes:    515
Dislikes: 0
Total Accepted:    44.9K
Total Submissions: 113.5K
Testcase Example:  '[9,9,6,0,6,6,9]'

给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。

我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。

所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。

请你返回「表现良好时间段」的最大长度。



示例 1：


输入：hours = [9,9,6,0,6,6,9]
输出：3
解释：最长的表现良好时间段是 [9,9,6]。

示例 2：


输入：hours = [6,6,6]
输出：0




提示：


1 <= hours.length <= 10^4
0 <= hours[i] <= 16




 */

// @lc code=start
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        // todo:
        vector<int> s(n+1) ;
        stack<int> st;
        st.push(0);
        for (int i=1;i<=n;i++) {
            s[i] = s[i-1] + (hours[i-1] >8?1:-1);
            if(s[i] < s[st.top()]) {
                st.push(i);
            }
        }
        int maxlen=0;
        for (int j=n;j>0;j--) {
            while(st.size() && s[j] - s[st.top()] > 0) {
                int k = st.top();
                st.pop();
                maxlen = max(maxlen,j-k);
            }
        }
        return maxlen;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [1124] 表现良好的最长时间段" << endl;
    #endif

    Solution k;
    vector<int> nums{9,9,6,0,6,6,9} ;
    println(k.longestWPI(nums));
    return 0;
}
