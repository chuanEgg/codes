#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> st;
        for(int i = 1; i*i <= n; i++){
            st.insert(i*i);
        }
        for(int i = 1; i*i*i <= n; i++){
            st.insert(i*i*i);
        }
        cout << st.size() << '\n';
    }
}