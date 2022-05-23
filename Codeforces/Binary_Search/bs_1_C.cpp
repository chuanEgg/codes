#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    while(q--){
        int temp;
        cin >> temp;
        cout << lower_bound(s.begin(), s.end(), temp)-s.begin()+1<<"\n";
    }
}