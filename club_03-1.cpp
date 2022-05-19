#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int n = 1e6;
int notPrime[n+1];

void bruh(){
    notPrime[2] = 0;
    int k = sqrt(n);
    for(int i = 3; i<=k; i+=2){
        if(!notPrime[i]){
            for(int j=i*i; j<=n; j+=i){
                prime[j] = 0;
            }
        }
    }
}
int main(){
    memset(notPrime, 1, 1e6+1);
}