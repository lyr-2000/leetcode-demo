#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i];

    vector<int> sum(n,vector<int> (n));
    for(int i=0;i<n;i++) {
        for(int j=1;j<n;j++) {
            sum[i][j]+= sum[i][j-1]
        }
    }


    return 0;
}

