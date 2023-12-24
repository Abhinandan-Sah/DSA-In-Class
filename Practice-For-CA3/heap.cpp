#include<iostream>
using namespace std;

void maxHeap(int arr[], int n, int i){
    int smallest= i;
    int l= (2*i)+1;
    int r= (2*i)+2;
    if(l<n && arr[l]< arr[smallest]){
        smallest=l;
    }
    if(r<n && arr[r]< arr[smallest]){
        smallest=r;
    }
    if(smallest!=i){
        swap(arr[smallest], arr[i]);
        maxHeap(arr, n, smallest);
    }
}

void buildHeap(int arr[], int n)
{
    for(int i=(n/2)-1; i>=0; i--){
        maxHeap(arr, n, i);
    }
}

void heapSort(int arr[], int n){
    buildHeap(arr, n);
    for(int i=n-1; i>0; i--){
        swap(arr[0], arr[i]);
        maxHeap(arr, i, 0);
    }
}

void deletion(int arr[], int &n){
    buildHeap(arr, n);
    int root= arr[0];
    arr[0]= arr[n-1];
    n--;
    maxHeap(arr, n, 0);
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

    // heapSort(arr, n);
    buildHeap(arr, n);
    deletion(arr, n);


    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}