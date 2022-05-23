#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int n,q,c,x;
        map<int,int> label;
        cin>>n>>q;
        for(int i=0; i<n; i++){
            cin>>c;
            while(c--){
                cin>>x;
                label[x]=i;
            }
        }
        queue<int> gL;
        queue<int> qL[n];
        while(q--)
        {
            int o;
            cin>>o;
            
            if(o==1){
                int temp;
                cin>>temp;
                int l=label[temp];
                //cout<<l<<endl;
                if(qL[l].empty()){
                    gL.push(l);
                }
                qL[l].push(temp);
            }else if(o==2){
                if(gL.empty()){
                    cout<<"-1\n";
                    continue;
                }
                int topG=gL.front();
                cout<<qL[topG].front()<<endl;
                qL[topG].pop();
                if(qL[topG].empty()){
                    gL.pop();
                }
            }
            
        }
    }
}