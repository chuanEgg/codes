#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    while(n--){
        queue<int> q;
        vector<int> s;
        for(int i=0; i<m; i++){
           int temp;
           cin>>temp;
            q.push(temp);
        }
        for(int i=1; i<=m; i++)
        {
            s.push_back(i);
            while(q.front()==s.back()&&!s.empty()){
                q.pop();
                s.pop_back();
                continue;
            }
        }
        cout<<(s.empty()?"Y\n":"N\n");
    }
}