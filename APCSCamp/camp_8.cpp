#include <iostream>
#include <set>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int s[n];
    for(int i=0; i<n; i++) cin>>s[i];
    int ans=0,fl,fr;
    set<int> v;
    int r=0;
    for(int l=0; l<n; l++)
    {
        if(l>0) v.erase(s[l-1]);
        bool pass=1;
        while (r<n)
        {
            if(v.count(s[r])==0){
                //cout<<s[r]<<" ";
                v.insert(s[r]);
            }else{
                break;
            }
            r++;
        }
        if(ans<(r-l)){
            ans=(r-l);
            fl=l; fr=r;
        }
    }
    for(int i=fl; i<fr; i++){
        cout<<s[i]<<" ";
    }
    cout<<"\n";
}