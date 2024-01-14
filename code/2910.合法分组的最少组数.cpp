#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
#define debug 1
void print() {}
template<typename Head, typename... Args>
void print(const Head& head, const Args&... args ) { cout << head << " "; print(args...); }
#define println(...) print(__VA_ARGS__),cout <<endl;
template <typename T>
void printa(vector<T> const &a,string fl="") { for(auto w:a) print(w); println(fl);}
template <typename T>
void printa2(vector<vector<T>> const &a) { for (auto f:a) printa(f); }
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makeLinkedList(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
void printl(ListNode *h) { while(h) { print(h->val); h = h->next; } println("");}
string bin(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }
/* clang-format on */


/*

<!-- @lc app=leetcode.cn id=2910 lang=cpp -->

[leetcode 2910.合法分组的最少组数](https://leetcode.cn/problems/minimum-number-of-groups-to-create-a-valid-assignment/description/)


algorithms
Medium (29.54%)
Likes:    27
Dislikes: 0
Total Accepted:    4.8K
Total Submissions: 16.4K
Testcase Example:  '[3,2,3,2,3]'

给你一个长度为 n 下标从 0 开始的整数数组 nums 。

我们想将下标进行分组，使得 [0, n - 1] 内所有下标 i 都 恰好 被分到其中一组。

如果以下条件成立，我们说这个分组方案是合法的：


对于每个组 g ，同一组内所有下标在 nums 中对应的数值都相等。
对于任意两个组 g1 和 g2 ，两个组中 下标数量 的 差值不超过 1 。


请你返回一个整数，表示得到一个合法分组方案的 最少 组数。



示例 1：


输入：nums = [3,2,3,2,3]
输出：2
解释：一个得到 2 个分组的方案如下，中括号内的数字都是下标：
组 1 -> [0,2,4]
组 2 -> [1,3]
所有下标都只属于一个组。
组 1 中，nums[0] == nums[2] == nums[4] ，所有下标对应的数值都相等。
组 2 中，nums[1] == nums[3] ，所有下标对应的数值都相等。
组 1 中下标数目为 3 ，组 2 中下标数目为 2 。
两者之差不超过 1 。
无法得到一个小于 2 组的答案，因为如果只有 1 组，组内所有下标对应的数值都要相等。
所以答案为 2 。

示例 2：


输入：nums = [10,10,10,3,1,1]
输出：4
解释：一个得到 2 个分组的方案如下，中括号内的数字都是下标：
组 1 -> [0]
组 2 -> [1,2]
组 3 -> [3]
组 4 -> [4,5]
分组方案满足题目要求的两个条件。
无法得到一个小于 4 组的答案。
所以答案为 4 。



提示：


1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9




 */

// @lc code=start
class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (int u:nums) mp[u] ++;
        int minx = INT_MAX;
        for (auto [k,v]: mp) {
            minx = min(minx,v);
        }
        int all = 0;
        for (auto [k,cnt]: mp) {
            // todo!
            if (cnt / minx < cnt % minx) {

            }
            
            #ifdef debug 
            println(minx,all,cnt);
            #endif
            
        } 
        return all;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2910] 合法分组的最少组数" << endl;
    #endif

    Solution k;
    vector<int> nums = {1,1,3,1,1,3 };
    println(k.minGroupsForValidAssignment(nums));
    return 0;
}
