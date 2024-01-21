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

<!-- @lc app=leetcode.cn id=2817 lang=cpp -->

[leetcode 2817.限制条件下元素之间的最小绝对差](https://leetcode.cn/problems/minimum-absolute-difference-between-elements-with-constraint/description/)


algorithms
Medium (31.73%)
Likes:    25
Dislikes: 0
Total Accepted:    5.1K
Total Submissions: 16K
Testcase Example:  '[4,3,2,4]\n2'

给你一个下标从 0 开始的整数数组 nums 和一个整数 x 。

请你找到数组中下标距离至少为 x 的两个元素的 差值绝对值 的 最小值 。

换言之，请你找到两个下标 i 和 j ，满足 abs(i - j) >= x 且 abs(nums[i] - nums[j]) 的值最小。

请你返回一个整数，表示下标距离至少为 x 的两个元素之间的差值绝对值的 最小值 。



示例 1：


输入：nums = [4,3,2,4], x = 2
输出：0
解释：我们选择 nums[0] = 4 和 nums[3] = 4 。
它们下标距离满足至少为 2 ，差值绝对值为最小值 0 。
0 是最优解。


示例 2：


输入：nums = [5,3,2,10,15], x = 1
输出：1
解释：我们选择 nums[1] = 3 和 nums[2] = 2 。
它们下标距离满足至少为 1 ，差值绝对值为最小值 1 。
1 是最优解。


示例 3：


输入：nums = [1,2,3,4], x = 3
输出：3
解释：我们选择 nums[0] = 1 和 nums[3] = 4 。
它们下标距离满足至少为 3 ，差值绝对值为最小值 3 。
3 是最优解。




提示：


1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= x < nums.length




 */

// @lc code=start
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int ans = INT_MAX, n = nums.size();
        set<int> s {};
        for (int i=x;i<n;i++) {
            s.insert(nums[i-x]);
            auto it = s.lower_bound(nums[i]);
            if (it != s.end()) {
                ans = min(ans,abs(nums[i]- *it));
            }
            if(it != s.begin()) {
                int prev = *(--it);
                ans = min(ans,abs(prev - nums[i]));
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2817] 限制条件下元素之间的最小绝对差" << endl;
    #endif

    Solution k;
    vector<int> nums{4,3,2,4} ;
    int x = 2;
    println(k.minAbsoluteDifference(nums,x));

    return 0;
}
