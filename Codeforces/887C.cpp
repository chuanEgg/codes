#include <iostream>

using namespace std;

int cube[25];
bool chk[7];
void check(int n, int cubix[25]){
    auto change = cubix;
    int cnt = 0;
    int color[7] = {0};
    for(int i=(n*4); i>=((n-1)*3); i--){
        color[cubix[i]]++;
    }
    for(int i=1; i<=6; i++){
        if(color[i]) cnt++;
    }
    if(cnt>=2){
        cout<<"NO\n";
        exit(0);
    }else if(cnt == 1){
        chk[n] = 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1; i<=24; i++){
        cin>>cube[i];
    }
    
}