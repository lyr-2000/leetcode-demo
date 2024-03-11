#include <bits/stdc++.h>
using namespace std;


const int mod = 1e9+7;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n*2) ;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        a[n+i] = a[i];
    }

    vector<vector<int> > dp(n*2+1,vector<int> (n*2+1) );
    // dp[i][j] = dp[i][k]* a[k] * dp[k+1][j]
    for(int l=1;l<n;l++) {
        for(int i=0;i<2*n-l;i++) {
            int j = i+l;
            for(int k=i;k<j;k++) {
                // cout << a[i]<<" " <<a[k+1]<<" " << a[j+1]<<endl;
                dp[i][j] = max(dp[i][j],
                dp[i][k] + dp[k+1][j] + (a[i]*a[k+1]*a[j+1] % mod));
            }
        } 
    }
    int ret=0;
    for(int i=0;i<n;i++)
        ret = max(ret,dp[i][i+n-1]);
    cout << ret;
    return 0;
}

