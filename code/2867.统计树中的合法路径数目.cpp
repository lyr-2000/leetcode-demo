#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
#define debug 1
void print() {}
template <typename T>
void echo(const T &t) { cout << t << " "; }
template <typename T>
void echo(vector<T> const &t) {for (auto w: t) echo(w); }
template <typename T>
void echo(vector<vector<T>> const &a) { for (auto f:a) echo(f); }
template<typename Head, typename... Args>
void print(const Head& head, const Args&... args ) { echo(head); print(args...); }
#define println(...) print(__VA_ARGS__),cout <<endl
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };
struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {} };
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) { if (node != nullptr) { cout << prefix; cout << (isLeft ? "├──" : "└──"); cout << node->val << endl; printt(prefix + (isLeft ? "│ " : " "), node->left, true); printt(prefix + (isLeft ? "│ " : " "), node->right, false); } }
void print(const ListNode *h) { while(h) { print(h->val); h = h->next; } println("");}
void print(const TreeNode *node) { printt("",node,false);}
TreeNode* makeTree(vector<int> levelOrder) { if (levelOrder.empty()) { return NULL; } queue<TreeNode*> q; TreeNode* root = new TreeNode(levelOrder[0]); q.push(root); int i = 1; while (!q.empty() && i < levelOrder.size()) { TreeNode* node = q.front(); q.pop(); if (levelOrder[i] != -1) { node->left = new TreeNode(levelOrder[i]); q.push(node->left); } i++; if (i < levelOrder.size() && levelOrder[i] != -1) { node->right = new TreeNode(levelOrder[i]); q.push(node->right); } i++; } return root; }
ListNode * makeLinkedList(vector<int> w) { if(w.size()==0) return NULL; ListNode *p = new ListNode(w[0]); ListNode *h = p; for (int i=1;i<w.size();i++) p->next = new ListNode(w[i]),p=p->next; return h; }
string bin(int a =0,int len=31) { string s = ""; while(a) { s.push_back(a%2 + '0'); a/=2; } int off = len - s.size(); while(off-->0) { printf("%c",'0'); } reverse(s.begin(),s.end()); return s; }
/* clang-format on */

/*

<!-- @lc app=leetcode.cn id=2867 lang=cpp -->

[leetcode
2867.统计树中的合法路径数目](https://leetcode.cn/problems/count-valid-paths-in-a-tree/description/)


algorithms
Hard (34.50%)
Likes:    17
Dislikes: 0
Total Accepted:    2.7K
Total Submissions: 7.8K
Testcase Example:  '5\n[[1,2],[1,3],[2,4],[2,5]]'

给你一棵 n 个节点的无向树，节点编号为 1 到 n 。给你一个整数 n 和一个长度为 n -
1 的二维整数数组 edges ，其中 edges[i] = [ui, vi] 表示节点 ui
和 vi 在树中有一条边。

请你返回树中的 合法路径数目 。

如果在节点 a 到节点 b 之间 恰好有一个 节点的编号是质数，那么我们称路径 (a, b) 是
合法的 。

注意：


路径 (a, b) 指的是一条从节点 a 开始到节点 b 结束的一个节点序列，序列中的节点
互不相同 ，且相邻节点之间在树上有一条边。 路径 (a, b) 和路径 (b, a) 视为
同一条 路径，且只计入答案 一次 。




示例 1：




输入：n = 5, edges = [[1,2],[1,3],[2,4],[2,5]]
输出：4
解释：恰好有一个质数编号的节点路径有：
- (1, 2) 因为路径 1 到 2 只包含一个质数 2 。
- (1, 3) 因为路径 1 到 3 只包含一个质数 3 。
- (1, 4) 因为路径 1 到 4 只包含一个质数 2 。
- (2, 4) 因为路径 2 到 4 只包含一个质数 2 。
只有 4 条合法路径。


示例 2：




输入：n = 6, edges = [[1,2],[1,3],[2,4],[3,5],[3,6]]
输出：6
解释：恰好有一个质数编号的节点路径有：
- (1, 2) 因为路径 1 到 2 只包含一个质数 2 。
- (1, 3) 因为路径 1 到 3 只包含一个质数 3 。
- (1, 4) 因为路径 1 到 4 只包含一个质数 2 。
- (1, 6) 因为路径 1 到 6 只包含一个质数 3 。
- (2, 4) 因为路径 2 到 4 只包含一个质数 2 。
- (3, 6) 因为路径 3 到 6 只包含一个质数 3 。
只有 6 条合法路径。




提示：


1 <= n <= 10^5
edges.length == n - 1
edges[i].length == 2
1 <= ui, vi <= n
输入保证 edges 形成一棵合法的树。



## 质数筛选法原理

把 2,3,4,5 列出来， 然后依次 把 前面的数的倍数标记为 false，应为是倍速
有因子，一定不是质数，后面没有被标记的就是质数

这题本质上是求一种类似于「非质数-质数-非质数」的路径个数。

这让我想到了另外一道题目 2242. 节点序列的最大得分。

这两题的共同点在于「枚举中间」，请读者细细品味。

作者：灵茶山艾府
链接：https://leetcode.cn/problems/count-valid-paths-in-a-tree/solutions/2456716/tu-jie-on-xian-xing-zuo-fa-pythonjavacgo-tjz2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */

// @lc code=start

const int MX = 1e5;
bool np[MX + 1]; // 质数=false 非质数=true
int init = []() {
    np[1] = true;
    for (int i = 2; i * i <= MX; i++) {
        if (!np[i]) {
            for (int j = i * i; j <= MX; j += i) {
                np[j] = true;
            }
        }
    }
    return 0;
}();

class Solution {
public:
  long long countPaths(int n, vector<vector<int>> &edges) {
    g = vector<vector<int> >(n+1) ;
    for (auto &vc : edges) {
      g[vc[0]].push_back(vc[1]);
      g[vc[1]].push_back(vc[0]);
    }
    vector<int> sizes(n+1) ;
    long long ans=0,sum=0;
    for (int x=1;x<=n;x++) {
        if (np[x]) continue; 
        // x是质数，枚举非质数（l,r)两个端点
        int sum=0;
        for (int y: g[x]) {
            // 是质数不看
            if(!np[y]) continue ;
            if(sizes[y] == 0) {
                nodes.clear();
                dfs(y,-1);
                for (int z:nodes) {
                    sizes[z] = nodes.size();
                }
            }
            ans += (long long) sizes[y] * sum;
            sum += sizes[y];
        }
        ans += sum;
    }
    return ans;
  }

  vector<vector<int>> g;
  vector<int> nodes ;
  void dfs(int j, int fa ) {
    nodes.push_back(j);
    for (int y: g[j]) {
        if (y != fa && np[y]) {
            dfs(y,j);
        }
    }
  }
};
// @lc code=end

int main() {
#ifdef debug
  cout << " * [2867] 统计树中的合法路径数目" << endl;
#endif

  Solution k;
  int n = 4;
  vector<vector<int>> edges{
    {1,2},{1,4},{3,4},
  };
  println(k.countPaths(n, edges));
  return 0;
}
