#include<iostream>
using namespace std;

int main()
{
    int arr[15];
    int n;
    cout<<"Enter the size of an array"<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int pos;
    cout<<"Enter position in which you want to Delete"<<endl;
    cin>>pos;

    // Deletion Algo
    for(int i=pos; i<n;i++ ){
        arr[i]=arr[i+1];
    }
    n=n-1;

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    
    


    return 0;
}