#include <iostream>
#include <string>
#include <unordered_map>
#include <vector >
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 *
 * https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/description/
 *
 * algorithms
 * Medium (60.04%)
 * Likes:    670
 * Dislikes: 0
 * Total Accepted:    61.5K
 * Total Submissions: 102.4K
 * Testcase Example:  '[3,10,5,25,2,8]'
 *
 * 给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [3,10,5,25,2,8]
 * 输出：28
 * 解释：最大运算结果是 5 XOR 25 = 28.
 *
 * 示例 2：
 *
 *
 * 输入：nums = [14,70,53,83,49,91,36,80,92,51,66,70]
 * 输出：127
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 2 * 10^5
 * 0 <= nums[i] <= 2^31 - 1
 *
 *
 *
 *
 */

// @lc code=start
class Node {
public:
    Node *v0;
    Node* v1;
};

// int 有31位，第32为符号位， 0为开始，所以减去1
#define hi (31-1)
class Solution
{
public:
    Node *makeTree(Node *root,int w) {
        if(!root) return NULL;
        // if (w==0) return root;
        for (int k=hi;k>=0;k--) {
            int b = (w>>k) & 1;
            if(b) {
                if(!root->v1)root->v1 = new Node();
                root = root->v1;
            }else {
                if(!root->v0) root->v0 = new Node();
                root = root->v0;
            }
        }
        return root;

    }
 
    int xorTree(Node *p,int x) {
        int ans=0;
        for(int i=hi;i>=0;i--) {
            int b = (x>>i) & 1;
            if(b) {
                // 1 
                if(p->v0) {
                    ans = ans *2 +1;
                    p = p->v0;
                }else if(p->v1) {
                   ans = ans *2;
                    p = p->v1;
                }

            }else {
                // 0
                if(p->v1) {
                    ans = ans *2 +1;
                    p = p->v1;
                }else{
                    p = p->v0;
                    ans = ans *2;
                }
            }
        }
        return ans;
         
    }
    int findMaximumXOR(vector<int> &nums)
    {
        Node p = {NULL,NULL};
       
        int ans=0;
        // 经可能为1
        for(int i=1,n= nums.size();i<n;i++) {
            // xor是对称的， a^b = b^a ,这样只需要遍历1遍即可
            makeTree(&p,nums[i-1]);
            ans = max(ans,xorTree(&p,nums[i]));
        }
        // 0 ^ 0 =>0
        // 0 ^ 1 => 1
        // 1 ^ 1 => 0
        return ans;
    }
};
// @lc code=end

int main()
{
    cout << " * [421] 数组中两个数的最大异或值" << endl;
    Solution k;
    vector<int> ans = { 0,8 };

    cout << "result:  " << k.findMaximumXOR(ans) << endl;
    return 0;
}
