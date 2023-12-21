#include<bits/stdc++.h>
using namespace std;

void printa(vector<vector<int>> &a) { int n = a.size(); for (int i = 0; i < n; i++) { for (int j = 0; j < a[i].size(); j++) { cout << a[i][j] << " "; } cout << endl; } }
void print0(vector<int> &a) { for(int w:a) cout << w << " "; cout <<endl;}
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* toTreeNode(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }

/*
 * @lc app=leetcode.cn id=1521 lang=cpp
 *
 * [1521] 找到最接近目标值的函数值
 *
 * https://leetcode.cn/problems/find-a-value-of-a-mysterious-function-closest-to-target/description/
 *
 * algorithms
 * Hard (44.19%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    4.5K
 * Total Submissions: 10.2K
 * Testcase Example:  '[9,12,3,7,15]\n5'
 *
 * 
 * 
 * Winston 构造了一个如上所示的函数 func 。他有一个整数数组 arr 和一个整数 target ，他想找到让 |func(arr, l, r)
 * - target| 最小的 l 和 r 。
 * 
 * 请你返回 |func(arr, l, r) - target| 的最小值。
 * 
 * 请注意， func 的输入参数 l 和 r 需要满足 0 <= l, r < arr.length 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [9,12,3,7,15], target = 5
 * 输出：2
 * 解释：所有可能的 [l,r] 数对包括
 * [[0,0],[1,1],[2,2],[3,3],[4,4],[0,1],[1,2],[2,3],[3,4],[0,2],[1,3],[2,4],[0,3],[1,4],[0,4]]，
 * Winston 得到的相应结果为 [9,12,3,7,15,8,0,3,7,0,0,3,0,0,0] 。最接近 5 的值是 7 和 3，所以最小差值为
 * 2 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [1000000,1000000,1000000], target = 1
 * 输出：999999
 * 解释：Winston 输入函数的所有可能 [l,r] 数对得到的函数值都为 1000000 ，所以最小差值为 999999 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [1,2,4,8,16], target = 0
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 10^5
 * 1 <= arr[i] <= 10^6
 * 0 <= target <= 10^7
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        unordered_set<int> all,pre;
        int res = INT_MAX;
        for (int cur: arr) {
            unordered_set<int> c;
            for(auto it= pre.begin();it!=pre.end();it++) {
                c.insert( *it & cur);
            }
            c.insert(cur);
            pre = c;
            for (auto it = c.begin();it!=c.end();it++) {
                int m = abs(*it - target);
                if (res > m) {
                    res = m;
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    cout << " * [1521] 找到最接近目标值的函数值" << endl;
    Solution k;
    vector<int> vec = {1,2,4,8,16};
    print0(vec);  
    cout << k.closestToTarget(vec,0)<<endl;
    return 0;
}
