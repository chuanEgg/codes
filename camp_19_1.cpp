#include <bits/stdc++.h>

using namespace std;
int main() {
  int n;
  stack<int> st;
  st.push(0);
  long long int ans = 0;
  cin >> n;
  vector<int> L;
  L.push_back(0);
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    L.push_back(a);
  }
  L.push_back(0);
  for(int i = 0; i < L.size(); i++) {
    while(!st.empty() && L[st.top()] > L[i]) {
      int s = st.top();
      st.pop();
      long long int l = i;
      if(!st.empty())
        l = i - st.top() - 1;
      ans = max(ans, l * L[s]);
    }
    st.push(i);
  }
  cout << ans << '\n';
}