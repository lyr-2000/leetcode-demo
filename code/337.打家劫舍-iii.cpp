#include<bits/stdc++.h>
using namespace std;

void printa(vector<vector<int>> &a) { int n = a.size(); for (int i = 0; i < n; i++) { for (int j = 0; j < a[i].size(); j++) { cout << a[i][j] << " "; } cout << endl; } }
void print0(vector<int> &a) { for(int w:a) cout << w << " "; cout <<endl;}
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }

/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 *
 * https://leetcode.cn/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (61.50%)
 * Likes:    1923
 * Dislikes: 0
 * Total Accepted:    325.4K
 * Total Submissions: 529.1K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
 * 
 * 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果
 * 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
 * 
 * 给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入: root = [3,2,3,null,3,null,1]
 * 输出: 7 
 * 解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7
 * 
 * 示例 2:
 * 
 * 
 * 
 * 
 * 输入: root = [3,4,5,1,3,null,1]
 * 输出: 9
 * 解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * 树的节点数在 [1, 10^4] 范围内
 * 0 <= Node.val <= 10^4
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        return dp(root,true);
    }
    unordered_map<TreeNode*,int> mp;
    unordered_map<TreeNode*,int> st;
    int dp(TreeNode *root,bool steal) {
        if(root==NULL) return 0;
        if (steal) {
            if (st.count(root)) return st[root];
            // 能偷， ，result = max(偷，不偷)
            // 偷
            int stealres = root->val + dp(root->left,false) + dp(root->right,false);
            // 对比2种情况
            int r= max(stealres,dp(root,false));
            st[root]=r;
            return r;
        }else {
            if (mp.count(root)) {
                return mp[root];
            }
            // 不偷
            int ans = dp(root->left,true) + dp(root->right,true);
            mp[root] = ans;
            return ans;
        }
    }
};
// @lc code=end

int main() {
    cout << " * [337] 打家劫舍 III" << endl;
    Solution k;
    vector<int> v = {3,2,3,-1,3,-1,1};
    TreeNode *root = makeTree(v);
    printt("@",root,false);
    printf("%d\n",k.rob(root));
    return 0;
}
