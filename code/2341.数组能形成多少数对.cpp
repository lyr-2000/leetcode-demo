#include<bits/stdc++.h>
using namespace std;

#define print(a) cout << a <<" "
#define printn(a) cout << a << endl
void printa(vector<int> &a) { for(int w:a) print(w); print("\n");}
void printa2(vector<vector<int>> &a) { for (auto f:a) printa(f); }
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }

/*
 * @lc app=leetcode.cn id=2341 lang=cpp
 *
 * [2341] 数组能形成多少数对
 *
 * https://leetcode.cn/problems/maximum-number-of-pairs-in-array/description/
 *
 * algorithms
 * Easy (80.96%)
 * Likes:    69
 * Dislikes: 0
 * Total Accepted:    41K
 * Total Submissions: 50.7K
 * Testcase Example:  '[1,3,2,1,3,2,2]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。在一步操作中，你可以执行以下步骤：
 * 
 * 
 * 从 nums 选出 两个 相等的 整数
 * 从 nums 中移除这两个整数，形成一个 数对
 * 
 * 
 * 请你在 nums 上多次执行此操作直到无法继续执行。
 * 
 * 返回一个下标从 0 开始、长度为 2 的整数数组 answer 作为答案，其中 answer[0] 是形成的数对数目，answer[1] 是对 nums
 * 尽可能执行上述操作后剩下的整数数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,3,2,1,3,2,2]
 * 输出：[3,1]
 * 解释：
 * nums[0] 和 nums[3] 形成一个数对，并从 nums 中移除，nums = [3,2,3,2,2] 。
 * nums[0] 和 nums[2] 形成一个数对，并从 nums 中移除，nums = [2,2,2] 。
 * nums[0] 和 nums[1] 形成一个数对，并从 nums 中移除，nums = [2] 。
 * 无法形成更多数对。总共形成 3 个数对，nums 中剩下 1 个数字。
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,1]
 * 输出：[1,0]
 * 解释：nums[0] 和 nums[1] 形成一个数对，并从 nums 中移除，nums = [] 。
 * 无法形成更多数对。总共形成 1 个数对，nums 中剩下 0 个数字。
 * 
 * 示例 3：
 * 
 * 输入：nums = [0]
 * 输出：[0,1]
 * 解释：无法形成数对，nums 中剩下 1 个数字。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n= nums.size();
        for(int i=0;i<n;i++) {
            mp[nums[i]] ++;
        }        
        int cnt = 0,rest=0;
        for (auto [k,v]: mp) {
            rest += v % 2;
            cnt += v/2;
        }
        return {cnt,rest};
    }
};
// @lc code=end

int main() {
    cout << " * [2341] 数组能形成多少数对" << endl;
    Solution k;
    auto k1 = vector<int> {1,3,2,1,3,2,2};
    auto x=k.numberOfPairs(k1);
    printa(x) ;

    return 0;
}
