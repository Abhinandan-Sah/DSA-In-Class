#include<iostream>
using namespace std;

int findPivot(int arr[], int low, int high){
    int pivot=low;
    int left=low+1;
    int right=high;
    while(low<=high){
        while(left<=right && arr[left]<=arr[pivot]){
            left++;
        }

        while(left<=right && arr[right]>arr[pivot]){
            right--;
        }

        if(left>right){
            break;
        }
        swap(arr[left], arr[right]);
    }
    swap(arr[low], arr[right]);
    return right;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
    int pivotElement= findPivot(arr, 0, high);
    findPivot(arr, low, pivotElement-1);
    findPivot(arr, pivotElement+1, high);
    }

}

int main()
{
    int arr[100];
    int n; cout<<"Enter the value of n: ";cin>>n; 
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
} 