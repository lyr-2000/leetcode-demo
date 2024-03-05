#include <bits/stdc++.h>
using namespace std;

bool ismatch(char a, char b) {
    if ((a == '(' && b == ')') || (a == '[' && b == ']')) {
        return true;
    }
    return false;
}
 

int main()
{
    

    string s;
    cin>>s;
    int n = s.size();
    vector<vector<int> > dp(n+1,vector<int>(n+1) );
    #define inf (1ll<<31)-1
    for(int i=0;i<n;i++) dp[i][i] =1;
    for(int l=2;l<=n;l++) {
        for(int i=0;i < n-l+1; i++) { //例如 len=2,{0,1} , i 只能到 n-len+1
            int j = i+l-1;
            if(j<=i) continue;
            //region {i~j}
            dp[i][j] = inf;
            if(ismatch(s[i],s[j])) {
                dp[i][j] = dp[i+1][j-1]; // {ax..yb} =>  {x..y}
            }
            for(int k=i;k<j;k++) {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout << dp[0][n-1];
    return 0;
}

