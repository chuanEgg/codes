#include<iostream>
#include<cmath>
using namespace std;
long int factorsum(long int n){
    long int r,t=0;
        for(r=1;r<=(n-1);r++){
        if(n%r==0){
            t=t+r;
        }
        else
        continue;
    }
    return t;
}
int main(){
    long int l,r,sum = 0;
    cin>>l>>r;
    for(l;l<=r;l++){
        sum+=abs(l-factorsum(l));
    }
    cout<<sum%1000000007;
}