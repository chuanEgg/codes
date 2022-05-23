#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
using ll = long long;

pair<ll,ll> X[(1<<21)+5], Y[(1<<21)+5];

void calc(ll A[], pair<ll,ll> x[], int N, int c){
    for(ll i=0; i<(1<<N); i++){
        ll sum = 0;
        for(int j=0; j<N; j++){
            if(i & (1<<j)){
                sum += A[j+c];
            }
        }
        x[i].first = sum;
        x[i].second = i;
    }
}
// void Report(int n){
//     cout << n <<"\n";
// }
void solve(int N, ll K, ll A[]){
    calc(A, X, N/2, 0);
    calc(A, Y, N-N/2, N/2);
    int size_X = 1<<(N/2);
    int size_Y = 1<<(N-N/2);
    sort(Y, Y+size_Y);

    // for(int i=0; i<size_X; i++)
    //     cout <<i<<":"<< X[i].first <<":" << X[i].second <<" ";
    // cout <<"\n";
    // for(int i=0; i<size_Y; i++)
    //     cout <<i<<":"<< Y[i].first <<":" << Y[i].second <<" ";
    // cout <<"\n";

    for(int i=0; i<size_X; i++){
        if(X[i].first <= K){
            pair<ll,ll> p = {K-X[i].first, 0};
            int j = lower_bound(Y, Y+size_Y, p)-Y;
            if(j == size_Y) continue;
            if(X[i].first + Y[j].first == K){
                for(int l=0; l<N/2; l++){
                    if((1 << l) & i)
                        Report(l+1);
                }
                for(int r=0; r<N-N/2; r++){
                    if((1<<r)& Y[j].second)
                        Report(N/2+r+1);
                }
                Report(-1);
                return;
            }
        }
    }
} // muen so dian

// int main(){
//     ll n, k;
//     cin >> n >> k;
//     ll a[n];
//     for(int i=0; i<n; i++){
//         cin >> a[i];
//     }
//     solve(n, k, a);
// }