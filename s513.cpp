#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    long long int ans=0;
    stack<int> s;
    vector<int> h;
    h.push_back(0);
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        h.push_back(temp);
    }
    h.push_back(0);
    for(int i=0; i<n+2; i++)
    {
        while(!s.empty()&& h[s.top()]>h[i]){
            int temp=s.top();
            s.pop();
            long long int l;
            if(!s.empty())
            {
                l=i-s.top()-1;
            }else{
                l= i;
            }
            long long int area = h[temp]*l;
            //cout<<area<<endl;
            ans= max(ans, area);
        }
        s.push(i);
    }
    
    cout<<ans<<endl;
}