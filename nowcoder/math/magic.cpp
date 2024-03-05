#include <bits/stdc++.h>
using namespace std;



int res;
vector<bool> flag; 
bool ismagic(int k) {
    if(k==0) return true;
    // if(k<=2) return k==2;
    auto p = to_string(k);
    int n = p.size();
    for(int i=0;i<n;i++) {
        int num=0;
        for(int j=i;j<n;j++) {
            num = num*10 + (p[j]-'0');
            if(j>i && !flag[num]) //长度大于1
                return false;
        }

    }
    return true;
}

int main()
{

    int n;
    scanf("%d",&n);
    // auto N = ((int)sqrt(n)) +1;
    flag.resize(n+1,false);
    // flag[0] = false; //01 不是质数
    flag[1] = true;
    for(int i=2;i<=n;i++) {
        if(!flag[i]) {
            for(int j=2;j*i<=n;j++) {
                flag[j*i] = true;
            }
        }
    }

    for(int i=1;i<=n;i++) {
        // solve(i);
        if(ismagic(i)) res++;
    }
    printf("%d\n",res);
    return 0;
}

