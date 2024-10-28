#include<iostream>
using namespace std;

void insertInHeap(int heap[], int& heapSize, int newElement) {
//   // Increase the heap size by 1.
//   heapSize++;

//   // Insert the new element at the end of the heap.
//   heap[heapSize - 1] = newElement;

//   // Percolate up the new element to maintain the max heap property.
//   int childIndex = heapSize - 1;
//   while (childIndex > 0 && heap[childIndex] > heap[(childIndex - 1) / 2]) {
//     swap(heap[childIndex], heap[(childIndex - 1) / 2]);
//     childIndex = (childIndex - 1) / 2;
//   }
    //****************or (SOURAV JOSHI SOLUTION)***********
    //mysirG solution
    if (heapSize == 0) {
    heap[heapSize] = newElement;
    return;
  }

  int newElementIndex = heapSize;
  while (newElementIndex > 0) {
    int parentIndex = (newElementIndex - 1) / 2;

    // Check if the new element is greater than its parent.
    if (newElement < heap[parentIndex]) {
      break;
    }

    // Swap the new element with its parent.
    heap[newElementIndex] = heap[parentIndex];
    newElementIndex = parentIndex;
  }

  // Insert the new element into the heap.
  heap[heapSize] = newElement;
  heapSize++;
}

int main()
{
    int arr[5]={10, 20, 5, 15, 25};
    int n=5;
    int item;
    cout<<"Enter the Item to be insert into heap: "<<endl;
    cin>>item;
    insertInHeap(arr, n, item);
    cout<<"Heap(maxHeap) after insertion is: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}