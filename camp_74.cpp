#include <iostream>
#include <queue>
#include <set>

using namespace std;
typedef pair<int,int> P;

const int maxn = 5e5+5;
int s[maxn], nextpos[maxn], pos[maxn];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,p,k;
    cin>>n>>k>>p;
    set<int> st;//存某個東西出現的位置
    for(int i=0; i<p; i++){
        cin>>s[i];
    }
    for(int i=1; i<=n; i++) pos[i]=p;
    for(int i=p-1; i>=0; i--){//記錄下一個位置
        nextpos[i] = pos[s[i]];
        pos[s[i]] = i; 
    }
    int ans = 0;
    for(int i=0; i<p; i++){
        if(st.count(i)){
            st.erase(i);
            st.insert(nextpos[i]);//更新位置
            continue;
        }else{
            if(st.size() == k){
                st.erase(prev(st.end()));//清理內存
            }
            st.insert(nextpos[i]);
            ans++;
        }
        
    }
    cout<<ans<<"\n";
}