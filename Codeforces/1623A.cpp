#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        // vector<int> map(n, vector<int>(m));
        int n, m, rb, cb, rd, cd;
        cin >> n >> m >> rb >> cb >> rd >> cd;
        cout << min(
            rb <= rd ? rd - rb : 2 * n - rb - rd,
            cb <= cd ? cd - cb : 2 * m - cb - cd
        ) << '\n';
    }
}