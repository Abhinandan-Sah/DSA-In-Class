#include<iostream>
using namespace std;

int partition(int a[], int low, int high){
    int pivot =a[high];
    int left=low;
    int right=high-1;
    while(true){
        while(left <= right && a[left]<=pivot){
            left++;
        }
        while(a[right]>pivot){
            right--;
        }
        if(left>right){
            break;
        }
        swap(a[left], a[right]);
    }
    swap(a[high], a[left]);
    return left;
}

void quickSort(int a[], int low, int high){
    if(low<high){
        int pivotIndex=partition(a, low, high);
        quickSort(a, low, pivotIndex-1);
        quickSort(a, pivotIndex+1, high);
    }
}

void display(int a[], int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[7]={5, 3, 8, 4, 2, 7, 1};
    int n=7;

    quickSort(arr, 0, n-1);
    // display(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}