#include <bits/stdc++.h>
using namespace std;


/**


a*b = 2 * (a/2) *b 
= 2 * 2 * (a/4 ) *b 
k *x + b
*/
https://space.bilibili.com/404499074/favlist
#define ll long long 
int qmi(int a,int b,int q) {
    if(b==0 || a==0) return 0;

    if(a % 2 == 1) {
        return (b +qmi(a-1,b,q)) % q;
    }
    auto p = qmi(a/2,b,q);
    return (p+p) % q;
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

