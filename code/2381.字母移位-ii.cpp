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

<!-- @lc app=leetcode.cn id=2381 lang=cpp -->

[leetcode 2381.字母移位
II](https://leetcode.cn/problems/shifting-letters-ii/description/)


algorithms
Medium (39.06%)
Likes:    24
Dislikes: 0
Total Accepted:    6.9K
Total Submissions: 17.8K
Testcase Example:  '"abc"\n[[0,1,0],[1,2,1],[0,2,1]]'

给你一个小写英文字母组成的字符串 s 和一个二维整数数组 shifts ，其中 shifts[i] =
[starti, endi,
directioni] 。对于每个 i ，将 s 中从下标 starti 到下标 endi （两者都包含）所有字符都进行移位运算，如果
directioni = 1 将字符向后移位，如果 directioni = 0 将字符向前移位。

将一个字符 向后 移位的意思是将这个字符用字母表中
下一个 字母替换（字母表视为环绕的，所以 'z' 变成 'a'）。类似的，将一个字符 向前
移位的意思是将这个字符用字母表中
前一个 字母替换（字母表是环绕的，所以 'a' 变成 'z' ）。

请你返回对 s 进行所有移位操作以后得到的最终字符串。



示例 1：

输入：s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
输出："ace"
解释：首先，将下标从 0 到 1 的字母向前移位，得到 s = "zac" 。
然后，将下标从 1 到 2 的字母向后移位，得到 s = "zbd" 。
最后，将下标从 0 到 2 的字符向后移位，得到 s = "ace" 。

示例 2:

输入：s = "dztz", shifts = [[0,0,0],[1,1,1]]
输出："catz"
解释：首先，将下标从 0 到 0 的字母向前移位，得到 s = "cztz" 。
最后，将下标从 1 到 1 的字符向后移位，得到 s = "catz" 。




提示：


1 <= s.length, shifts.length <= 5 * 10^4
shifts[i].length == 3
0 <= starti <= endi < s.length
0 <= directioni <= 1
s 只包含小写英文字母。




 */

// @lc code=start
class Solution {
public:
  string shiftingLetters(string s, vector<vector<int>> &shifts) {
    int n = s.size();
    vector<int> d(n + 3);
    for (auto &shift : shifts) {
      int start = shift[0], end = shift[1];
      int k = shift[2]==0? -1:1;
      d[start] += k;
      if (end+1<n) d[end+1] -= k;
    }
#ifdef debug
    printa(d);
#endif
    int all=0;
    for (int i=0;i<n;i++) {
        all += d[i];
        if (!all) continue;
        int offset = (s[i]-'a' + all) % 26;
        while (offset<0) offset += 26;
        s[i] = 'a'+offset;
    }
    return s;
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [2381] 字母移位 II" << endl;
#endif

  Solution k;
  vector<vector<int> > shifts = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
  println(k.shiftingLetters("abc", shifts));
  return 0;
}
