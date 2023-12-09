#include <iostream>
#include <string>
#include <unordered_map>
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
    Node *left;
    Node* right;
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
    }
};
// @lc code=end

int main()
{
    cout << " * [421] 数组中两个数的最大异或值" << endl;
    Solution k;
    auto ans = {1, 2, 3, 3, 5};

    cout << "result:  " << k.findMaximumXOR(ans) << endl;
    return 0;
}
