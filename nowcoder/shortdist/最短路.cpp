#include <bits/stdc++.h>
using namespace std;
template <class T, class S, class C>
S& Container(priority_queue<T, S, C>& q) {
    struct HackedQueue : private priority_queue<T, S, C> {
        static S& Container(priority_queue<T, S, C>& q) {
            return q.*&HackedQueue::c;
        }
    };
    return HackedQueue::Container(q);
}
struct edge {
    int v;
    int w;
    edge(int v=0,int w=0): v(v),w(w){}
    bool operator <(const edge&r) const {
        return w > r.w;
    }
};
void printq(priority_queue<edge> &q) {
    auto v = Container(q);
    for(edge w: v) {
        printf("%d ",w.v);
    }
    printf("\n");
}

int main()
{
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<edge> > g; 
    while(m--) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    #define inf INT32_MAX
    priority_queue<edge> q;
    vector<int>distTo(5001,inf) ;
    distTo[1] = 0;
    q.push(edge{1,0});
    while(q.size() ) {
        auto s = q.top();q.pop();
        if(distTo[s.v] < s.w) {
            continue;
        }
        vector<edge> all = g[s.v] ;
        //获取所有可达点
        for(auto edg: all) {
            int w = edg.w,to = edg.v;
            // if(vis.count(to)) continue;
            if(distTo[to] > distTo[s.v] + w) { //经常错  s === (cost=w) ===> v
                distTo[to] = distTo[s.v] + w;
                // printf("u,v : %d %d\n",s.v,s.w);
                q.push(edge{to,distTo[to]});
                // printf("(%d-> %d) w:%d distTo[%d]: %d\n",s.v,edg.v,edg.w,edg.v,distTo[edg.v]);
                // printq(q);
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

