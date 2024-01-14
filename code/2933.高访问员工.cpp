#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
#define debug 1
#define print(a) cout << a <<" "
#define printn(a) cout << a << endl
template <typename T>
void printa(vector<T> const &a,string fl="") { for(auto w:a) print(w); printn(fl);}
template <typename T>
void printa2(vector<vector<T>> const &a) { for (auto f:a) printa(f); }
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makeLinkedList(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
void printl(ListNode *h) { while(h) { print(h->val); h = h->next; } printn("");}
string bin(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }
/* clang-format on */

/*

<!-- @lc app=leetcode.cn id=2933 lang=cpp -->

[leetcode
2933.高访问员工](https://leetcode.cn/problems/high-access-employees/description/)


algorithms
Medium (49.73%)
Likes:    1
Dislikes: 0
Total Accepted:    4.8K
Total Submissions: 9.7K
Testcase Example:
'[["a","0549"],["b","0457"],["a","0532"],["a","0621"],["b","0540"]]'

给你一个长度为 n 、下标从 0 开始的二维字符串数组 access_times 。对于每个 i（0 <=
i <= n - 1 ），access_times[i][0] 表示某位员工的姓名，access_times[i][1]
表示该员工的访问时间。access_times 中的所有条目都发生在同一天内。

访问时间用 四位 数字表示， 符合 24 小时制 ，例如 "0800" 或 "2250" 。

如果员工在 同一小时内 访问系统 三次或更多 ，则称其为 高访问 员工。

时间间隔正好相差一小时的时间 不 被视为同一小时内。例如，"0815" 和 "0915"
不属于同一小时内。

一天开始和结束时的访问时间不被计算为同一小时内。例如，"0005" 和 "2350"
不属于同一小时内。

以列表形式，按任意顺序，返回所有 高访问 员工的姓名。



示例 1：


输入：access_times =
[["a","0549"],["b","0457"],["a","0532"],["a","0621"],["b","0540"]]
输出：["a"]
解释："a" 在时间段 [05:32, 06:31] 内有三条访问记录，时间分别为 05:32 、05:49 和
06:21 。 但是 "b" 的访问记录只有两条。 因此，答案是 ["a"] 。

示例 2：


输入：access_times =
[["d","0002"],["c","0808"],["c","0829"],["e","0215"],["d","1508"],["d","1444"],["d","1410"],["c","0809"]]
输出：["c","d"]
解释："c" 在时间段 [08:08, 09:07] 内有三条访问记录，时间分别为 08:08 、08:09 和
08:29 。 "d" 在时间段 [14:10, 15:09] 内有三条访问记录，时间分别为 14:10 、14:44
和 15:08 。 然而，"e" 只有一条访问记录，因此不能包含在答案中，最终答案是
["c","d"] 。

示例 3：


输入：access_times =
[["cd","1025"],["ab","1025"],["cd","1046"],["cd","1055"],["ab","1124"],["ab","1120"]]
输出：["ab","cd"]
解释："ab"在时间段 [10:25, 11:24] 内有三条访问记录，时间分别为 10:25 、11:20 和
11:24 。 "cd" 在时间段 [10:25, 11:24] 内有三条访问记录，时间分别为 10:25 、10:46
和 10:55 。 因此，答案是 ["ab","cd"] 。



提示：


1 <= access_times.length <= 100
access_times[i].length == 2
1 <= access_times[i][0].length <= 10
access_times[i][0] 仅由小写英文字母组成。
access_times[i][1].length == 4
access_times[i][1] 采用24小时制表示时间。
access_times[i][1] 仅由数字 '0' 到 '9' 组成。




 */

// @lc code=start

class Solution {
public:
  vector<string> findHighAccessEmployees(vector<vector<string>> &access_times) {
    unordered_map<string, vector<int>> mp;
    for (auto vec : access_times) {
      auto name = vec[0];
      auto ss = vec[1];
      auto d = str2int(ss.substr(0, 2)) * 60 + str2int(ss.substr(2));
      mp[name].push_back(d);
    }
    vector<string> res;
    vector<int> sum(25 * 60);
    for (auto [k, vec] : mp) {
      fill(sum.begin(), sum.end(), 0);
      int n = sum.size();
      for (int k : vec) {
        sum[k] += 1;
        if (k + 60 < n)
          sum[k + 60]--;
      }
      int all = 0;
      for (int i = 0; i < n; i++) {
        all += sum[i];
        if (all >= 3) {
          res.push_back(k);
          break;
        }
      }
    }
    return res;
  }
  int str2int(string a) {
    int k = 0;
    for (int i = 0, n = a.size(); i < n; i++) {
      k = k * 10 + (a[i] - '0');
    }
    return k;
  }
  bool cmp(int a, int b) { return a < b; }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [2933] 高访问员工" << endl;
#endif

  Solution k;
  vector<vector<string>> res = {{"a", "0549"},
                                {"b", "0457"},
                                {"a", "0532"},
                                {"a", "0621"},
                                {"b", "0540"}};
  //   cout <<  << endl;
  printa(k.findHighAccessEmployees(res));
  return 0;
}
