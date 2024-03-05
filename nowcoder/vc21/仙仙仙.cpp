#include <bits/stdc++.h>
using namespace std;

struct node {
    double x,y;
};

vector<node> all;

bool cmp(node &x,node&y) {
    return x.x != y.x
}

double calck(node &a,node &b) {
    if(a.x == b.x) {
        return -1;
    }
    return (a.y - b.y) / (a.x-b.x)
}
int islc(node &a,node &b) {
    return a.x == b.x;
}

void solve() {
    if(islc(all[0],all[1])) {
        auto h = fabs(all[0].y - all[1].y);
        auto x = fabs(all[0].x - all[2].x);
        cout << h*x/2 <<endl;
        return 0;
    }

    auto k = calck(all[0],all[1]);
    auto k2 = 1/k;
    // y = k*x + b => b = y - k*x
    auto b = all[0].y - k2 * all[0].x;


}

int main()
{
    for(int i=0;i<3;i++) {
        node x;
        cin>>x.x>>x.y;
        all.push_back(x);
    }
    solve();
    
    return 0;
}

