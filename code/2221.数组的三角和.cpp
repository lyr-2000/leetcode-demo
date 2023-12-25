#include<bits/stdc++.h>
using namespace std;

#define print(a) cout << a <<" "
#define printn(a) cout << a << endl
void printa(vector<int> &a) { for(int w:a) print(w); printn("");}
void printa2(vector<vector<int>> &a) { for (auto f:a) printa(f); }
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makeLinkedList(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
void printl(ListNode *h) { while(h) { print(h->val); h = h->next; } printn("");}
string itoa2(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }


/*
 * @lc app=leetcode.cn id=2221 lang=cpp
 *
 * [2221] 数组的三角和
 *
 * https://leetcode.cn/problems/find-triangular-sum-of-an-array/description/
 *
 * algorithms
 * Medium (79.19%)
 * Likes:    16
 * Dislikes: 0
 * Total Accepted:    10.5K
 * Total Submissions: 13.3K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你一个下标从 0 开始的整数数组 nums ，其中 nums[i] 是 0 到 9 之间（两者都包含）的一个数字。
 * 
 * nums 的 三角和 是执行以下操作以后最后剩下元素的值：
 * 
 * 
 * nums 初始包含 n 个元素。如果 n == 1 ，终止 操作。否则，创建 一个新的下标从 0 开始的长度为 n - 1 的整数数组 newNums
 * 。
 * 对于满足 0 <= i < n - 1 的下标 i ，newNums[i] 赋值 为 (nums[i] + nums[i+1]) % 10 ，%
 * 表示取余运算。
 * 将 newNums 替换 数组 nums 。
 * 从步骤 1 开始 重复 整个过程。
 * 
 * 
 * 请你返回 nums 的三角和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：nums = [1,2,3,4,5]
 * 输出：8
 * 解释：
 * 上图展示了得到数组三角和的过程。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5]
 * 输出：5
 * 解释：
 * 由于 nums 中只有一个元素，数组的三角和为这个元素自己。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int triangularSum(vector<int>& nums0) {
        vector<int> nums(nums0);
        int n = nums.size();
        if(!n) return 0;
        if (n==1) return nums[0];
        while (n) {
            for (int i=0;i<n-1;i++) {
                int cur = nums[i];
                int next = nums[i+1];
                nums[i] = (cur + next) %10;
            }
            // printa(nums);
            n--;
            // nums0 = nums;
        }
        return nums[0];
    }
};
// @lc code=end

int main() {
    cout << " * [2221] 数组的三角和" << endl;
    Solution k;
    vector<int> nums = {1,2,3,4,5};

    printa(nums)    ;
    print( k.triangularSum(nums));
    return 0;
}
