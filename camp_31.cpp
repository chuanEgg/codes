#include <iostream>
#include <queue>

using namespace std;

struct S
{
    unsigned long long dis;
    int x,y,z;
};
struct cmp{
    bool operator()(S a, S b){
        if(a.dis!=b.dis){
            return a.dis>b.dis;
        }
        if(a.x!=b.x){
            return a.x>b.x;
        }
        if(a.y!=b.y){
            return a.y>b.y;
        }
        return a.z>b.z;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<S, vector<S>, cmp> pq;
    int n,o;
    cin>>n;
    while(n--){
        cin>>o;
        if(o==1){
            unsigned long long x,y,z;
            cin>>x>>y>>z;
            S s={((x*x)+(y*y)+(z*z)), x, y, z};
            pq.push(s);
        }else if(o==2){
            if(pq.empty()){
                cout<<"none\n";
                continue;
            }
            S s=pq.top();
            pq.pop();
            cout<<s.x<<" "<<s.y<<" "<<s.z<<"\n";
        }
    }
}