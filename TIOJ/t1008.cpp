#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, d, maxm=0;
    cin>>n;
    int cup[n+1];
    for(int i=0; i<n; i++){
        cin>>cup[i];
        maxm = max(maxm, cup[i]);
        if(i)
            d = __gcd(cup[i], d);
        else
            d = cup[i];
    }
    int m;
    cin>>m;
    if(m%d||m>maxm) cout<<"-1\n";
    queue<vector<int>> q;
    vector<int> temp;
    for(int i=0; i<n; i++){
        temp.push_back(0);
        if(cup[i] == m){
            cout<<"1\n";
            exit(0);
        }
    }
    temp.push_back(0);
    set<vector<int>> st;
    q.push(temp);
    int cnt = 0;
    while(q.size()){
        vector<int> t = q.front();
        //cout<<cnt<<"\n";
        q.pop();
        vector<int> push = t;
        if(push.size())
            push.pop_back();
        if(st.count(push)) continue;
        st.insert(push);
        t[n]++;
        vector<int> pour = t;
        //print(pour);
        for(int i = 0; i<n; i++){
            pour[i] = 0;
            q.push(pour);
            pour = t;
            
        }
        for(int i = 0; i<n; i++){
            pour[i] = cup[i];
            q.push(pour);
            pour = t;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j|| pour[j] == cup[j] || !pour[i]) continue;
                if(pour[j] == cup[j]) continue;
                if(cup[j] - pour[j] > pour[i]){
                    pour[j] += pour[i];
                    pour[i] = 0;
                }else{
                    pour[j] = cup[j];
                    pour[i] -= (pour[j]-t[j]);
                }
                if(pour[i] == m || pour[j] == m){
                    cout<<pour[n]<<"\n";
                    exit(0);
                }
                q.push(pour);
                pour = t;
            }
        }   
    }
}