#include <iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;
typedef pair<int,int> P;

int main(){
    int n,m,t,x,y,k,o;
    cin>>n>>m>>t;
    vector<stack<int>> locker;
    set<P> usedLocker;
    while(t--){
        cin>>o;
        if(o==1){
            cin>>x>>y>>k;
            if(!usedLocker.count(P(x,y))){
                
            }
            
        }else if(o==2){
            cin>>x>>y;
            
        }else if(o==3){
            cin>>x>>y;
            
        }
    }
}