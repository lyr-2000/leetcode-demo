#include <bits/stdc++.h>
using namespace std;
 

// https://www.nowcoder.com/practice/35175cee9e634b92b35b634244d81feb?tpId=347&tqId=10068437&ru=/practice/5dc1ccabaa0442d8b83f00ec74b225fa&qru=/ta/vip-algorithm/question-ranking&sourceUrl=/exam/oj



vector<pair<int,int>>  nodes;
vector<int>  g;
int find(int x,vector<int>&g )  {
    if (g[x]!=x) {
        g[x] = find(g[x],g);
    }
    return g[x];
}
int dis(int a,int b,int c,int d) 
{
    return (a-c) * (a-c) + (b-d)*(b-d) ;
}
vector<int >sz; 
bool checkk(int k, int w,int n,vector<int> &g ) {
    for(int i=0;i<n;i++) g[i] = i;
    for(int i=0;i<n;i++) sz[i] = 1;
    int merge=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(i!=j) {
                if(dis(nodes[i].first,nodes[i].second,nodes[j].first,nodes[j].second) > w ) {
                    // return false;
                    continue;
                }else {
                    int x = find(i,g);
                    int y = find(j,g);
                    if(x!=y) {
                        g[x] = y;
                        sz[y] += sz[x];
                        merge++;
                      //  if (merge >= k) return true;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(sz[i]>=k) return true;
    }
    return false;

}

int main()
{
    int n,k;
    cin>>n>>k;
    g.assign(n+1,0);
    sz.assign(n+1,0);
    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        nodes.push_back({x,y});
    }
    int r = 9000,l=0;
    while(l<r) {
        int w = (l+r)/2;
        // printf("w:%d\n",w);
        if(checkk(k,w,n,g)) {
            r = w;
        }else {
            l = w+1;
        }
    }
    cout << r << endl;

    return 0;
}


