#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n) ;
    for(int i=0;i<n;i++)
        cin>>a[i];
    // vector<int> dp(2*n+1) ;
    // dp[]k
    int dpmin,dpmax;
    dpmax= dpmin=a[0];
    int mx=a[0];
    int mn = 0;
    int sum=mx;
    for(int i=1;i<(n);i++) {
        int j = a[i];
        sum+=j;
        dpmax = max(dpmax,dpmax+j);
        if(mx<dpmax) mx = dpmax;
    }
    for(int i=1;i<n-1;i++) {
        int j = a[i];
        dpmin = min(dpmin,0)+j;
        if(mn > dpmin)
            mn = dpmin;
    }
    cout <<max(mx,sum-mn) <<endl;
    return 0;
}

