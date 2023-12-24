#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int lb, int mid, int ub){
    // vector<int> b((mid-lb)+(ub-(mid+1)));
    int b[ub-lb+1];
    int i=lb;
    int j=mid+1;
    int k=lb;
    while(i<=mid && j<=ub){
        if(arr[i]<=arr[j]){
            b[k]=arr[i];
            i++;
        }
        else{
            b[k]=arr[j];
            j++;
        }
        k++;
    }

    if(i>mid){
        while(j<=ub){
            b[k]=arr[j];
            j++; k++;
        }
    }
    else{
        while(i<=mid){
            b[k]=arr[i];
            i++; 
            k++;
        }
    }

    for(k=lb; k<=ub; k++){
        arr[k]=b[k];
    }
    // cout<<1<<endl;
    
}

void mergeSort(int arr[], int lb, int ub){
    if(lb<ub){
        int mid= (lb+ub)/2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid+1, ub);
        merge(arr, lb, mid, ub);
    }
    
}

int main()
{
    // int n; cin>>n;
    // int arr[n];
    int arr[9]={15, 5, 24, 8, 1, 3, 16, 10, 20};
    int n=9;
    mergeSort(arr, 0, 8);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}