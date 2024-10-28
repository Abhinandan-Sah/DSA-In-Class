//This is code for Kth Smallest element

#include<iostream>
using namespace std;

int findPivotIndex(int arr[], int si, int ei){
    int pivotElem=arr[ (si+ei)/2 ];  
    int count=0;
    for(int i=si; i<=ei; i++){

        if(i== (si+ei)/2 ) continue;
        if(arr[i]<=pivotElem){
            count++;
        }
    }
    int pivotIndex= si+count;
    swap(arr[ (si+ei)/2 ], arr[pivotIndex]);

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

int KthSmallest(int arr[], int si, int ei, int k){
    if(si>=ei){
        return;
    }
    int pi= findPivotIndex(arr, si, ei);
    if(pi+1 ==k) return arr[pi+1];
    else if((pi+1) < k){
    return KthSmallest(arr, pi+1, ei, k);
    }else{
    return KthSmallest(arr, si, pi-1, k);
    }
}

int main()
{
    int arr[]={5, 1, 8, 2, 7, 6, 3, 4, -8};
    int n=sizeof(arr)/sizeof(arr[0]);

    int k=4;
    cout<<"Kth Smallest element is: "<<KthSmallest(arr, 0, n-1, k);

    return 0;
}