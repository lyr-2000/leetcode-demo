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

<!-- @lc app=leetcode.cn id=2894 lang=cpp -->

[leetcode 2894.分类求和并作差](https://leetcode.cn/problems/divisible-and-non-divisible-sums-difference/description/)


algorithms
Easy (87.03%)
Likes:    11
Dislikes: 0
Total Accepted:    7.2K
Total Submissions: 8.3K
Testcase Example:  '10\n3'

给你两个正整数 n 和 m 。

现定义两个整数 num1 和 num2 ，如下所示：


num1：范围 [1, n] 内所有 无法被 m 整除 的整数之和。
num2：范围 [1, n] 内所有 能够被 m 整除 的整数之和。


返回整数 num1 - num2 。



示例 1：


输入：n = 10, m = 3
输出：19
解释：在这个示例中：
- 范围 [1, 10] 内无法被 3 整除的整数为 [1,2,4,5,7,8,10] ，num1 = 这些整数之和 = 37 。
- 范围 [1, 10] 内能够被 3 整除的整数为 [3,6,9] ，num2 = 这些整数之和 = 18 。
返回 37 - 18 = 19 作为答案。


示例 2：


输入：n = 5, m = 6
输出：15
解释：在这个示例中：
- 范围 [1, 5] 内无法被 6 整除的整数为 [1,2,3,4,5] ，num1 = 这些整数之和 =  15 。
- 范围 [1, 5] 内能够被 6 整除的整数为 [] ，num2 = 这些整数之和 = 0 。
返回 15 - 0 = 15 作为答案。


示例 3：


输入：n = 5, m = 1
输出：-15
解释：在这个示例中：
- 范围 [1, 5] 内无法被 1 整除的整数为 [] ，num1 = 这些整数之和 = 0 。 
- 范围 [1, 5] 内能够被 1 整除的整数为 [1,2,3,4,5] ，num2 = 这些整数之和 = 15 。
返回 0 - 15 = -15 作为答案。




提示：


1 <= n, m <= 1000




 */

// @lc code=start
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total = (1+n)*n/2;
        int left = 0;
        for (int i=m;i<=n;i+=m) {
            left += i;
        }
        #ifdef debug 
        println(total," --- ","---",left);
        #endif
        return (total - left ) - left;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2894] 分类求和并作差" << endl;
    #endif

    Solution k;
    println( k.differenceOfSums(5,6));
    println( k.differenceOfSums(5,1));
    println( k.differenceOfSums(10,3));
    // vector<int> a = {1,2,3};
    // printa(a);
    return 0;
}
