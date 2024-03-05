#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
// int q[N];
vector<int> q ;
int sz;
int u;
int t = 0;

int l = 0, r = 0;
void push(int x) {
  if (l == (r + 1) % sz) {
    puts("full");
    return;
  }
  q[r ] = x;
  r = (r + 1) % sz;
}
void pop() {
  if (l == r) {
    puts("empty");
    return;
  }
  cout << q[l++] << endl;
  l %= sz;
}
void front() {
  if (l == r) {
    puts("empty");
    return;
  }
  cout << q[l] << endl;
}
int main() {
  cin >> sz >> u;
  sz++;
  q.resize(sz);
  while (u--) {
    string a;
    cin >> a;
    if (a == "push") {
      cin >> t;
      push(t);
    } else if (a == "pop") {
      pop();
    } else {
      // front
      front();
    }
  }
  return 0;
}
