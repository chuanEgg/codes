#include <iostream>
#include <map>
#define int long long
using namespace std;

int x[1001], y[1001];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<=n; i++)
        cin>>x[i]>>y[i];
    pair<int,int> start = make_pair((x[n]-x[n-1]), (y[n]-y[n-1]));
    pair<int,int> last = make_pair((x[1]-x[0]), (y[1]-y[0]));
    int dir = (last.first*start.second)-(start.first*last.second);
    cout<<dir<<"\n";
    int temp, cnt = 0;
    for(int i=1; i<n; i++){
        last = make_pair((x[i+1]-x[i]), (y[i+1]-y[i]));
        start = make_pair((x[i]-x[i-1]), (y[i]-y[i-1]));
        temp = (last.first*start.second)-(start.first*last.second);
        cout<<temp<<"\n";
        if(dir*temp<0) cnt++;
    }
    cout<<cnt<<"\n";
}