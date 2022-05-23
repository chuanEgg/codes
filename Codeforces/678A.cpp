#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, k;
    cin >> n>>k;
    cout << (n/k+1)*k <<"\n";
}