#include <iostream>

using namespace std;

bool s[30][30];
int stat[30];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int all = 1;
    int n,m, temp = 0;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>s[i][j];
            if(i-1>0 && s[i-1][j] != s[i][j])
                temp++;
            if(j-1>0 && s[i][j-1] != s[i][j])
                temp++;
        }
    } 
    int ans =  temp;
    for(int i=1; i<=n*m; i++){
        all*=2;
    }
    //cout<<all<<"\n";
    for(int i=0; i<all; i++){
        temp = 0;
        auto ns = s;
        int x = i;
        for(int j=1; j<=n*m; j++){
            stat[j] = x%2, x/=2;
            //cout<<stat[j];
        }
        //cout<<endl;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(stat[(i-1)*m+j]){
                    ns[i][j] = !(ns[i][j]);
                    temp+=2;
                }
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(i-1>0 && ns[i-1][j] != ns[i][j])
                    temp++;
                if(j-1>0 && ns[i][j-1] != ns[i][j])
                    temp++;
            }
        } 
        //cout<<temp<<"\n";
        ans = min(temp, ans);
        //cout<<endl;
    }
    cout<<ans<<"\n";
}