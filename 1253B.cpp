#include <iostream>
#include <set>
#include <vector>

using namespace std;
const int maxn = 1e6+1;
int n, s[maxn];
set<int> in;
set<int> day;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    int total=0, today = 0;
    vector<int> l;
    for(int i=0; i<n; i++){
        today++;
        if(s[i] > 0){
            if(!in.count(s[i]) && !day.count(s[i])){
                in.insert(s[i]);
                day.insert(s[i]);
            }else if(day.count(s[i]) && !in.count(s[i])){
                if(in.empty()){//new day
                    total+=today;
                    l.push_back(today);
                    today = 0;
                    in.clear();
                    day.clear();
                    continue;
                }else{
                    today = 0;
                    in.clear();
                    day.clear();
                    continue;
                }
            }else if(in.count(s[i])){ //illegal
                today = 0;
                in.clear();
                day.clear();
                continue;
            }
        }else if(s[i]<0){
            if(!in.count(-1*s[i])){
                today = 0;
                in.clear();
                day.clear();
                continue;
            }else{
                in.erase(-1*s[i]);
                if(in.empty()){
                    total+=today;
                    l.push_back(today);
                    today = 0;
                    in.clear();
                    day.clear();
                    continue; 
                }
            }
        }
        
    }
    if(l.size()==0 || total != n) cout<<"-1\n";
    else{
        cout<<l.size()<<"\n";
        for(auto i:l){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}