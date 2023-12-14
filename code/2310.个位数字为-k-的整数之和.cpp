#include <iostream>
using namespace std;
// 解题思路和分析:  任意数 都能表示为 (ai+k) , 那么 给定一个数 a[n] = (a[i?] + k) ,  那么 a[i] 会是一个递归表示 a[i] 只能是 10 * N + k  或者 10 *N

/*
 * @lc app=leetcode.cn id=2310 lang=cpp
 *
 * [2310] 个位数字为 K 的整数之和
 *
 * https://leetcode.cn/problems/sum-of-numbers-with-units-digit-k/description/
 *
 * algorithms
 * Medium (28.01%)
 * Likes:    29
 * Dislikes: 0
 * Total Accepted:    9.5K
 * Total Submissions: 33.8K
 * Testcase Example:  '58\n9'
 *
 * 给你两个整数 num 和 k ，考虑具有以下属性的正整数多重集：
 *
 *
 * 每个整数个位数字都是 k 。
 * 所有整数之和是 num 。
 *
 *
 * 返回该多重集的最小大小，如果不存在这样的多重集，返回 -1 。
 *
 * 注意：
 *
 *
 * 多重集与集合类似，但多重集可以包含多个同一整数，空多重集的和为 0 。
 * 个位数字 是数字最右边的数位。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：num = 58, k = 9
 * 输出：2
 * 解释：
 * 多重集 [9,49] 满足题目条件，和为 58 且每个整数的个位数字是 9 。
 * 另一个满足条件的多重集是 [19,39] 。
 * 可以证明 2 是满足题目条件的多重集的最小长度。
 *
 *
 * 示例 2：
 *
 *
 * 输入：num = 37, k = 2
 * 输出：-1
 * 解释：个位数字为 2 的整数无法相加得到 37 。
 *
 * 示例 3：
 *
 *
 * 输入：num = 0, k = 7
 * 输出：0
 * 解释：空多重集的和为 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= num <= 3000
 * 0 <= k <= 9
 *
 *
 */

// @lc code=start
class Solution {
public:
  int minimumNumbers(int num, int k) {
    if(!num &&!k) return 0;
    int len = 0;
    if(k == 0 && num % 10 == 0) return 1;
    if(k<=0) return -1;
    while (num) {
      if (num < k) {
        return -1;
      }
      num -= k;
      len++;
      if (num % 10 == 0) {
        return len;
      }
    }
    return len;
  }
};
// @lc code=end

int main(void) {

  Solution so;
  // todo:
  cout << "个位数字为 K 的整数之和 " << so.minimumNumbers(10, 0) << endl;
  return 0;
}
