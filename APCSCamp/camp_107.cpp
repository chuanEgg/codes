#include <iostream>
#include <algorithm>

using namespace std;

int n,k,s[100001];
void m(int l, int r){
    
    if(k<=1||l==r){
        return;
    }int mid=(r+l)/2;
    k-=2;
    if((r-l+1)%2==0){
        swap(s[mid], s[mid+1]);
        //cout<<s[mid+1]<<" "<<s[mid]<<endl;
        m(l,mid);
        m(mid+1,r);
    }else{
        swap(s[mid], s[mid-1]);
        m(l,mid-1);
        m(mid,r);
    }/*
    for(int i=l; i<=r; i++){
        cout<<s[i];
    }
    cout<<endl<<"\t"<<l<<" "<<mid<<" "<<r<<endl;*/
    
    
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    if(k>=2*n||k%2==0){
        cout<<"-1\n";
    }else{
        for(int i=0; i<n; i++){
            s[i]=i+1;
        }
        k-=1;
        m(0,n-1);
        for(int i=0; i<n; i++){
            if(i) cout<<" ";
            cout<<s[i];
        }
        cout<<"\n";
    }
    
}