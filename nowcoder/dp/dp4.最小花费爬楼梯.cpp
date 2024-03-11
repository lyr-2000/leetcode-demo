#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    scanf("%d",&n);
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<int>dp(n+1) ;
    if(n<=2)
    {
        puts("error");
        return 0;
    }
    for(int i=3;i<=n+1;i++) {
        dp[i] = min(dp[i-1]+a[i-1],dp[i-2]+a[i-2]) ;
    }
    cout << dp[n+1];

    return 0;
}

