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

<!-- @lc app=leetcode.cn id=2909 lang=cpp -->

[leetcode 2909.元素和最小的山形三元组 II](https://leetcode.cn/problems/minimum-sum-of-mountain-triplets-ii/description/)


algorithms
Medium (51.11%)
Likes:    15
Dislikes: 0
Total Accepted:    6.4K
Total Submissions: 12.4K
Testcase Example:  '[8,6,1,5,3]'

给你一个下标从 0 开始的整数数组 nums 。

如果下标三元组 (i, j, k) 满足下述全部条件，则认为它是一个 山形三元组 ：


i < j < k
nums[i] < nums[j] 且 nums[k] < nums[j]


请你找出 nums 中 元素和最小 的山形三元组，并返回其 元素和 。如果不存在满足条件的三元组，返回 -1 。



示例 1：


输入：nums = [8,6,1,5,3]
输出：9
解释：三元组 (2, 3, 4) 是一个元素和等于 9 的山形三元组，因为： 
- 2 < 3 < 4
- nums[2] < nums[3] 且 nums[4] < nums[3]
这个三元组的元素和等于 nums[2] + nums[3] + nums[4] = 9 。可以证明不存在元素和小于 9 的山形三元组。


示例 2：


输入：nums = [5,4,8,7,10,2]
输出：13
解释：三元组 (1, 3, 5) 是一个元素和等于 13 的山形三元组，因为： 
- 1 < 3 < 5 
- nums[1] < nums[3] 且 nums[5] < nums[3]
这个三元组的元素和等于 nums[1] + nums[3] + nums[5] = 13 。可以证明不存在元素和小于 13 的山形三元组。


示例 3：


输入：nums = [6,5,4,3,4,5]
输出：-1
解释：可以证明 nums 中不存在山形三元组。




提示：


3 <= nums.length <= 10^5
1 <= nums[i] <= 10^8




 */

// @lc code=start
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        // [a,b,c] , ab 上升,bc下降 
        int n = nums.size();
        if(!n) return -1;
        if (n<3) return -1;
        vector<int> values(n,0) ;
        values[0] = nums[0];
        for (int i=1;i<n;i++) {
            if (nums[i] > values[i-1]) {
                values[i] = values[i-1];
            }else {
                values[i] = nums[i];
                //记录前面的最小值
            }
        }
        #ifdef debug 
           printa(values);
        #endif
        
        int ans = INT_MAX;
        int r = nums[n-1];
        for (int i=n-1-1;i>0;i--) {
            int curr = nums[i];
            if ( curr > r && curr > values[i-1]) {
                ans = min(ans,curr + r + values[i-1]);
            }
            r = min(nums[i],r);
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2909] 元素和最小的山形三元组 II" << endl;
    #endif

    Solution k;
    vector<int > nums = {5,4,8,7,10,2 };
    cout << k.minimumSum(nums) <<endl;
    return 0;
}
