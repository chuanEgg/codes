#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

char c[10005][10005];
bool ta[10005][10005];
map<char,int>mp;
int mean, n, m, g;
vector<pair<char,int>>vmp;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void dfs(int nowx,int nowy,char now){
    int gx,gy;
    for(int x=0;x<4;x++){
        gx=nowx+dx[x];
        gy=nowy+dy[x];
        if(!ta[gx][gy] && (gx>=1 && gx<=n) && (gy>=1 && gy<=m) && c[gx][gy]==now){
            ta[gx][gy]=true;
            dfs(gx,gy,now);
        }
    }
}
bool cmp(const pair<char,int>&v1,const pair<char,int>&v2){
    if(v1.second==v2.second){
        return (v1.first)<(v2.first);
    }
    return v1.second>v2.second;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> g;
    mean=g;
    while(g--){
        cin >> n >> m;
        for(int x=1;x<=n;x++){
            for(int y=1;y<=m;y++){
                cin >> c[x][y];
                ta[x][y]=false;
            }
        }
        for(int x=1;x<=n;x++){
            for(int y=1;y<=m;y++){
                if(!ta[x][y]){
                    ta[x][y]=true;
                    mp[c[x][y]]++;
                    dfs(x,y,c[x][y]);
                }
            }
        }
        cout << "World #"<< mean-g << endl;
        for(auto it=mp.begin();it!=mp.end();it++){
            vmp.push_back(make_pair(it->first,it->second));
        }
        sort(vmp.begin(),vmp.end(),cmp);
        for(auto it=vmp.begin();it!=vmp.end();it++){
            cout << it->first << ": " << it->second << endl;
        }
        mp.clear();
        vmp.clear();
    }
}