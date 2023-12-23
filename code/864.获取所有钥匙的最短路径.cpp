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

/*
 * @lc app=leetcode.cn id=864 lang=cpp
 *
 * [864] 获取所有钥匙的最短路径
 *
 * https://leetcode.cn/problems/shortest-path-to-get-all-keys/description/
 *
 * algorithms
 * Hard (59.25%)
 * Likes:    275
 * Dislikes: 0
 * Total Accepted:    21.7K
 * Total Submissions: 36.7K
 * Testcase Example:  '["@.a..","###.#","b.A.B"]'
 *
 * 给定一个二维网格 grid ，其中：
 * 
 * 
 * '.' 代表一个空房间
 * '#' 代表一堵墙
 * '@' 是起点
 * 小写字母代表钥匙
 * 大写字母代表锁
 * 
 * 
 * 
 * 我们从起点开始出发，一次移动是指向四个基本方向之一行走一个单位空间。我们不能在网格外面行走，也无法穿过一堵墙。如果途经一个钥匙，我们就把它捡起来。除非我们手里有对应的钥匙，否则无法通过锁。
 * 
 * 假设 k 为 钥匙/锁 的个数，且满足 1 <= k <= 6，字母表中的前 k
 * 个字母在网格中都有自己对应的一个小写和一个大写字母。换言之，每个锁有唯一对应的钥匙，每个钥匙也有唯一对应的锁。另外，代表钥匙和锁的字母互为大小写并按字母顺序排列。
 * 
 * 返回获取所有钥匙所需要的移动的最少次数。如果无法获取所有钥匙，返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：grid = ["@.a.#","###.#","b.A.B"]
 * 输出：8
 * 解释：目标是获得所有钥匙，而不是打开所有锁。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：grid = ["@..aA","..B#.","....b"]
 * 输出：6
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: grid = ["@Aa"]
 * 输出: -1
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 30
 * grid[i][j] 只含有 '.', '#', '@', 'a'-'f' 以及 'A'-'F'
 * 钥匙的数目范围是 [1, 6] 
 * 每个钥匙都对应一个 不同 的字母
 * 每个钥匙正好打开一个对应的锁
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool iskey(char f) {
        return f>='a' && f<='z';
    }
    bool isblock(char f) { 
        return f=='#';
    }
    bool islock(char f) {
        return f>='A' && f<='Z';
    }
    struct node  {
        int x;
        int y;
        int mask;
    };
    int shortestPathAllKeys(vector<string>& grid) {
        int n= grid.size();
        if(!n) return 0;
        int m = grid[0].size();
        int state = 0;
        unordered_map<int,int> idxkey;
        unordered_map<int,bool> vis;
        int x=0,y=0;
        for (int i=0;i<grid.size();++i) {
            for (int j=0;j<grid[i].size();j++) {
                if (iskey(grid[i][j])) {
                    idxkey[grid[i][j]] = state++;
                }
                if(grid[i][j] == '@') {
                    x=i,y=j;
                }
            }
        }
        queue<node> q;
        q.push({x,y,0});
        vector<vector<vector<int> > >  dist(n,vector<vector<int> > (m,vector<int> (1<<state,-1)));
        dist[x][y][0] = 0;
        vector<pair<int,int> > dirs = {
            {1,0},
            {0,1},
            {-1,0},
            {0,-1},
        };
        while( q.size()) {
            auto [x,y,mask] = q.front();q.pop();
            for(auto [a,b]: dirs) {
                auto nx = a+x;
                auto ny = b+y;
                if(nx<0 || nx>=n || ny<0||ny>=m) continue;
                auto f= grid[nx][ny];
                if(f == '.' || f == '@') {
                    if (dist[nx][ny][mask] == -1) {
                        dist[nx][ny][mask] = dist[x][y][mask]+1;
                        q.push({nx,ny,mask});
                    }
                }else if(f == '#') {//block
                    continue;
                }else if (islock(f)) {
                    //has lock 
                    auto id = idxkey[(f-'A' +'a')];
                    if ((mask >> id) & 1) {
                        // success 
                        if(dist[nx][ny][mask]==-1) {
                            dist[nx][ny][mask] = dist[x][y][mask]+1;
                            q.push({nx,ny,mask});
                        }
                    }
                }else if (iskey(f)) {
                    auto id = idxkey[f];
                    int m = mask | (1<<id);
                        // success 
                    if(dist[nx][ny][m] == -1) {
                        dist[nx][ny][m] = dist[x][y][mask]+1;
                        q.push({nx,ny,m});
                    } 
                       
                    if (m == (1<<state)-1) {
                        return dist[nx][ny][m];
                    }
                }
            }
        }
        return -1;

    }
    
};
// @lc code=end

int main() {
    cout << " * [864] 获取所有钥匙的最短路径" << endl;
    Solution k;
    vector<string > a = {
        "Dd#b@",".fE.e","##.B.","#.cA.","aF.#C"
    };
    print(k.shortestPathAllKeys(a));

    return 0;
}
