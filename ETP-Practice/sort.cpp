#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter size: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter values: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}