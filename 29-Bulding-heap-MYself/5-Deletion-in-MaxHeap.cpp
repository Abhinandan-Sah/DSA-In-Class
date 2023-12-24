// You are using GCC
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest=i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    if(l<n && arr[l] > arr[largest]){
        largest=l;
    }
    if(r<n && arr[r] > arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void deleteMax(int arr[], int& n) 
{
    if(n<=0){
        cout<<"Heap is empty"<<endl;
        return;
    }
    
    int root= arr[0];
    arr[0]=arr[n-1];
    n--;
    heapify(arr, n, 0);
}

void displayHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildMaxHeap(arr, n);

    deleteMax(arr, n);

    displayHeap(arr, n);

    return 0;
}
