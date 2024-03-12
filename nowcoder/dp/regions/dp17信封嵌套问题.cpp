#include <bits/stdc++.h>
using namespace std;

bool lte(pair<int,int>x,pair<int,int>y) {
    return x.first <= y.first && x.second<=y.second;
}
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i].first >> a[i].second;
  if(n==1) {
    puts("1");
    return 0;
  }

  // 转化为最长上升子序列问题
  sort(a.begin(), a.end());
  vector<pair<int,int>> tail(n);
  int flag=0;
  for (int i = 0; i < n; i++) {
    if(flag==0) tail[flag++] = a[i];
    else {
        int l=0,r=flag-1;
        while(l<r) {
            int m = (l+r)/2;
            if(lte(tail[m],a[i])) //a[i]>=a[m]
            {
                r=m;
            }else { //a[i] < a[m]
                l = m+1;
            }
        }
        if(lte(tail[r],a[i])) {
            tail[r] = a[i];
        }else {
            tail[++flag] = a[i];
        }
    }
  }

  cout << flag << endl;
  return 0;
}
