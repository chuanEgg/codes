#include <iostream>
#include<vector>
#include<stack>

using namespace std;

typedef pair<int*, int> P;

int dsu[40005], dsutemp[40005], n, m, sz[40005];
// stack<P> st_sz, st_dsu;

int fnd(int x){
    return dsu[x] == x? x: fnd(dsu[x]);
}
void uin(int x, int y){
    x = fnd(x);
    y = fnd(y);
    if(x == y) return;
    if(sz[x] > sz[y]) swap(x, y);
    // st_dsu.push({&dsu[x], dsu[x]});
    // st_sz.push({&sz[y], sz[y]});
    dsu[x] = y;
    sz[y] += sz[x];
}
// void undo(){
//     auto a = st_sz.top(); st_sz.pop();
//     auto b = st_dsu.top(); st_dsu.pop();
//     *a.first = a.second;
//     *b.first = b.second;
// }
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y, p, k, cnt = 0;
    cin >> n >> m;
    for(int i = 0; i <= 2 * n; i++){
        dsu[i] = i;
        sz[i] = 1;
    }
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        uin(x, y + n);
        uin(x + n, y);
    }
    // while(!st_dsu.empty()) st_dsu.pop();
    // while(!st_sz.empty()) st_sz.pop();
    
    // for(int i = 0; i < 2 * n; i++) cout << i << " " << dsu[i] << "\n";
    cin >> p >> k;
    copy(begin(dsu), end(dsu), begin(dsutemp));
    for(int t = 1; t <= p; t++){
        copy(begin(dsutemp), end(dsutemp), begin(dsu));
        bool cyc = 0;
        for(int i = 0; i < k; i++){
            cin >> x >> y;
            if(fnd(x) == fnd(y)){
                cyc = 1;
                //break;
            }
            uin(x, y + n);
            uin(x + n, y);
            
        }
        if(cyc){
            cout<<t<<"\n";
            cnt++;
            if(cnt == 3){
                break;
            }
        }
        // for(int i=0; i<n; i++){
        //     if(fnd(i) == fnd(i + n)){
        //         cout << t << "\n";
        //         cnt++;
        //         if(cnt == 3) break;
        //         break;
        //         // while(!st_dsu.empty() && !st_sz.empty()) undo();
        //     }
        // }
        
        
        // else{
        //     while(!st_dsu.empty()){
        //         st_dsu.pop();
        //     }
        //     while(!st_sz.empty()) st_sz.pop();
        // }
        // for(int i = 0; i < 2 * n; i++) cout << i << " " << dsu[i] << "\n";
        
    }
    return 0;
}