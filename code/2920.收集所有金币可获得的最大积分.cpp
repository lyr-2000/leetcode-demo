#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
#define debug 1
#define print(a) cout << a <<" "
#define printn(a) cout << a << endl
void printa(vector<int> &a,string fl="") { for(int w:a) print(w); printn(fl);}
void printa2(vector<vector<int>> &a) { for (auto f:a) printa(f); }
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makeLinkedList(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
void printl(ListNode *h) { while(h) { print(h->val); h = h->next; } printn("");}
string bin(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }
/* clang-format on */


/*

<!-- @lc app=leetcode.cn id=2920 lang=cpp -->

[leetcode 2920.收集所有金币可获得的最大积分](https://leetcode.cn/problems/maximum-points-after-collecting-coins-from-all-nodes/description/)


algorithms
Hard (41.70%)
Likes:    10
Dislikes: 0
Total Accepted:    2.7K
Total Submissions: 6.5K
Testcase Example:  '[[0,1],[1,2],[2,3]]\n[10,10,3,3]\n5'

有一棵由 n 个节点组成的无向树，以 0  为根节点，节点编号从 0 到 n - 1 。给你一个长度为 n - 1 的二维 整数 数组 edges
，其中 edges[i] = [ai, bi] 表示在树上的节点 ai 和 bi 之间存在一条边。另给你一个下标从 0 开始、长度为 n 的数组
coins 和一个整数 k ，其中 coins[i] 表示节点 i 处的金币数量。

从根节点开始，你必须收集所有金币。要想收集节点上的金币，必须先收集该节点的祖先节点上的金币。

节点 i 上的金币可以用下述方法之一进行收集：


收集所有金币，得到共计 coins[i] - k 点积分。如果 coins[i] - k 是负数，你将会失去 abs(coins[i] - k)
点积分。
收集所有金币，得到共计 floor(coins[i] / 2) 点积分。如果采用这种方法，节点 i 子树中所有节点 j 的金币数 coins[j]
将会减少至 floor(coins[j] / 2) 。


返回收集 所有 树节点的金币之后可以获得的最大积分。



示例 1：


输入：edges = [[0,1],[1,2],[2,3]], coins = [10,10,3,3], k = 5
输出：11                        
解释：
使用第一种方法收集节点 0 上的所有金币。总积分 = 10 - 5 = 5 。
使用第一种方法收集节点 1 上的所有金币。总积分 = 5 + (10 - 5) = 10 。
使用第二种方法收集节点 2 上的所有金币。所以节点 3 上的金币将会变为 floor(3 / 2) = 1 ，总积分 = 10 + floor(3 /
2) = 11 。
使用第二种方法收集节点 3 上的所有金币。总积分 =  11 + floor(1 / 2) = 11.
可以证明收集所有节点上的金币能获得的最大积分是 11 。 


示例 2：
⁠


输入：edges = [[0,1],[0,2]], coins = [8,4,4], k = 0
输出：16
解释：
使用第一种方法收集所有节点上的金币，因此，总积分 = (8 - 0) + (4 - 0) + (4 - 0) = 16 。




提示：


n == coins.length
2 <= n <= 10^5
0 <= coins[i] <= 10^4
edges.length == n - 1
0 <= edges[i][0], edges[i][1] < n
0 <= k <= 10^4




 */

// @lc code=start
#define ll int
class Solution {
public:

    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        g = vector<vector<int> >(n) ;
        this->k = k;
        for(auto w: edges){ 
            g[w[0]].push_back(w[1]);
            g[w[1]].push_back(w[0]);
        }
        memo = vector<vector<ll> >(n,vector<ll> (14,-1)) ;
        return dfs(0,0,-1,coins);
    }
    vector<vector<int> >g ;
    vector<vector<ll> > memo;
    int k;
    ll dfs(int i, int j,int fa,vector<int> &coins) {
        // if (i == g.size()) return 0;
        auto p = memo[i][j];
        if(p!=-1) return p;
        ll res1 = (coins[i] >> j) - k    ;
        ll res2 = coins[i] >> (j+1);
        for (auto ne: g[i]) {
            if (ne == fa) continue; 
            res1 += dfs(ne,j,i,coins);
            if (j < 13) {
                res2 += dfs(ne,j+1,i,coins);
            }
        }
        memo[i][j] = max(res1,res2);
        return memo[i][j];
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2920] 收集所有金币可获得的最大积分" << endl;
    #endif

    vector<vector<int> >  edges = {{0,1},{1,2},{2,3}};
    vector<int>  coins = {10,10,3,3};
    int k = 5;
    Solution b;
    cout<< to_string(1e5)<<" " << log(1e5)<<endl;
    cout << b.maximumPoints(edges,coins,k)<<endl;
    return 0;
}
