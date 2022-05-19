#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> s(n+2), v(n+2);
    long long cur=0, ans=0;
    long long prevSum[n]={0};
    s[0]=0; v[0]=0;
    for(int i=1; i<=n; i++){
        cin>>s[i];
    }
    for(int i=1; i<=n; i++){
        cin>>v[i];
    }
    for(int i=1; i<=n; i++){
        prevSum[i]=prevSum[i-1]+(s[i]*v[i]);
    }
    //cout<<prevSum[n]<<endl;
    int l,r;
    ans=prevSum[n];
    for(int i=1; i<=n; i++){
        long long tempSum[n+1];
        tempSum[0]=0;
        l=0;
        while(i-l>=1&&i+l+1<=n){
            long long temp=0;
            tempSum[l+1]=tempSum[l]+(s[i-l]*v[i+l+1])+(s[i+l+1]*v[i-l]);
            temp+=(prevSum[n]-(prevSum[i+l+1]-prevSum[i-l-1]));
            temp+=tempSum[l+1];
            //cout<<tempSum[l+1]<<endl;
            //cout<<i-l<<"\t"<<i+l+1<<"\t"<<temp<<endl;
            ans =max(temp,ans);
            l++;
        } 
    }
    for(int i=1; i<=n; i++){
        long long tempSum[n+1];
        tempSum[0]=0;
        l=1;
        while(i-l>=1&&i+l<=n){
            long long temp=0;
            tempSum[l]=tempSum[l-1]+(s[i-l]*v[i+l])+(s[i+l]*v[i-l]);
            temp+=(prevSum[n]-(prevSum[i+l]-prevSum[i-l-1]))+prevSum[i]-prevSum[i-1];
            temp+=tempSum[l];
            //cout<<tempSum[l]<<endl;
            //cout<<i-l<<"\t"<<i+l+1<<"\t"<<temp<<endl;
            ans =max(temp,ans);
            l++;
        }
    }
    cout<<ans<<endl;
}
