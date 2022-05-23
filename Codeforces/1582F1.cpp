#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <deque>
using namespace std;

const int maxn = 1e5+1;
int s[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    set<int> st;
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>s[i];
        st.insert(s[i]);
    }
    st.insert(0);
    
    cout<<st.size()<<"\n";
    for(auto i:st){
        cout<<i<<" ";
    }
    cout<<"\n";
}