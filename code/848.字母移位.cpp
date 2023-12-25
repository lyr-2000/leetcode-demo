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
 * @lc app=leetcode.cn id=848 lang=cpp
 *
 * [848] 字母移位
 *
 * https://leetcode.cn/problems/shifting-letters/description/
 *
 * algorithms
 * Medium (46.41%)
 * Likes:    74
 * Dislikes: 0
 * Total Accepted:    15.1K
 * Total Submissions: 32.4K
 * Testcase Example:  '"abc"\n[3,5,9]'
 *
 * 有一个由小写字母组成的字符串 s，和一个长度相同的整数数组 shifts。
 * 
 * 我们将字母表中的下一个字母称为原字母的 移位 shift() （由于字母表是环绕的， 'z' 将会变成 'a'）。
 * 
 * 
 * 例如，shift('a') = 'b', shift('t') = 'u', 以及 shift('z') = 'a'。
 * 
 * 
 * 对于每个 shifts[i] = x ， 我们会将 s 中的前 i + 1 个字母移位 x 次。
 * 
 * 返回 将所有这些移位都应用到 s 后最终得到的字符串 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abc", shifts = [3,5,9]
 * 输出："rpl"
 * 解释： 
 * 我们以 "abc" 开始。
 * 将 S 中的第 1 个字母移位 3 次后，我们得到 "dbc"。
 * 再将 S 中的前 2 个字母移位 5 次后，我们得到 "igc"。
 * 最后将 S 中的这 3 个字母移位 9 次后，我们得到答案 "rpl"。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "aaa", shifts = [1,2,3]
 * 输出: "gfd"
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 由小写英文字母组成
 * shifts.length == s.length
 * 0 <= shifts[i] <= 10^9
 * 
 * ​​​​​​
 */

// @lc code=start
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        uint32_t b = 0;
        for (int n=shifts.size(),i=n-1;i>=0;i--) {
            // for (int j=0;j<=i;j++) {
            b+= shifts[i];
            b %= 26;
            int offset = ((s[i] - 'a') + b) % 26;
            s[i] = 'a' + offset;
        }
        return s;
    }
};
// @lc code=end

int main() {
    cout << " * [848] 字母移位" << endl;
    Solution k;

    string s = "abc";
    vector<int>  shifts = {3,5,9};
    print(  k.shiftingLetters(s,shifts) )    ;
    return 0;
}
