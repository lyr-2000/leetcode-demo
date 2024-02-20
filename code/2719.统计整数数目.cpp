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

<!-- @lc app=leetcode.cn id=2719 lang=cpp -->

[leetcode
2719.统计整数数目](https://leetcode.cn/problems/count-of-integers/description/)


algorithms
Hard (48.27%)
Likes:    95
Dislikes: 0
Total Accepted:    14.6K
Total Submissions: 26.1K
Testcase Example:  '"1"\n"12"\n1\n8'

给你两个数字字符串 num1 和 num2 ，以及两个整数 max_sum
和 min_sum 。如果一个整数 x 满足以下条件，我们称它是一个好整数：


num1 <= x <= num2
min_sum <= digit_sum(x) <= max_sum.


请你返回好整数的数目。答案可能很大，请返回答案对 10^9 + 7 取余后的结果。

注意，digit_sum(x) 表示 x 各位数字之和。



示例 1：


输入：num1 = "1", num2 = "12", min_num = 1, max_num = 8
输出：11
解释：总共有 11 个整数的数位和在 1 到 8 之间，分别是 1,2,3,4,5,6,7,8,10,11 和 12
。所以我们返回 11 。


示例 2：


输入：num1 = "1", num2 = "5", min_num = 1, max_num = 5
输出：5
解释：数位和在 1 到 5 之间的 5 个整数分别为 1,2,3,4 和 5 。所以我们返回 5 。




提示：


1 <= num1 <= num2 <= 10^22
1 <= min_sum <= max_sum <= 400



此外，由于前导零对数位和无影响（sum+0=sum\textit{sum}+0=\textit{sum}sum+0=sum），模板中的 isNum\textit{isNum}isNum 可以省略。

作者：灵茶山艾府
链接：https://leetcode.cn/problems/count-of-integers/solutions/2296043/shu-wei-dp-tong-yong-mo-ban-pythonjavacg-9tuc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

// @lc code=start
class Solution {
public:
  const int MOD = 1e9 + 7;
  int calc(string &Limit, int L, int R) {
    int n = Limit.size();
    vector<vector<int>> memo(n, vector<int>(min(9 * n, R) + 1, -1));
    function<int(int, int, bool)> f = [&](int i, int x, bool islimit) -> int {
      if (x > R)
        return 0;
      if (i == n)
        return x >= L ? 1 : 0;
      if (!islimit && memo[i][x] != -1)
        return memo[i][x];
      int up = islimit ? Limit[i] - '0' : 9;
      int res = 0;
      for (int d = 0; d <= up; d++) {
        res = (res*1ll + f(i + 1, x + d, islimit && d == up)) % MOD;
      }
      if (!islimit)
        memo[i][x] = res;
      return res;
    };
    return f(0, 0, true);
  }
  int count(string num1, string num2, int min_sum, int max_sum) {
    int res = calc(num2, min_sum, max_sum) - calc(num1, min_sum, max_sum);
    #ifdef debug
    cout << "debug:"<< res << endl;
    #endif
    if(res<0) res += MOD;
    int sum = 0;
    for (char c : num1) {
      sum += c - '0';
    }
    if (sum <= max_sum && sum >= min_sum)
      return (res + 1) % MOD;
    return res % MOD;
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [2719] 统计整数数目" << endl;
#endif

  Solution k;
  cout << k.count("1", "12", 1, 8) << endl;
  cout << k.count("4179205230", "7748704426", 8, 46) << endl;
  return 0;
}
