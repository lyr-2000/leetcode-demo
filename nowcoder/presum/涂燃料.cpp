#include <iostream>
#include<vector>
using namespace std;



void printx(int x) {
    if (x == 0) {
        printf("O");
        return;
    }
    x = (x - 1) % 3;
    switch (x) {
        case 0:
            printf("R");
            break;
        case 1:
            printf("G");
            break;
        case 2:
            printf("B");
            break;
    }
}
vector<int> a;

int main() {
    int n, k, l, r;
    cin >> n >> k;
    a.resize(n + 2);
    while (k--) {
        cin >> l >> r;
        a[l] += 1;
        a[min(r + 1, n+1)] -= 1;
    }
    l = 0;
    for (int i = 1; i <= n; i++) {
        l += a[i];
        printx(l);
    }
    return 0;
}

