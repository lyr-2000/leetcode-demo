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
 * @lc app=leetcode.cn id=2926 lang=cpp
 *
 * [2926] 平衡子序列的最大和
 *
 * https://leetcode.cn/problems/maximum-balanced-subsequence-sum/description/
 *
 * algorithms
 * Hard (37.65%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    2.7K
 * Total Submissions: 7.1K
 * Testcase Example:  '[3,3,5,6]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。
 * 
 * nums 一个长度为 k 的 子序列 指的是选出 k 个 下标 i0 < i1 < ... < ik-1 ，如果这个子序列满足以下条件，我们说它是
 * 平衡的 ：
 * 
 * 
 * 对于范围 [1, k - 1] 内的所有 j ，nums[ij] - nums[ij-1] >= ij - ij-1 都成立。
 * 
 * 
 * nums 长度为 1 的 子序列 是平衡的。
 * 
 * 请你返回一个整数，表示 nums 平衡 子序列里面的 最大元素和 。
 * 
 * 一个数组的 子序列 指的是从原数组中删除一些元素（也可能一个元素也不删除）后，剩余元素保持相对顺序得到的 非空 新数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,3,5,6]
 * 输出：14
 * 解释：这个例子中，选择子序列 [3,5,6] ，下标为 0 ，2 和 3 的元素被选中。
 * nums[2] - nums[0] >= 2 - 0 。
 * nums[3] - nums[2] >= 3 - 2 。
 * 所以，这是一个平衡子序列，且它的和是所有平衡子序列里最大的。
 * 包含下标 1 ，2 和 3 的子序列也是一个平衡的子序列。
 * 最大平衡子序列和为 14 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,-1,-3,8]
 * 输出：13
 * 解释：这个例子中，选择子序列 [5,8] ，下标为 0 和 3 的元素被选中。
 * nums[3] - nums[0] >= 3 - 0 。
 * 所以，这是一个平衡子序列，且它的和是所有平衡子序列里最大的。
 * 最大平衡子序列和为 13 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [-2,-1]
 * 输出：-1
 * 解释：这个例子中，选择子序列 [-1] 。
 * 这是一个平衡子序列，而且它的和是 nums 所有平衡子序列里最大的。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
    /*
nums[i] - i >= nums[j] -j 
b[i] = nums[i] - i 
求 b[i] 是递增的序列
即转化为 求最长递增子序列问题

f[i] = 以下标i结尾的子序列，对应 nums的元素合的最大值 

f[i] = f[j] + nums[i]
j 满足 b[j] <= b[i] and j<i

在从左到右 遍历的情况下：一定满足 j<i
只要要 b[j] <= b[i] 即可 

 用若干个小区间合并为一个大区间
 树状数组模板
【树形 DP + 树状数组优化 DP【力扣周赛 370】】 【精准空降到 44:54】 https://www.bilibili.com/video/BV1Fc411R7xA/?share_source=copy_web&vd_source=74fd53b3c51a4a795f4749ab033306f4&t=2694
    */
public:
    #define ll long long
    #define lowbit(x) x & (-x)
    vector<ll> tree;
    void update(int i,ll val) {
        while (i && i<tree.size()) {
            tree[i] = max(tree[i],val);
            i+= i & -i;
        }
    }
    long long premax(int i) {
        ll mx= INT_MIN;
        while (i>0) {
            mx = max(mx,tree[i]);
            i -= i & -i;
        }
        return mx;
    }
    
/* 
数组a:  -3 6  -1  2
转化为 rank数组： 
        1 4   2   3
例如 6是最大的排在第 4位, 通过离散化映射下标，就能使用数组了
  */
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        auto b = remap0(nums) ;
        // for (int i=0;)r
        #ifdef printa
        printa(nums);
        printa(b);
        #endif
        tree.resize(b.size()+1,0);
        ll ans= -1e9;
        int n = nums.size();
        for (int i=0;i<n;i++) {
            int rank = lower_bound(b.begin(),b.end(),nums[i] - i) - b.begin()+1;
            // ll curmax = max(premax(rank) + (nums[i] ), (ll) nums[i]);
            ll curmax = max(premax(rank),(ll)0) + nums[i];
            update(rank,curmax);
            ans = max(ans,curmax);
        }
        return ans;
    }
    vector<int> remap0(vector<int> &nums) {
        auto b = nums;
        int n = nums.size();
        for (int i=0;i<n;i++) {
            b[i] -= i;
        }     
        sort(b.begin(),b.end());
        b.erase( unique(b.begin(),b.end()),b.end());
        return b;
    }
    vector<int> remap(vector<int> &nums ) {
        vector<int>  b = nums;
        int n = nums.size();
        for (int i=0;i<n;i++) {
            b[i] -= i;
        }     
        sort(b.begin(),b.end());
        unordered_set<int> se;
        vector<int> news;
        for (int k:b) {
            if(!se.count(k)) {
                se.insert(k);
                news.push_back(k);
            }
        } 
        return news;
    }
};
// @lc code=end

int main() {
    cout << " * [2926] 平衡子序列的最大和" << endl;
    Solution k;
    vector<int> a = {3,3,5,6};
    cout << k.maxBalancedSubsequenceSum(a)<<endl;
    return 0;
}

