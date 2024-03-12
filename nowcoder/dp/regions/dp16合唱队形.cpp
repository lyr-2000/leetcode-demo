#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n;
    cin>>n;
    vector<int> a(n) ;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> l(n+1,1),r(n+1,1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
                l[i] = max(l[i],l[j]+1);
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(a[i]>a[j])
                r[i] = max(r[i],r[j]+1);
        }
    }
    int kmore = 0;
    for(int i=0;i<n;i++)
    {
        int k = l[i]+r[i]-1;
        if(kmore < k)
        {
            kmore = k;
        }
    }
    cout << n - kmore <<endl;
    return 0;
}

