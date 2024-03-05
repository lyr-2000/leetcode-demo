#include <bits/stdc++.h>
using namespace std;



struct Node {
    Node *next;
    int val;
    Node() {
        val = 0;
        next=NULL;
    }
    ~Node() {
        auto p = next;
        next = NULL;
        if(p) {
            auto d = p->next;
            p->next=NULL;
            delete p;
            p = d;            
        }
    }
};
const int maxn = 1e4+10;
unordered_map<int,*Node> g;
Node *tail=NULL;
void insert(int x,int y) {
    if(g.count(x)) {

    }else {
        if(!tail) {
            tail = new Node();
            tail->val = y;
            g[tail->val] = tail;
        }else {
            tail->next = new Node();
            tail = tail->next;
            tail->val = y;
            g[tail->val] = tail;
        }
    }
}

int main()
{


    return 0;
}

