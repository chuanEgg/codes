#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<char> stat(n,'N');
    map<char,int> alp;
    string a, b;
    cin >> a >> b;
    for(int i=0;i<n; i++){
        if(a[i] == b[i]){
            stat[i] = 'M';
            a[i] = '.';
        }else{
            alp[a[i]]++;
        }
    }
    // for(auto i:stat){
    //     cout<<i;
    // }cout<<"\n";
    for(int i=0; i<n; i++){
        if(stat[i] != 'N') continue;
        if(alp[b[i]] > 0){
            alp[b[i]] --;
            stat[i] = 'P';
        }
    }
    for(auto i:stat){
        cout<<i;
    }cout<<"\n";
}