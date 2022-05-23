#include <iostream>
#include <queue>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,p,l,r;
    cin>>n>>p>>l>>r;
    int s[n], d[n];
    for(int i=0; i<n; i++){
        cin>>s[i];
        d[i]=-1;
    }
    queue<int> q;
    q.push(0);
    d[0]=0;
    while(!q.empty()){
        if(d[p]!=-1) break;
        int pos= q.front();
        q.pop();
        if(pos<0||pos>=n)
            continue;
        int npos=pos-l;
        if(npos>=0&&npos<n&&d[npos]==-1&&s[npos]>=0&&s[npos]<n){
            q.push(s[npos]);
            d[npos]=d[pos]+1;
            if(d[s[npos]]==-1)
            d[s[npos]]=d[npos];
            //cout<<npos<<"\t"<<s[npos]<<"l\t"<<d[npos]<<endl;
        }
        npos=pos+r;
        if(npos>=0&&npos<n&&d[npos]==-1&&s[npos]>=0&&s[npos]<n){
            q.push(s[npos]);
            d[npos]=d[pos]+1;
            if(d[s[npos]]==-1)
            d[s[npos]]=d[npos];
            //cout<<npos<<"\t"<<s[npos]<<"r\t"<<d[npos]<<endl;
        }
    }
    cout<<d[p]<<"\n";
}