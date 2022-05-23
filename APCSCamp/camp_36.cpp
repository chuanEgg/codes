#include <iostream>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    map<string,int> mp;
    string temp;
    int i=0;
    while(n--){
        cin>>temp;
        if(mp.find(temp)==mp.end()){
            cout<<"TAK "<<++i<<"\n";
            mp[temp]=i;
        }else{
            cout<<"NIE "<<mp[temp]<<"\n";
        }
    }
}