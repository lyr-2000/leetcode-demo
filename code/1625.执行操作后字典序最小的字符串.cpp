#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
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
/* clang-format on */


/*
 * @lc app=leetcode.cn id=1625 lang=cpp
 *
 * [1625] 执行操作后字典序最小的字符串
 *
 * https://leetcode.cn/problems/lexicographically-smallest-string-after-applying-operations/description/
 *
 * algorithms
 * Medium (66.67%)
 * Likes:    116
 * Dislikes: 0
 * Total Accepted:    17.5K
 * Total Submissions: 26.3K
 * Testcase Example:  '"5525"\n9\n2'
 *
 * 给你一个字符串 s 以及两个整数 a 和 b 。其中，字符串 s 的长度为偶数，且仅由数字 0 到 9 组成。
 * 
 * 你可以在 s 上按任意顺序多次执行下面两个操作之一：
 * 
 * 
 * 累加：将  a 加到 s 中所有下标为奇数的元素上（下标从 0 开始）。数字一旦超过 9 就会变成 0，如此循环往复。例如，s = "3456" 且 a
 * = 5，则执行此操作后 s 变成 "3951"。
 * 轮转：将 s 向右轮转 b 位。例如，s = "3456" 且 b = 1，则执行此操作后 s 变成 "6345"。
 * 
 * 
 * 请你返回在 s 上执行上述操作任意次后可以得到的 字典序最小 的字符串。
 * 
 * 如果两个字符串长度相同，那么字符串 a 字典序比字符串 b 小可以这样定义：在 a 和 b 出现不同的第一个位置上，字符串 a
 * 中的字符出现在字母表中的时间早于 b 中的对应字符。例如，"0158” 字典序比 "0190" 小，因为不同的第一个位置是在第三个字符，显然 '5'
 * 出现在 '9' 之前。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "5525", a = 9, b = 2
 * 输出："2050"
 * 解释：执行操作如下：
 * 初态："5525"
 * 轮转："2555"
 * 累加："2454"
 * 累加："2353"
 * 轮转："5323"
 * 累加："5222"
 * 累加："5121"
 * 轮转："2151"
 * 累加："2050"​​​​​
 * 无法获得字典序小于 "2050" 的字符串。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "74", a = 5, b = 1
 * 输出："24"
 * 解释：执行操作如下：
 * 初态："74"
 * 轮转："47"
 * 累加："42"
 * 轮转："24"​​​​​
 * 无法获得字典序小于 "24" 的字符串。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "0011", a = 4, b = 2
 * 输出："0011"
 * 解释：无法获得字典序小于 "0011" 的字符串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= s.length <= 100
 * s.length 是偶数
 * s 仅由数字 0 到 9 组成
 * 1 <= a <= 9
 * 1 <= b <= s.length - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string ans="";
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string ss(n,'9');
        ans = ss;
        dfs(s,a,b);

        return ans;
    }
    unordered_set<string> se;
    string rotate(string s,int b) {
        string news = s+s;
        string xx = news.substr(b,s.size());
        return xx;
    }
    string adda(string s,int a) {
        int n= s.size();
        for (int i=1;i<n;i+=2) {
            int k = s[i] - '0';
            int res = (k+a) % 10;
            s[i] = res + '0';
        }
        return s;
    }
    void dfs(string s,int a,int b) {
        if (se.count(s)) {
            return ;
        }
        if (s < ans) {
            ans = s;
        }
        se.insert(s);
        string l = rotate(s,b);
        string r = adda(s,a);
        dfs(l,a,b);
        dfs(r,a,b);
    }
};
// @lc code=end

int main() {
    cout << " * [1625] 执行操作后字典序最小的字符串" << endl;
    Solution k;
    
//  * 初态："5525"
//  * 轮转："2555"
    // cout << k.rotate("5525",2) <<endl;
    cout << k.findLexSmallestString("5525",9,2) <<endl;
    return 0;
}
