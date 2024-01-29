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

<!-- @lc app=leetcode.cn id=2830 lang=cpp -->

[leetcode 2830.销售利润最大化](https://leetcode.cn/problems/maximize-the-profit-as-the-salesman/description/)


algorithms
Medium (42.39%)
Likes:    46
Dislikes: 0
Total Accepted:    5.9K
Total Submissions: 13.8K
Testcase Example:  '5\n[[0,0,1],[0,2,2],[1,3,2]]'

给你一个整数 n 表示数轴上的房屋数量，编号从 0 到 n - 1 。

另给你一个二维整数数组 offers ，其中 offers[i] = [starti, endi, goldi] 表示第 i 个买家想要以 goldi
枚金币的价格购买从 starti 到 endi 的所有房屋。

作为一名销售，你需要有策略地选择并销售房屋使自己的收入最大化。

返回你可以赚取的金币的最大数目。

注意 同一所房屋不能卖给不同的买家，并且允许保留一些房屋不进行出售。



示例 1：


输入：n = 5, offers = [[0,0,1],[0,2,2],[1,3,2]]
输出：3
解释：
有 5 所房屋，编号从 0 到 4 ，共有 3 个购买要约。
将位于 [0,0] 范围内的房屋以 1 金币的价格出售给第 1 位买家，并将位于 [1,3] 范围内的房屋以 2 金币的价格出售给第 3 位买家。
可以证明我们最多只能获得 3 枚金币。

示例 2：


输入：n = 5, offers = [[0,0,1],[0,2,10],[1,3,2]]
输出：10
解释：有 5 所房屋，编号从 0 到 4 ，共有 3 个购买要约。
将位于 [0,2] 范围内的房屋以 10 金币的价格出售给第 2 位买家。
可以证明我们最多只能获得 10 枚金币。



提示：


1 <= n <= 10^5
1 <= offers.length <= 10^5
offers[i].length == 3
0 <= starti <= endi <= n - 1
1 <= goldi <= 10^3




 */

// @lc code=start
class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        N = n+5;
        a = vector<int>(N,0);
        int res=0;
        for(auto &ve: offers) {
            int l = ve[0]+1, r=ve[1]+1,g = ve[2];
            int cur = query(l-1)+g;
            res = max(res,cur);
            update(r,cur);
        }     
        return res;
    }
    vector<int> a;
    int N;
    int lowbit(int f) {
        return f & -f;
    }
    void update(int idx, int values) { // dp[idx] = max(dp[idx],values)
        for(;idx<N;idx+= lowbit(idx)) {
            a[idx] = max(a[idx],values);
        }
    } 
    int query(int r) { // max{a[k] | 1<=k<=r }
        int res=0;
        for(;r>0; r -= lowbit(r)) {
            res = max(res,a[r]);
        }
        return res;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2830] 销售利润最大化" << endl;
    #endif

    Solution k;
    // offers = [[0,0,1],[0,2,2],[1,3,2]]
    // n = 5


    return 0;
}
