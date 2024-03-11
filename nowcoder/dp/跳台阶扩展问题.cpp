#include <bits/stdc++.h>
using namespace std;


int main()
{
    //f(n) = 2*f(n-1)
    // f(n) = 2^(n-1)
    int n;
    cin>>n;
    cout << pow(2,n-1);
    return 0;
}

