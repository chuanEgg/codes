#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int,int> P;
P s[100001];

int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
		int m, l, r, n=0, t;
		cin>>t;
		while(t--){
            cin>>l>>r;
			s[n++]={l,r};
		}
		sort(s,s+n);
		vector<P> ans;
		int i=0;
        m=s[n-1].second;
		l=s[0].first;
		while(l<m){
			bool pass=0;
			int maxr=0, maxi=0;
			while(i<n&&(s[i].first-1)<=l){
				pass=1;
				if(s[i].second>maxr){
					maxi=i;
					maxr=s[i].second;
				}
				i++;
			}
			if(pass){
				ans.push_back(s[maxi]);
                //cout<<maxi<<endl;
				l=maxr;
			}else break;
		}
		if(l>=m){
			cout<<ans.size()<<"\n";
		}else{
			cout<<"-1\n";
		}
}