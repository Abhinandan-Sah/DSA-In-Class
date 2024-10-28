// You are using GCC
#include <iostream>
using namespace std;

void heapify(char arr[], int n, int i) 
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

void buildMaxHeap(char arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(char arr[], int n)
{
    buildMaxHeap(arr, n);
    for(int i=n-1; i>0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int no;
    cin >> no;
    char arr[no];

    for (int i = 0; i < no; i++)
        cin >> arr[i];

    int totalGrade = no;
    heapSort(arr, totalGrade);

    for (int i = 0; i < totalGrade; i++)
        cout << arr[i] << " ";

    return 0;
}
