#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    long long prevSum[2*n+1]={0};
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    for(int i=1; i<=2*n; i++){
        prevSum[i]=prevSum[i-1]+v[(i-1)%n];
        //cout<<prevSum[i]<<' ';
    }
    //cout<<endl;
    int s=0;
    while(m--){
        int q;
        cin>>q;
        int l=-1, r=n;
        while(l<r-1){
            int pos= l+(r-l)/2;
            if(prevSum[s+pos+1]-prevSum[s]<q){
                l=pos;
            }else{
                r=pos;
            }
        }
        s+=(r+1);
        if(s>=n){
            s-=n;
        }
        //cout<<s<<endl;
    }
    cout<<s<<"\n";
}