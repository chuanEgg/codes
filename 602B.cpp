#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 1e5+1;
set<int> st;
void print(){
    for(auto i:st) cout<<i;
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> s(n);
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    int ans = 0;
    int l=0;

    st.clear();
    for(; l<n; l++){
        st.insert(s[l]);
        for(int r=l; r<n; r++){
            st.insert(s[r]);
            // print();
            int temp = (*(st.begin())-*(st.rbegin()));
            // cout<<*st.begin()<<" "<<*st.rbegin()<<"\n";
            // cout<<l<<"\t"<<r<<"\n"<<temp<<"\n";
            
            if(temp <= 1 && temp >= -1){
                ans = max(ans, r-l+1);
            }else{
                l = 0;
                st.clear();
                break;
            }
        }
    }
    cout<<ans<<"\n";
}