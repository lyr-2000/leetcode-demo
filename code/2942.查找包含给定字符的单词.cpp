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

<!-- @lc app=leetcode.cn id=2942 lang=cpp -->

[leetcode 2942.查找包含给定字符的单词](https://leetcode.cn/problems/find-words-containing-character/description/)


algorithms
Easy (89.60%)
Likes:    1
Dislikes: 0
Total Accepted:    4.5K
Total Submissions: 5.1K
Testcase Example:  '["leet","code"]\n"e"'

给你一个下标从 0 开始的字符串数组 words 和一个字符 x 。

请你返回一个 下标数组 ，表示下标在数组中对应的单词包含字符 x 。

注意 ，返回的数组可以是 任意 顺序。



示例 1：


输入：words = ["leet","code"], x = "e"
输出：[0,1]
解释："e" 在两个单词中都出现了："leet" 和 "code" 。所以我们返回下标 0 和 1 。


示例 2：


输入：words = ["abc","bcd","aaaa","cbc"], x = "a"
输出：[0,2]
解释："a" 在 "abc" 和 "aaaa" 中出现了，所以我们返回下标 0 和 2 。


示例 3：


输入：words = ["abc","bcd","aaaa","cbc"], x = "z"
输出：[]
解释："z" 没有在任何单词中出现。所以我们返回空数组。




提示：


1 <= words.length <= 50
1 <= words[i].length <= 50
x 是一个小写英文字母。
words[i] 只包含小写英文字母。




 */

// @lc code=start
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        int n = words.size();
        for (int i=0;i<n;i++) {
            auto &s = words[i];
            for (char f: s) {
                if (f == x) {
                    res.push_back(i);
                    break;
                }
            }
        } 
        return res;
    }
};
// @lc code=end

int main() {
    #ifdef debug
    cout << " * [2942] 查找包含给定字符的单词" << endl;
    #endif

    Solution k;
    vector<string> res = {"ae","f"};
    auto out =  k.findWordsContaining(res,'a');
    printa(out);
    return 0;
}
