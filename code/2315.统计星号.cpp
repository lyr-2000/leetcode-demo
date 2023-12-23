#include<bits/stdc++.h>
using namespace std;

void printa(vector<vector<int>> &a) { int n = a.size(); for (int i = 0; i < n; i++) { for (int j = 0; j < a[i].size(); j++) { cout << a[i][j] << " "; } cout << endl; } }
void print0(vector<int> &a) { for(int w:a) cout << w << " "; cout <<endl;}
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }

/*
 * @lc app=leetcode.cn id=2315 lang=cpp
 *
 * [2315] 统计星号
 *
 * https://leetcode.cn/problems/count-asterisks/description/
 *
 * algorithms
 * Easy (85.19%)
 * Likes:    59
 * Dislikes: 0
 * Total Accepted:    37.8K
 * Total Submissions: 44.4K
 * Testcase Example:  '"l|*e*et|c**o|*de|"'
 *
 * 给你一个字符串 s ，每 两个 连续竖线 '|' 为 一对 。换言之，第一个和第二个 '|' 为一对，第三个和第四个 '|' 为一对，以此类推。
 * 
 * 请你返回 不在 竖线对之间，s 中 '*' 的数目。
 * 
 * 注意，每个竖线 '|' 都会 恰好 属于一个对。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "l|*e*et|c**o|*de|"
 * 输出：2
 * 解释：不在竖线对之间的字符加粗加斜体后，得到字符串："l|*e*et|c**o|*de|" 。
 * 第一和第二条竖线 '|' 之间的字符不计入答案。
 * 同时，第三条和第四条竖线 '|' 之间的字符也不计入答案。
 * 不在竖线对之间总共有 2 个星号，所以我们返回 2 。
 * 
 * 示例 2：
 * 
 * 输入：s = "iamprogrammer"
 * 输出：0
 * 解释：在这个例子中，s 中没有星号。所以返回 0 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "yo|uar|e**|b|e***au|tifu|l"
 * 输出：5
 * 解释：需要考虑的字符加粗加斜体后："yo|uar|e**|b|e***au|tifu|l" 。不在竖线对之间总共有 5 个星号。所以我们返回 5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 只包含小写英文字母，竖线 '|' 和星号 '*' 。
 * s 包含 偶数 个竖线 '|' 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countAsterisks(string s) {
        int mod=0;
        int pro = 0;
        for(char w:s) {
            if (w == '|') {
                mod++;
                
            }
            if (w == '*') {
                if(mod % 2 == 0) {
                    pro++;
                }
            }
        }    
        return pro;
    }

};
// @lc code=end

int main() {
    cout << " * [2315] 统计星号" << endl;
    Solution k;
    auto s = "yo|uar*|**";
    int p = k.countAsterisks(s);
    printf("%d\n",p);
    return 0;
}
