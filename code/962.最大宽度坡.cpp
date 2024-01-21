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

<!-- @lc app=leetcode.cn id=962 lang=cpp -->

[leetcode 962.最大宽度坡](https://leetcode.cn/problems/maximum-width-ramp/description/)


algorithms
Medium (47.91%)
Likes:    242
Dislikes: 0
Total Accepted:    26.2K
Total Submissions: 54.6K
Testcase Example:  '[6,0,8,2,1,5]'

给定一个整数数组 A，坡是元组 (i, j)，其中  i < j 且 A[i] <= A[j]。这样的坡的宽度为 j - i。

找出 A 中的坡的最大宽度，如果不存在，返回 0 。



示例 1：

输入：[6,0,8,2,1,5]
输出：4
解释：
最大宽度的坡为 (i, j) = (1, 5): A[1] = 0 且 A[5] = 5.


示例 2：

输入：[9,8,1,0,1,9,4,0,4,1]
输出：7
解释：
最大宽度的坡为 (i, j) = (2, 9): A[2] = 1 且 A[9] = 1.




提示：


2 <= A.length <= 50000
0 <= A[i] <= 50000


这道题是万恶之源！
先生成一个严格单调递减的数列存进栈中（从0位置开始），这是所有可能的i值，因为大于等于栈中元素的位置
如果想要成为i值，必然可以被在它左边的比它小的栈中位置替代（因为值更小，位置也更小，否则的话这个元素
也会入栈），因此我们通过第一步完成了对i的取值的存储；
接下来为了使得长度最长，我们从最右边开始找j值，一旦栈顶位置元素值小于等于当前j位置的值，我们就可以
考虑把i的位置向左移动使得长度增加（右边界固定寻找最远的左边界），之后再开始减少右边界，如此循环直到j不再
满足条件

作者：游世无双
链接：https://leetcode.cn/problems/maximum-width-ramp/solutions/1/dan-diao-zhan-bi-shua-ti-by-jiachengpku-okjt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


 */

// @lc code=start
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> d;
        for (int i=0;i<n;i++) {
            if(d.size()==0||  nums[i] < nums[d.top()]) 
                d.push(i);
        } 
        int maxlen=0;
        //递减 
        for (int j=n-1;j>=0;j--) {
            while(d.size() && nums[j] >= nums[d.top()]) {
                int i = d.top();
                d.pop();
                if (i < j && j-i > maxlen) maxlen = j-i;

            }
        }
        return maxlen;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [962] 最大宽度坡" << endl;
    #endif

    Solution k;
    vector<int> w = {10,10,10,7,1,6,2,1,7} ;
    println(k.maxWidthRamp(w));

    return 0;
}
