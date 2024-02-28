#include <bits/stdc++.h>
using namespace std;

struct Node {

  int val;
  int key;
  Node *next;
  Node *prev;
  Node() {
    this->next = nullptr;
    this->prev = nullptr;
    this->key = 0;
    this->val = 9999;
  }
};
class Solution {

public:
  Solution(int capacity) {
    // write code here
    cap = capacity;
    first = new Node();
    tail = new Node();

    tail->next = NULL;
    first->prev = NULL;
    link(first, tail);
  }
  int cap;

  unordered_map<int, Node *> tab;
  Node *first;
  Node *tail;
  void link(Node *l, Node *r) {
    if(l && r) {
        l->next = r;
        r->prev = l;
    }
  }
  void printlist() {
    auto x = first;
    while(x) {
        cout <<"{"<<x->key<<"," <<x->val << "} -> ";
        x=x->next;
    }
    cout <<endl;

  }
  void remove(Node *x, int key) {
    // cout << x->val << " " << key << endl;
    //  if(x == first) return;
    auto p = x->prev;
    auto n = x->next;

    x->next = NULL;
    x->prev = NULL;
    link(p, n);
    if (key >= 0) {
      tab.erase(key);
    }
  }
  void puthead(Node *x) {
    auto right = first->next;
    link(first, x);
    link(x, right);
  }

  int get(int key) {
    printlist();
    // write code here
    if (!tab.count(key))
      return -1;
    auto n = tab[key];
    remove(n, -1);
    puthead(n);
    return n->val;
  }

  void set(int key, int value) {
        printlist();
    // write code here
    bool ok = tab.count(key);
    if (ok) {
      get(key);
      tab[key]->val = value;
    } else {
      if (tab.size() >= cap) {
        remove(tail->prev, tail->prev->key);
      }
      // insert
      auto n = new Node();
      n->val = value;
      n->key = key;
      tab[key] = n;
      puthead(n);
    }
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* solution = new Solution(capacity);
 * int output = solution->get(key);
 * solution->set(key,value);
 */

int main(void) {
  auto p = Solution(2);
  p.set(1, 2);
  p.set(2, 2);
  p.get(1);
  p.set(3, 3);
  p.get(2);
  p.set(4, 4);
  p.get(1);
  p.get(3);
  p.get(4);
  return 0;
}