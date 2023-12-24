#include <iostream>
using namespace std;

void maxHeapify(int arr[],int n, int i){
    int largestIndex=i;
    int l= (2*i) + 1;
    int r= (2*i) + 2;
    if(l<n && arr[l] > arr[largestIndex]){
        largestIndex=l;
    }
    if(r<n && arr[r] > arr[largestIndex]){
        largestIndex=r;
    }
    if(largestIndex != i){
        swap(arr[largestIndex], arr[i]);
        maxHeapify(arr,n, largestIndex);
    }
    
}

void buildHeap(int arr[], int n){
    // Start from the last non-leaf node and heapify all subtrees
    int startIndex = (n/2) -1;  //It is done because we don't swap leaf node
    //for max you can also do startIndex=(n-2)/2;
    for(int i=startIndex; i>=0; i--){
        maxHeapify(arr,n, i);
    }

}

int main()
{
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }
    cout << "\nOriginal Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    buildHeap(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;

}