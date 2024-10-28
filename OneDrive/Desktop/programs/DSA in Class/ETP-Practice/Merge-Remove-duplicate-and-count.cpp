#include<iostream>
using namespace std;

int  removeDupli(int arr[], int &n){
    int cnt=0;
    for(int i=0; i<n-1; i++){
        int val=arr[i];
        for(int j=i+1; j<n; j++){
            if(val==arr[j]){
                for(int k=j; k<n; k++){
                    arr[k]=arr[k+1];
                }
                n--; 
                j--;
            }

        }
        cnt++;
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<removeDupli(arr, n);
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    // return 0;
    
}