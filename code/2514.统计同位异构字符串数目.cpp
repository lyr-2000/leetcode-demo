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
 * @lc app=leetcode.cn id=2514 lang=cpp
 *
 * [2514] 统计同位异构字符串数目
 *
 * https://leetcode.cn/problems/count-anagrams/description/
 *
 * algorithms
 * Hard (46.62%)
 * Likes:    16
 * Dislikes: 0
 * Total Accepted:    2.6K
 * Total Submissions: 5.6K
 * Testcase Example:  '"too hot"'
 *
 * 给你一个字符串 s ，它包含一个或者多个单词。单词之间用单个空格 ' ' 隔开。
 * 
 * 如果字符串 t 中第 i 个单词是 s 中第 i 个单词的一个 排列 ，那么我们称字符串 t 是字符串 s 的同位异构字符串。
 * 
 * 
 * 比方说，"acb dfe" 是 "abc def" 的同位异构字符串，但是 "def cab" 和 "adc bef" 不是。
 * 
 * 
 * 请你返回 s 的同位异构字符串的数目，由于答案可能很大，请你将它对 10^9 + 7 取余 后返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "too hot"
 * 输出：18
 * 解释：输入字符串的一些同位异构字符串为 "too hot" ，"oot hot" ，"oto toh" ，"too toh" 以及 "too oht"
 * 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "aa"
 * 输出：1
 * 解释：输入字符串只有一个同位异构字符串。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 只包含小写英文字母和空格 ' ' 。
 * 相邻单词之间由单个空格隔开。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countAnagrams(string s) {
        
    }
};
// @lc code=end

int main() {
    cout << " * [2514] 统计同位异构字符串数目" << endl;
    Solution k;
    

    return 0;
}
