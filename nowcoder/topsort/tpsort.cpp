#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
#define debug 1
 

int main()
{
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<int> >g ;
    vector<int> d(n+1) ;
    for(int k=0;k<m;k++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        d[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(d[i]==0)
            q.push(i);
    if(q.size()==0)
    {
        puts("-1");
        return 0;
    }
    vector<int> seq; 
    while(q.size()) {
        int x = q.front();q.pop();
        seq.push_back(x);
        for(auto ne: g[x]) {
            d[ne]--;
            if(d[ne]==0) q.push(ne);
        }
    }
    if(seq.size() != n) {
        puts("-1");
        return 0;
    }
    for(int i=0,n=seq.size();i<n;i++)
    {
        printf("%d",seq[i]);
        if(i+1<n) printf(" ");
    }



    return 0;
}

