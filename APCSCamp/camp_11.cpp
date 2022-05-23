#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long int k;
    while(cin >> k)
    {   
        long long int n=k+1;
        bool prime[n];
        for (int i=0; i<n; i++) prime[i] = true;
        prime[0] = false;
        prime[1] = false;
        for (int i=2; i<n; i++)
        {
            if (prime[i]){
                for (int k=(n-1)/i, j=i*k; k>=i; k--, j-=i){
                    if (prime[k])
                    prime[j] = false;
                }   
            }
        }
        if(prime[k]){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
}