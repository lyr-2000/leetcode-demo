#include <bits/stdc++.h>
using namespace std;

#define print(a) cout << a << " "
#define printn(a) cout << a << endl
void printa(vector<int> &a) {
  for (int w : a)
    print(w);
  printn("");
}
void printa2(vector<vector<int>> &a) {
  for (auto f : a)
    printa(f);
}
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void printt(const std::string &prefix, const TreeNode *node, bool isLeft) {
  if (node != nullptr) {
    cout << prefix;
    cout << (isLeft ? "├──" : "└──");
    cout << node->val << endl;
    printt(prefix + (isLeft ? "│ " : " "), node->left, true);
    printt(prefix + (isLeft ? "│ " : " "), node->right, false);
  }
}
TreeNode *makeTree(vector<int> levelOrder) {
  if (levelOrder.empty()) {
    return NULL;
  }
  queue<TreeNode *> q;
  TreeNode *root = new TreeNode(levelOrder[0]);
  q.push(root);
  int i = 1;
  while (!q.empty() && i < levelOrder.size()) {
    TreeNode *node = q.front();
    q.pop();
    if (levelOrder[i] != -1) {
      node->left = new TreeNode(levelOrder[i]);
      q.push(node->left);
    }
    i++;
    if (i < levelOrder.size() && levelOrder[i] != -1) {
      node->right = new TreeNode(levelOrder[i]);
      q.push(node->right);
    }
    i++;
  }
  return root;
}
ListNode *makeLinkedList(vector<int> w) {
  if (w.size() == 0)
    return NULL;
  ListNode *p = new ListNode(w[0]);
  ListNode *h = p;
  for (int i = 1; i < w.size(); i++)
    p->next = new ListNode(w[i]), p = p->next;
  return h;
}
void printl(ListNode *h) {
  while (h) {
    print(h->val);
    h = h->next;
  }
  printn("");
}
string itoa2(int a = 0, int len = 31) {
  string s = "";
  while (a) {
    s.push_back(a % 2 + '0');
    a /= 2;
  }
  int off = len - s.size();
  while (off-- > 0) {
    printf("%c", '0');
  }
  reverse(s.begin(), s.end());
  return s;
}

/*
 * @lc app=leetcode.cn id=1797 lang=cpp
 *
 * [1797] 设计一个验证系统
 *
 * https://leetcode.cn/problems/design-authentication-manager/description/
 *
 * algorithms
 * Medium (64.70%)
 * Likes:    89
 * Dislikes: 0
 * Total Accepted:    33.2K
 * Total Submissions: 51.3K
 * Testcase Example:
 '["AuthenticationManager","renew","generate","countUnexpiredTokens","generate","renew","renew","countUnexpiredTokens"]\n'
 +
  '[[5],["aaa",1],["aaa",2],[6],["bbb",7],["aaa",8],["bbb",10],[15]]'
 *
 * 你需要设计一个包含验证码的验证系统。每一次验证中，用户会收到一个新的验证码，这个验证码在 currentTime 时刻之后 timeToLive
 * 秒过期。如果验证码被更新了，那么它会在 currentTime （可能与之前的
 currentTime 不同）时刻延长 timeToLive 秒。
 *
 * 请你实现 AuthenticationManager 类：
 *
 *
 * AuthenticationManager(int timeToLive) 构造 AuthenticationManager 并设置
 * timeToLive 参数。
 * generate(string tokenId, int currentTime) 给定
 tokenId ，在当前时间 currentTime
 * 生成一个新的验证码。
 * renew(string tokenId, int currentTime) 将给定 tokenId 且 未过期 的验证码在
 currentTime
 * 时刻更新。如果给定 tokenId 对应的验证码不存在或已过期，请你忽略该操作，不会有任何更新操作发生。
 * countUnexpiredTokens(int
 currentTime) 请返回在给定 currentTime 时刻，未过期 的验证码数目。
 *
 *
 * 如果一个验证码在时刻 t 过期，且另一个操作恰好在时刻 t 发生（renew 或者 countUnexpiredTokens 操作），过期事件 优先于
 * 其他操作。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：
 * ["AuthenticationManager", "renew", "generate", "countUnexpiredTokens",
 * "generate", "renew", "renew", "countUnexpiredTokens"]
 * [[5], ["aaa", 1], ["aaa", 2], [6], ["bbb", 7], ["aaa", 8], ["bbb", 10],
 * [15]]
 * 输出：
 * [null, null, null, 1, null, null, null, 0]
 *
 * 解释：
 * AuthenticationManager authenticationManager = new AuthenticationManager(5);
 * // 构造 AuthenticationManager ，设置 timeToLive = 5 秒。
 * authenticationManager.renew("aaa", 1); // 时刻 1 时，没有验证码的 tokenId 为
 "aaa"
 * ，没有验证码被更新。
 * authenticationManager.generate("aaa", 2); // 时刻 2 时，生成一个 tokenId 为
 "aaa"
 * 的新验证码。
 * authenticationManager.countUnexpiredTokens(6); // 时刻 6 时，只有 tokenId 为
 "aaa"
 * 的验证码未过期，所以返回 1 。
 * authenticationManager.generate("bbb", 7); // 时刻 7 时，生成一个 tokenId 为
 "bbb"
 * 的新验证码。
 * authenticationManager.renew("aaa", 8); // tokenId 为 "aaa" 的验证码在时刻 7
 过期，且 8
 * >= 7 ，所以时刻 8 的renew 操作被忽略，没有验证码被更新。
 * authenticationManager.renew("bbb", 10); // tokenId 为 "bbb" 的验证码在时刻 10
 * 没有过期，所以 renew 操作会执行，该 token 将在时刻 15 过期。
 * authenticationManager.countUnexpiredTokens(15); // tokenId 为 "bbb"
 的验证码在时刻
 * 15 过期，tokenId 为 "aaa" 的验证码在时刻 7 过期，所有验证码均已过期，所以返回
 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * 1
 * tokenId 只包含小写英文字母。
 * 所有 generate 函数的调用都会包含独一无二的 tokenId 值。
 * 所有函数调用中，currentTime 的值 严格递增 。
 * 所有函数的调用次数总共不超过 2000 次。
 *
 *
 */

// @lc code=start
class AuthenticationManager {
public:
  unordered_map<string, int> idx;
  int ttl;
  AuthenticationManager(int timeToLive) { this->ttl = timeToLive; }

  void generate(string tokenId, int currentTime) {
    idx[tokenId] = currentTime + this->ttl;
  }

  void renew(string tokenId, int currentTime) {
    if (idx[tokenId] <= currentTime)
      return;
    idx[tokenId] = currentTime + this->ttl;
  }

  int countUnexpiredTokens(int currentTime) {
    int t = 0;
    for (auto [k, v] : this->idx) {
      if (v > currentTime) {
        ++t;
      }
    }
    return t;
  }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
// @lc code=end

int main() {
  cout << " * [1797] 设计一个验证系统" << endl;
  auto k = new AuthenticationManager(5);
  k->renew("aaa", 1);
  k->generate("aaa", 2);
  k->generate("bbb", 7);
  k->renew("aaa", 8);
  k->renew("bbb", 10);
  print(k->countUnexpiredTokens(15));
  return 0;
}
