#include<bits/stdc++.h>
using namespace std;

void printa(vector<vector<int>> &a) { int n = a.size(); for (int i = 0; i < n; i++) { for (int j = 0; j < a[i].size(); j++) { cout << a[i][j] << " "; } cout << endl; } }
void print0(vector<int> &a) { for(int w:a) cout << w << " "; cout <<endl;}
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
TreeNode* toTreeNode(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }


${comment.start}
${comment.line} @lc app=${app} id=${fid} lang=${lang}
${comment.line}
${comment.line} [${fid}] ${name}
${comment.line}
${comment.line} ${link}
${comment.line}
${comment.line} ${category}
${comment.line} ${level} (${percent}%)
${comment.line} Likes:    ${likes}
${comment.line} Dislikes: ${dislikes}
${comment.line} Total Accepted:    ${totalAC}
${comment.line} Total Submissions: ${totalSubmit}
${comment.line} Testcase Example:  ${testcase}
${comment.line}
{{ desc.forEach(function(x) { }}${comment.line} ${x}
{{ }) }}${comment.end}

${comment.singleLine} @lc code=start
${code}
${comment.singleLine} @lc code=end

int main(void) {

  Solution so;
  //todo:
  cout << "${name} "  << endl;
  return 0;
}
