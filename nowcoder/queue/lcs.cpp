#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    //todo vaid n  
    vector<vector<int> >  lcs(n+1,vector<int>(m+1) );

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(a[i] == b[j]) {
                // dp[i-1][j-1] + 1
                if(i-1>=0 && j-1>=0) {
                    lcs[i][j] = lcs[i-1][j-1]+1;
                }else {
                    lcs[i][j] = 1;
                }
            }else {
                lcs[i][j] = max(i-1>=0?lcs[i-1][j]:0,j-1>=0? lcs[i][j-1]:0);
            }
        }
    }
    cout << lcs[n-1][m-1];
    return 0;
}

