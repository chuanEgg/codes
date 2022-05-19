#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int restore(int arr[], int n)
{
    pair<int, int> Pos[n];
    for (int i = 0; i < n; i++){
        Pos[i].first = arr[i];
        Pos[i].second = i;
    }
    sort(Pos, Pos + n);
    vector<bool> vis(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (vis[i] || Pos[i].second == i){
            continue;
        }
        int j = i;
        int size = 0;
        while (!vis[j]){
            vis[j] = 1;
            j = Pos[j].second;
            size++;
        }
        if (size > 0){
            ans += (size - 1);
        }
    }
    return ans;
}
int main()
{
    int len;
    cin>>len;
    int position[len];
    for(int i = 0;i<len;i++){
        cin>>position[i];
    }
    int n = (sizeof(position) / sizeof(int));
    cout << restore(position, n);
    return 0;
}