#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll toint(string &s,int k) {

 ll ans=0;
 for(int i=0,n=s.size();i<n;i++) {
    int t = (s[i]-'0');
    ans = ans * k + t;
 }   
 return ans;
}

int main()
{

    int p,q;
    cin>>p>>q;
    string f;
    cin>> f;

    int res=0;
    for(auto c:s) {
        res = (res *p + c - '0') % q;
    }
    cout << res<<endl;
    return 0;
}

