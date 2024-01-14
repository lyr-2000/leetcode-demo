#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
#define debug 1
void print() {}
template<typename Head, typename... Args>
void print(const Head& head, const Args&... args ) { cout << head << " "; print(args...); }
#define println(...) print(__VA_ARGS__),cout <<endl
template <typename T>
void printa(vector<T> const &a,string fl="") { for(auto w:a) print(w); println(fl);}
template <typename T>
void printa(vector<vector<T>> const &a) { for (auto f:a) printa(f); }
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makeLinkedList(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
void printl(ListNode *h) { while(h) { print(h->val); h = h->next; } println("");}
string bin(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }
/* clang-format on */

/*

<!-- @lc app=leetcode.cn id=46 lang=cpp -->

[leetcode 46.全排列](https://leetcode.cn/problems/permutations/description/)


algorithms
Medium (79.01%)
Likes:    2792
Dislikes: 0
Total Accepted:    986.4K
Total Submissions: 1.2M
Testcase Example:  '[1,2,3]'

给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序
返回答案。



示例 1：


输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


示例 2：


输入：nums = [0,1]
输出：[[0,1],[1,0]]


示例 3：


输入：nums = [1]
输出：[[1]]




提示：


1 <= nums.length <= 6
-10 <= nums[i] <= 10
nums 中的所有整数 互不相同




 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<int> tmp;
    
    makeVec(0, nums, tmp);
    return all;
  }
  vector<vector<int>> all;
  void makeVec(int state, vector<int> &nums, vector<int> &res) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int newst = state;
      if ( ((state >> i) & 1) == 0) {
        newst |= 1 << i;
        res.push_back(nums[i]);
        makeVec(newst, nums, res);
        if (res.size() == n) {
          all.push_back(res);
        }
        res.pop_back();
      }
    }
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [46] 全排列" << endl;
#endif

  Solution k;
  vector<int> tp = {1,2,3} ;
  printa(k.permute(tp));

  return 0;
}
