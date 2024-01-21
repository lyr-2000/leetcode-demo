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

<!-- @lc app=leetcode.cn id=2815 lang=cpp -->

[leetcode 2815.数组中的最大数对和](https://leetcode.cn/problems/max-pair-sum-in-an-array/description/)


algorithms
Easy (68.16%)
Likes:    14
Dislikes: 0
Total Accepted:    8K
Total Submissions: 11.8K
Testcase Example:  '[51,71,17,24,42]'

给你一个下标从 0 开始的整数数组 nums 。请你从 nums 中找出和 最大 的一对数，且这两个数数位上最大的数字相等。

返回最大和，如果不存在满足题意的数字对，返回 -1 。



示例 1：

输入：nums = [51,71,17,24,42]
输出：88
解释：
i = 1 和 j = 2 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 71 + 17 = 88 。 
i = 3 和 j = 4 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 24 + 42 = 66 。
可以证明不存在其他数对满足数位上最大的数字相等，所以答案是 88 。

示例 2：

输入：nums = [1,2,3,4]
输出：-1
解释：不存在数对满足数位上最大的数字相等。




提示：


2 <= nums.length <= 100
1 <= nums[i] <= 10^4




 */

// @lc code=start
class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> maxval(10,INT_MIN) ;
        int ans=-1;
        for (int bak: nums) {
            int id = 0;
            int u = bak;
            while(u) {
               id = max(id,u%10) ;
               u/=10;
            }

            ans = max(ans,maxval[id] + bak);
            maxval[id] = max(maxval[id],bak);
        }
        return ans;

    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2815] 数组中的最大数对和" << endl;
    #endif

    Solution k;
    vector<int> nums{51,71,17,24,42} ;
    println(k.maxSum(nums));

    return 0;
}
