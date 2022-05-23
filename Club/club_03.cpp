#include <iostream>
#include <cmath>
#include <cstring>
#pragma GCC optimize("Ofast")

using namespace std;

const int n = 1e6;
bool prime[n+1];

void bruh(){
    prime[0] = prime[1] = 0;
    for(int i=2; i<=n; i+=2){
        prime[i]=0;
    }
    prime[2] = 1;
    int k = sqrt(n);
    for(int i = 3; i<=k; i+=2){
        if(prime[i]){
            for(int j=i*i; j<=n; j+=i){
                prime[j] = 0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    memset(prime, 1, n+1);
    bruh();
    /*for(int i=0; i<1000000; i++)
        cout<<prime[i]<<" ";
    cout<<endl;*/
    int t;
    cin>>t;
    int temp;
    
    while(t--){
        cin>>temp;
        if(prime[temp])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}