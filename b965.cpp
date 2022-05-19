#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
//#define int long long
using namespace std;
int a[11][11], cmd[10], b[11][11];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r, c, m;
    while(cin>>r>>c>>m){
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> a[i][j];
            }
        }
        for(int i = 0; i < m; i++) cin >> cmd[i];
        while(m--){
            if(cmd[m]){
                for(int i = 0; i < r / 2; i++){
                    for(int j = 0; j < c; j++){
                        swap(a[i][j], a[r - 1 - i][j]);
                    }
                }
            }
            else{
                for(int i = 0; i < r; i++){
                    for(int j = 0; j < c; j++){
                        b[c - 1 - j][i] = a[i][j];
                    }
                }
                swap(r, c);
                for(int i = 0; i < r; i++){
                    for(int j = 0; j < c; j++) a[i][j] = b[i][j];
                }
            }
        }
        cout << r <<" " << c << "\n";
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(j) cout<<" ";
                cout << a[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}