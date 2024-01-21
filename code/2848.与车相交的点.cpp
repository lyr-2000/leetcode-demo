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

<!-- @lc app=leetcode.cn id=2848 lang=cpp -->

[leetcode
2848.与车相交的点](https://leetcode.cn/problems/points-that-intersect-with-cars/description/)


algorithms
Easy (73.93%)
Likes:    14
Dislikes: 0
Total Accepted:    8K
Total Submissions: 10.8K
Testcase Example:  '[[3,6],[1,5],[4,7]]'

给你一个下标从 0 开始的二维整数数组 nums
表示汽车停放在数轴上的坐标。对于任意下标 i，nums[i] = [starti, endi] ，其中
starti 是第 i 辆车的起点，endi 是第 i 辆车的终点。

返回数轴上被车 任意部分 覆盖的整数点的数目。



示例 1：


输入：nums = [[3,6],[1,5],[4,7]]
输出：7
解释：从 1 到 7 的所有点都至少与一辆车相交，因此答案为 7 。


示例 2：


输入：nums = [[1,3],[5,8]]
输出：7
解释：1、2、3、5、6、7、8 共计 7 个点满足至少与一辆车相交，因此答案为 7 。




提示：


1 <= nums.length <= 100
nums[i].length == 2
1 <= starti <= endi <= 100




 */

// @lc code=start
class Solution {
public:
  int numberOfPoints(vector<vector<int>> &nums) {
    int n = nums.size();
    if (!n)
      return 0;
    n=0;
    for(auto &ve: nums) 
       n = max(ve[0],max(ve[1],n)) ;
    vector<int> d(n+2) ;
    for(auto &ve: nums) {
        int l=ve[0],r = ve[1];
        d[l]+=1;
        d[r+1]-=1;
    }
    int total =0;
    int sum=0;
    
    for(int i=0;i<n+2;i++) {
        sum += d[i];
        if(sum) 
            total++;
    }
    return total;
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [2848] 与车相交的点" << endl;
#endif

  Solution k;
  vector<vector<int>> nums{{4, 4}, {9, 10}, {9, 10}, {3, 8}};
  println(k.numberOfPoints(nums));
  return 0;
}
