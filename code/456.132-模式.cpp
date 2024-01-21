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

<!-- @lc app=leetcode.cn id=456 lang=cpp -->

[leetcode 456.132 模式](https://leetcode.cn/problems/132-pattern/description/)


algorithms
Medium (36.44%)
Likes:    808
Dislikes: 0
Total Accepted:    79.5K
Total Submissions: 218.1K
Testcase Example:  '[1,2,3,4]'

给你一个整数数组 nums ，数组中共有 n 个整数。132 模式的子序列 由三个整数 nums[i]、nums[j] 和 nums[k]
组成，并同时满足：i < j < k 和 nums[i] < nums[k] < nums[j] 。

如果 nums 中存在 132 模式的子序列 ，返回 true ；否则，返回 false 。



示例 1：


输入：nums = [1,2,3,4]
输出：false
解释：序列中不存在 132 模式的子序列。


示例 2：


输入：nums = [3,1,4,2]
输出：true
解释：序列中有 1 个 132 模式的子序列： [1, 4, 2] 。


示例 3：


输入：nums = [-1,3,2,0]
输出：true
解释：序列中有 3 个 132 模式的的子序列：[-1, 3, 2]、[-1, 3, 0] 和 [-1, 2, 0] 。




提示：


n == nums.length
1 
-10^9 




 */

// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // i 常数, j,k   , j<k ,and  nums[j] > nums[k]
        // nums[i] < nums[k], 找到 最大的满足要求 的 nums[k]
        stack<int> s;
        int n = nums.size();
        if(n<3) return 0;
        int K = INT_MIN;
        for (int i=n-1;i>=0;i--) {
            if(nums[i] < K) return true;
            // 固定i, (i<j<k), 求  nums[j] > nums[k], 维护一个递减序列 
            while(s.size() && nums[i] > nums[s.top()]) {
                K = nums[s.top()];
                s.pop();
            }
            s.push(i);
        }
         
        return false;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [456] 132 模式" << endl;
    #endif

    Solution k;
    vector<int> nums{1,3,2,4,5,6,7,8,9,10} ;
    println(k.find132pattern(nums));

    return 0;
}
