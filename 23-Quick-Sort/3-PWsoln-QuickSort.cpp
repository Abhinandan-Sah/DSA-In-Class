#include<iostream>
using namespace std;

int findPivotIndex(int arr[], int si, int ei){
    int pivotElem=arr[si];   //if we use pivotElem=arr[(si+ei)/2];  this will save the T.C from being O(n2)
    int count=0;
    for(int i=si; i<=ei; i++){
        //if we using Randomized then condition will be if(i== (si+ei)/2 ) continue;

        if(i==si) continue;
        if(arr[i]<=pivotElem){
            count++;
        }
    }
    int pivotIndex= si+count;
    swap(arr[si], arr[pivotIndex]);

    //putting left side of pivot element smaller than pivot element and right side element should be > pivotElem
    int i=si;
    int j=ei;
    while(i<pivotIndex && j>pivotIndex){
        if(arr[i]<=pivotElem){
            i++;
        }
        if(arr[j]>pivotElem){
            j--;
        }
        else if( arr[i]>pivotElem && arr[j]<=pivotElem ){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }

    }
    return pivotIndex;
}

void quickSort(int arr[], int si, int ei){
    // condition here, si=start index  , ei=end index, pi=pivot index
    if(si>=ei){
        return;
    }
    int pi= findPivotIndex(arr, si, ei);
    findPivotIndex(arr, si, pi-1);
    findPivotIndex(arr, pi+1, ei);
}

int main()
{
    int arr[]={1, 4, 6, 2, 3};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}