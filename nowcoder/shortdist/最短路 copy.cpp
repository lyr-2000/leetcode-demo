#include <bits/stdc++.h>
using namespace std;

#define edge pair<int,int>

int main()
{
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<edge> > g; 
    while(m--) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({w,v});
        g[v].push_back({w,u});
    }
    #define inf INT32_MAX
    priority_queue<edge,vector<edge>,greater<edge> > q;
    vector<int>distTo(5001,inf) ;
    distTo[1] = 0;
    q.push(make_pair(0,1));
    while(q.size() ) {
        auto s = q.top();q.pop();
        int from = s.second;
        vector<edge> all = g[from] ;
        if(distTo[from] < s.first) continue;
        //获取所有可达点
        for(auto edg: all) {
            int to = edg.second, weight = edg.first;
            // if(vis.count(to)) continue;
            if(distTo[to] > distTo[from] + weight) { //经常错  s === (cost=w) ===> v
                distTo[to] = distTo[from] + weight;
                q.push(edge{distTo[to],to});
            }
        }
    }
    if(distTo[n] != inf) {
        cout <<distTo[n] <<endl;
    }else {
        puts("-1");
    }
    return 0;
}

