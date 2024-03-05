#include <bits/stdc++.h>
using namespace std;

// https://www.nowcoder.com/practice/12f72e06fc424e4d9c685cd89f2bed36?tpId=347&tqId=10090360&ru=%2Fpractice%2Fc34a8121ea1e447db94a32b5a1b99d5f&qru=%2Fta%2Fvip-algorithm%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D347

int main()
{
    int n;
    cin>>n ;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end());
    int l=2,r=n-2;
    long long rsum = a[n-1],lsum = a[0]+a[1];
    int k=1;
    while(l<r && (rsum <= lsum)) {
        k++;
        lsum += a[l++];
        rsum += a[r--];
    }
    if((lsum >= rsum )) puts("-1");
    else cout << k;
    return 0;
}

