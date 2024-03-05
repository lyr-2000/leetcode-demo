#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n;cin>>n;
    vector<int> a(n) ;
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> que;
    for(int k: a) {
        if(que.size()==0) {
            que.push_back(k);
        }else{
            if(k > que.back()) {
                que.push_back(k);
            }else {
                auto p = lower_bound(que.begin(),que.end(),k);
                *p = k;
            }
        }
    }
    cout << que.size() <<endl;

    return 0;
}

