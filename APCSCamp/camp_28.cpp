#include <iostream>
#include <set>
#include <queue>

#define maxn 200001
using namespace std;
typedef pair<int,int> P;

int s[maxn], ans[maxn];
int n,k;

void print_s(){
    for(int i=0; i<n; i++){
        cout<<s[i]<<" ";
    }
    cout<<"\n";
}
void print_ans(){
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    priority_queue<P> pq;
    for(int i=0; i<n; i++){
        cin>>s[i];
        pq.push(make_pair(s[i],i));
    }
    int now=0;
    while(!pq.empty()){
        P top = pq.top();
        int pos = top.second;
        if(s[pos]){
            ans[pos] = now;
            s[pos] = 0;
            int j=pos;
            for(int i=1; i<=k&&j<n; i++, j++){
                while(j<n&&!s[j]){
                    j++;
                }
                ans[j]=now;
                s[j]=0;
                //print_s();
                //print_ans();
            }
            j=pos;
            for(int i=1; i<=k&&j>=0; i++, j--){
                while(j>=0&&!s[j]){
                    j--;
                }
                ans[j]=now;
                s[j]=0;
                //print_s();
                //print_ans();
            }
            now = !now;
        }
        pq.pop();
    }
    for(int i=0; i<n; i++){
        cout<<ans[i]+1;
    }
    cout<<"\n";
}