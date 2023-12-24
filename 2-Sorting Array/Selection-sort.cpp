#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of element of array: ";
    cin>>n;
    vector<int>arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //Selection sort
    for(int i=0; i<n; i++){
        int minIndex=i;
        for(int j=i+1; j<n; j++){
            if(arr[minIndex] > arr[j]){
                minIndex=j;
            }
        }
        //swapping
        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}