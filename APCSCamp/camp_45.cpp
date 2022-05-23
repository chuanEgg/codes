#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
        cin>>arr[i];
	}
    sort(arr,arr+n);
	do  
    {
        for(int i=0; i<n; i++) cout<<arr[i]<<" ";
        cout<<"\n";
    }while(next_permutation(arr,arr+n)); 
	
}