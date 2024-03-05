#include <bits/stdc++.h>
using namespace std;

// 字符{a, b, c, d}，对应次数{1, 3, 8, 2}，如图所示：

int main()
{
    priority_queue<int,vector<int>,greater<int>> q;
    int n;cin>>n;
    int t;
    for(int i=0;i<n;i++) {
        cin>>t;
        q.push(t);
    }
    while(q.size()) {
        int l = q.top();
        

    }
    return 0;
}

