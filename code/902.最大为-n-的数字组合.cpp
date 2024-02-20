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

<!-- @lc app=leetcode.cn id=902 lang=cpp -->

[leetcode 902.最大为 N
的数字组合](https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/description/)


algorithms
Hard (46.79%)
Likes:    271
Dislikes: 0
Total Accepted:    29.8K
Total Submissions: 63.3K
Testcase Example:  '["1","3","5","7"]\n100'

给定一个按 非递减顺序 排列的数字数组 digits 。你可以用任意次数 digits[i] 来写的数字。例如，如果 digits
=
['1','3','5']，我们可以写数字，如 '13', '551', 和 '1351315'。

返回 可以生成的小于或等于给定整数 n 的正整数的个数 。



示例 1：


输入：digits = ["1","3","5","7"], n = 100
输出：20
解释：
可写出的 20 个数字是：
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75,
77.


示例 2：


输入：digits = ["1","4","9"], n = 1000000000
输出：29523
解释：
我们可以写 3 个一位数字，9 个两位数字，27 个三位数字，
81 个四位数字，243 个五位数字，729 个六位数字，
2187 个七位数字，6561 个八位数字和 19683 个九位数字。
总共，可以使用D中的数字写出 29523 个整数。

示例 3:


输入：digits = ["7"], n = 8
输出：1




提示：



1 <= digits.length <= 9
digits[i].length == 1
digits[i] 是从 '1' 到 '9' 的数
digits 中的所有值都 不同 
digits 按 非递减顺序 排列
1 <= n <= 10^9




 */

// @lc code=start
class Solution {
public:
  int atMostNGivenDigitSet(vector<string> &digits, int n) {
    maxnum = to_string(n);
    dp = vector<int>(maxnum.size(), -1);
    this->digits = digits; //保证digits是有序的
    return f(0, true, false);
  }
  string maxnum;
  vector<int> dp;
  vector<string> digits; 
  int f(int i, bool islimit, bool isnum) { // f[i] = f[i+1] or i == m?1:0
    if (i == maxnum.size()) {
      return isnum;
    }
    if (!islimit && isnum && dp[i] >= 0)
      return dp[i];
    int cmax = islimit ? maxnum[i] : '9';
    int res = 0;
    if (!isnum)
      res += f(i + 1, false /*位数比N短*/, isnum);
    for (auto &str : digits) {
      if (str[0] > cmax)
        break; // sort(digits)
      res += f(i + 1, cmax == str[0] && islimit, true);
    }
    if (!islimit && isnum)
      dp[i] = res;
    return res;
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [902] 最大为 N 的数字组合" << endl;
#endif

  Solution k;

  return 0;
}
