#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
#define debug 1
#define print(a) cout << a <<" "
#define printn(a) cout << a << endl
void printa(vector<int> &a,string fl="") { for(int w:a) print(w); printn(fl);}
void printa2(vector<vector<int>> &a) { for (auto f:a) printa(f); }
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makeLinkedList(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
void printl(ListNode *h) { while(h) { print(h->val); h = h->next; } printn("");}
string bin(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }
/* clang-format on */


/*

<!-- @lc app=leetcode.cn id=2918 lang=cpp -->

[leetcode 2918.数组的最小相等和](https://leetcode.cn/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/)


algorithms
Medium (35.36%)
Likes:    8
Dislikes: 0
Total Accepted:    5.3K
Total Submissions: 15.1K
Testcase Example:  '[3,2,0,1,0]\n[6,5,0]'

给你两个由正整数和 0 组成的数组 nums1 和 nums2 。

你必须将两个数组中的 所有 0 替换为 严格 正整数，并且满足两个数组中所有元素的和 相等 。

返回 最小 相等和 ，如果无法使两数组相等，则返回 -1 。



示例 1：


输入：nums1 = [3,2,0,1,0], nums2 = [6,5,0]
输出：12
解释：可以按下述方式替换数组中的 0 ：
- 用 2 和 4 替换 nums1 中的两个 0 。得到 nums1 = [3,2,2,1,4] 。
- 用 1 替换 nums2 中的一个 0 。得到 nums2 = [6,5,1] 。
两个数组的元素和相等，都等于 12 。可以证明这是可以获得的最小相等和。


示例 2：


输入：nums1 = [2,0,2,0], nums2 = [1,4]
输出：-1
解释：无法使两个数组的和相等。




提示：


1 <= nums1.length, nums2.length <= 10^5
0 <= nums1[i], nums2[i] <= 10^6




 */

// @lc code=start
#define ll long long
class Solution {
public:
    struct E  {
        ll l;
        ll r;
        int cnt;
    };
    E counte(vector<int> &a) {
        E e = {0,0,0};
        for(int u:a) {
            int f = u==0;
            if(f) e.cnt++;
            e.l+=u;
        }
        e.l = e.l+e.cnt;
        if(e.cnt) e.r = LONG_MAX;
        else e.r = e.l;
        return e;
    }
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        auto a = counte(nums1);
        auto b = counte(nums2);
        if(a.r < b.l || b.r < a.l) {
            // 无交集 
            return -1;
        }
        auto L = max(a.l,b.l);
        return L;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2918] 数组的最小相等和" << endl;
    #endif

    Solution k;
    vector<int> a = {3,2,0,1,0} ;
    vector<int> b = {6,5,0} ;
    cout << k.minSum(a,b)<<endl;
    return 0;
}
