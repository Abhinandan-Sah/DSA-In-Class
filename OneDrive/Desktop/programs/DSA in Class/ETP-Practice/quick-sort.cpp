#include<iostream>
using namespace std;

int findPivot(int arr[], int low, int high){
    int pivot= arr[low];
    int count=0;
    for(int i=low+1; i<=high; i++){
        if(pivot >= arr[i]){
            count++;
        }
    }
    int pivotIdx= low+count;
    swap(arr[low], arr[pivotIdx]);
    
    int si=low;
    int ei=high;

    while(si< pivotIdx && ei > pivotIdx){
        if(arr[si]<= arr[pivotIdx]){
            si++;
        }
        if(arr[ei] > arr[pivotIdx]){
            ei--;
        }

        if(arr[si] > arr[pivotIdx] && arr[pivotIdx] >= arr[ei]){
            swap(arr[si], arr[ei]);
            si++;
            ei--;
        }
    }
    return pivotIdx;

}

void quickSort(int arr[], int low, int high){
    if(low< high){
    int pivot= findPivot(arr, low, high);
    quickSort(arr, low, pivot-1);
    quickSort(arr, pivot+1, high);
    }
}

int main()
{
    int arr[5]={3, 1, 2, 5, 4};
    quickSort(arr, 0, 4);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}