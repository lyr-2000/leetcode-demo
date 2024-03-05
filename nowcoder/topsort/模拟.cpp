#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    vector<int>v1;
    vector<int>v2;
    for(int i=0;i<24*60;i++){
        int h=i/60,m=i%60;
        if((h/10==s1[0]-'0'||s1[0]=='?')&&(h%10==s1[1]-'0'||s1[1]=='?')&&(m/10==s1[3]-'0'||s1[3]=='?')&&(m%10==s1[4]-'0'||s1[4]=='?')){
            v1.push_back(i);
        }
        if((h/10==s2[0]-'0'||s2[0]=='?')&&(h%10==s2[1]-'0'||s2[1]=='?')&&(m/10==s2[3]-'0'||s2[3]=='?')&&(m%10==s2[4]-'0'||s2[4]=='?')){
            v2.push_back(i);
        }
    }
    int minm=1e9,maxm=0;
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            if(v1[i]<v2[j]){
                maxm=max(maxm,v2[j]-v1[i]);
                minm=min(minm,v2[j]-v1[i]);
            }
        }
    }
    cout<<minm<<" "<<maxm<<endl;
}