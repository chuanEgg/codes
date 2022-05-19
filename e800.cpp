#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<double, string> P;

int main()
{
    int n;
    cin >> n;
    set<P> st;
    for(int i = 0; i < n; i++)
    {
        string str;
        double p,l,w,r;
        cin >> str >> p >> l >> w >> r;
        double temp = (w/l)*r*p;
        st.insert(pair<double,string>(temp, str));
    }
    for (auto it=st.rbegin(); it!=st.rend(); it++) {
        cout << (*it).second << '\n';
    }
}