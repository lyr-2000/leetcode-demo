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

<!-- @lc app=leetcode.cn id=2866 lang=cpp -->

[leetcode 2866.美丽塔 II](https://leetcode.cn/problems/beautiful-towers-ii/description/)


algorithms
Medium (45.93%)
Likes:    123
Dislikes: 0
Total Accepted:    16K
Total Submissions: 34.9K
Testcase Example:  '[5,3,4,1,1]'

给你一个长度为 n 下标从 0 开始的整数数组 maxHeights 。

你的任务是在坐标轴上建 n 座塔。第 i 座塔的下标为 i ，高度为 heights[i] 。

如果以下条件满足，我们称这些塔是 美丽 的：


1 <= heights[i] <= maxHeights[i]
heights 是一个 山脉 数组。


如果存在下标 i 满足以下条件，那么我们称数组 heights 是一个 山脉 数组：


对于所有 0 < j <= i ，都有 heights[j - 1] <= heights[j]
对于所有 i <= k < n - 1 ，都有 heights[k + 1] <= heights[k]


请你返回满足 美丽塔 要求的方案中，高度和的最大值 。



示例 1：


输入：maxHeights = [5,3,4,1,1]
输出：13
解释：和最大的美丽塔方案为 heights = [5,3,3,1,1] ，这是一个美丽塔方案，因为：
- 1 <= heights[i] <= maxHeights[i]  
- heights 是个山脉数组，峰值在 i = 0 处。
13 是所有美丽塔方案中的最大高度和。

示例 2：


输入：maxHeights = [6,5,3,9,2,7]
输出：22
解释： 和最大的美丽塔方案为 heights = [3,3,3,9,2,2] ，这是一个美丽塔方案，因为：
- 1 <= heights[i] <= maxHeights[i]
- heights 是个山脉数组，峰值在 i = 3 处。
22 是所有美丽塔方案中的最大高度和。

示例 3：


输入：maxHeights = [3,2,5,5,2,3]
输出：18
解释：和最大的美丽塔方案为 heights = [2,2,5,5,2,2] ，这是一个美丽塔方案，因为：
- 1 <= heights[i] <= maxHeights[i]
- heights 是个山脉数组，最大值在 i = 2 处。
注意，在这个方案中，i = 3 也是一个峰值。
18 是所有美丽塔方案中的最大高度和。




提示：


1 <= n == maxHeights <= 10^5
1 <= maxHeights[i] <= 10^9




 */

// @lc code=start
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& nums) {
        #define ll long long
        int n = nums.size();
        if(!n) return 0;
        stack<ll> s;
        vector<ll> suml(n+1),sumr(n+1) ;
        for (int i=0;i<n;i++) {
            while(s.size() && nums[i] < nums[s.top()]) {
                s.pop();
            }
            int j = -1;
            if(s.size()) j=s.top();
            suml[i+1] = nums[i]*1ll * (i-j) + suml[j+1];
            s.push(i);
        }
        
        while(s.size()) s.pop();

        for (int i=n-1;i>=0;i--) {
            while(s.size() && nums[i] < nums[s.top()] ) {
                s.pop();
            }
            int j = n;
            if(s.size()) j=s.top();
            sumr[i] = nums[i]*1ll * (j-i) + sumr[j];
            s.push(i);
        }

        #ifdef debug
        println(sumr);
        
        #endif
        ll maxx=0;
        for (int i=0;i<n;i++) maxx = max(maxx, suml[i] + sumr[i]);

        return maxx;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2866] 美丽塔 II" << endl;
    #endif

    Solution k;
vector<int> nums{5,3,4,1,1} ;
println(k.maximumSumOfHeights(nums));
    return 0;
}
