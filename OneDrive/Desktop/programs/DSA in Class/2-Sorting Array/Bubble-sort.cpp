#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    // Taking each element at last
    for(int step=1; step<n; step++){

        bool flag=false;
        // To compare array element
        for(int i=0; i<n-step; i++){
            
            //for swapping
            if(arr[i]>arr[i+1] && (i+1)<n){
                flag=true;

                int temp = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }

        if(flag==false){
            //sub loop sai bahar aa jao, kyuki array sorted hai
            break;
        }
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[50];
    int n;
    cout<<"Enter Size of array: ";
    cin>>n;

    cout<<"Enter the Elements in Array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    
    bubbleSort(arr, n);
    
    return 0;
}