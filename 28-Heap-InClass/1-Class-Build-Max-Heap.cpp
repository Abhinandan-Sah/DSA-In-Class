#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && arr[left] > arr[largest]){
largest = left;
}
if (right < n && arr[right] > arr[largest]){
largest = right;
}
if (largest != i) {
swap(arr[i], arr[largest]);
maxHeapify(arr, n, largest);
}
}

void buildMaxHeap(int arr[], int n) {
for (int i = n / 2 - 1; i >= 0; i--) {
maxHeapify(arr, n, i);
}
}

void heapSort(int arr[], int n) {
buildMaxHeap(arr, n);
for (int i = n - 1; i > 0; i--) {
swap(arr[0], arr[i]);
maxHeapify(arr, i, 0);
}
}

int main() {
int n;
cout<<"Enter no. of elements: ";
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
cout<<"Enter arr["<<i<<"]: ";
cin>>arr[i];
}
cout<<"\nOriginal Array: ";
for (int i=0; i<n; i++) {
cout<<arr[i]<<" ";
}
cout<<endl;

heapSort(arr, n);

cout<<"\nSorted array: ";
for(int i = 0; i < n; i++) {
cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}