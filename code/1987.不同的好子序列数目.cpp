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
 * @lc app=leetcode.cn id=1987 lang=cpp
 *
 * [1987] 不同的好子序列数目
 *
 * https://leetcode.cn/problems/number-of-unique-good-subsequences/description/
 *
 * algorithms
 * Hard (51.16%)
 * Likes:    54
 * Dislikes: 0
 * Total Accepted:    2.7K
 * Total Submissions: 5.2K
 * Testcase Example:  '"001"'
 *
 * 给你一个二进制字符串 binary 。 binary 的一个 子序列 如果是 非空 的且没有 前导 0 （除非数字是 "0" 本身），那么它就是一个 好
 * 的子序列。
 * 
 * 请你找到 binary 不同好子序列 的数目。
 * 
 * 
 * 比方说，如果 binary = "001" ，那么所有 好 子序列为 ["0", "0", "1"] ，所以 不同 的好子序列为 "0" 和 "1" 。
 * 注意，子序列 "00" ，"01" 和 "001" 不是好的，因为它们有前导 0 。
 * 
 * 
 * 请你返回 binary 中 不同好子序列 的数目。由于答案可能很大，请将它对 10^9 + 7 取余 后返回。
 * 
 * 一个 子序列 指的是从原数组中删除若干个（可以一个也不删除）元素后，不改变剩余元素顺序得到的序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：binary = "001"
 * 输出：2
 * 解释：好的二进制子序列为 ["0", "0", "1"] 。
 * 不同的好子序列为 "0" 和 "1" 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：binary = "11"
 * 输出：2
 * 解释：好的二进制子序列为 ["1", "1", "11"] 。
 * 不同的好子序列为 "1" 和 "11" 。
 * 
 * 示例 3：
 * 
 * 输入：binary = "101"
 * 输出：5
 * 解释：好的二进制子序列为 ["1", "0", "1", "10", "11", "101"] 。
 * 不同的好子序列为 "0" ，"1" ，"10" ，"11" 和 "101" 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= binary.length <= 10^5
 * binary 只含有 '0' 和 '1' 。
 * 
 * 
 */

/*
尝试构造状态dp[i]，表示截止第i个字符为止，我们能够创建的distinct子序列有多少．对于这个dp[i]的定义，我们并不要求s[i]必须是子序列的一部分。

接下来，对于第i个字符ch，我们尝试思考它如何参与到已有子序列dp[i-1]的构建来．

情况I:如果它不参与到子序列的构建，那么dp[i-1]有多少子序列，dp[i]一定会保留全部的这些，所以dp[i]+=dp[i-1]。举个例子，如果对于dp[i-1]已经有了如下的不同子序列
XXXX   (1)
XXX    (2) 
XXX    (3)
XX     (4)

那么对于dp[i]而言，以上这些字符串仍然是其一部分。

情况II:如果它参与到子序列的构建，那么dp[i-1]有多少子序列（包括空序列），末位加上S[i]之后，就能生成同样数目的新子序列．所以继续有dp[i]+=dp[i-1]．假设s[i]=='a'，那么我们就可以构造出新的子序列（接上面的例子

XXXXa (5)
XXXa  (6)
XXXa  (7)
XXa   (8)


所以综合一下，dp[i]=dp[i-1]*2 (*)

但是我们显然要处理一种重复的情况，比如说(1)和(6)会不会重复？出现重复的原因在于，如果(1)中的最后一个字符也是'a'，当(1)中的前三个字符和(6)中的前三个字符的来源相同时，这些序列的数目就在(*)式里面被重复计算了两遍。

如何去掉这个重复呢？对于(1)而言，我们需要定位第四个字符'a'的位置j。这个j是i之前最后一次出现字符'a'的index。我们可以验证，dp[j-1]所对应子序列xxx，加上s[j]，可以得到"xxxa"的形式；同时dp[j-1]所对应子序列xxx，加上s[i]，也可以得到"xxxa"的形式。这两部分的子序列是完全相同的，是被(*)式所重复计算的，所以我们需要减去。

所以综上，dp[i]的更新式子是:dp[i] = dp[i-1]*2-dp[j-1]其中j就是i前面最后一个满足S[j]==S[i]的index。


此题是字符串序列的一道经典题。如果第一次做的话，可能会觉得有难度。

尝试构造状态dp[i]，表示截止第i个字符为止，我们能够创建的distinct子序列有多少．对于这个dp[i]的定义，我们并不要求s[i]必须是子序列的一部分。

*/

// @lc code=start
class Solution {
public:
    long M = 1e9 + 7;
    int numberOfUniqueGoodSubsequences(string s) {
        int n = s.size();
        if(!n) return 0;
        if(n==1) return 1;
        // unordered_map<char,int> m;
        // dp[0][1] = 1;
        int w  = 0;
        long long v[2] = {0,0};
        for (int i=1;i<=n;i++) {
            char c = s[i-1];
            if (c == '0') {
                w = 1;
                v[0] = (v[0] + v[1]) %M;
            }else {
                v[1] = (v[0] + v[1]+1) %M;
            }
        }
        return (w + v[0] + v[1] ) % M;
    }
};
// @lc code=end

int main() {
    cout << " * [1987] 不同的好子序列数目" << endl;
    Solution k;
    print (  k.numberOfUniqueGoodSubsequences("101") );
    return 0;
}
