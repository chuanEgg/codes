#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    set<int> st;
    cin >> q;
    while(q--){
        string o;
        int n;
        cin >> o >> n;
        if(o == "insert"){
            st.insert(n);
        }else if(o == "delete"){
            st.erase(n);
        }else{
            auto it = st.lower_bound(n);
            auto prev = it;
            prev--;
            if(it == st.end()){
                cout << *prev <<"\n";
            }else if(*prev == *st.rend()){
                cout << *it <<"\n";
            }else{
                if(n-*prev == *it-n){
                    cout << *prev <<" "<< *it<<"\n";
                }else if(n-*prev > *it-n){
                    cout << *it <<"\n";
                }else{
                    cout << *prev <<"\n";
                }
            }
        }
    }
}