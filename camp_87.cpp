#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

const int max_n=100001;
int c[max_n]={0};
int n,m;
vector<int> graph[100001];

bool bfs(int j){
    c[j]=1;
    queue<int> q;
    q.push(j);
    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(int i:graph[p]){
            if(c[i]==0){
                q.push(i);
                c[i]=-c[p];
            }
            if(c[i]==c[p])
                return false;
        }
    }
    return true;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int t1,t2;
        cin>>t1>>t2;
        graph[t1].push_back(t2);
        graph[t2].push_back(t1);
    }
    bool pass=1;
    for(int i=1; i<=n; i++){
        if(c[i]==0&&!bfs(i)){
            pass=0;
            break;
        }
    }
    cout<<((!pass)?"No\n":"Yes\n");
    return 0;
}