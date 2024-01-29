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

<!-- @lc app=leetcode.cn id=2008 lang=cpp -->

[leetcode 2008.出租车的最大盈利](https://leetcode.cn/problems/maximum-earnings-from-taxi/description/)


algorithms
Medium (56.53%)
Likes:    171
Dislikes: 0
Total Accepted:    23.4K
Total Submissions: 41.5K
Testcase Example:  '5\n[[2,5,4],[1,5,1]]'

你驾驶出租车行驶在一条有 n 个地点的路上。这 n 个地点从近到远编号为 1 到 n ，你想要从 1 开到 n
，通过接乘客订单盈利。你只能沿着编号递增的方向前进，不能改变方向。

乘客信息用一个下标从 0 开始的二维数组 rides 表示，其中 rides[i] = [starti, endi, tipi] 表示第 i
位乘客需要从地点 starti 前往 endi ，愿意支付 tipi 元的小费。

每一位 你选择接单的乘客 i ，你可以 盈利 endi - starti + tipi 元。你同时 最多 只能接一个订单。

给你 n 和 rides ，请你返回在最优接单方案下，你能盈利 最多 多少元。

注意：你可以在一个地点放下一位乘客，并在同一个地点接上另一位乘客。



示例 1：

输入：n = 5, rides = [[2,5,4],[1,5,1]]
输出：7
解释：我们可以接乘客 0 的订单，获得 5 - 2 + 4 = 7 元。


示例 2：

输入：n = 20, rides =
[[1,6,1],[3,10,2],[10,12,3],[11,12,2],[12,15,2],[13,18,1]]
输出：20
解释：我们可以接以下乘客的订单：
- 将乘客 1 从地点 3 送往地点 10 ，获得 10 - 3 + 2 = 9 元。
- 将乘客 2 从地点 10 送往地点 12 ，获得 12 - 10 + 3 = 5 元。
- 将乘客 5 从地点 13 送往地点 18 ，获得 18 - 13 + 1 = 6 元。
我们总共获得 9 + 5 + 6 = 20 元。



提示：


1 <= n <= 10^5
1 <= rides.length <= 3 * 10^4
rides[i].length == 3
1 <= starti < endi <= n
1 <= tipi <= 10^5




 */

// @lc code=start
class Solution {
public:
    #define ll long long
    void unique(unordered_map<int,int>&mp ,vector<vector<int>>& rides) {
        set<int> se;
        for(auto &ve: rides) {
            se.insert(ve[0]);
            se.insert(ve[1]);
        }
        int idx=1;
        for(int w:se) {
            mp[w] = idx++;
        }
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        unordered_map<int,int> idxx ;
        unique(idxx,rides);
        N = idxx.size()+6;
        a = vector<ll>(N,0);
        ll res=0;
        for(auto &ve:rides){
            int l = ve[0],r = ve[1], w = r-l+ve[2];
            l=idxx[ve[0]],r = idxx[ve[1]];
            ll getx = query(l) + w;
            res = max(res,getx);
            update(r, getx);
        }
        return res;

    }
    vector<ll> a;
    int N;
    int lowbit(int f) {
        return f & -f;
    }
    ll query(int idx) { // query(r) = Max { a[k] , 1<=k <=idx }, a[k] = range(0,k)
        ll res=0;
        for(;idx; idx-=lowbit(idx)) {
            res = max(res,a[idx]);
        }

        return res;
    }
    void update(int idx,ll value) { // a[idx] = max(a[idx],value)
        for(;idx<N;idx+=lowbit(idx)) {
            a[idx] = max(a[idx],value);
        }
    }

};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2008] 出租车的最大盈利" << endl;
    #endif

    Solution k;

    return 0;
}
