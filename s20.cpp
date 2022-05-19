#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 1e6+5;
int team[maxn], inqueue[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int n;
        cin >> n;
        fill(team, team+maxn, 0);
        fill(inqueue, inqueue+maxn, 0);
        for(int i=1; i<=n; i++){
            int k;
            cin >> k;
            for(int j=0; j<k; j++){
                int temp;
                cin >> temp;
                team[temp] = i;
            }
        }
        int m;
        cin >> m;
        queue<int> line;
        vector<queue<int>> teamLine(n+1); 
        vector<int> ans;
        while(m--){
            string o;
            cin >> o;
            if(o == "ENQUEUE"){
                int temp;
                cin >> temp;
                if(!inqueue[team[temp]] || team[temp] == 0){
                    line.push(team[temp]);
                    inqueue[team[temp]] = 1;
                }
                teamLine[team[temp]].push(temp);

            }else{
                int outTeam = line.front();
                ans.push_back(teamLine[outTeam].front());
                teamLine[outTeam].pop();
                if(teamLine[outTeam].empty() || outTeam == 0){
                    line.pop();
                    inqueue[outTeam] = 0;
                }
            }
        }
        cout << "Line #" <<t+1<<"\n";
        for(auto i:ans){
            cout << i <<"\n";
        } 
    }
}