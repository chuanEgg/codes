#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> P;
vector<int> st;
vector<P> car;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,s,t;
    cin>>n>>k>>s>>t;
    car.resize(n);
    st.resize(k);
    for(int i=0; i<n; i++){
        cin>>car[i].second>>car[i].first;
    }
    for(int i=0; i<k; i++){
        cin>>st[i];
    }
}