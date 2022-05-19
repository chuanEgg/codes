#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n && n){
        bool flag = 1;
        while(flag){
            queue<int> q;
            vector<int> s;
            for(int i=0; i<n; i++){
                int temp;
                cin>>temp;
                if(temp == 0){
                    flag = 0;
                    break;
                }
                q.push(temp);
            }
            if(flag){
                for(int i=1; i<=n; i++)
                {
                    s.push_back(i);
                    while(q.front()==s.back()&&!s.empty()){
                        q.pop();
                        s.pop_back();
                        continue;
                    }
                }
                cout<<(s.empty()?"Yes\n":"No\n");
            }
        }
    }
}