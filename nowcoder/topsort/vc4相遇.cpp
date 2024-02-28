#include <bits/stdc++.h>
using namespace std;


const int mod =  100007;
int main()
{
    
    int n,m,t;
    cin>>n>>m>>t;
    unordered_map<int,vector<int> >mp ;
    vector<int> ind(n+1); 
    // vector<int> dfn(n+1); 
    // vector<int> mdfn(n+1); 
    for(int i=0;i<m;i++) {

        int u,v;
        cin>>u>>v;
        mp[u].push_back(v);
        ind[v]++;
    }
    int qx;
    int cnt=0;
    cin>>qx;
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(ind[i]==0)
            q.push(i);
    vector<int> seq; 
    while(q.size()) {
        int x = q.front();q.pop();
        seq.push_back(x);
        for(auto p: mp[x]) {
            ind[p]--;
            if(ind[p]==0)
                q.push(p);
        }
    }
    vector<int> dp(n+1);
    dp[t] = 1;

    for(int i=seq.size()-1;i>=0;i--) {
        int k = seq[i];
        for(auto ne: mp[k]) {
            dp[k] = (dp[k] + dp[ne]) % mod;
        }
    } 
    for(int i=0;i<qx;i++) {
        int s;
        cin>>s;
        //s->t cnt 
        cout << dp[s]<<endl;
    }
    return 0;
}

