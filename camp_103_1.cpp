#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> v1, vector<int> v2) {
	vector<int> out;
    for(int i=0, j=0; i<v1.size()|| j<v2.size();){
        if(i<v1.size()&&(j==v2.size()||v1[i]<v2[j]))
            out.push_back(v1[i++]);
        else out.push_back(v2[j++]);
    }
    /*cout<<"\t";
    for(int i=0; i<out.size(); i++) cout<<out[i]<<" ";
    cout<<endl;*/
    return out;
} 
vector<int> mergeSort(vector<int> v) {
	if(v.size()<=1) return v;
    vector<int> l,r;
    for(int i=0; i<v.size(); i++){
        (i<(v.size()/2)?l:r).push_back(v[i]);
        //cout<<v[i]<<endl;
    }/*
    for(int i=0; i<v.size()/2; i++)
        l.push_back(v[i]);
    for(int i=v.size()/2; i<v.size(); i++)
        r.push_back(v[i]);
    for(int i=0; i<l.size(); i++) cout<<l[i]<<" ";
    cout<<endl;
    for(int i=0; i<r.size(); i++) cout<<r[i]<<" ";
    cout<<endl;*/
    return merge(mergeSort(l), mergeSort(r));
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<int> ans=mergeSort(v);
    for(int i=0; i<n; i++) cout<<ans[i]<<" ";
    cout<<"\n";
}