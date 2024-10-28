// #include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int low, int high){
    int pivot =a[low];
    int left=low+1;
    int right=high;
    while(low<=high){
        while(a[left]<=pivot){
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
    swap(a[low], a[right]);
    return right;
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
    // int arr[7]={1, 4, 3, 2, 7, 5,6};
    int arr[7]={1, 4, 6, 2, 3};
    // int arr[7]={5, 3, 8, 4, 2, 7, 1};
    int n=7;
    cout<<"Orginal array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quickSort(arr, 0, n-1);
    // sort(arr, arr+n);
    // display(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}