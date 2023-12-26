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
 * @lc app=leetcode.cn id=2193 lang=cpp
 *
 * [2193] 得到回文串的最少操作次数
 *
 * https://leetcode.cn/problems/minimum-number-of-moves-to-make-palindrome/description/
 *
 * algorithms
 * Hard (49.26%)
 * Likes:    53
 * Dislikes: 0
 * Total Accepted:    3.6K
 * Total Submissions: 7.3K
 * Testcase Example:  '"aabb"'
 *
 * 给你一个只包含小写英文字母的字符串 s 。
 * 
 * 每一次 操作 ，你可以选择 s 中两个 相邻 的字符，并将它们交换。
 * 
 * 请你返回将 s 变成回文串的 最少操作次数 。
 * 
 * 注意 ，输入数据会确保 s 一定能变成一个回文串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "aabb"
 * 输出：2
 * 解释：
 * 我们可以将 s 变成 2 个回文串，"abba" 和 "baab" 。
 * - 我们可以通过 2 次操作得到 "abba" ："aabb" -> "abab" -> "abba" 。
 * - 我们可以通过 2 次操作得到 "baab" ："aabb" -> "abab" -> "baab" 。
 * 因此，得到回文串的最少总操作次数为 2 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "letelt"
 * 输出：2
 * 解释：
 * 通过 2 次操作从 s 能得到回文串 "lettel" 。
 * 其中一种方法是："letelt" -> "letetl" -> "lettel" 。
 * 其他回文串比方说 "tleelt" 也可以通过 2 次操作得到。
 * 可以证明少于 2 次操作，无法得到回文串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 2000
 * s 只包含小写英文字母。
 * s 可以通过有限次操作得到一个回文串。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
    //    unordered_map<char,int> mp;
    //    for(char k:s) {
    //         if(mp[k]) mp[k]--;
    //         else {
    //             mp[k]++;
    //         }
    //    } 
    //    int cnt=0;
    //    for (auto [k,v]: mp) {
    //      if(cnt && (v & 1)==1) {
    //         return 0;
    //      } 
    //    }
    // 一定会变回文 
        return dp(s);
    }
    int dp(string s) {
        int n = s.size();
        if(n<=1) return 0;
        for (int i=n-1;i>0;i--) 
        {
            if (s[i] == s[0]) {
                //  i  
                //a a b  N:
                //0 1 2  3
                int sz = n-i-1;
                // aabb 
                auto ns = s.substr(1,i-1) + s.substr(i+1);
                // cout << ns<<endl;
                return sz + dp(ns);
            }
        }
        int m = n/2;
        return m + dp(s.substr(1));
    }
};
// @lc code=end

int main() {
    cout << " * [2193] 得到回文串的最少操作次数" << endl;
    Solution k;
    
    print(k.minMovesToMakePalindrome("aabb"));
    return 0;
}
