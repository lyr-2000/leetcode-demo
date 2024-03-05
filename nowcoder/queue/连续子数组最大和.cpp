#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t=0,n;
    scanf("%d",&n);
    int l=0,r=INT32_MIN;
    while(n--) {
        scanf("%d",&t);
        l+= t;
        r = max(l,r);
        if(l<0) l=0;
    }
    printf("%d\n",r); 


    return 0;
}

