#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    set<int> st;
    for(int i=0; i<m; i++){
        int temp;
        cin >> temp;
        st.insert(temp);
    }
    // sort(s.begin(), s.end());
    for(auto i:s){
        if(st.count(i)){
            cout << i <<" ";
        }
    }
    cout <<"\n";
}