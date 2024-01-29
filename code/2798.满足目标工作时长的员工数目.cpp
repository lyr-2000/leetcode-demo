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

<!-- @lc app=leetcode.cn id=2798 lang=cpp -->

[leetcode 2798.满足目标工作时长的员工数目](https://leetcode.cn/problems/number-of-employees-who-met-the-target/description/)


algorithms
Easy (85.11%)
Likes:    11
Dislikes: 0
Total Accepted:    10.3K
Total Submissions: 12.1K
Testcase Example:  '[0,1,2,3,4]\n2'

公司里共有 n 名员工，按从 0 到 n - 1 编号。每个员工 i 已经在公司工作了 hours[i] 小时。

公司要求每位员工工作 至少 target 小时。

给你一个下标从 0 开始、长度为 n 的非负整数数组 hours 和一个非负整数 target 。

请你用整数表示并返回工作至少 target 小时的员工数。



示例 1：

输入：hours = [0,1,2,3,4], target = 2
输出：3
解释：公司要求每位员工工作至少 2 小时。
- 员工 0 工作 0 小时，不满足要求。
- 员工 1 工作 1 小时，不满足要求。
- 员工 2 工作 2 小时，满足要求。
- 员工 3 工作 3 小时，满足要求。
- 员工 4 工作 4 小时，满足要求。
共有 3 位满足要求的员工。


示例 2：

输入：hours = [5,1,4,2,2], target = 6
输出：0
解释：公司要求每位员工工作至少 6 小时。
共有 0 位满足要求的员工。




提示：


1 <= n == hours.length <= 50
0 <= hours[i], target <= 10^5




 */

// @lc code=start
class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int res=0;
        for(int w:hours) {
            res += w>=target;
        }
        return res;
        
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2798] 满足目标工作时长的员工数目" << endl;
    #endif

    Solution k;

    return 0;
}
