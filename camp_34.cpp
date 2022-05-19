#include <iostream>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,o,temp;
    cin>>n;
    set<int> s;
    while(n--){
        cin>>o;
        if(o==1){
            cin>>temp;
            s.insert(temp);
        }else if(o==2){
            if(!s.empty()){
                cout<<*(s.begin())<<"\n";
                s.erase(s.begin());
            }else
                cout<<"done\n";
        }else{
            if(!s.empty()){
                cout<<*(s.rbegin())<<"\n";
                s.erase(--s.end());
            }else
                cout<<"done\n";
        }
    }
}