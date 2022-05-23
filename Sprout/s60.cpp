#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

int m, s, t, a, b, c ,d;
int get_time(int x){
/*
    17 60 10 4
    36 255 10
    180 + stop 1 s+ 60 + 17
*/
    // cout <<x<<":\t"<< (m+d*x)/c <<"\t" << (s-((m+d*x)/c*b))/a <<"\t" << (s-((m+d*x)/c*b))/a + x + ((m+d*x)/c) <<"\n"; 
    if((m+d*x)/c*b >= s){
        return (s+b-1)/b+x;
    }else{
        return (s-((m+d*x)/c*b)+a-1)/a + x + ((m+d*x)/c);
    }
}
int get_dis(int x){
    // cout <<"get_dis\t" <<x<<":\t" <<(d*x+m)/c << "\t" << t-(d*x+m)/c-x <<"\t" << t-x <<"\t" << min((d*x+m)/c, t-x)*b + max(t-(d*x+m)/c-x, 0LL)*a <<"\n";
    return min((d*x+m)/c, t-x)*b + max(t-(d*x+m)/c-x, 0LL)*a;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c >> d >> m >> s >> t;
    //stop x => min(d*x+m/c, t-x)*b + max(t-d*x+m/c-x, 0)*a;
    int maxDis = 0;
    for(int i=0; i<=t; i++){
        maxDis = max(maxDis, get_dis(i));
    }
    // cout << maxDis <<"\n"; 
    // int maxDis = max(get_dis((c*t-m)/(c+d)), get_dis((c*t-m)/(c+d)+1));
    if(maxDis >= s){
        int ans = 3e5+5;
        for(int i = 0; i<=t; i++){
            if(get_dis(i) >= s){
                ans = min(ans, get_time(i));
                // cout << ans <<"\n";
            }
        }
        cout << "Yes\n" << ans <<"\n";
    }else{
        cout << "No\n" << maxDis <<"\n";
    }
}