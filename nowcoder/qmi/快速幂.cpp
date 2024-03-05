#include <bits/stdc++.h>
using namespace std;


#define ll long long 
long long qmi(int a,int b,int q) {
    if(b==0) return 1;
    if(b & 1) {
        return (a *qmi(a,b-1,q)) % q;
    }
    ll ans = qmi(a,b/2,q) ;
    return ans * ans % q;
}

int main()
{

    int q;cin>>q;
    while(q--) {
        int a,b,q;
        cin>>a>>b>>q;

        cout << qmi(a,b,q) <<endl;
    }
    return 0;
}

