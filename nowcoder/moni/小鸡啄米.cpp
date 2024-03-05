#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp(int a,int b) {
    return a>b;
}
int main()
{

    int n;cin>>n;
    vector<int> a(n) ;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end(),cmp);
    long long res=0,prev=0;
    for(int i=0;i<n;i++) {
        prev += a[i];
        res += prev;
    }
    printf("%d\n",res);
    return 0;
}

