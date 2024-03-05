#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> l(n),r(n) ;
    for(int i=0;i<n;i++)
        cin>>a[i];

    stack<int> s;
    for(int i=0;i<n;i++) {
        if(s.size()) {
            while(s.size() && a[s.top()] < a[i]) {
                s.pop();
            }
            l[i] = s.size();
        }
        s.push(i);
    }
    while(s.size()) s.pop();
    for(int i=n-1;i>=0;i--) {
        while(s.size() && a[i] > a[s.top()]) {
            s.pop();
        }    
        r[i] = s.size();
        s.push(i);
    }
    for(int i=0;i<n;i++) {
        printf("%d ",n -(l[i]+r[i])-1);
    }
    return 0;
}

