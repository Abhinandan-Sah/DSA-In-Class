#include<iostream>
using namespace std;

int findPeakElement(int arr[], int n){
    if(n==1) return 1;
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;
    
    int s=0; int e=n-1;
    
    while(s<=e){
        int mid= s+(e-s)/2;
        if(arr[mid]> arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(arr[mid]>arr[mid-1]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[100];
    int n; 
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int index = findPeakElement(arr, n);
    if(index!=-1){
        cout<<arr[index];
    }
    else{
        cout<<0;
    }
    return 0;
}