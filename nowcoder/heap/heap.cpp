#include <bits/stdc++.h>
using namespace std;


int a[5000];
int sz ;
void down(int p) {
    int c =p*2;
    while(c<sz) {
        if(c+1 < sz && a[c] < a[c+1]) {
            c=c+1;
        }
        if(a[c] < a[p]) {
            break;
        }
        //a[c] >a[p]
        swap(a[c],a[p]);
        p = c; 
        c = p<<1;
    }
}
void up(int k) {
    while(k/2 && a[k/2] < a[k]) {
        swap(a[k/2],a[k]);
        k/=2;
    }
}
void push(int x) {
    a[sz++] = x;
    up(sz-1);
}
void pop() {
    if(sz<=0) puts("empty");
    else {
        cout << a[0] <<endl;
        swap(a[0],a[sz-1]) ;
        sz--;
        down(0);
    }
}
void top() {
    if(sz<=0) puts("empty");
    else {
        cout << a[0] <<endl;
    }
}

int main()
{

    int m;
    cin>>m;
    while(m--) {
        string op;
        cin>>op ;
        if(op == "push")
        {
            int k;cin>>k;
            push(k);
        }else if (op == "top") {
            top();
        }else {
            pop();
        }
    }

    return 0;
}

