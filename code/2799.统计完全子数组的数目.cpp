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

<!-- @lc app=leetcode.cn id=2799 lang=cpp -->

[leetcode 2799.统计完全子数组的数目](https://leetcode.cn/problems/count-complete-subarrays-in-an-array/description/)


algorithms
Medium (58.21%)
Likes:    28
Dislikes: 0
Total Accepted:    7.4K
Total Submissions: 12.7K
Testcase Example:  '[1,3,1,2,2]'

给你一个由 正 整数组成的数组 nums 。

如果数组中的某个子数组满足下述条件，则称之为 完全子数组 ：


子数组中 不同 元素的数目等于整个数组不同元素的数目。


返回数组中 完全子数组 的数目。

子数组 是数组中的一个连续非空序列。



示例 1：

输入：nums = [1,3,1,2,2]
输出：4
解释：完全子数组有：[1,3,1,2]、[1,3,1,2,2]、[3,1,2] 和 [3,1,2,2] 。


示例 2：

输入：nums = [5,5,5,5]
输出：10
解释：数组仅由整数 5 组成，所以任意子数组都满足完全子数组的条件。子数组的总数为 10 。




提示：


1 <= nums.length <= 1000
1 <= nums[i] <= 2000




 */

// @lc code=start
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int m=unordered_set<int>(nums.begin(),nums.end()).size() ;
        unordered_map<int,int> mp;
        int ans=0,left=0;
        for(int v: nums) {
            mp[v]++;
            while(mp.size() == m) {
                int j = nums[left];
                left++;
                mp[j]--;
                if(mp[j] == 0) {
                    mp.erase(j);
                }
            }
            ans += left;
        }
       
        return ans;
        
    }
    /**
    
     int n = nums.size();
        unordered_set<int> f;
        for(int u:nums)f.insert(u);
        int m= f.size();
        int r=0;
        for(int i=0;i<n;i++) {
            unordered_set<int> se;
            for(int j=i;j<n;j++) {
                se.insert(nums[j]); 
                if (se.size() == m ){
                    r++;
                }
            }
        }
    
    */
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2799] 统计完全子数组的数目" << endl;
    #endif

    Solution k;

    return 0;
}
