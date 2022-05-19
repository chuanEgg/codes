#include<bits/stdc++.h>

using namespace std;

void solve(int N, long long K, long long A[]){
    vector<pair<int,int>> v1, v2;
    for(int i = 0; i < (1 << (N / 2)); i++){
        int sum = 0;
        for(int j = 0; j < N / 2; j++){
            if((1 << j) & i){
                sum += A[j];
                if(sum > K)
                    break;
            }
        }
        if(sum <= K) v1.push_back({sum, i});
    }
    for(int i = 0; i < (1 << ((N + 1) / 2)); i++){
        int sum = 0;
        for(int j = 0; j < (N + 1) / 2; j++){
            if((1 << j) & i){
                sum += A[j + N / 2];
                if(sum > K) break;
            }
        }
        if(sum <= K) v2.push_back({sum, i});
    }
    for(auto [sum1, i]: v1){
        for(auto [sum2, j]: v2){
            if(sum1 + sum2 == K){
                for(int l = 0; l < N / 2; l++){
                    if((1 << l) & i)
                        Report(l + 1);
                }
                for(int r = 0; r < (N + 1) / 2; r++){
                    if((1 << r) & j)
                        Report(N / 2 + r + 1);
                }
                Report(-1);
                return;
            }
        }
    }
}