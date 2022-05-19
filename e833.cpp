#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, sum0 = 0, sum1 = 0;
    cin >> n;
    vector<int> s(n+1);
    for(int i=1; i<=n; i++){
        cin >> s[i];
        sum0 += s[i];
        sum1 += s[i]*i;
    }
    cout << sum0 <<" "<<sum1<<"\n";
}