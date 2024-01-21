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

<!-- @lc app=leetcode.cn id=2420 lang=cpp -->

[leetcode 2420.找到所有好下标](https://leetcode.cn/problems/find-all-good-indices/description/)


algorithms
Medium (32.46%)
Likes:    45
Dislikes: 0
Total Accepted:    8.8K
Total Submissions: 27K
Testcase Example:  '[2,1,1,1,3,4,1]\n2'

给你一个大小为 n 下标从 0 开始的整数数组 nums 和一个正整数 k 。

对于 k <= i < n - k 之间的一个下标 i ，如果它满足以下条件，我们就称它为一个 好 下标：


下标 i 之前 的 k 个元素是 非递增的 。
下标 i 之后 的 k 个元素是 非递减的 。


按 升序 返回所有好下标。



示例 1：


输入：nums = [2,1,1,1,3,4,1], k = 2
输出：[2,3]
解释：数组中有两个好下标：
- 下标 2 。子数组 [2,1] 是非递增的，子数组 [1,3] 是非递减的。
- 下标 3 。子数组 [1,1] 是非递增的，子数组 [3,4] 是非递减的。
注意，下标 4 不是好下标，因为 [4,1] 不是非递减的。

示例 2：


输入：nums = [2,1,1,2], k = 2
输出：[]
解释：数组中没有好下标。




提示：


n == nums.length
3 <= n <= 10^5
1 <= nums[i] <= 10^6
1 <= k <= n / 2




 */

// @lc code=start
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dec(n,1) ;
        vector<int> asc(n,1) ;
        vector<int> res; 
        for (int i=n-2;i>=0;i--)
            if(nums[i] <= nums[i+1])
                dec[i] = dec[i+1] + 1;
        for(int i=1;i<n;i++)
            if(nums[i] <= nums[i-1]) 
                asc[i] = asc[i-1]+1;
        for(int i=1;i<n-k;i++) {
            if(asc[i-1]>=k && dec[i+1]>=k) {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2420] 找到所有好下标" << endl;
    #endif

    Solution k;
    vector<int> nums{2,1,1,1,3,4,1} ;
    println(k.goodIndices(nums,2));

    return 0;
}
