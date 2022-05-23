#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int maxn = 1005;
int map[maxn][maxn];
bool bomb[maxn][maxn];
int ax,ay,bx,by;
string as, bs;
int n;

pair<int,int> location(char c){
    if(c == 'L'){
        return make_pair(-1,0);
    }else
    if(c == 'R'){
        return make_pair(1,0);
    }else
    if(c == 'U'){
        return make_pair(0,1);
    }else{
        return make_pair(0,-1);
    }
}
signed main(){
    memset(bomb,0,sizeof(bomb));
    cin>>n;
    cin>>ax>>ay>>bx>>by;
    int m;
    cin>>m>>as>>bs;
    bool upa = 1, upb = 1;
    int axx, ayy, bxx, byy;
    for(int i=0; i<m; i++){
        // cout<<ax<<" "<<ay<<" ";
        // cout<<bx<<" "<<by<<"\n";
        if(upa){
            axx = ax;
            ayy = ay;
            if(i)
            bomb[ax][ay] = 1;
            ax+=location(as[i]).first;
            ay+=location(as[i]).second;
        }
        if(upb){
            bxx = bx;
            byy = by;
            if(i)
            bomb[bx][by] = 1;
            bx+=location(bs[i]).first;
            by+=location(bs[i]).second;
        }
        if(ax <= 0 || ax > n || ay <=0 || ay > n || bomb[ax][ay]){
            upa = 0;
            if(bomb[ax][ay]){
                axx = ax;
                ayy = ay;
            }
        }
        if(bx <= 0 || bx > n || by <= 0 || by > n || bomb[bx][by]){
            upb = 0;
            if(bomb[bx][by]){
                bxx = bx;
                byy = by;
            }
        }
        if(ax == bx && ay == by){
            upa = upb = 0;
            axx = ax;
            ayy = ay;
            bxx = bx;
            byy = by;
        }
    }
    if(upa){
        cout<<ax<<" "<<ay<<" ";
    }else{
        cout<<axx<<" "<<ayy<<" ";
    }
    if(upb){
        cout<<bx<<" "<<by<<"\n";
    }else{
        cout<<bxx<<" "<<byy<<"\n";
    }
} // implementation is pain