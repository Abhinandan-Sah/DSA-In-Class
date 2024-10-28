#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){

    for(int round=1; round<n; round++){

        //storing 2 vale of arr in val
        int val=arr[round];
        int j=round-1;
        for(; j>=0; j--){
            
            // compare
            if(arr[j]>val){
                //shift
                arr[j+1]=arr[j];
            }
            else{
                //rukna hai
                break;
            }
        }

        arr[j+1]=val;

    }
}

int main()
{
    int arr[100];
    int n;
    cout<<"Enter the size of array: ";
    cin>>n; 
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    insertionSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}