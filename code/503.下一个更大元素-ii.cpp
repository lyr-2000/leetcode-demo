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

<!-- @lc app=leetcode.cn id=503 lang=cpp -->

[leetcode 503.下一个更大元素 II](https://leetcode.cn/problems/next-greater-element-ii/description/)


algorithms
Medium (67.23%)
Likes:    906
Dislikes: 0
Total Accepted:    226.2K
Total Submissions: 336.4K
Testcase Example:  '[1,2,1]'

给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的
下一个更大元素 。

数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1
。



示例 1:


输入: nums = [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数； 
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。


示例 2:


输入: nums = [1,2,3,4,3]
输出: [2,3,4,-1,4]




提示:


1 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9




 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if(!n) return {};
        // vector<int> nums(n*2);
        // for (int i=0;i<n;i++) {
        //     nums[i] = nums_[i];
        // }
        // for (int i=0;i<n;i++) {
        //     nums[i+n] = nums_[i];
        // }
        // todo:
        // 1 2 1
        // [1 2 1 1 2] 1
        stack<int> s;
        vector<int> res(n,-1);
        for (int i = 0; i < 2 * n - 1; i++) {
            while(s.size()  && nums[remap(s.top(),n)] < nums[remap(i,n)]) {
                int j = s.top();
                s.pop();
                res[remap(j,n)] = nums[remap(i,n)];
            }
            s.push(i);
        }
        return res;
    }
    int remap(int i,int n) {
        return i % n;
        // if (i >= n) {
        //     return i-n;
        // }
        // return i;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [503] 下一个更大元素 II" << endl;
    #endif

    Solution k;
    vector<int> res = {1,2,1} ;
    println(k.nextGreaterElements(res));

    return 0;
}
